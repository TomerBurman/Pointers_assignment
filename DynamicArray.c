/*Assignment 4.2
Tomer Burman
ID: 207598970
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int* divide(int a[], int size_a, int b[], int size_b);

int main() {
	int sizeA=0, sizeB=0;
	int* arrA;
	int i, j;
	int* arrB;
	int* ptr = NULL;
		printf("Please enter size of the first array.", sizeA);
		scanf("%d", &sizeA);
		arrA = (int*)malloc(sizeA * sizeof(int));//dynamic array
		if (arrA == NULL) {// in case of memory fail.
			printf("Cannot allocate memory.");
			exit(1);
		}
		printf("Please enter the first array.");
		for (i = 0; i < sizeA; i++)
			scanf("%d", arrA + i);
		printf("Please enter the size of the second array. ", sizeB);
		scanf("%d", &sizeB);
		arrB = (int*)malloc(sizeB * sizeof(int));
		if (arrB == NULL) {// in case of memory fail
			printf("Cannot allocate memory");
			exit(1);
		}
		printf("Please enter the second array");
		for (i = 0; i < sizeB; i++) {
			scanf("%d", arrB + i);
			if (!(arrB[i]))//incase of an input of 0 in the divisor. 
				arrB[i] = 1;
		}
		ptr = divide(arrA, sizeA, arrB, sizeB);//pointing at the first element in the array recieved. 
		for (i = 0; i < sizeB; i++)
			printf("%d ", *(ptr+i));
		free(arrA);//free
		free(arrB);//free
		free(ptr);//free
		return 0;
}
/*a={49,700,35,125,27,63,512,350,75}, b={7,2,11,9,5}
c={5,3,0,2,5}.
*/
int* divide(int a[], int size_a, int b[], int size_b) {
	int i = 0, j = 0;
	int* arr;
	arr = (int*)calloc(size_b, sizeof(int));//dynamic array all elements set to zero.
	if (arr == NULL) {
		printf("Memory allocation failed. ");
		exit(1);
	}
	for (i = 0; i < size_b; i++) {
		for (j = 0; j < size_a; j++) {
			if (a[j] % b[i] == 0)
				*(arr+i) += 1;
		}
	}
	return arr;

}
