#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <random>
#include "ArrayList.h"
#include "List.h"
#include "DoublyList.h"
#include "TailList.h"
#include "ArrayList.h"

// FUNCKJE MAJA IDENTYCZNE DEFINICJE ROZNIA SIE TYLKO ARGUMENTAMI


// TESTUJE PODSTAWOWE OPERACJE NA LISCIE DWUKIERUNKOWEJ Z LOSOWO GENEROWANYMI WARTOSCIAMI
void randomTest(int operation,int times,ArrayList<int>& list){
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    switch(operation) {
        case 0: // addFront
            std::srand(std::time(nullptr));
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                int random = std::rand() % list.getSize();
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
                int random = std::rand() % list.getSize();
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
                int random = std::rand() % list.getSize();
                list.addRandom(random,random);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addRandom TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;

        case 3: // removeRandom
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                int random = std::rand() % list.getSize();
                list.removeRandom(random);
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
void randomTest(int operation, int times,DoublyList<int>& list) {
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    switch(operation) {
        case 0: // addFront
            std::srand(std::time(nullptr));
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                int random = std::rand() % list.getSize();
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
                int random = std::rand() % list.getSize();
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
                int random = std::rand() % list.getSize();
                list.addRandom(random,random);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addRandom TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;

        case 3: // removeRandom
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                int random = std::rand() % list.getSize();
                list.removeRandom(random);
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
void randomTest(int operation, int times,List<int>& list) {
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    switch(operation) {
        case 0: // addFront
            std::srand(std::time(nullptr));
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                int random = std::rand() % list.getSize();
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
                int random = std::rand() % list.getSize();
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
                int random = std::rand() % list.getSize();
                list.addRandom(random,random);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addRandom TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;

        case 3: // removeRandom
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                int random = std::rand() % list.getSize();
                list.removeRandom(random);
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
void randomTest(int operation, int times,TailList<int>& list) {
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    switch(operation) {
        case 0: // addFront
            std::srand(std::time(nullptr));
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                int random = std::rand() % list.getSize();
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
                int random = std::rand() % list.getSize();
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
                int random = std::rand() % list.getSize();
                list.addRandom(random,random);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addRandom TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;

        case 3: // removeRandom
            start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < times; i++) {
                int random = std::rand() % list.getSize();
                list.removeRandom(random);
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
void addFromFile (int operation, const std::string& filename,ArrayList<int>& list){
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
                std::srand(std::time(nullptr));
                int random = std::rand() % list.getSize();
                list.addRandom(num,random);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addRandom TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;
    }

    file.close();
    return;
}
void addFromFile (int operation, const std::string& filename,List<int>& list){
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
                std::srand(std::time(nullptr));
                int random = std::rand() % list.getSize();
                list.addRandom(num,random);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addRandom TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;
    }

    file.close();
    return;
}

void addFromFile (int operation,const std::string& filename,DoublyList<int>& list){
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
                std::srand(std::time(nullptr));
                int random = std::rand() % list.getSize();
                list.addRandom(num,random);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addRandom TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;
    }

    file.close();
    return;
}

void addFromFile (int operation, const std::string& filename,TailList<int>& list){
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
                std::srand(std::time(nullptr));
                int random = std::rand() % list.getSize();
                list.addRandom(num,random);
            }

            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "addRandom TEST Execution time: " << duration.count() << " seconds" << std::endl;
            break;
    }

    file.close();
    return;
}

std::vector<int> Generator(int seed,int amount){
        std::vector<int> numbers;
        std::mt19937 rng(seed);

        for (int i = 0; i < amount; ++i) {
            numbers.push_back(rng());
        }

        return numbers;
}

double generatorTest(int operation,int* seeds,int seedsSize,int amount,ArrayList<int>& list){
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double data[seedsSize];

    for (int i=0  ; i<seedsSize ; i++ ){
        if(list.getSize() != 0){
            throw std::logic_error("Lista nie zostala poprawnie wyczyszczona");
        }
        std::vector<int> temp = Generator(seeds[i], amount);

        for (int num: temp) {
            list.addFront(num);
        }

        start = std::chrono::high_resolution_clock::now();
        switch (operation){
            case 0:
                list.addFront(seeds[i]);
                break;
            case 1:
                list.addEnd(seeds[i]);
                break;
            case 2:
                list.addRandom(seeds[i],seeds[i]);
                break;
            case 3:
                list.removeRandom(seeds[i]);
                break;
            case 4:
                list.removeFront();
                break;
            case 5:
                list.removeEnd();
                break;
        }
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << duration.count() << std::endl;
        data[i] = duration.count();

        while(list.getSize() != 0){
            list.removeFront();
        }
    }

    double answer = 0;
    for (int i= 0 ; i<seedsSize ;i++){
        answer += data[i];
    }
    answer = answer / seedsSize;

    return answer;
}

double generatorTest(int operation,int* seeds,int seedsSize,int amount,TailList<int>& list){
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double data[seedsSize];

    for (int i=0  ; i<seedsSize ; i++ ){
        if(list.getSize() != 0){
            throw std::logic_error("Lista nie zostala poprawnie wyczyszczona");
        }
        std::vector<int> temp = Generator(seeds[i], amount);

        for (int num: temp) {
            list.addFront(num);
        }

        start = std::chrono::high_resolution_clock::now();
            switch (operation){
                case 0:
                    list.addFront(seeds[i]);
                    break;
                case 1:
                    list.addEnd(seeds[i]);
                    break;
                case 2:
                    list.addRandom(seeds[i],seeds[i]);
                    break;
                case 3:
                    list.removeRandom(seeds[i]);
                    break;
                case 4:
                    list.removeFront();
                    break;
                case 5:
                    list.removeEnd();
                    break;
            }
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << duration.count() << std::endl;
        data[i] = duration.count();

        while(list.getSize() != 0){
            list.removeFront();
        }
    }

    double answer = 0;
    for (int i= 0 ; i<seedsSize ;i++){
        answer += data[i];
    }
    answer = answer / seedsSize;
    return answer;
}

double generatorTest(int operation,int* seeds,int seedsSize,int amount,DoublyList<int>& list){
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double data[seedsSize];

    for (int i=0  ; i<seedsSize ; i++ ){
        if(list.getSize() != 0){
            throw std::logic_error("Lista nie zostala poprawnie wyczyszczona");
        }
        std::vector<int> temp = Generator(seeds[i], amount);

        for (int num: temp) {
            list.addFront(num);
        }

        start = std::chrono::high_resolution_clock::now();
            switch (operation){
                case 0:
                    list.addFront(seeds[i]);
                    break;
                case 1:
                    list.addEnd(seeds[i]);
                    break;
                case 2:
                    list.addRandom(seeds[i],seeds[i]);
                    break;
                case 3:
                    list.removeRandom(seeds[i]);
                    break;
                case 4:
                    list.removeFront();
                    break;
                case 5:
                    list.removeEnd();
                    break;
            }
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << duration.count() << std::endl;
        data[i] = duration.count();

        while(list.getSize() != 0){
            list.removeFront();
        }
    }

    double answer = 0;
    for (int i= 0 ; i<seedsSize ;i++){
        answer += data[i];
    }
    answer = answer / seedsSize;
    return answer;
}

double generatorTest(int operation,int* seeds,int seedsSize,int amount,List<int>& list){
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double data[seedsSize];

    for (int i=0  ; i<seedsSize ; i++ ){
        if(list.getSize() != 0){
            throw std::logic_error("Lista nie zostala poprawnie wyczyszczona");
        }
        std::vector<int> temp = Generator(seeds[i], amount);

        for (int num: temp) {
            list.addFront(num);
        }

        start = std::chrono::high_resolution_clock::now();
            switch (operation){
                case 0:
                    list.addFront(seeds[i]);
                    break;
                case 1:
                    list.addEnd(seeds[i]);
                    break;
                case 2:
                    list.addRandom(seeds[i],seeds[i]);
                    break;
                case 3:
                    list.removeRandom(seeds[i]);
                    break;
                case 4:
                    list.removeFront();
                    break;
                case 5:
                    list.removeEnd();
                    break;
            }
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << duration.count() << std::endl;
        data[i] = duration.count();

        while(list.getSize() != 0){
            list.removeFront();
        }
    }

    double answer = 0;
    for (int i= 0 ; i<seedsSize ;i++){
        answer += data[i];
    }
    answer = answer / seedsSize;
    return answer;
}

