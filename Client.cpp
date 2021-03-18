//
// Created by Alexandra on 10.03.2021.
//

#include "Client.h"
#include <iostream>

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

