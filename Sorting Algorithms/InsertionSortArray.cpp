#include <iostream>

using namespace std;

class InsertionSortAl
{
public:
    void display(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }


    void insertionSort(int arr[], int n)
    {
        for(int i = 1; i <= n-1; i++)
        {
            int val = arr[i];
            int j = i-1;
            while (j>= 0 && arr[j] > val)
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = val;
        }
    }
};

int main()
{
    InsertionSortAl Is;
    int arr[6] = {3,7,2,5,1};
    int n = 6;
    Is.display(arr, n);
    Is.insertionSort(arr, n);
    Is.display(arr, n);
}
