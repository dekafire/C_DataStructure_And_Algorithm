/*
	-->Copy this file to your program folder
	-->include it as header file i.e. #include "arrayList.h"
	-->List of opereations
		**init_Array_DataType() - to initalize array as list.Please follow the following syntax:
			syantx:		Array* NameOfTheList = init_Array_DataType();
		**getSize(ListName) - returns size of array.
		**doubleLength(listName) - doubles the array size;
		**getLength(ListName) - returns length of array.
		**append(ListName,value) - insert value at the end of list.
		**insert(ListName,value,index) - insert a value at an index of the list.
		**removeEnd(ListName) - remove last element from the list.
		**del(ListName,index) - delete element  at index from the list.
		**isEmpty(ListName) - if empty returns True, else False.
		**isFull(ListName) - if Full returns True, else False.
		**traverse(ListName) - print Array as List.
		**compare(ListName1,ListName2) - if both are equal returns True, else False.
		**concatList(ListName1,ListName2) - combines ListName1 and ListName2 in ListName1.
		**add(ListName,value) - add value to all elements of list.
		**multiply(ListName,value) - multiply value to all elements of list.
		**divide(ListName,value) - divide all elements of list by value.
		**
		**
		**
		**
*/

#include<stdio.h>
#include<stdlib.h>

typedef enum { False = 0,
 				True} t_bool;

typedef struct Array 
{
	int size;
	int length;
	int* array;
}Array;


Array* init_Array_DataType()
{
	Array* list = (Array*) malloc(sizeof(Array));
	list->size = 0;
	list->length = 1;
	list->array = (int*) malloc(sizeof(int));
	return list;
}

int getLength(Array *self)
{
	return self->length;
}

int getSize(Array *self)
{
	return self->size;
}

//special fuction to double the size of the ArrayList when array is full;
void doubleLength(Array *self)
{
	int i = 0;
	Array temp;
	Array* tempArray = (Array*) malloc(sizeof(Array));
	tempArray->length = 2*(self->length);
	tempArray->size = (self->length);
	tempArray->array = (int*) malloc(tempArray->size*sizeof(int));
	do
	{
		tempArray->array[i] = self->array[i];
		i = i+1;
	}while(i<=(self->length));
	temp = *self;
	*self = *tempArray;
	free(tempArray);
} 

void append(Array *self, int value)
{
	if(self->size == self->length)
	{
		doubleLength(self);
	}
	self->array[self->size] = value;
	self->size = self->size+1;
}

void insert(Array *self, int value,int index)
{
	int i=self->size;
	if(index < 0||index>self->size)
	{
		printf("\nInvalid insertion index");
		return;
	}
	if(self->size == self->length)
	{
		doubleLength(self);
	}
	while(i>=index)
	{
		self->array[i] = self->array[i-1];
		i = i-1;
	}
	self->array[index] = value;
	self->size = self->size+1;
}

void removeEnd(Array *self)
{
	if(self->size==0)
	{
		printf("\nArrayList is empty");
		return;
	}
	
	self->size = self->size-1;
}

void del(Array *self,int index)
{
	int i = index;
	if(self->size==0)
	{
		printf("\nArrayList is empty");
		return;
	}
	while(i<self->size-1)
	{
		self->array[i] = self->array[i+1];
		i = i+1;
	}
	self->size = self->size-1;
}

t_bool isEmpty(Array *self)
{
	if(self->size<1)
		return True;
	return False;
}

t_bool isFull(Array *self)
{
	if(self->size == self->length)
		return True;
	return False;
}

void traverse(Array *self)
{
	int i = 0;
	if (self->size==0)
	{
		printf("\nArrayList is empty");
		return;
	}
	printf("\nPrinting Array List:\n");
	do
	{
		printf("|%d",self->array[i]);
		i = i+1;
	}while(i<self->size);
	printf("|");
}

t_bool compare(Array* self,Array* list)
{
	int i =0;
	if(self->size==getSize(list))
	{
		while(i<self->size)
		{
			if(self->array[i]!=list->array[i])
				return False;
		}
		return True;
	}	
	return False;	
}

void concatList(Array* self,Array* list)
{	
	int i = 0;
	if(isEmpty(list)==True)
	{
		return;
	}
	while(i<getSize(list))
	{
		append(self,list->array[i]);
		i = i+1;
	}
}

void add(Array *self, int value)
{
	int i = 0;
	if (self->size==0)
	{
		return;
	}
	do
	{
		self->array[i] = self->array[i]+value;
		i = i+1;
	}while(i<self->size);
}

void multiply(Array *self, int value)
{
	int i = 0;
	if (self->size==0)
	{
		return;
	}
	do
	{
		self->array[i] = (self->array[i])*value;
		i = i+1;
	}while(i<self->size);
}

void divide(Array *self, int value)
{
	int i = 0;
	if (self->size==0)
	{
		return;
	}
	do
	{
		self->array[i] = (self->array[i])/value;
		i = i+1;
	}while(i<self->size);
}
