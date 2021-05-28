#include<iostream>

using namespace std;

class HeapSort
{
public:
    void MaxHeap(int arr[], int i, int n)
    {
        int lef, rig, max, loc;
        lef = 2*i;
        rig = (2*i)+1;

        if ( (lef <= n) && arr[lef] > arr[i])
            max = lef;
        else
            max = i;
        if( (rig <= n) && (arr[rig] > arr[max] ) )
            max = rig;
        if(max != i)
        {
            loc = arr[i];
            arr[i] = arr[max];
            arr[max] = loc;
            MaxHeap(arr, max, n);
        }
    }

    void BuildMaxHeap(int arr[], int n)
    {
        for(int i = n/2; i >= 1; i--)
            MaxHeap(arr, i, n);
    }

    void heapSort(int arr[], int n)
    {
       BuildMaxHeap(arr, n);
       int i, temp;
       for(i = n; i >= 2; i--)
       {
           temp = arr[i];
           arr[i] = arr[1];
           arr[1] = temp;
           MaxHeap(arr, 1, i-1);
       }
    }
    int inorder(int n, int arr[])
    {
        if(n==0)
            return true;
        for(int i =0; i < n-1; i++)
        {
            if(arr[i] >= arr[i+1]) //inorder
                return false;
        }
        return true;
    }

};

int main()
{
    HeapSort mh;
    int size, i;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];
    cout << "Enter elements: ";

    for(i =1; i <= size; i++)
        cin >> arr[i];

    for(i = 1; i <= size; i++)
        cout << arr[i] << " ";

    mh.heapSort(arr, size);
    cout << "\nSorted: ";
    for(i = 1; i <= size; i++)
        cout << arr[i] << " ";

        mh.inorder(size, arr);
    return 0;
}
