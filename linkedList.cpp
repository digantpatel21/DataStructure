/**
*   This is linked List header file 
*   Author: Digant Patel
*/
#include "linkedList.h"

void singlyLinkedList::insert(int data, int pos ) {
    singly *temp= head;
    singly *newNode = createSLLNode(data);
    int count = 1;

    // Insert at HEAD
    if(pos == HEAD_POS) {
        newNode->next = head;
        head = newNode;
    }
    else {

        while(temp->next != NULL && count < pos)
        {
            temp = temp->next;
            count++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void singlyLinkedList::deleteNode(int pos) {
    singly *current = head;

    if(pos == HEAD_POS) {
        head = head->next;
        current->next = NULL;

        delete(current);    
    } else {
        singly * previous = head;
        current = current->next;
        int count = 1;

        while(count < (pos-1) ) {
            current = current->next;
            previous = previous->next;
            count++;
        }

        previous->next = current->next;
        current->next = NULL;
        delete(current);
    }
}

void singlyLinkedList::display() {
    singly * temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" --> ";
        temp = temp->next;
    }
    cout<<endl;
}

