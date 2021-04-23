//
// Created by Alexandra on 10.03.2021.
//

#include "ContCurent.h"
#include "Exceptii.h"
#include <iostream>

ContCurent::ContCurent() {
    suma = 0;
    dataDeschidere = 0;
}

void ContCurent::setIban(const std::string &iban) {
    this->iban = iban;
}

void ContCurent::setData(int data) {
    dataDeschidere = data;
}

std::ostream &operator<<(std::ostream &os, const ContCurent &c) {
    os<< "Cod IBAN: "<< c.iban <<"\n";
    os<<"Suma:"<< c.suma <<"\n";
    return os;
}

void ContCurent::adaugaBani(double s) {
    suma += s;
}

void ContCurent::scoateBani(double s) {
    if(suma < s){
        throw eroare_bani_insuficienti();
    }
    suma -= s;
}

double ContCurent::getSuma() {
    return suma;
}
