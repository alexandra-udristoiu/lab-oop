//
// Created by Alexandra on 10.03.2021.
//

#ifndef POO_TEMA_CLIENT_H
#define POO_TEMA_CLIENT_H


#include <string>
#include <vector>
#include<memory>
#include "ContCurent.h"
#include "Depozit.h"

class Client {
    long long cnp;
    std::string nume;
    std::string adresa;
    ContCurent cont;
    std::vector< std::unique_ptr<Depozit> > depozite;
public:
    Client(long long cnp, std::string nume, std::string adresa, int data, std::string iban);
    friend std::ostream &operator<<(std::ostream &os, const Client &c);
    ~Client();
    Client(const Client &c);
    Client& operator=(const Client &c);
    void adaugaBaniCont(double suma);
    void scoateBaniCont(double suma);
    std::string getNume();
    double getSumaCont();
    void setNume(std::string nume);
    void setAdresa(std::string adresa);
    void depozitNou(int tip1, int tip2, double suma, int data);
    void updateData(int data);
    void afisareDepozite();
    void inchidereDepozit(int codDepozit, int data);
};


#endif //POO_TEMA_CLIENT_H
