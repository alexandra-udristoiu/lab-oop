//
// Created by Alexandra on 10.03.2021.
//

#include "Client.h"
#include "DepozitNormal.h"
#include "DepozitReinnoire.h"
#include "DepozitCapitalizare.h"
#include "Exceptii.h"
#include <iostream>
#include <memory>
#include "rlutil.h"
#include "templatef.cpp"

template
void afismax<int>(std::vector<int> v);

Client::Client(long long cnp, const std::string &nume, const std::string &adresa, int data, const std::string &iban) {
    this->cnp = cnp;
    this->nume = nume;
    this->adresa = adresa;
    cont.setIban(iban);
    cont.setData(data);
}

std::ostream &operator<<(std::ostream &os, const Client &c) {
    os<< "Nume client: "<< c.nume <<"\n";
    os<< "Adresa client: "<< c.adresa <<"\n";
    os<< c.cont;
    return os;
}

Client::~Client() {
    std::cout<<"S-a apelat destructor client pentru "<< nume <<"\n";
}

Client::Client(const Client &c) {
    cnp = c.cnp;
    nume = c.nume;
    adresa = c.adresa;
    cont = c.cont;
    std::cout<<"S-a apelat constructorul de copiere pentru "<< nume <<"\n";
}

Client &Client::operator=(const Client &c) {
    cnp = c.cnp;
    nume = c.nume;
    adresa = c.adresa;
    cont = c.cont;
    //std::cout<<"operator= "<< nume <<"\n";
    return *this;
}

void Client::adaugaBaniCont(double suma) {
    cont.adaugaBani(suma);
}

void Client::scoateBaniCont(double suma) {
    cont.scoateBani(suma);
}

std::string Client::getNume() {
    return nume;
}

double Client::getSumaCont() {
    return cont.getSuma();
}

void Client::setNume(const std::string &nume) {
    this->nume = nume;
}

void Client::setAdresa(const std::string &adresa) {
    this->adresa = adresa;
}

void Client::depozitNou(int tipDepozit, int durataDepozit, double suma, int data) {
    if (tipDepozit == 1) {
        depozite.push_back(std::make_unique<DepozitNormal>(durataDepozit, data, suma));
    } else {
        if (tipDepozit == 2) {
            depozite.push_back(std::make_unique<DepozitReinnoire>(durataDepozit, data, suma));
        } else {
            if (tipDepozit == 3) {
                depozite.push_back(std::make_unique<DepozitCapitalizare>(durataDepozit, data, suma));
            } else {
                throw eroare_tip_depozit();
            }
        }
    }
}

void Client::updateData(int data) {
    for(int i = 0; i < depozite.size(); i++){
        if( depozite[i]->updateData(data) ){
            double suma = depozite[i]->scadenta();
            cont.adaugaBani(suma);
            if(depozite[i]->trebuieSters(data) ){
                depozite.erase(depozite.begin() + i);
                i--;
            }
        }
    }
}

void Client::afisareDepozite() {
    std::cout<<"Depozitele clientului "<< nume <<"\n";
    for(int i = 0; i < depozite.size(); i++){
        std::cout<< *depozite[i] <<"\n";
    }
    std::cout<<"\n";
}

void Client::inchidereDepozit(int codDepozit, int data) {
    for(int i = 0; i < depozite.size(); i++){
        if(depozite[i]->getCod() == codDepozit){
            depozite[i]->inchidereInainte(data);
            depozite.erase(depozite.begin() + i);
            rlutil::setColor(5);
            std::cout<<"Depozitul "<< codDepozit << " a fost inchis\n";
            rlutil::resetColor();
            break;
        }
    }
}


bool Client::operator<(Client c) {
    return this->getSumaCont() < c.getSumaCont();
}

void Client::sumMaxDepozit() {
    std::vector<int> s;
    for(int i = 0; i < depozite.size(); i++){
        s.push_back(depozite[i]->getSumaCurenta() );
    }
    afismax(s);
}


