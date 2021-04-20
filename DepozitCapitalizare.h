//
// Created by Alexandra on 20.04.2021.
//

#ifndef POO_TEMA_DEPOZITCAPITALIZARE_H
#define POO_TEMA_DEPOZITCAPITALIZARE_H


#include "DepozitReinnoire.h"

class DepozitCapitalizare : public DepozitReinnoire {
public:
    explicit DepozitCapitalizare(int tip, int dataDeschidere, double suma);
    double scadenta() override;
    void afisare(std::ostream &os) const override;
    ~DepozitCapitalizare() override;
};


#endif //POO_TEMA_DEPOZITCAPITALIZARE_H
