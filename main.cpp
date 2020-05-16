#include <iostream>
#include "linkedList.h"

using namespace std;

int main () {
    singlyLinkedList *sll = new singlyLinkedList();
    sll->insert(1,HEAD_POS);
    sll->insert(2);
    sll->insert(3);
    sll->insert(4);
    sll->deleteNode(2);
    sll->display();
    return 0;
}