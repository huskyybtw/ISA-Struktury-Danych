#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>

#include "List.h"
#include "DoublyList.h"
#include "TailList.h"



// TESTUJE PODSTAWOWE OPERACJE NA LISCIE DWUKIERUNKOWEJ Z LOSOWO GENEROWANYMI WARTOSCIAMI
void randomTest(int operation,int times,DoublyList<int>& list){
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    switch(operation) {
        case 0: // addFront
            std::srand(std::time(nullptr));
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                int random = std::rand() % 100;
                random = random + i; // BUG GENEROWALO CALY CZAS TE SAME LICZBY NIE WIEM CZEMU
                list.addFront(random);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addFront TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;

        case 1: // addEnd
            start = std::chrono::high_resolution_clock::now();
            std::srand(std::time(nullptr));
            for (int i = 0; i < times; i++) {
                int random = std::rand() % 100;
                random = random + i; // BUG GENEROWALO CALY CZAS TE SAME LICZBY NIE WIEM CZEMU
                list.addEnd(random);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addEnd TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;

        case 2: // addRandom
            start = std::chrono::high_resolution_clock::now();
            std::srand(std::time(nullptr));

            for (int i = 0; i < times; i++) {
                int random = std::rand() % 100;
                random = random + i; // BUG GENEROWALO CALY CZAS TE SAME LICZBY NIE WIEM CZEMU
                list.addRandom(random);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addRandom TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;

        case 3: // removeRandom
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                list.removeRandom();
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "removeRandom TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;

        case 4: // removeFront
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                list.removeFront();
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "removeFront TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;

        case 5: //removeEnd
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                list.removeEnd();
            }
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "removeEnd TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;
    }
}

// TESTUJE PODSTAWOWE OPERACJE NA LISCIE Z LOSOWO GENEROWANYMI WARTOSCIAMI
void randomTest(int operation, int times, TailList<int>& list) {
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    switch (operation) {
        case 0: // addFront
            std::srand(std::time(nullptr));
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                int random = std::rand() % 100;
                random = random + i; // BUG GENEROWALO CALY CZAS TE SAME LICZBY NIE WIEM CZEMU
                list.addFront(random);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addFront TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;

        case 1: // addEnd
            start = std::chrono::high_resolution_clock::now();
            std::srand(std::time(nullptr));
            for (int i = 0; i < times; i++) {
                int random = std::rand() % 100;
                random = random + i; // BUG GENEROWALO CALY CZAS TE SAME LICZBY NIE WIEM CZEMU
                list.addEnd(random);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addEnd TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;

        case 2: // addRandom
            start = std::chrono::high_resolution_clock::now();
            std::srand(std::time(nullptr));

            for (int i = 0; i < times; i++) {
                int random = std::rand() % 100;
                random = random + i; // BUG GENEROWALO CALY CZAS TE SAME LICZBY NIE WIEM CZEMU
                list.addRandom(random);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addRandom TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;

        case 3: // removeRandom
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                list.removeRandom();
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "removeRandom TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;

        case 4: // removeFront
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                list.removeFront();
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "removeFront TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;

        case 5: //removeEnd
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                list.removeEnd();
            }
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "removeEnd TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;
    }
}

void readFile (int operation,const std::string& filename,DoublyList<int>& list){
    std::ifstream file(filename);

    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    if(!file.is_open()){
        std::cout << "Error with a file" << std::endl;
        return;
    }

    std::string line;
    std::vector<int> numbers;

    while (std::getline(file,line)){
        try {
            numbers.push_back(std::stoi(line));
        }
        catch (const std::exception& e){
            std::cerr << "Error" << e.what() << std::endl;
        }
    }

    switch (operation) {
        case 0:
            start = std::chrono::high_resolution_clock::now();

            for (int num : numbers) {
                list.addFront(num);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addFront TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;
        case 1:
            start = std::chrono::high_resolution_clock::now();

            for (int num : numbers) {
                list.addEnd(num);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addEnd TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;
        case 2:
            start = std::chrono::high_resolution_clock::now();

            for (int num : numbers) {
                list.addRandom(num);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addRandom TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;
    }

    file.close();
    return;
}

void readFile (int operation, const std::string& filename, TailList<int>& list){
    std::ifstream file(filename);

    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    if(!file.is_open()){
        std::cout << "Error with a file" << std::endl;
        return;
    }

    std::string line;
    std::vector<int> numbers;

    while (std::getline(file,line)){
        try {
            numbers.push_back(std::stoi(line));
        }
        catch (const std::exception& e){
            std::cerr << "Error" << e.what() << std::endl;
        }
    }

    switch (operation) {
        case 0:
            start = std::chrono::high_resolution_clock::now();

            for (int num : numbers) {
                list.addFront(num);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addFront TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;
        case 1:
            start = std::chrono::high_resolution_clock::now();

            for (int num : numbers) {
                list.addEnd(num);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addEnd TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;
        case 2:
            start = std::chrono::high_resolution_clock::now();

            for (int num : numbers) {
                list.addRandom(num);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addRandom TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;
    }

    file.close();
    return;
}
