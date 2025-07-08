//
// Created by feder on 07/07/2025.
//

#ifndef CONTOCORRENTEPROJECT_CONTOCORRENTE_H
#define CONTOCORRENTEPROJECT_CONTOCORRENTE_H

#include "Transazione.h"   // Per usare la classe Transazione
#include <vector>          // Per gestire un elenco dinamico di transazioni
#include <string>

// Classe che rappresenta un conto con un elenco di transazioni
class ContoCorrente {
private:
    std::vector<Transazione> transazioni;  // Lista delle transazioni registrate

public:
    // Aggiunge una transazione all'elenco
    void aggiungiTransazione(const Transazione& t);

    // Calcola il saldo totale tenendo conto di entrate e uscite
    double calcolaSaldo() const;

    // Salva le transazioni su un file
    void salvaSuFile(const std::string& filename) const;

    // Carica transazioni da un file
    void leggiDaFile(const std::string& filename);
};

#endif
