//
// Created by Alexandra on 10.03.2021.
//

#include "Client.h"
#include "DepozitNormal.h"
#include "DepozitReinnoire.h"
#include "DepozitCapitalizare.h"
#include <iostream>
#include <memory>

Client::Client(long long cnp, std::string nume, std::string adresa, int data, std::string iban) {
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
    std::cout<<"operator= "<< nume <<"\n";
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

void Client::setNume(std::string nume) {
    this->nume = nume;
}

void Client::setAdresa(std::string adresa) {
    this->adresa = adresa;
}

void Client::depozitNou(int tip1, int tip2, double suma, int data) {
    try {
        if (tip1 == 1) {
            depozite.push_back(std::make_unique<DepozitNormal>(tip2, data, suma));
        } else {
            if (tip1 == 2) {
                depozite.push_back(std::make_unique<DepozitReinnoire>(tip2, data, suma));
            } else {
                if (tip1 == 3) {
                    depozite.push_back(std::make_unique<DepozitCapitalizare>(tip2, data, suma));
                } else {
                    throw std::domain_error("Acest tip de depozit nu exista");
                }
            }
        }
    }
    catch(std::domain_error &e){
        std::cout<< e.what() <<"\n";
    }
}

void Client::updateData(int data) {
    for(int i = 0; i < depozite.size(); i++){
        if( depozite[i]->updateData(data) ){
            double suma = depozite[i]->scadenta();
            cont.adaugaBani(suma);
            std::cout<<"S-a sters depozitul "<< i <<" "<< nume <<"\n";
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
    //TO DO: de terminat inchiderea depozitelor
}

