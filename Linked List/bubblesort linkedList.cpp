#include<iostream>

using namespace std;

class node {
  public:

    int data;
  node * next;
}* head, * temp, * newnode;
int count;

class sort {
  public:

    void bubblesort() {

      node * node1, * node2;

      node1 = head;
      while (node1 != 0) {

        node2 = node1;
        while (node2 != 0) {

          if (node1 -> data > node2 -> data) {

            int ctemp = node1 -> data;
            node1 -> data = node2 -> data;
            node2 -> data = ctemp;
          }

          if (node2 -> next == NULL) {
            break;
          }
          node2 = node2 -> next;
        }
        if (node1 -> next == NULL) {
          return;
        }
        node1 = node1 -> next;
      }
    }
};

class createList {
  public:
    void create() {

      newnode = new node;
      cout << "Enter data: ";
      cin >> newnode -> data;
      newnode -> next = 0;
      if (head == 0) {
        head = newnode;
        temp = newnode;
      }
      else
        {
        temp -> next = newnode;
        temp = newnode;
      }

    }

  void display() {
    temp = head;
    while (temp != 0) {
      cout << temp -> data << " ";
      temp = temp -> next;
      count++;
    }
    cout << endl;
  }
};

int main() {
  createList cre;
  sort sr;
  cre.create();
  cre.create();
  cre.create();
  cre.create();

  cout << "Before sorting" << endl;
  cre.display();
  sr.bubblesort();
  cout << "After sorting" << endl;
  cre.display();

}
