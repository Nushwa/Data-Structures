#include<iostream>

using namespace std;

class MinHeap
{
public:
    int heap[10];

    MinHeap()
    {
        for(int i = 0; i < 10; i++)
            heap[i] = 4; //Dummy value
    }
    void InsertH(int data)
    {
        if(heap[0] == 4)
        {
            heap[0] = data;
            return;
        }
        else
        {
            int i=0, left, right;
            while(i < 10)
            {
                left = (i*2);
                right = (i*2)+1;
                if(heap[left] == 4)
                {
                    heap[left] = data;
                    swaph(left);
                    return;
                }
                if(heap[right] == 4)
                {
                    heap[right] = data;
                    swaph(right);
                    return;
                }
                i++;
            }
            cout << "Heap is Full" << endl;
        }

    }
    void swaph(int index)
    {
        while(index > 0)
        {
            int par = (index-1)/2;

            if(heap[par] > heap[index])
            {
                int temp = heap[par];
                heap[par] = heap[index];
                heap[index] = temp;
                 cout << heap[index] << " and " << heap[par] << " Swapped." << endl;
            }
            index = par;
        }
        return;
    }

    void Deleteh()
    {
        if(heap[0] == 4)
        {
            cout << "Heap is Empty" << endl;
            return;
        }
        int i = 0;
        while(heap[i] != 4)
        {
            i++;
        }
        heap[0] = heap[i-1];
        heap[i-1] = 4;
        DeleteSwap();
    }

    void DeleteSwap()
    {
        int i =0, left, right;
        while(true)
        {
            left = (i*2);
            right = (i*2)+1;
            if(heap[i] <= heap[left] && heap[i] >= heap[right])
                return;

            if(heap[left] < heap[i])
            {
                int temp = heap[i];
                heap[i] = heap[left];
                heap[left] = temp;
            }
            if(heap[right] < heap[i])
            {
                int temp = heap[i];
                heap[i] = heap[right];
                heap[right] = temp;
            }
            i++;
        }
    }

    void display()
    {
        for(int i = 0; i < 10; i++)
        {
            if(heap[i] != 4)
                cout << heap[i] << " ";
        }
        cout << endl;
    }

};

int main()
{

    int choice;
    MinHeap mheap;
    do
    {
        cout << "\n1- Insert\n2-Delete\n3-Display\n0-Exit\n";
        cin >> choice;
        switch(choice)
        {
        case 1:
            int data;
            cout << "Enter data: ";
            cin >> data;
            mheap.InsertH(data);
            break;
        case 2:
            mheap.Deleteh();
            break;
        case 3:
            mheap.display();
            break;
        }
    } while(choice != 0);

    return 0;
}
