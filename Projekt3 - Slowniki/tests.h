#ifndef ISA_STRUKTURY_DANYCH_TESTS_H
#define ISA_STRUKTURY_DANYCH_TESTS_H
#include <vector>

std::vector<int> Generator(int seed,int amount);

double test_Bucket(int operation,int* seeds,int seedsSize,int amount,int times);
double test_Cuckoo(int operation,int* seeds,int seedsSize,int amount,int times);
double test_Open(int operation,int* seeds,int seedsSize,int amount,int times);

#endif //ISA_STRUKTURY_DANYCH_TESTS_H
