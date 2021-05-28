/*
Prepared By Nushwa Javed
Stack using Array
*/

#include <iostream>
using namespace std;
#define MAX_SIZE 10

int top = -1;
int stack[MAX_SIZE] = {0};


int isFull()
{
    if(top == MAX_SIZE)
       return 1;
   else
      return 0;

}

int isEmpty(){
    if(top == -1)
         return 1;
   else
      return 0;

}

int push(int data){

    if(!isFull() ){

    top++;
    stack[top] = data;
    cout << "The element " << data << " is pushed in stack."<<endl;
    }else{
        cout << "The stack is full";
    }
}

int pop(){
    int num;

    if(!isEmpty() ){
        num = stack[top];
        top--;
        cout << "The element " << num << " is popped"<<endl ;
    }else{
        cout << "The stack is empty";
    }
}

void peep(){
    if (top >= 0)
    {
        cout << "The value on top of the stack is " << stack[top]<< endl;
    }
    else
    {
        cout << "The value on top of the stack is " << top;
    }
}

int main(){

    int choice, num;
    do{
    cout << "\nChoose the option: "<<endl;
    cout << "\n1-Push\n2-Pop\n3-Peep\n0-END"<<endl;
    cin >> choice;

    switch(choice){
case 1:
    cout << "Enter the number: "<<endl;
    cin >> num;
    push(num);
    break;

case 2:
    pop();
    break;

case 3:
    peep();
    break;

default:
    cout << "Wrong choice"<<endl;
    break;
    }

    }
    while(choice != 0);

    return 0;
}
