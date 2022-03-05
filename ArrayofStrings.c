/*Assignment 4.4
Tomer Burman
ID: 207598970
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50//Max size of string. 
enum{ADD =1,DOUBLE=2,FIND=3,PRINT=4,END=5 };

char** init_arr(int* psize);
char** add(char** arr, int* psize, char* str);
void twice(char** arr, int size, int index);
int find(char** arr, int size, char* str);
void print(char** arr, int size);
void menu();


int main() {
	int size=0,i;
	char** arr;
	char** arr2;
	int choice;
	char str[MAX];
	int index=0;
	printf("Please enter number of words you want to write.\n");
	scanf("%d", &size);
	arr=init_arr(&size);
	getchar();
	for (i = 0; i < size; i++) {
		printf("Please enter word number %d:\n", i + 1);//words #1 #2 ... 
		gets(arr[i]);
	}
	do {
		menu();//menu function
		scanf("%d", &choice);
		switch (choice) {//case 1-5, default will result menu function. 
		case ADD://in case choice=1Add
			printf("\nPlease enter another word.\n");
			scanf("%s", &str);
			arr2 = arr;
			arr=add(arr, &size, str);
			if (arr != NULL)
				printf("Done.\n");
			else
				arr = arr2;
			break;
		case DOUBLE://in case choice=2Twice
			printf("\nPlease enter the index of the word you want to double.");//index >=1. humans language.
			scanf("%d", &index);
			twice(arr,size,index-1);//doubles the word in the index. ex . two becomes twotwo.
			break;
		case FIND://in case choice=3Find
			printf("\nEnter a word that you want it's location.");
				scanf("%s", &str);
				if ((index=find(arr, size, &str)) >= 0)//if the string is contained.
					printf("The index is %d\n",index+1);
				else
				printf("\nThe word is not in the string. ");
				break;
		case PRINT://in case choice=4print
			print(arr, size);
			break;
		case END:////in case choice=5Free
			for (i = 0; i < size; i++)
				free(*(arr + i));
			free(arr);
			printf("Goodbye.");
			break;
		default ://in any other case. 
			printf("You entered an invalid choice, Please try again.\n");
		}

	} while (choice != END);//while choice !=5

	return 0;
}


char** init_arr(int* psize) {//A
	char** str;
	int i;
	str = (char**)malloc(*psize * sizeof(char*));//creating an array of strings. 
	if (str == NULL) {
		printf("Cannot allocate memory.\n");
		return NULL;
		}
	for (i=0; i < *psize; i++) {
		str[i] = (char*)malloc(MAX*sizeof(char));//size of every string (50 MAX).
		if (str[i] == NULL) {
			printf("Cannot allocate memory.\n");
			return NULL;
		}
	}
	return str;
	
}

char** add(char** arr, int* psize, char* str) {//B
	int i;
	char** arr_new;
	for (i = 0; i < *psize; i++) {
		if (!(strcmp(arr[i], str))) {//abcD abcd abcd abcd D - d abcd-abcd = 0
			printf("You entered an exsisting string. ");
			return NULL;
		}
	}
	arr_new = (char**)realloc(arr, (*psize+1)*sizeof(char*));//new arr of strings.
	if (arr_new == NULL) {
		printf("Cannot allocate memory.");
		return NULL;
	}
	arr_new[*psize] = (char*)malloc((strlen(str)+1)* sizeof(char));//string size. 
	if (arr_new[*psize] == NULL) {
		printf("Cannot allocate memory");
		return NULL;
	}
	strcpy(arr_new[*psize], str);//copies str to the last place in the array. 
	*psize += 1;

	return arr_new;

}

void twice(char** arr, int size, int index) {//index>=1.in the example index 4 was word five, by humans language it's index 5.
	if (index<0|| index >size - 1) {
		printf("\nYou entered an ilegal index. ");
		return;
	}
	char temp[MAX];
	strcpy(temp, *(arr+index));//copy of the string to a temp string. 
	*(arr+index) = (char*)realloc(*(arr+index), ((strlen(*(arr+index)) * 2) +2) * sizeof(char));//size doubled.
	if (*(arr + index) == NULL)
		return;
	strcat(*(arr+index), temp);
	printf("\nThe word in the index has been doubled.");
}

int find(char** arr, int size, char* str) {//checks if string is  contained in the array string. 
	int i;
	for (i = 0; i < size; i++) {
		if (!(strcmp(*(arr+i), str))) {//compares strings.
			return i;
		}
	}
	return -1;
}

void print(char** arr, int size) {//prints an array of strings.
	int i, j;
	for (i = 0; i < size; i++) {
			printf("%s ", *(arr+i));
	}

}

void menu() {//menu.
	printf("Please choose one of the following :\n");
	printf("1-    Add\n2-    Twice\n3-    Find\n4-    Print\n5-    End\n");
}
