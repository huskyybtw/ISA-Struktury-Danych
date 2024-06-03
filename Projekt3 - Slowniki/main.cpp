#include <iostream>
#include "HashTable_Bucket.h"
#include "HashTable.h"
#include "HashTable_Cuckoo.h"
#include "HashTable_Open.h"
#include <random>

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
int main () {
    int seedsSize = sizeof(seeds) / sizeof(seeds[0]);

    HashTable_Open table;

    table.insert(-1, 100);
    table.insert(2, 400);
    table.insert(3, 500);
    table.insert(4, 600);
    table.insert(13, 50100);
    table.insert(15, 50040);
    table.insert(3461, 50300);
    table.insert(31, 50200);
    table.insert(51, 50003);
    table.insert(856, 50400);
    table.insert(61, 50030);
    table.insert(151, 5060);
    table.insert(141, 5060);
    table.insert(121, 54000);
    table.insert(171, 50400);

    table.remove(171);
    table.remove(3);

    table.print();




    return 0;
}