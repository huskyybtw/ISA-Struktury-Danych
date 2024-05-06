//
// Created by marek on 23.04.2024.
//
#include <iostream>
#include <vector>
#include <random>
#include "chrono"
#include "PQheap.h"
#include "ArrayPQueue.h"

std::vector<Node<int>> Generator(int seed,int amount){
    std::vector<Node<int>> numbers;
    std::mt19937 rng(seed);

    for (int i = 0; i < amount; ++i) {
        int randPrio = rng();
        numbers.push_back({randPrio,i});
    }

    return numbers;
}

bool checkValidHeap(int seed,int amount){
    PQheap<int> queue;
    std::vector<Node<int>> temp;
    int* testArray = new int[amount];
    temp = Generator(seed, amount);

    for (Node<int> num: temp) {
        queue.insert(num.priority,num.elem);
    }

    for(int j=0 ; j<amount ; j++){
        testArray[j] = queue.popWithPrio();
    }

    for(int j=0 ; j<amount-1 ; j++){
        if(testArray[j] < testArray[j+1]){
            std:: cout << "WRONGLY SORTED" << std::endl;
            return false;
        }
    }
    return true;
}

bool checkValidArray(int seed,int amount){
    PriorityQueue<int> queue;
    std::vector<Node<int>> temp;
    int* testArray = new int[amount];
    temp = Generator(seed, amount);

    for (Node<int> num: temp) {
        queue.insert(num.priority,num.elem);
    }

    for(int j=0 ; j<amount ; j++){
        testArray[j] = queue.extractMaxPrio();
    }

    for(int j=0 ; j<amount-1 ; j++){
        if(testArray[j] < testArray[j+1]){
            std:: cout << "WRONGLY SORTED" << std::endl;
            return false;
        }
    }
    return true;
}

double generatorTestHeap(int operation,int* seeds,int seedsSize,int amount){
    double data = 0;
    std::vector<Node<int>> temp;

    for (int i=0  ; i<seedsSize ; i++ ){
        temp = Generator(seeds[i], amount);
        double seedData = 0;

        if(!checkValidHeap(seeds[i],amount)){
            std::cerr << "Wrongly sorted" << std::endl;
        }

        for(int j=0; j<100; j++) {
            PQheap<int> *queue = new PQheap<int>();

            for (Node<int> num: temp) {
                queue->insert(num.priority,num.elem);
            }
            auto start = std::chrono::high_resolution_clock::now();
            switch (operation) {
                case 0:
                    queue->insert(seeds[i],i);
                    break;
                case 1:
                    queue->pop();
                    break;
                case 2:
                    queue->getMax();
                    break;
                case 3:
                    queue->modifyKey(-1, queue->getSize() / 2);
                    queue->modifyKey(temp[queue->getSize() / 2].priority, queue->getSize() / 2);
                    break;
                case 4:
                    queue->modifyKey(seeds[i], queue->getSize() / 2);
                    queue->modifyKey(temp[queue->getSize() / 2].priority, queue->getSize() / 2);
                    break;
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            //std::cout << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << duration.count() << std::endl;
            seedData += duration.count();

            delete queue;
        }
        data = data + ( seedData / 100 );
    }
    return data / seedsSize;
}

double generatorTestArray(int operation,int* seeds,int seedsSize,int amount){
    double data = 0;
    std::vector<Node<int>> temp;

    for (int i=0  ; i<seedsSize ; i++ ){
        temp = Generator(seeds[i], amount);
        double seedData = 0;

        if(!checkValidArray(seeds[i],amount)){
            std::cerr << "Wrongly sorted" << std::endl;
        }

        for(int j=0; j<100; j++) {
            PriorityQueue<int> *queue = new PriorityQueue<int>();

            for (Node<int> num: temp) {
                queue->insert(num.priority,num.elem);
            }
            auto start = std::chrono::high_resolution_clock::now();
            switch (operation) {
                case 0:
                    queue->insert(seeds[i],i);
                    break;
                case 1:
                    queue->extractMax();
                    break;
                case 2:
                    queue->peek();
                    break;
                case 3:
                    queue->modifyKey(-1, queue->getSize() / 2);
                    queue->modifyKey(temp[queue->getSize() / 2].priority, queue->getSize() / 2);
                    break;
                case 4:
                    queue->modifyKey(seeds[i], queue->getSize() / 2);
                    queue->modifyKey(temp[queue->getSize() / 2].priority, queue->getSize() / 2);
                    break;
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            //std::cout << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << duration.count() << std::endl;
            seedData += duration.count();

            delete queue;
        }
        data = data + ( seedData / 100 );
    }
    return data / seedsSize;
}