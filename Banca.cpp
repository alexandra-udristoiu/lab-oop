#include "Banca.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

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
        std::cout<<"Clientul nu exista\n";
        return;
    }
    int pos = codClienti[cnp];
    std::cout<< clienti[pos - 1];
}

void Banca::adaugaBaniCont(std::string iban, double suma) {
    if(ibanClienti.count(iban) == 0){
        std::cout<<"Clientul nu exista\n";
        return;
    }
    int pos = ibanClienti[iban] - 1;
    clienti[pos].adaugaBaniCont(suma);
}

void Banca::scoateBaniCont(std::string iban, double suma) {
    if(ibanClienti.count(iban) == 0){
        std::cout<<"Clientul nu exista\n";
        return;
    }
    int pos = ibanClienti[iban] - 1;
    clienti[pos].scoateBaniCont(suma);
}

void Banca::tranzactie(std::string iban, std::string ibanDest, std::string nume, double suma) {
    if(ibanClienti.count(iban) == 0){
        std::cout<<"Clientul nu exista\n";
        return;
    }
    if(ibanClienti.count(ibanDest) == 0){
        std::cout<<"Destinatarul nu exista\n";
        return;
    }
    int pos = ibanClienti[iban] - 1;
    int posDest = ibanClienti[ibanDest] - 1;
    if(nume != clienti[posDest].getNume() ){
        std::cout<<"Datele nu sunt corecte\n";
    }
    else{
        if(suma > clienti[pos].getSumaCont() ){
            std::cout<<"Nu sunt suficienti bani in cont\n";
        }
        else{
            std::cout<<"Tranzactie efectuata cu succes\n";
            clienti[pos].scoateBaniCont(suma);
            clienti[posDest].adaugaBaniCont(suma);
        }
    }
}

void Banca::setNumeClient(long long int cnp, std::string nume) {
    if(codClienti.count(cnp) == 0){
        std::cout<<"Clientul nu exista\n";
    }
    else{
        int pos = codClienti[cnp] - 1;
        clienti[pos].setNume(nume);
    }
}

void Banca::setAdresaClient(long long int cnp, std::string adresa) {
    if(codClienti.count(cnp) == 0){
        std::cout<<"Clientul nu exista\n";
    }
    else{
        int pos = codClienti[cnp] - 1;
        clienti[pos].setAdresa(adresa);
    }
}

void Banca::depozitNou(long long cnp, int tip1, int tip2, double suma) {
    if(codClienti.count(cnp) == 0){
        std::cout<<"Clientul nu exista\n";
    }
    else{
        int pos = codClienti[cnp] - 1;
        clienti[pos].depozitNou(tip1, tip2, suma, data);
    }
}

void Banca::afisareDepoziteClient(long long int cnp) {
    if(codClienti.count(cnp) == 0){
        std::cout<<"Clientul nu exista\n";
    }
    else{
        int pos = codClienti[cnp] - 1;
        clienti[pos].afisareDepozite();
    }
}

void Banca::inchidereDepozitClient(long long int cnp, int codDepozit) {
    if(codClienti.count(cnp) == 0){
        std::cout<<"Clientul nu exista\n";
    }
    else{
        int pos = codClienti[cnp] - 1;
        clienti[pos].inchidereDepozit(codDepozit, data);
    }
}
