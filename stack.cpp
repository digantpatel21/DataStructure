#include <iostream>

using namespace std;

#define STACK_SIZE_MAX 	100
#define STACK_PUSH 	1
#define STACK_POP 	2
#define STACK_DISPLAY 	3
#define STACK_CONTENT_INVALID 0xFFFF
typedef struct stack
{
   int data[STACK_SIZE_MAX];
   int top;
};

stack st = {0};
bool isStackFull()
{
   return st.top ==(STACK_SIZE_MAX-1) ? true : false;
}

bool isStackEmpty()
{
   return st.top == -1 ? true : false;
}

void push(int data)
{
   if(!isStackFull())
   	st.data[++st.top] = data;
}

int pop()
{
   if(!isStackEmpty())
	return st.data[st.top--];

   return STACK_CONTENT_INVALID;
}

void display()
{
   cout<< "stack content is : ";
   for(int i = st.top; i > 0; i--)
   	cout << st.data[i]<<"\t";

   cout<<endl;
}

int main()
{
   push(10);
   push(20);
   push(30);
   push(40);
   pop();
   display();
   return 0;
}
