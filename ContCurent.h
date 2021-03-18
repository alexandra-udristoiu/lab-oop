//
// Created by Alexandra on 10.03.2021.
//

#ifndef POO_TEMA_CONTCURENT_H
#define POO_TEMA_CONTCURENT_H

#include <string>


class ContCurent {
    double suma;
    int dataDeschidere;
    std::string iban;
public:
    ContCurent();
    void setIban(std::string iban);
    void setData(int data);
    friend std::ostream &operator<<(std::ostream &os, const ContCurent& c);

    void adaugaBani(double s);

     void scoateBani(double s);

    double getSuma();
};


#endif //POO_TEMA_CONTCURENT_H
