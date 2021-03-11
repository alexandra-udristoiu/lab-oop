//
// Created by Alexandra on 10.03.2021.
//

#ifndef POO_TEMA_BANCA_H
#define POO_TEMA_BANCA_H

#include <map>
#include<vector>
#include "Client.h"

class Banca {
    int nrClienti;
    static const int zileAn = 365;
    int data;
    std::vector<Client> clienti;
    std::map<long long, int> codClienti;
public:
    Banca();
    void clientNou(long long cnp, const std::string &nume, const std::string &adresa);

    void updateData();
};


#endif //POO_TEMA_BANCA_H
