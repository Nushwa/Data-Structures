/*
Prepared By Nushwa Javed
Queue using Array
*/
#include <iostream>
#define SIZE 8

using namespace std;

class Queue{
    public:
    int front = -1;
    int back = -1;
    int queue[SIZE];

    int isEmpty(){
        if(front == -1 ){
            return 1 ;
    }
        return 0;
    }

    int isFull(){
        if(back == SIZE-1){
            return 1;
        }
        return 0;
    }

    void enqueue(int value){
        if(isFull() ){
            cout << "Queue Overflow" << endl;

        }
        else
            back++;
            queue[back] = value;
            if(front == -1) front = 0;

            cout << "The value " << queue[back] << " has been added " << endl;
        //if(front == -1)
          //  front = 0;


    }

    void dequeue(){
       int value = 0;
       if(isEmpty() ){
        cout << "Queue Underflow" <<endl;
       }
       else
        value = queue[front];
        cout << "The value " <<  value << " has been deleted " << endl;


    }

    void peek(){
        cout << "Queue's peek: " << front << endl;
    }
};

int main(){
    Queue q1;
    q1.enqueue(30);
    q1.enqueue(26);
    q1.enqueue(10);
    q1.dequeue();
    //cout << q1.dequeue() << endl; //d1
    q1.enqueue(20);
     q1.dequeue();//cout << q1.dequeue() <<endl; //d1
    q1.enqueue(80);
     q1.dequeue();// cout << q1.dequeue() <<endl; //d1
    q1.enqueue(29);

return 0;
}
