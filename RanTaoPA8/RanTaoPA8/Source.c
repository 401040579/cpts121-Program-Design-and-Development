/*******************************************************************************************
* Programmer: Ran Tao                                                                       
* Class: CptS 121, Fall  2015																
* Programming Assignment: PA 8
* Date: Dec 7, 2015                                                                         
* Description:For this assignment you will be required to write functions which solve each
of the following problems. You must place all of your functions in one project. If you use 
any code that you find online, you must reference it in comments.								
*******************************************************************************************/
#include "Header.h"
int binary_search(int arr_sorted_int[], int target){
	int left = 1, right = nu, targetindex = -1, found = 0, mid;
	while(found == 0 && arr_sorted_int[left-1] < arr_sorted_int[right-1]){
		mid = (left+right)/2;
		if(target == arr_sorted_int[mid-1]){
			found = 1;
			return mid;
		}else if(target < arr_sorted_int[mid-1]){
			right = mid;
		}else{
			left = mid;
		}
	}
}

void bubble_sort(char *arr, int num){
	int marker_u, marker_c, buffer;
	marker_u = num;
	while(marker_u>1){
		marker_c = 1;
		while(marker_c < marker_u){
			if(arr[marker_c]<arr[marker_c-1]){
				buffer = arr[marker_c];
				arr[marker_c]=arr[marker_c-1];
				arr[marker_c-1] = buffer;
			}
			marker_c++;
		}
		marker_u--;
	}
}
void bubble_sort1(char * arr, int num, int order)
{
	int marker_u, marker_c, buffer;
	marker_u = num;
	while (marker_u>1) {
		marker_c = 1;
		while (marker_c < marker_u) {

			if (order==1 ? arr[marker_c]<arr[marker_c - 1] : arr[marker_c]>arr[marker_c - 1]) {
				buffer = arr[marker_c];
				arr[marker_c] = arr[marker_c - 1];
				arr[marker_c - 1] = buffer;
			}

			marker_c++;
		}
		marker_u--;
	}
}
/*
int is_palindrome2(char *str, int len, int n){
char *str_temp = str;
while(*str != '/0'){
if(*str != ' ')
{
*str_temp++=*str;
}
++str;
}
*str_temp='/0';

if(len < 2) return 1;

if(str[0] == str[len-1]){
is_palindrome2(++str, len-2, n);
}else{
return 0;
}
}*/

int is_palindrome(char *string, int length, int num){
	length = strlen(string);

	if (num >= (length/2))
	{
		return 1;
	}

	if (isspace(*string))
	{
		return is_palindrome(++string, length, num);
	}

	if (isspace(string[length - num]))
	{
		return is_palindrome(string, length, ++num);
	}

	return is_palindrome(++string, length, ++num);
}

void maximum_occurences(Occurrences *list, char *string, int *n, char *c)
{
	int len = 0,i = 0,j = 0,occurence = 0;
	*n = 0;
	len = strlen(string);
	for (; string[i] != '\0'; i++)
	{
		if (string[i] != ' ')
		{
			for (j = 0; string[j] != '\0'; j++)
			{
				if (string[j] == string[i])
				{
					occurence++;
				}
			}

			list[i].num_occurrences = occurence;
			list[i].frequency = occurence/len;

			occurence = 0;

			if (list[i].num_occurrences > *n)
			{
				*n = list[i].num_occurrences;
				*c = string[i];
			}
		}
	}
}

void max_consecutive_intergers(int arr[][5], int row, int col, int *ptr, int *ptr2){
	int i,j,k,n=1,temp_n=1,num,temp_num;
	for(k=0;k<row*col;k++){
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(arr[i][j] == arr[i][j+1]){
					temp_num = arr[i][j];
					temp_n++;
					if(temp_n>n){
						n=temp_n;
						ptr = &(arr[i][j-n+2]);/* because if ptr = &(arr[i][j]), it will store the penult address of the maximum consecutive sequence of one integer.
											   so, i need to move the pointer to point the start of the maximum consecutive sequence of the same integer.*/
						num=temp_num;
						*ptr2 = num;
					}
				}else{	
					temp_n = 1;
				}
			}
		}
	}
	printf("\n\n");
	printf("ptr(the address of the start of the maximum consecutive sequence of the same integer): %d\nptr2(the number of the same consecutive integers): %d\ntimes of repetition: %d\n", ptr, *ptr2, n);
	//printf("*(ptr-1): %d\n", *(ptr-1)); // should be = to last one
}