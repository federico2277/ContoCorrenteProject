#include <gtest/gtest.h>
#include "Transazione.h"

TEST(TransazioneTest, CreazioneTransazione) {
Transazione t("2025-07-07", 100.0, TipoTransazione::Entrata, "Stipendio");
EXPECT_EQ(t.getImporto(), 100.0);
EXPECT_EQ(t.getTipo(), TipoTransazione::Entrata);
}