
#include <string>
#include <vector>
#include <iostream>
#include "ArrayPQueue.h"
#include "PQheap.h"
#include "test.h"

// plik .exe nie w folderze razem z plikami
std::string basePath = "..\\data";

int seeds[50] = {
        18860,
        26252,
        45347,
        55589,
        57082,
        60773,
        65138,
        73396,
        87991,
        90312,
        93356,
        94394,
        104853,
        110012,
        119089,
        127799,
        131538,
        148148,
        160802,
        161908,
        170168,
        182750,
        194588,
        200202,
        201862,
        203437,
        205453,
        210771,
        218650,
        220821,
        221303,
        232474,
        248815,
        254938,
        266165,
        281231,
        291060,
        298441,
        305660,
        306538,
        310570,
        316167,
        320036,
        330340,
        332417,
        332900,
        337522,
        339220,
        340315,
        343179,
};
int main() {
    generatorTestHeap(0,seeds,3,100000);
    return 0;
}
