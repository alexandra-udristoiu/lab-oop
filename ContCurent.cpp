//
// Created by Alexandra on 10.03.2021.
//

#include "ContCurent.h"
#include <iostream>

ContCurent::ContCurent() {
    suma = 0;
}

void ContCurent::setIban(std::string iban) {
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
        std::cout<<"Nu exista suficienti bani in cont\n";
    }
    else{
        suma -= s;
    }
}

double ContCurent::getSuma() {
    return suma;
}
