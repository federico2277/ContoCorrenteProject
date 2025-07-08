cmake_minimum_required(VERSION 3.22)
project(ContoCorrenteProject)

set(CMAKE_CXX_STANDARD 17)

# Includi header
include_directories(include)

# ========== ESEGUIBILE PRINCIPALE ==========
add_executable(ContoCorrenteApp
        main.cpp
        src/ContoCorrente.cpp
        src/Transazione.cpp
)

# ========== GOOGLE TEST SETUP ==========

# Aggiunge GoogleTest dal sotto-progetto
add_subdirectory(external/googletest)

# Rendi disponibili gli header di gtest e gmock
include_directories(external/googletest/googletest/include)
include_directories(external/googletest/googlemock/include)

# Abilita testing
enable_testing()

# ========== ESEGUIBILI DI TEST ==========

# TestTransazione
add_executable(TestTransazione
        test/TestTransazione.cpp
        src/Transazione.cpp
        src/ContoCorrente.cpp
)
target_link_libraries(TestTransazione gtest gtest_main)

# TestConto
add_executable(TestConto
        test/TestConto.cpp
        src/Transazione.cpp
        src/ContoCorrente.cpp
)
target_link_libraries(TestConto gtest gtest_main)

# Auto-discovery dei test
include(GoogleTest)
gtest_discover_tests(TestTransazione)
gtest_discover_tests(TestConto)
