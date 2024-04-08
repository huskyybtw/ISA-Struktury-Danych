#include <iostream>
#include "List.h"
#include "DoublyList.h"
#include "tests.h"
#include "ArrayList.h"


int main() {
    // ArrayList<int> lista;

    std::string test0 = "C:/Users/bart2/CLionProjects/ISA-Struktury-Danych/data10";
    std::string test1 = "C:/Users/bart2/CLionProjects/ISA-Struktury-Danych/data20";
    std::string test2 = "C:/Users/bart2/CLionProjects/ISA-Struktury-Danych/data30";
    std::string test3 = "C:/Users/bart2/CLionProjects/ISA-Struktury-Danych/data40";
    std::string test4 = "C:/Users/bart2/CLionProjects/ISA-Struktury-Danych/data50";
    std::string test5 = "C:/Users/bart2/CLionProjects/ISA-Struktury-Danych/data60";
    std::string test6 = "C:/Users/bart2/CLionProjects/ISA-Struktury-Danych/data70";
    std::string test7 = "C:/Users/bart2/CLionProjects/ISA-Struktury-Danych/data80";
    std::string test8 = "C:/Users/bart2/CLionProjects/ISA-Struktury-Danych/data90";
    std::string test9 = "C:/Users/bart2/CLionProjects/ISA-Struktury-Danych/data100";
    List<int>* lista = new List<int>();
    //randomTest(0,70000,*lista);
    addFromFile(2,test6,*lista);
    randomTest(3,70000,*lista);
    delete lista;
    //lista->printList();
    // lista->printRandom();
    return 0;
}

