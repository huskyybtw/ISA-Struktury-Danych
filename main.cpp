#include <iostream>
#include "List.h"
#include "DoublyList.h"
#include "tests.h"
#include "ArrayList.h"

int main() {

   // ArrayList<int> lista;

    ArrayList<int>* lista = new ArrayList<int>();
    randomTest(0,10,*lista);



    lista.printList();
   // lista->printRandom();

 return 0;
}

