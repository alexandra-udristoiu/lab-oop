//
// Created by Alexandra on 10.03.2021.
//

#include "Client.h"
#include <iostream>

Client::Client(long long cnp, std::string nume, std::string adresa, int data) {
    this->cnp = cnp;
    this->nume = nume;
    this->adresa = adresa;
    cont = new ContCurent();

}

std::ostream &operator<<(std::ostream &os, const Client &c) {
    os<< "nume client: "<< c.nume <<"\n";
    os<< "adresa client: "<< c.adresa <<"\n";
    return os;
}

