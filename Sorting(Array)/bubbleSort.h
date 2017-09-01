void swap(int* num1, int* num2);
void bubbleSort(int* Array,int size);

void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void bubbleSort(int* Array,int size)
{
	int i=0,
		j;
	while(i<size-1)
	{
		j = 1;
		while(j<size-i)
		{
			if(Array[j]<Array[j-1])
			{
				swap(&Array[j-1],&Array[j]);
			}
			j = j+1;
		}
		i = i+1;
	}
}
