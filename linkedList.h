/**
*   This is linked List header file 
*   Author: Digant Patel
*/
#include <iostream>

#define HEAD_POS 1
#define LAST_POS INT_MAX

using namespace std;
typedef struct singly{
    public:
        int data;
        singly* next;
    public:
        singly(int data): data(data), next(NULL) { }
}SLL, *pSLL;

class singlyLinkedList {
    private:
        SLL *head;
    public:
        singlyLinkedList (): head(0) { }

        void insert(int data, int pos = HEAD_POS);

        void deleteNode(int pos = HEAD_POS);
        // Generate SLL node
        pSLL createSLLNode(int data) {
            return new singly(data);
        }

        void display();
};

