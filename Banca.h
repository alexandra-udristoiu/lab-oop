//
// Created by Alexandra on 10.03.2021.
//

#ifndef POO_TEMA_BANCA_H
#define POO_TEMA_BANCA_H

#include <map>
#include<vector>
#include "Client.h"

class Banca {
    int data;
    std::vector<Client> clienti;
    std::map<long long, int> codClienti;
    std::map<std::string, int> ibanClienti;
public:
    Banca();
    void clientNou(long long cnp, const std::string &nume, const std::string &adresa);
    void updateData();

    void afisareClient(long long int i);

    void adaugaBaniCont(std::string iban, double suma);

    void scoateBaniCont(std::string iban, double suma);

    void tranzactie(std::string iban, std::string ibanDest, std::string nume, double suma);

    void setNumeClient(long long cnp, std::string nume);

    void setAdresaClient(long long cnp, std::string adresa);

    void depozitNou(long long cnp, int tip1, int tip2, double suma);

    void afisareDepoziteClient(long long cnp);

    void inchidereDepozitClient(long long cnp, int codDepozit);

private:
    std::string createIban();
};


#endif //POO_TEMA_BANCA_H
