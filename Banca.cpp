#include "Banca.h"
#include "Exceptii.h"
#include <iostream>
#include <string>


Banca::Banca() {
    //TO DO: schimbat format data
    data = 0;
}

void Banca::clientNou(long long cnp, const std::string &nume, const std::string &adresa) {
    if(codClienti.count(cnp) == 1){
        std::cout<<"Clientul exista deja!\n";
    }
    else{
        std::cout<<"Client inregistrat!\n";
        std::string iban = createIban();
        Client clientNou(cnp, nume, adresa, data, iban);
        clienti.push_back(clientNou);
        codClienti[cnp] = clienti.size();
        ibanClienti[iban] = clienti.size();
    }
}

void Banca::updateData() {
    data++;
    for(int i = 0; i < clienti.size(); i++){
        clienti[i].updateData(data);
    }
}

std::string Banca::createIban() {
    std::string iban = "RO10BANK000000";
    int x = clienti.size();
    for(int i = 1; i <= 8; i++){
        iban.push_back(x % 10 + '0');
        x /= 10;
    }
    return iban;
}

void Banca::afisareClient(long long cnp) {
    if(codClienti.count(cnp) == 0){
        throw eroare_client_inexistent();
    }
    int pos = codClienti[cnp];
    std::cout<< clienti[pos - 1];
}

void Banca::adaugaBaniCont(const std::string &iban, double suma) {
    if(ibanClienti.count(iban) == 0){
        throw eroare_client_inexistent();
    }
    int pos = ibanClienti[iban] - 1;
    clienti[pos].adaugaBaniCont(suma);
}

void Banca::scoateBaniCont(const std::string &iban, double suma) {
    if(ibanClienti.count(iban) == 0){
        throw eroare_client_inexistent();
    }
    int pos = ibanClienti[iban] - 1;
    clienti[pos].scoateBaniCont(suma);
}

void Banca::tranzactie(const std::string &iban, const std::string &ibanDest, const std::string &nume, double suma) {
    if(ibanClienti.count(iban) == 0){
        throw eroare_client_inexistent();
    }
    if(ibanClienti.count(ibanDest) == 0){
        throw eroare_destinatar();
    }
    int pos = ibanClienti[iban] - 1;
    int posDest = ibanClienti[ibanDest] - 1;
    if(nume != clienti[posDest].getNume() ){
        throw eroare_destinatar();
    }
    if(suma > clienti[pos].getSumaCont() ){
        throw eroare_bani_insuficienti();
    }
    clienti[pos].scoateBaniCont(suma);
    clienti[posDest].adaugaBaniCont(suma);
}

void Banca::setNumeClient(long long int cnp, const std::string &nume) {
    if(codClienti.count(cnp) == 0){
        throw eroare_client_inexistent();
    }
    int pos = codClienti[cnp] - 1;
    clienti[pos].setNume(nume);
}

void Banca::setAdresaClient(long long int cnp, const std::string &adresa) {
    if(codClienti.count(cnp) == 0){
        throw eroare_client_inexistent();
    }
    int pos = codClienti[cnp] - 1;
    clienti[pos].setAdresa(adresa);
}

void Banca::depozitNou(long long cnp, int tipDepozit, int durataDepozit, double suma) {
    if(codClienti.count(cnp) == 0){
        throw eroare_client_inexistent();
    }
    int pos = codClienti[cnp] - 1;
    clienti[pos].depozitNou(tipDepozit, durataDepozit, suma, data);
}

void Banca::afisareDepoziteClient(long long int cnp) {
    if(codClienti.count(cnp) == 0){
        throw eroare_client_inexistent();
    }
    int pos = codClienti[cnp] - 1;
    clienti[pos].afisareDepozite();
}

void Banca::inchidereDepozitClient(long long int cnp, int codDepozit) {
    if(codClienti.count(cnp) == 0){
        throw eroare_client_inexistent();
    }
    int pos = codClienti[cnp] - 1;
    clienti[pos].inchidereDepozit(codDepozit, data);
}
