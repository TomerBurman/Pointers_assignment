/*Assignment 4.3
Tomer Burman 
207598970*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
long long** shrink(unsigned int** a, int size);
int multi(int num);//checks the number range ex. for 400 returns 1000 for 40 returns 100 and etc.



int main() {
	unsigned int** arr = NULL;
	long long** ptr = NULL;
	int size;
	int i,j;
	printf("Please enter the array size");
	scanf("%d", &size);
	arr = (unsigned int**)malloc(size * sizeof(unsigned int*));//creating an array of pointers.
	if (arr == NULL) {
		printf("Cannot allocate memory");
		exit(1);
	}
	for (i = 0; i < size; i++) {//creating 1 dim array.
		arr[i] = (unsigned int*)malloc(size * sizeof(unsigned int));
		if (arr[i] == NULL) {
			printf("Cannot allocate memory");
			exit(1);
		}
	}
		for (i = 0; i < size; i++) {//recieving array.
			printf("Please enter array number %d, enter %d positive numbers.", i + 1, size);
			for (j = 0; j < size; j++) {
					scanf("%d", &arr[i][j]);
			}
		}
		ptr = shrink(arr, size);//points at the starting adress of the new array.

		for (i = 0; i < size; i++)//free old arr.
			free(arr[i]);
		free(arr);

		for (i = 0; i < size/2; i++) {//prints new array. 
			for (j = 0; j < size/2; j++) {
				printf("%lld   ", ptr[i][j]);
			}
			printf("\n");
		}
		for (i = 0; i < size/2; i++)//free new arr.
			free(ptr[i]);
		free(ptr);
		
		return 0;
}


long long** shrink(unsigned int** a, int size) {//creating 2 dim square array, returning long type 2 dim array with size/2 elements.
	int i = 0;
	int j = 0;
	long long temp = 0;
	long long** arr;

	if (size % 2) {//if size=uneven
		printf("You entered an uneven array. The function is working for even matrixs. ");
		return NULL;
	}

	arr = (long long**)calloc((size / 2), sizeof(long long*));//creating an array of pointers.
	if (arr == NULL) {
		printf("Cannot allocate memory.");
		exit(1);
	}
	for (i = 0; i < size / 2; i++) {
		*(arr + i) = (long long*)malloc((size / 2) * sizeof(long long));//creating 1 dim array.
		if (arr == NULL) {
			printf("Cannot allocate memory.");
			exit(1);
		}
	}
	for (i = 0; i < size / 2; i++) {//Algorithem.
		for (j = 0; j < size / 2; j++) {
			arr[i][j] = a[2 * i][2 * j];
			arr[i][j] *= multi(a[2 * i][2 * j + 1]);
			arr[i][j] += a[2 * i][2 * j + 1];
			arr[i][j] *= multi(a[2 * i + 1][2 * j]);
			arr[i][j] += a[2 * i + 1][2 * j];
			arr[i][j] *= multi(a[2 * i + 1][2 * j + 1]);
			arr[i][j] += a[2 * i + 1][2 * j + 1];
		}
	}
	return arr;
}

	int multi(int num) {//digit function. 
		int counter = 1;
		while (num > 0) {
			num /= 10;
			counter *= 10;
		}
		return counter;

	}
