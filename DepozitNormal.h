//
// Created by Alexandra on 18.04.2021.
//

#ifndef POO_TEMA_DEPOZITNORMAL_H
#define POO_TEMA_DEPOZITNORMAL_H

#include "Depozit.h"

class DepozitNormal : public Depozit {
public:
    explicit DepozitNormal(int tip, int dataDeschidere, double suma);
    double scadenta() override;
    void afisare(std::ostream &os) const override;
    ~DepozitNormal() override;
};


#endif //POO_TEMA_DEPOZITNORMAL_H
