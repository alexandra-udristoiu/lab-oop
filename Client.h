//
// Created by Alexandra on 10.03.2021.
//

#ifndef POO_TEMA_CLIENT_H
#define POO_TEMA_CLIENT_H


#include <string>
#include "ContCurent.h"

class Client {
    long long cnp;
    std::string nume;
    std::string adresa;
    ContCurent *cont;
public:
    Client(long long cnp, std::string nume, std::string adresa, int data);
    friend std::ostream &operator<<(std::ostream &os, const Client& c);
};


#endif //POO_TEMA_CLIENT_H
