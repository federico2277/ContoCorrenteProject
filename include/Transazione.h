//
// Created by feder on 07/07/2025.
//

#ifndef CONTOCORRENTEPROJECT_TRANSAZIONE_H
#define CONTOCORRENTEPROJECT_TRANSAZIONE_H

#include <string>              // Serve per usare il tipo std::string

// Enum per distinguere tra una transazione in entrata o in uscita
enum class TipoTransazione { Entrata, Uscita };

// Classe che rappresenta una singola transazione
class Transazione {
private:
    std::string data;          // Data della transazione (es. "2025-07-07")
    double importo;            // Valore della transazione
    TipoTransazione tipo;      // Tipo: entrata o uscita
    std::string descrizione;   // Descrizione (es. "stipendio", "spesa alimentare")

public:
    // Costruttore
    Transazione(std::string data, double importo, TipoTransazione tipo, std::string descrizione);

    // Restituisce la transazione in formato stringa per salvataggio su file
    std::string toString() const;

    // Crea una transazione a partire da una stringa letta da file
    static Transazione fromString(const std::string& riga);

    // Restituisce l'importo
    double getImporto() const;

    // Restituisce il tipo (entrata/uscita)
    TipoTransazione getTipo() const;
};

#endif  // Fine protezione inclusione
