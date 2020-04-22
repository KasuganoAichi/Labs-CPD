#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
using namespace std;


int binary_search (int a[], int low, int high, int key) {
	int mid;
	if (low == high)
		return low;
	mid = low + ((high-low)/2);
	if (key > a[mid])
		return binary_search(a, mid+1, high, key);
	else if (key < a [mid])
		return binary_search(a, low, mid, key);
	return mid;
}

void print_array(int C[], int tam) {
	printf("[");
	for (int i=0; i<tam-1; i++) {
		printf("%d, ", C[i]);
	}
	printf("%d]", C[tam-1]);
}

void binary_insertion_sort(int C[], int tam, int print_ok) {
	long changes = 0;
	int i, j, chave;
	int ins;
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
	
	if (print_ok) {
		printf("\nArray before:");
		print_array(C, tam);
	}
	for (j=1; j<tam; j++) {
		ins = binary_search(C, 0, j, C[j]);
		chave = C[j];
		for (int k=j-1; k>=ins; k--) {
			C[k+1] = C[k];
			changes++;
		}
		C[ins]=chave;
	} 
    QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;

	if (print_ok) {
		printf("\nArray after:");
		print_array(C, tam);
	}
	printf("\nInsertion Sort Binary Search of %d elements: #changes = %ld - time = %10.4Lf ms", tam, changes, interval*1000);
}

void shell_insertion_sort(int C[], int tam, int print_ok) 
{

	int h, k;
	
	k = 1;
	while (h > 1)
	{
		h = tam / pow(2,k);
		f = 0
		for (j=1; j<h; j++)
		{
			insertion_sort(C, tam, print_ok, h, f);
			f++;
			
		}
		k++;
	
	}
	
}

void insertion_sort(int C[], int tam, int print_ok, int h, int f) {
	long changes = 0;
	int i, j, chave;
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
	
	if (print_ok) {
		printf("\nArray before:");
		print_array(C, tam);
	}
	for (j=f+h; j<tam; j = j + h) {
		chave = C[j];
		i = j-1;
		while ((i>=0) && C[i]>chave) {
			C[i+1] = C[i];
			i--;
			changes++;
		}
		C[i+1]=chave;
	} 
    QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;

	if (print_ok) {
		printf("\nArray after:");
		print_array(C, tam);
	}
	printf("\nInsertion Sort of %d elements: #changes = %ld - time = %10.4Lf ms", tam, changes, interval*1000);
}

void copy_array (int* array_origem, int* array_destino, int size) {
	for (int i=0; i< size; i++) array_destino [i] = array_origem [i];
}

#define SIZE1 1000
#define SIZE2 10000
#define SIZE3 100000
#define NSIZES 3

int main(){
	int arr1[10]={12,2,5,4,8,7,6,9,1,15};
	int arr2[10]={1,2,3,4,5,6,7,8,9,10};
	int arr3[10]={10,9,8,7,6,5,4,3,2,1};

	int arr_sizes[NSIZES] = {SIZE1, SIZE2, SIZE3};
	int arr_origem[SIZE3];
	int arr_destino[SIZE3];

	shell_insertion_sort(arr1, 10, 1);
	shell_insertion_sort(arr2, 10, 1);
	shell_insertion_sort(arr3, 10, 1);

	// Generate test arrays
	for (int j=0; j<NSIZES; j++) {
		int size = arr_sizes[j];
		for (int i=0; i<size; i++) arr_origem[i]=rand()%size+1;	// arr_size1[i] = SIZE1-i;
		copy_array(arr_origem, arr_destino, size);
		cout << "\nStarting Insertion Sort" << flush;
		insertion_sort(arr_destino, size, 0);
		cout << "\nEnd Insertion Sort" << flush;

		copy_array(arr_origem, arr_destino, size);
		cout << "\nStarting Binary Insertion Sort" << flush;
		binary_insertion_sort(arr_destino, size, 0);
		cout << "\nEnd Insertion Sort" << flush;

		copy_array(arr_origem, arr_destino, size);
		cout << "\nStarting Shell Sort" << flush;
		shell_insertion_sort(arr_destino, size, 0);	
		cout << "\nEnd Shell Sort" << flush;

	}


	for (int i=0; i<SIZE2; i++) arr_size2[i]=rand()%SIZE2+1;	
	for (int i=0; i<SIZE3; i++) arr_size3[i]=rand()%SIZE3+1;	
	for (int i=0; i<SIZE4; i++) arr_size4[i]=rand()%SIZE4+1;	
	for (int i=0; i<SIZE5; i++) arr_size5[i]=rand()%SIZE5+1;	

	copy_array(arr_size1, arr_sort, SIZE1);
	shell_insertion_sort(arr_size1, SIZE1, 0);
	printf("\n\n");
}
