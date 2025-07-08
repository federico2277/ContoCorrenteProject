#include "ContoCorrente.h"     // Includiamo la nostra libreria
#include "Transazione.h"
#include <iostream>            // Per usare std::cout

int main() {
    ContoCorrente conto;

    conto.leggiDaFile("data/transazioni.txt");

    conto.aggiungiTransazione(Transazione("2025-07-07", 500.0, TipoTransazione::Entrata, "Stipendio"));
    conto.aggiungiTransazione(Transazione("2025-07-08", 100.0, TipoTransazione::Uscita, "Spesa"));

    conto.salvaSuFile("data/transazioni.txt");

    std::cout << "Saldo attuale: " << conto.calcolaSaldo() << " euro\n";

    return 0;
}