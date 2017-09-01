/*
	-->Just use copy the file to your program location.
	-->and write the following in your main program:
			#include "quickSort.h"
	-->to invoke sorting, just use the fuction use:
		quickSort(Name_Of_Your_Array,SizeOfYourArray)
		 
*/

void swap(int* num1,int* num2);
void quickSort(int* Array,int size);
void quick_Sort(int* Array,int first,int last,int pivot);
int partition(int* Array,int first,int last,int pivot);


void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void quickSort(int* Array,int size)
{
	quick_Sort(Array,0,(size-1),0);
}

void quick_Sort(int* Array,int first,int last,int pivot)
{
	int p;
	if(last-first<1)
		return;
	p = partition(Array,first,last,pivot);
	quick_Sort(Array,first,p-1,first);
	quick_Sort(Array,p+1,last,p+1);
}

int partition(int* Array,int first,int last,int pivot)
{
	int i = first+1,
		j = pivot,
		k = Array[pivot];
	while(i<=last)
	{
		if(Array[i]<k)
		{
			j=j+1;
			swap(&Array[i],&Array[j]);
		}
		i=i+1;
	}
	swap(&Array[pivot],&Array[j]);
	return j;
	
}
