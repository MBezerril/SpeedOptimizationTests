#include "hybrid.h"

void InternalInsertionSortArray(int *arr, int start, int end)  
{  
    int i, key, j;  
    for (i = 1; i < end; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        while (j >= start && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}

void InternalInsertionSortVector(std::vector<int> *arr, int start, int end)  
{  
    int i, key, j;  
    for (i = 1; i < end; i++) 
    {  
        key = arr->at(i);  
        j = i - 1;  
        while (j >= start && arr->at(j) > key) 
        {  
            arr->at(j + 1) = arr->at(j);  
            j = j - 1;  
        }  
        arr->at(j + 1) = key;  
    }  
}

int HybridPartitionVector(std::vector<int> *a,int start,int end){
	int pivot=a->at(end);
	//P-index indicates the pivot value index

	int P_index=start;
	int i,t; //t is temporary variable

	//Here we will check if array value is 
	//less than pivot
	//then we will place it at left side
	//by swapping 

	for(i=start;i<end;i++){
		if(a->at(i)<=pivot){
			t=a->at(i);
			a->at(i)=a->at(P_index);
			a->at(P_index)=t;
			P_index++;
		}
	}
	//Now exchanging value of
	//pivot and P-index
	t=a->at(end);
	a->at(end)=a->at(P_index);
	a->at(P_index)=t;

	//at last returning the pivot value index
	return P_index;
}

int HybridPartitionArray(int *a,int start,int end){
	int pivot=a[end];
	//P-index indicates the pivot value index

	int P_index=start;
	int i,t; //t is temporary variable

	//Here we will check if array value is 
	//less than pivot
	//then we will place it at left side
	//by swapping 

	for(i=start;i<end;i++){
		if(a[i]<=pivot){
			t=a[i];
			a[i]=a[P_index];
			a[P_index]=t;
			P_index++;
		}
	}
	//Now exchanging value of
	//pivot and P-index
	t=a[end];
	a[end]=a[P_index];
	a[P_index]=t;

	//at last returning the pivot value index
	return P_index;
}

void HybridQuicksortVector(std::vector<int> *a,int start,int end){
	if(end - start > 10){
		int P_index=HybridPartitionVector(a,start,end);
		HybridQuicksortVector(a,start,P_index-1);
		HybridQuicksortVector(a,P_index+1,end);
	}else{
		InternalInsertionSortVector(a, start, end);
	}
}

void HybridQuicksortArray(int *a,int start,int end){
	if(end - start > 10){
		int P_index=HybridPartitionArray(a,start,end);
		HybridQuicksortArray(a,start,P_index-1);
		HybridQuicksortArray(a,P_index+1,end);
	}else{
		InternalInsertionSortArray(a, start, end);
	}
}

