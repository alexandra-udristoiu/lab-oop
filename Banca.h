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
    Banca();
    static Banca* bank;
public:

    static Banca* getBank(){
        if(bank == nullptr){
            bank = new Banca();
        }
        return bank;
    }
    void clientNou(long long cnp, const std::string &nume, const std::string &adresa);
    void updateData();

    void afisareClient(long long int i);

    void adaugaBaniCont(const std::string &iban, double suma);

    void scoateBaniCont(const std::string &iban, double suma);

    void tranzactie(const std::string &iban, const std::string &ibanDest, const std::string &nume, double suma);

    void setNumeClient(long long cnp, const std::string &nume);

    void setAdresaClient(long long cnp, const std::string &adresa);

    void depozitNou(long long cnp, int tipDepozit, int durataDepozit, double suma);

    void afisareDepoziteClient(long long cnp);

    void inchidereDepozitClient(long long cnp, int codDepozit);

    void afisMaxime();

private:
    std::string createIban();
};


#endif //POO_TEMA_BANCA_H
