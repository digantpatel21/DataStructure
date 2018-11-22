#include <iostream>

using namespace std;

#define QUEUE_SIZE_MAX 10
#define QUEUE_INSERT  1
#define QUEUE_DELETE  2
#define QUEUE_DISPLAY 3

struct queue
{
   int data[QUEUE_SIZE_MAX];
   int front;
   int rear;
};

struct queue que;

bool  isQueueFull()
{
   return que.front >= (QUEUE_SIZE_MAX-1) ? true : false;
}

bool isQueueEmpty()
{
   return (que.front == que.rear) || que.front ==-1 ? true: false;
}

void initializeQueue()
{
  que.front = que.rear =-1;
}

void insert(int data)
{
  if(!isQueueFull())
	que.data[++que.front] = data;
}

void deleteQ()
{
   if(!isQueueEmpty())
      que.data[++que.rear] = 0;
}

void display()
{
   cout<<"Queue Data is: ";
   for(int i = (que.rear+1); i <= que.front; i++ )
   {
	cout<<que.data[i]<<"\t";
   }
   cout<<endl;
}

int main()
{
   initializeQueue();
   insert(10);
   insert(20);
   insert(30);
   insert(40);
   deleteQ();
   deleteQ();
   display();
   return 0;
} 
