#include<stdio.h>
#include<iostream>
#define SIZE 10

using namespace std;

int arr[SIZE];

class MergeSortArr{
public:
void merge(int arr[], int st, int e)
{
    int middle, i, j, k;
    middle = (st + e)/2;
    i = st;
    j = middle+1;
    k = st;
    int temp[100];

    while( (i <= middle) && (j <= e) )
    {
        if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
             i++;
        }
        else
        {
            temp[k] = arr[j];
             j++;
        }
        k++;
    }
    //copy the remaining elements of left arr
    while (i <= middle)
    {

        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= e)
    {

        temp[k] = arr[j];
        k++;
        j++;
    }
    for(int i = st; i <= e; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int st, int ed)
{
    if (st  >= ed)
        return;

        //if 2 elements are in the array then divide
        int mid = (st+ed)/2;
        mergeSort(arr, st, mid); //1st half
        mergeSort(arr, mid+1, ed);  //2nd hald
        merge (arr, st, ed);
}

bool Search(int arr[], int count, int num)
{
    mergeSort(arr, 0, 9);
    binary_search(arr, num, 0, count);
}

bool binary_search(int ary[], int key, int l, int r)
{

    if (l > r)
        return false;


    int mid = (l + r) / 2;


    if (ary[mid] == key)
        return true;


    if (key < ary[mid])
        return binary_search(ary, key, l, mid - 1);
    else
        return binary_search(ary, key, mid + 1, r);
}


};
int main()
{
    MergeSortArr mg;
    int arr[10] = {3,6,2,1,8,9,5,4,7};
    int st = 0;
    int en = 9;


       if( mg.Search(arr, 10, 4))
            cout <<"\nNot found";
             else
             cout << "\nFound";
}
