#include "ContoCorrente.h"
#include "Transazione.h"
#include <iostream>

int main() {
    ContoCorrente conto;
    std::string filepath = "data/transazioni.txt";

    // 1. Carica le transazioni precedenti da file (se esiste)
    conto.leggiDaFile(filepath);
    std::cout << "Transazioni caricate dal file.\n";

    // 2. Ciclo per aggiungere transazioni da input utente
    while (true) {
        std::string data, descrizione, tipoInput;
        double importo;

        std::cout << "\nInserisci una nuova transazione\n";
        std::cout << "Data (es: 2025-07-07): ";
        std::getline(std::cin, data);

        std::cout << "Importo: ";
        std::cin >> importo;
        std::cin.ignore(); // Per pulire il newline

        std::cout << "Tipo (entrata/uscita): ";
        std::getline(std::cin, tipoInput);

        std::cout << "Descrizione: ";
        std::getline(std::cin, descrizione);

        // Converti il tipo
        TipoTransazione tipo;
        if (tipoInput == "entrata")
            tipo = TipoTransazione::Entrata;
        else if (tipoInput == "uscita")
            tipo = TipoTransazione::Uscita;
        else {
            std::cout << "Tipo non valido. Transazione ignorata.\n";
            continue;
        }

        // Aggiungi la transazione al conto
        conto.aggiungiTransazione(Transazione(data, importo, tipo, descrizione));
        std::cout << "Transazione aggiunta.\n";

        // Chiedi se continuare
        std::string risposta;
        std::cout << "Vuoi aggiungere un'altra transazione? (s/n): ";
        std::getline(std::cin, risposta);
        if (risposta != "s") break;
    }

    // 3. Salva tutte le transazioni su file
    conto.salvaSuFile(filepath);
    std::cout << "\nTransazioni salvate su file.\n";

    // 4. Mostra il saldo aggiornato
    std::cout << "Saldo totale: " << conto.calcolaSaldo() << " euro\n";

    return 0;
}
