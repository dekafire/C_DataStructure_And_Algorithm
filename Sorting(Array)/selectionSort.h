void swap(int* num1, int* num2);
void selectionSort(int* Array,int size);

void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void selectionSort(int* Array,int size)
{
	int i = 0,
		j,minIndex;
	while(i<(size-1))
	{
		j = i+1;
		minIndex = i;
		while(j<size)
		{
			if(Array[j]<Array[minIndex])
				minIndex = j;
			j = j+1;
		}
		swap(&Array[i],&Array[minIndex]);
		i = i+1;
	}
}
