#include<iostream>

using namespace std;

class maxheap{
private:
    int heap[15] = {0};
public:
    void InsertHeap(int data)
    {
        if(heap[0] == 0)
        {
            heap[0] = data;
            return;
        }
        else
        {
            int i=1;
            int left, right;

            while(i < 15) //array limit
            {
                left = (i*2); //parent
                right = (i*2)+1;
                if(heap[left] == 0)
                {
                    heap[left] = data;
                    swap(left);
                    return;
                }
                if(heap[right] == 0)
                {
                    heap[right] = data;
                    swap(right);
                    return;
                }
                i++;
            }
            cout << "Heap is Full" << endl;
        }
    }

    void swap(int val)
    {
        int par;
        while (val > 0)
        {
            par = (val-1)/2;

            if( heap[par] < heap[val] ) //if parent val is less than val ->swap
            {
                int temp = heap[par]; //swapping
                heap[par] = heap[val];
                heap[val] = temp;
                cout << heap[val] << " and " << heap[par] << " Swapped." << endl;
            }
            val= par;
        }
        return;
    }

    void Delete()
    {
        if(heap[0] == 0)
            cout << "Heap is Empty" << endl;
        int i =0;
        while(heap[i] != 0)
            i++;
        heap[0] = heap[i-1]; //swap last added node with root
        heap[i-1] = 0; //and put 0 at last node
        heaplify();
    }

    void heaplify()
    {
        int left, right, i = 0;
        while (true)
        {
            left = (2 * i);
            right = (2*i) +1;
            if( heap[i] >= heap[left] && heap[i] >= heap[right]  )
                return; //parent is larger than child ->end

            if( heap[left] > heap[i] ) //swap left child
            {
                int temp = heap[i];
                heap[i] = heap[left];
                heap[left] = temp;
            }
            if( heap[right] > heap[i] ) //swap right child
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
        for (int i = 0; i < 15; i++)
        {
            if(heap[i] == 0)
                return;
            else
                cout << heap[i] << " ";
        }
        cout << endl;
    }

    int inorder(int n, int a[])
    {
        if(n==0)
            return true;
        for(int i =0; i < n-1; i++)
        {
            if(a[i] >= a[i+1]) //inorder
                return false;
        }
        return true;
    }

    int heapSort(int *a, int len)
    {
        build_heap(a, len);
        int temp;
        while (len > 1)
        {
            temp = a[0];
            a[0] = a[len-1];
            a[len-1] = temp;
            len--;

            heaplify();
        }
    }

    int build_heap(int *a,int len){
    int i;
    for (i=len-1; i>=0; i--) {
        if(2*i+1>len-1) continue;
        heaplify();
    }
    }
};

int main()
{
    int Arr[6] = {14, 7, 12, 18, 5};
    int choice;
    maxheap maxh;
    /*do
    {
        cout << "\n1- Insert\n2-Delete\n3-Display\n0-Exit\n";
        cin >> choice;
        switch(choice)
        {
        case 1:
            int data;
            cout << "Enter data: ";
            cin >> data;
            maxh.InsertHeap(data);
            break;

        case 2:
            maxh.Delete();
            break;
        case 3:
            maxh.display();
            break;
        }

    } while(choice != 0);
    */
    maxh.display();
    int i;
    for (i=0; i< 6; i++) {
        printf("%d ",Arr[i]);
    }
    printf("\n");

    cout << "Sorting: ";
        maxh.heapSort(Arr, 6);

    for (i=0; i< 6; i++) {
        printf("%d ",Arr[i]);
    }

    return 0;
}
