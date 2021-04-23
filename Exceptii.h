//
// Created by Alexandra on 23.04.2021.
//

#ifndef POO_TEMA_EXCEPTII_H
#define POO_TEMA_EXCEPTII_H


#include <stdexcept>

class eroare_tip_depozit : public std::domain_error{
public:
    eroare_tip_depozit() noexcept;
};

class eroare_suma_depozit : public std::domain_error{
public:
    eroare_suma_depozit() noexcept;
};

class eroare_client_inexistent : public std::domain_error{
public:
    eroare_client_inexistent() noexcept;
};

class eroare_bani_insuficienti : public std::domain_error{
public:
    eroare_bani_insuficienti() noexcept;
};

class eroare_destinatar : public std::domain_error{
public:
    eroare_destinatar() noexcept;
};



#endif //POO_TEMA_EXCEPTII_H
