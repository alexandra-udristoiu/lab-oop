//
// Created by Alexandra on 18.04.2021.
//

#include "DepozitNormal.h"
#include <iostream>

void DepozitNormal::afisare(std::ostream &os) const {
    os<<"Depozit numarul: "<< codDepozit <<"\n";
    os<<"Suma: "<< suma <<"\n";
    os<<"Dobanda pana in acest moment: "<< sumaDobanda <<"\n";
}

double DepozitNormal::scadenta() {
    return suma + sumaDobanda;
}

DepozitNormal::~DepozitNormal() {
    std::cout<<"S-a apelat destructorul pentru depozitul " << codDepozit <<"\n";
}

DepozitNormal::DepozitNormal(int tip, int dataDeschidere, double suma) : Depozit(tip, dataDeschidere, suma){
}
