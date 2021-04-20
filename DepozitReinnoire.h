//
// Created by Alexandra on 18.04.2021.
//

#ifndef POO_TEMA_DEPOZITREINNOIRE_H
#define POO_TEMA_DEPOZITREINNOIRE_H

#include "Depozit.h"

class DepozitReinnoire : public Depozit {
protected:
    int dataInitiala;
    int durata;
public:
    explicit DepozitReinnoire(int tip, int dataDeschidere, double suma);
    double scadenta() override;
    void afisare(std::ostream &os) const override;
    bool trebuieSters(int dataCurenta) override;
    ~DepozitReinnoire() override;


};


#endif //POO_TEMA_DEPOZITREINNOIRE_H
