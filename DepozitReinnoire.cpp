//
// Created by Alexandra on 18.04.2021.
//

#include "DepozitReinnoire.h"
#include <iostream>

DepozitReinnoire::DepozitReinnoire(int tip, int dataDeschidere, double suma) : Depozit(tip, dataDeschidere, suma) {
    this->dataInitiala = dataDeschidere;
    this->durata = tipuriDepozite[tip].first;
}

double DepozitReinnoire::scadenta() {
    double val = sumaDobanda;
    sumaDobanda = 0;
    dataDeschidere = dataInchidere;
    dataInchidere = dataDeschidere + durata;
    return val;
}

void DepozitReinnoire::afisare(std::ostream &os) const {
    os<<"Depozit cu reinnoire automata numarul: "<< codDepozit <<"\n";
    os<<"Suma: "<< suma <<"\n";
    os<<"Dobanda pana in acest moment: "<< sumaDobanda <<"\n";
}

bool DepozitReinnoire::trebuieSters(int dataCurenta) {
    return false;
}

DepozitReinnoire::~DepozitReinnoire() {
    std::cout<<"S-a apelat destructorul pentru depozitul cu reinnoire automata: " << codDepozit <<"\n";
}
