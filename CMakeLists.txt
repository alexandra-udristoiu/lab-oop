cmake_minimum_required(VERSION 3.17)
project(poo_tema)

set(CMAKE_CXX_STANDARD 14)

add_executable(poo_tema cmake-build-debug/main.cpp cmake-build-debug/Banca.cpp cmake-build-debug/Banca.h cmake-build-debug/Client.cpp cmake-build-debug/Client.h cmake-build-debug/ContCurent.cpp cmake-build-debug/ContCurent.h cmake-build-debug/Depozit.cpp cmake-build-debug/Depozit.h cmake-build-debug/DepozitNormal.cpp cmake-build-debug/DepozitNormal.h cmake-build-debug/DepozitReinnoire.cpp cmake-build-debug/DepozitReinnoire.h cmake-build-debug/DepozitCapitalizare.cpp cmake-build-debug/DepozitCapitalizare.h cmake-build-debug/Exceptii.cpp cmake-build-debug/Exceptii.h cmake-build-debug/templatef.cpp cmake-build-debug/templatef.h)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")