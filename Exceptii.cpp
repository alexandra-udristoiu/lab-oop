//
// Created by Alexandra on 23.04.2021.
//

#include "Exceptii.h"

eroare_tip_depozit::eroare_tip_depozit() noexcept : std::domain_error("Acest tip de depozit nu exista") {}

eroare_suma_depozit::eroare_suma_depozit() noexcept : std::domain_error("Suma depusa este prea mica"){}

eroare_client_inexistent::eroare_client_inexistent() noexcept : std::domain_error("Clientul nu exista") {}

eroare_bani_insuficienti::eroare_bani_insuficienti() noexcept : std::domain_error("Nu sunt suficienti bani in cont"){}

eroare_destinatar::eroare_destinatar() noexcept : std::domain_error("Datele destinatarului nu sunt corecte") {}
