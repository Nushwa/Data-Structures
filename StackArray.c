#include<stdio.h>
#include<conio.h>
#define MAX_SIZE 8

int push(int num);
void pop();
int isFull();
int isEmpty();
int show();

int stack[MAX_SIZE];
int top = -1;

int main(){
    int choice,data;

    do{
    printf("\n-----MENU-------");
    printf("\n1-Push\n2-Pop\n3-Show\n0 to end\n");
    scanf("%d", &choice);
    switch(choice){

case 1:
    printf("Enter the data: ");
    scanf("%d", &data);
    push(data);
    break;

case 2:
    pop();
    break;

case 3:
    show();
    break;

default:
    printf("Wrong choice");
    break;
    }

}
    while(choice != 0);


   return 0;
}

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

int push(int num){

    if(!isFull() ){
        top = top + 1;
        stack[top] = num;
        printf("Element %d added to the stack", num);

    }else {
            printf("The stack can't be pushed");
    }
}

void pop(){
    int num;

    if(!isEmpty() ){

        num = stack[top];
        top = top - 1;
        printf("\nElement %d popped", num);
    }
    else{
        printf("The stack is empty\n");
    }
}

int show(){
    printf("The value on top of stack is: %d", stack[top]);

}
