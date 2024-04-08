#include <iostream>
#include "ArrayList.h"
#include "List.h"
#include "DoublyList.h"
#include "TailList.h"
#include "tests.h"
#include "ui.h"

int main() {
    ArrayList<int>* alist = new ArrayList<int>();
    List<int>* list = new List<int>();
    TailList<int>* tlist = new TailList<int>();
    DoublyList<int>* dlist = new DoublyList<int>();

    App(*alist,*list,*tlist,*dlist);
    return 0;
}

