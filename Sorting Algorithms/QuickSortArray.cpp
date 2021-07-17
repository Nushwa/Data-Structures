#include <stdio.h>
#include<iostream>

using namespace std;
int size = 10;
void Quicksort(int* array, int size, int e)
{
    if (size >= e)
        return;

    int i = size, j = size;
    while (++j < e)
    {
        if (array[j] < array[size])
            swap(array[++i], array[j]);
    }
    swap(array[size], array[i]);

    Quicksort(array, size, i);
    Quicksort(array, i + 1, e);
}

int swap(int arr[],int  ar1[])
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        temp = arr[i];
        arr[i] = ar1[i];
        ar1[i] = temp;
    }

}


bool binsearch(int a[], int key, int left, int right)
{

    if (left > right)
        return false;


    int mid = (left + right) / 2;


    if (a[mid] == key)
        return true;


    if (key < a[mid])
        return binsearch(a, key, left, mid - 1);
    else
        return binsearch(a, key, mid + 1, right);
}
bool Search(int ar[], int counter, int num)
{
    Quicksort(ar, 10, 9);

    return binsearch(ar,num,0,counter-1);
}


int main()
{
    int a[] = { 8, 9, 2, 6, 5, 4 ,5, 3, 0, 1, 7 };

    int count = sizeof(a) / sizeof(a[0]);
    Quicksort(a, 0, count);

    for (int i=0; i<count; ++i)
    {
        cout << a[i] << " ";
    }

     if( Search(a, 10, 7)== true)
            cout << "\nFound";
        else
            cout <<"\nNot found";
    return 0;
}
