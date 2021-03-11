#include "Banca.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

Banca::Banca() {
    nrClienti = 0;
    data = 0;
}

void Banca::clientNou(long long cnp, const std::string &nume, const std::string &adresa) {
    if(codClienti.count(cnp) == 1){
        std::cout<<"Clientul exista deja!";
    }
    else{
        std::cout<<"Client inregistrat!";
        nrClienti++;
        Client clientNou(cnp, nume, adresa, data);
        clienti.push_back(clientNou);
        codClienti[cnp] = nrClienti;
    }
}

void Banca::updateData() {
    data++;
}
