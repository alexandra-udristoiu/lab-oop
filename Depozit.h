//
// Created by Alexandra on 18.04.2021.
//

#ifndef POO_TEMA_DEPOZIT_H
#define POO_TEMA_DEPOZIT_H
#include<vector>
#include<algorithm>
#include<iostream>


class Depozit {
protected:
    double suma;
    double sumaDobanda;
    double dobanda;
    int codDepozit;
    int dataDeschidere;
    int dataInchidere;
    static int nrDepozite;
    static const std::vector< std::pair<int, double> > tipuriDepozite;
    static const int sumaMinima = 500;
    static const int zileAn = 360;
public:
    explicit Depozit(int tip, int dataDeschidere, double suma);
    virtual double scadenta() = 0;
    virtual void afisare(std::ostream &os) const = 0;
    //double getSumaFinala();
    double inchidereInainte(int dataCurenta);
    void calculDobanda(int nrZile);
    bool updateData(int dataCurenta);
    virtual bool trebuieSters(int dataCurenta);
    virtual ~Depozit() = default;
    friend std::ostream &operator<<(std::ostream &os, const Depozit &d);
    int getCod();
};


#endif //POO_TEMA_DEPOZIT_H
