#include <iostream>
#include<fstream>
#include <string>
#include "Banca.h"

int main() {
    std::ifstream fin("date.in");
    int operatie;
    Banca bank;
    while (fin>> operatie) {
        if (operatie == 1) {
            bank.updateData();
        }
        if(operatie == 10) {
            long long cnp;
            std::string nume, adresa;
            fin >> cnp;
            getline(fin, nume);
            getline(fin, adresa);
            bank.clientNou(cnp, nume, adresa);
        }
    }
}
