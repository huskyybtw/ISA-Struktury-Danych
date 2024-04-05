#include <iostream>
#include "List.h"
#include "DoublyList.h"
#include "tests.h"
#include "ArrayList.h"

int main() {

    ArrayList<int> lista;
    lista.addFront(1);
    lista.addEnd(2);
    lista.addEnd(55);
    lista.addFront(43);
    lista.addFront(33);
    lista.addFront(877);
  //  lista.removeEnd();
  //  lista.removeFront();
  //  lista.removeRandom();
  lista.addRandom(66);
    lista.printList();
 return 0;
}

