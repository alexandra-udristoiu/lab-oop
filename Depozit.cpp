//
// Created by Alexandra on 18.04.2021.
//

#include "Depozit.h"
#include "Exceptii.h"
#include <algorithm>
#include <vector>
#include <cmath>

const std::vector< std::pair<int, double> > Depozit::tipuriDepozite{
        {30, 0.40}, {90, 0.50}, {180, 1}, {360, 1.60}, {720, 1.65}
};
int Depozit::nrDepozite = 0;

Depozit::Depozit(int tip, int dataDeschidere, double suma) {
    if(tip < 0 || tip >= tipuriDepozite.size() ){
        throw eroare_tip_depozit();
    }
    if(suma < sumaMinima){
        throw eroare_suma_depozit();
    }
    this->dataDeschidere = dataDeschidere;
    this->suma = suma;
    nrDepozite++;
    codDepozit = nrDepozite;
    dataInchidere = dataDeschidere + tipuriDepozite[tip].first;
    dobanda = tipuriDepozite[tip].second;
    sumaDobanda = 0;
}

/*double Depozit::getSumaFinala() {
    return suma + sumaDobanda;
}*/

void Depozit::calculDobanda(int nrZile) {
    sumaDobanda = suma * dobanda / 100 * nrZile / zileAn;
    sumaDobanda = floor(sumaDobanda * 100);
    sumaDobanda /= 100;
}


bool Depozit::updateData(int dataCurenta) {
    calculDobanda(dataCurenta - dataDeschidere);
    if(dataCurenta == dataInchidere){
        return true;
    }
    else{
        return false;
    }
}

double Depozit::inchidereInainte(int dataCurenta) {
    if(dataCurenta - dataDeschidere >= zileAn){
        calculDobanda(zileAn);
        return suma + sumaDobanda;
    }
    else{
        return suma;
    }
}

bool Depozit::trebuieSters(int dataCurenta) {
    if(dataCurenta == dataInchidere){
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Depozit &d) {
    d.afisare(os);
    return os;
}

int Depozit::getCod() {
    return codDepozit;
}
