#include <iostream>
#include "List.h"
#include "DoublyList.h"
#include "tests.h"
#include "ArrayList.h"

int main() {

   // ArrayList<int> lista;

    ArrayList<int>* lista = new ArrayList<int>();
    randomTest(1,100,*lista);
    randomTest(1,100,*lista);
    randomTest(2,100,*lista);
    randomTest(2,100,*lista);
    randomTest(2,100,*lista);
   // randomTest(0,100,*lista);
  //  randomTest(1,100,*lista);
  //  randomTest(2,100,*lista);
    //randomTest(2,100,*lista);
    randomTest(3,100,*lista);
    randomTest(4,100,*lista);
    randomTest(5,100,*lista);

  //  lista.removeEnd();
  //  lista.removeFront();
  //  lista.removeRandom();

    lista->printList();
 return 0;
}

