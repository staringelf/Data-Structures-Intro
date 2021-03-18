#include <stdio.h>
#include <stdlib.h>

#define MAX 50000

void print_array(int *arr, int n);
void select_sort(int *arr, int n);
void new_sort(int *arr, int n);
void bubble_sort(int * arr, int n);
void swap(int *a, int *b);

int main(void)
{
	int size;
	int list[MAX];


	for(int i = 0; i < MAX; i++)
		list[i] = 10 + rand() % 10;

	size = sizeof(list) / sizeof(list[0]);
	
	bubble_sort(list, size);
}

void select_sort(int *a, int n)
{
	int loc;

	for(int i = 0; i < n; ++i){
		loc = i;
		for(int j = i; j < n; ++j)
			if(a[j] < a[loc])
				loc = j;
		if(loc != i)
			swap(&a[loc], &a[i]);
	}
	printf("%15s ","Sorted Array:");
	print_array(a, n);
}


void new_sort(int *a, int n)
{
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++)
			if(a[j] > a[i])
				swap(&a[j], &a[i]);
	}
	printf("%15s ","Sorted Array:");
	print_array(a, n);
}


void bubble_sort(int *a, int n)
{
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n-i-1; j++)
			if(a[j] > a[j+1])
				swap(&a[j], &a[j+1]);
	}
	printf("%15s ","Sorted Array: ");
	print_array(a, n);
}

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void print_array(int *a, int n)
{
	for(int i = 0; i < n; i++)
		printf(" %d ", *(a + i));
	printf("\n\n");
}

