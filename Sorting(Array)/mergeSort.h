#include<stdlib.h>
/*
	-->Just use copy the file to your program location.
	-->and write the following in your main program:
			#include "mergeSort.h"
	-->to invoke sorting, just use the fuction use:
		mergeSort(Name_Of_Your_Array,SizeOfYourArray)
		 
*/
void mergeSort(int* Array,int size);
void merge_Sort(int* Array,int first,int last);
void merge(int* Array,int first,int last,int mid);

void mergeSort(int* Array,int size)
{
	merge_Sort(Array,0,size-1);
}

void merge_Sort(int* Array,int first,int last)
{
	if(last == first)
		return;
	int mid = (first+last)/2;
	merge_Sort(Array,first,mid);
	merge_Sort(Array,(mid+1),last);
	merge(Array,first,last,mid);
	
}

void merge(int* Array,int first,int last,int mid)
{
	int i, j, k;
	int* tempArray1 = (int*) malloc((last-mid+1)*sizeof(int));
	int* tempArray2 = (int*) malloc((mid-first+1)*sizeof(int));
	for(i=first;i<=mid;i=i+1)
		tempArray1[i-first] = Array[i];
	for(j=mid+1;j<=last;j=j+1)
		tempArray2[j-mid-1] = Array[j];
	i = 0;
	j = 0;
	k = first;
	do
	{
		if(i+first>mid)
		{
			Array[k]=tempArray2[j];
			j++;
		}
		else if(j+mid+1>last)
		{
			Array[k]=tempArray1[i];
			i++;
		}
		else if(tempArray1[i]<=tempArray2[j])
		{
			Array[k]=tempArray1[i];
			i++;
		}
		else
		{
			Array[k]=tempArray2[j];
			j++;
		}
		k++;
	}while(k<=last);
	free(tempArray1);
	free(tempArray2);
}

