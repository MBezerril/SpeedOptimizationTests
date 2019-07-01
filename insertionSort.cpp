#include "insertionSort.h"

void InsertionSort(int *arr, int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}

void InsertionSortVector(std::vector<int> *arr, int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr->at(i);  
        j = i - 1;  
        while (j >= 0 && arr->at(j) > key) 
        {  
            arr->at(j + 1) = arr->at(j);  
            j = j - 1;  
        }  
        arr->at(j + 1) = key;  
    }  
}
