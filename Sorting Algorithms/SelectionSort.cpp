#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{

    int data[] = {77, 42, 35, 12, 101, 5};
    int i, j, k, temp;
    int n = sizeof(data) / sizeof(data[0]);
    int ddata[] = {};
    cout << "Selection Sort" << endl;

    cout << "Unsorted Data : ";
    for (i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }

    cout << "\nSorted Data : ";
    for (i = 0; i < n; i++)
    {
        int sortt = i;
        for (j = i + 1; j < n; j++)
        {
            if (data[j] < data[sortt])
            {
                sortt = j;
            }
        }

        int temp = data[i];
        data[i] = data[sortt];
        data[sortt] = temp;

        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}
