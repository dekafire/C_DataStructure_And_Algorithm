void swap(int* num1, int* num2);
void insertionSort(int* Array,int size);

void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void insertionSort(int* Array,int size)
{
	int i = 1,
		j;
	while(i<size)
	{
		j = i;
		while(j>0)
		{
			if(Array[j]<Array[j-1])
				swap(&Array[j],&Array[j-1]);
				j = j-1;
		}
		i = i+1;
	}
}
