#include "Transazione.h"
#include <sstream>

Transazione::Transazione(std::string data, double importo, TipoTransazione tipo, std::string descrizione)
        : data(data), importo(importo), tipo(tipo), descrizione(descrizione) {}

std::string Transazione::toString() const {
    return data + "," + std::to_string(importo) + "," +
           (tipo == TipoTransazione::Entrata ? "entrata" : "uscita") + "," + descrizione;
}

Transazione Transazione::fromString(const std::string& riga) {
    std::stringstream ss(riga);
    std::string data, importoStr, tipoStr, descrizione;

    std::getline(ss, data, ',');
    std::getline(ss, importoStr, ',');
    std::getline(ss, tipoStr, ',');
    std::getline(ss, descrizione);

    double importo = std::stod(importoStr);
    TipoTransazione tipo = (tipoStr == "entrata") ? TipoTransazione::Entrata : TipoTransazione::Uscita;

    return Transazione(data, importo, tipo, descrizione);
}

double Transazione::getImporto() const {
    return importo;
}

TipoTransazione Transazione::getTipo() const {
    return tipo;
}