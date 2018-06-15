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

int main(){
	int arr[10]={1,3,5,7,9,11,14,14,20,20};
	char arr1[100] = "qwertyuiopasdfghjklzxcvbnm";
	char arr2[100] = "raca r"; int length;
	char arr3[100] = "test string"; Occurrences struct_list[20] = {'\0'}; int occurences = 0; char max_occerence_char = '\0';
	int i;
	int r,c;
	int ptr;
	int ptr2;
	int arr4[4][5]={-5,6,0,2,2,2,2,2,9,3,3,3,3,-3,2,7,-2,6,0,4};
	

	printf("----------1, Binary_search:----------\nlist: ");
	for(i = 0;i<10;i++){
		printf("%d, ",arr[i]);
	}
	printf("\ntarget value:7\nlocation of target value: %d\n\n", binary_search(arr,7));

	printf("----------2, bubble_sort----------\nbefore sort: %s\n",arr1);
	bubble_sort1(arr1,26,2);
	printf("after sort: %s\n\n", arr1);

	printf("----------3, is_palindrome----------\n");
	length = strlen(arr2);
    if(is_palindrome(arr2, 5, 1) == 1)
    {
        printf ("%s is a palindrome\n\n", arr2);
    }
    else
    {
        printf ("%s is not a palindrome\n\n", arr2);
    }

	printf("----------4, maximum_occurences----------\nthe string is: ");
	puts(arr3);
	maximum_occurences (struct_list, arr3, &occurences, &max_occerence_char);
	printf ("Max occuring char in {%s}: '%c' Max number of occurences: %d\n\n", arr3, max_occerence_char, occurences);

	printf("----------5, max_consecutive_integers----------\n");
	printf("the array should look like:\n");
	for(r=0;r<4;r++){
		printf("\n");
		for(c=0;c<5;c++){
			printf("%d ",arr4[r][c]);
		}

	}
	max_consecutive_intergers(arr4, 4, 5, &ptr, &ptr2);

	return 0;
}
