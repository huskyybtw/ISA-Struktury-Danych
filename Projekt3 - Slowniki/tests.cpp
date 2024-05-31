#include "tests.h"
#include "HashTable_Bucket.h"
#include "HashTable_Cuckoo.h"
#include "HashTable_Open.h"
#include <chrono>
#include <vector>
#include <random>
#include <iostream>

std::vector<int> Generator(int seed,int amount){
    std::vector<int> numbers;
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distrib(INT_MIN+1,INT_MAX);

    for (int i = 0; i < amount; ++i) {
        int randPrio = distrib(gen);
        numbers.push_back(randPrio);
    }
}

double test_Bucket(int operation,int* seeds,int seedsSize,int amount,int times){
    double result = 0;
    for(int i=0 ; i < seedsSize ; i++) {
        std::vector<int> numbers = Generator(seeds[i], amount);
        double avg = 0;
        for(int j=0 ; j<times ; j++) {
            HashTable_Bucket *virt = new HashTable_Bucket();

            for (int it: numbers) {
                virt->insert(it,it);
            }

            auto start = std::chrono::high_resolution_clock::now();
            switch (operation) {
                case 0:
                    virt->insert(1, 1);
                    break;
                case 1:
                    virt->remove(1);
                    break;
            }

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            avg += duration.count();
            std::cout << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << duration.count() << std::endl;
            delete virt;
        }
        avg = avg/times;
        result += avg;

        std::cout << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << avg << std::endl;
    }
    return result / seedsSize;
}

double test_Cuckoo(int operation,int* seeds,int seedsSize,int amount,int times){
    double result = 0;
    for(int i=0 ; i < seedsSize ; i++) {
        std::vector<int> numbers = Generator(seeds[i], amount);
        double avg = 0;
        for(int j=0 ; j<times ; j++) {
            HashTable_Cuckoo *virt = new HashTable_Cuckoo();

            for (int it: numbers) {
                virt->insert(it,it);
            }

            auto start = std::chrono::high_resolution_clock::now();
            switch (operation) {
                case 0:
                    virt->insert(1, 1);
                    break;
                case 1:
                    virt->remove(1);
                    break;
            }

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            avg += duration.count();
            std::cout << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << duration.count() << std::endl;
            delete virt;
        }
        avg = avg/times;
        result += avg;

        std::cout << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << avg << std::endl;
        avg = 0;
    }
    return result / seedsSize;
}

double test_Open(int operation,int* seeds,int seedsSize,int amount,int times){
    double result = 0;
    for(int i=0 ; i < seedsSize ; i++) {
        std::vector<int> numbers = Generator(seeds[i], amount);
        double avg = 0;
        for(int j=0 ; j<times ; j++) {
            HashTable_Open *virt = new HashTable_Open();

            for (int it: numbers) {
                virt->insert(it,it);
            }

            auto start = std::chrono::high_resolution_clock::now();
            switch (operation) {
                case 0:
                    virt->insert(1, 1);
                    break;
                case 1:
                    virt->remove(1);
                    break;
            }

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            avg += duration.count();
            std::cout << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << duration.count() << std::endl;
            delete virt;
        }
        avg = avg/times;
        result += avg;

        std::cout << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << avg << std::endl;
        avg = 0;
    }
    return result / seedsSize;
}
