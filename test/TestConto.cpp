#include <gtest/gtest.h>
#include "ContoCorrente.h"

// Test per verificare il calcolo corretto del saldo
TEST(ContoCorrenteTest, CalcolaSaldoCorretto) {
    ContoCorrente conto;
    conto.aggiungiTransazione(Transazione("2025-07-07", 200.0, TipoTransazione::Entrata, "Stipendio"));
    conto.aggiungiTransazione(Transazione("2025-07-08", 50.0, TipoTransazione::Uscita, "Spesa"));

    // Il saldo atteso è 200 - 50 = 150
    EXPECT_DOUBLE_EQ(conto.calcolaSaldo(), 150.0);
}
