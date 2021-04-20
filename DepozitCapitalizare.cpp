//
// Created by Alexandra on 20.04.2021.
//

#include "DepozitCapitalizare.h"
#include <iostream>

double DepozitCapitalizare::scadenta() {
    suma += sumaDobanda;
    sumaDobanda = 0;
    dataDeschidere = dataInchidere;
    dataInchidere = dataDeschidere + durata;
    return 0;
}

void DepozitCapitalizare::afisare(std::ostream &os) const{
    os<<"Depozit cu capitalizare numarul: "<< codDepozit <<"\n";
    os<<"Suma: "<< suma <<"\n";
    os<<"Dobanda pana in acest moment: "<< sumaDobanda <<"\n";
}

DepozitCapitalizare::~DepozitCapitalizare() {
    std::cout<<"S-a apelat destructorul pentru depozitul cu capitalizare: " << codDepozit <<"\n";
}

DepozitCapitalizare::DepozitCapitalizare(int tip, int dataDeschidere, double suma) : DepozitReinnoire(tip, dataDeschidere,suma) {
}
