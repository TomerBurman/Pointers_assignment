/*Assignment 4.1
Tomer Burman 207598970
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 50// Max amount of chars in string. 
void str_statics(char str[], int* small, int* big, int* num);


int main() {
	int small = 0, big = 0, num = 0;
	char str[MAX];
	printf("Please enter a string that you want information on \n");
	gets(str);
	str_statics(str, &small, &big, &num);//sending string, and 3 adresses to statics function
	printf(" %d small letters.\n %d capital letters.\n %d digits ", small, big, num);
	return 0;
}
/*function that tells you how many big letters, small letters and numbers you have in
a string. EX. 123TomEr 4 small letters, 2 capital letters and 3 numbers.
*/
void str_statics(char str[], int* small, int* big, int* num) {
	int i=0;
	while (str[i] != '\0') {
		if (str[i] > 'A' && str[i] < 'Z')//Capital
			*big += 1;
		else if (str[i] > 'a' && str[i] < 'z')//Small letters
			*small += 1;
		else if (str[i] >= '0' && str[i] <= '9')//Numbers
			*num += 1;
			i++;
	}
}
