#include "ContoCorrente.h"   // Includiamo il file header
#include <fstream>           // Per lettura/scrittura da file

// Aggiunge una transazione alla lista
void ContoCorrente::aggiungiTransazione(const Transazione& t) {
    transazioni.push_back(t);  // Inserisce la transazione alla fine del vettore
}

// Calcola il saldo sommando entrate e sottraendo le uscite
double ContoCorrente::calcolaSaldo() const {
    double saldo = 0.0;
    for (const auto& t : transazioni) {   // Scorre tutte le transazioni
        // Se entrata aggiunge, se uscita sottrae
        saldo += (t.getTipo() == TipoTransazione::Entrata) ? t.getImporto() : -t.getImporto();
    }
    return saldo;  // Ritorna il totale
}

// Scrive tutte le transazioni su un file (una per riga)
void ContoCorrente::salvaSuFile(const std::string& filename) const {
    std::ofstream file(filename);  // Apre il file in scrittura
    for (const auto& t : transazioni) {
        file << t.toString() << "\n";  // Scrive la stringa della transazione
    }
}

// Legge le transazioni da un file
void ContoCorrente::leggiDaFile(const std::string& filename) {
    std::ifstream file(filename);     // Apre il file in lettura
    std::string riga;
    while (std::getline(file, riga)) {   // Legge ogni riga
        transazioni.push_back(Transazione::fromString(riga));  // Aggiunge la transazione
    }
}
