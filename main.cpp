#include <iostream>
#include<fstream>
#include <string>
#include "Banca.h"

int main() {
    std::ifstream fin("date.in");
    int operatie;
    Banca bank;
    while (fin >> operatie) {
        try {
            switch (operatie) {
                case 1: {
                    bank.updateData();
                    break;
                }
                case 10: {
                    long long cnp;
                    std::string nume, adresa;
                    fin >> cnp;
                    getline(fin, nume);
                    getline(fin, nume);
                    getline(fin, adresa);
                    //getline(fin, adresa);
                    bank.clientNou(cnp, nume, adresa);
                    break;
                }
                case 11: {
                    long long cnp;
                    fin >> cnp;
                    bank.afisareClient(cnp);
                    break;
                }
                case 12: {
                    std::string iban;
                    getline(fin, iban);
                    getline(fin, iban);
                    double suma;
                    fin >> suma;
                    bank.adaugaBaniCont(iban, suma);
                    std::cout<<"Ati adaugat in cont "<< suma <<" lei\n";
                    break;
                }
                case 13: {
                    std::string iban;
                    getline(fin, iban);
                    getline(fin, iban);
                    double suma;
                    fin >> suma;
                    bank.scoateBaniCont(iban, suma);
                    std::cout<<"Ati scos din cont "<< suma <<" lei\n";
                    break;
                }
                case 14: {
                    std::string iban, iban2, nume;
                    getline(fin, iban);
                    getline(fin, iban);
                    getline(fin, iban2);
                    getline(fin, nume);
                    std::cout<< iban2 <<" "<< nume;
                    double suma;
                    fin >> suma;
                    bank.tranzactie(iban, iban2, nume, suma);
                    std::cout<<"Tranzactie efectuata cu succes\n";
                    break;
                }
                case 15: {
                    long long cnp;
                    fin >> cnp;
                    std::string nume;
                    getline(fin, nume);
                    getline(fin, nume);
                    bank.setNumeClient(cnp, nume);
                    break;
                }
                case 16: {
                    long long cnp;
                    fin >> cnp;
                    std::string adresa;
                    getline(fin, adresa);
                    getline(fin, adresa);
                    bank.setAdresaClient(cnp, adresa);
                    break;
                }
                case 21: {
                    long long cnp;
                    int tipDepozit, durataDepozit;
                    double suma;
                    fin >> cnp >> tipDepozit >> durataDepozit >> suma;
                    bank.depozitNou(cnp, tipDepozit, durataDepozit, suma);
                    break;
                }
                case 22: {
                    long long cnp;
                    fin >> cnp;
                    bank.afisareDepoziteClient(cnp);
                    break;
                }
                case 23: {
                    long long cnp;
                    int codDepozit;
                    fin >> cnp >> codDepozit;
                    bank.inchidereDepozitClient(cnp, codDepozit);
                    break;
                }
            }
        }
        catch (std::domain_error &e) {
            std::cout << e.what() << "\n";
        }
    }
}
