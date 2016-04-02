/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void find_aps(int *a, int len, int *res){
	int i, j, aps1 = -1,ape1 = -1,aps2 = -1,ape2 = -1;
	
	for (i = 0; i < len-1; i++){
		int d = a[i + 1] - a[i];
		aps1 = i;
		for (j = i; j < len-1; j++){
			if (a[j + 1] - a[j] == d){
				continue;
			}
			else{
				ape1 = j;
				break;
			}
		}
		if (aps1 != -1 && ape1 != -1 && (ape1-aps1 != 1))
			break;
	}
	res[0] = aps1;
	res[1] = ape1;

	for (i = aps1 + 1; i < len-1; i++){
		int d = a[i + 1] - a[i];
		aps2 = i;
		for (j = i; j < len-1; j++){
			if (a[j + 1] - a[j] == d){
				continue;
			}
			else{
				ape2 = j;
				break;
			}
		}
		if (aps2 != -1 && ape2 != -1 && (ape2 - aps2 != 1))
			break;
	}
	res[2] = aps2;
	res[3] = ape2;
}

void find_gp(int *a, int len, int *res){
	int i, j, gps = -1, gpe = -1;
	for (i = 0; i < len - 1; i++){
		int r = a[i + 1] / a[i];
		gps = i;
		for (j = i; j < len - 1; j++){
			if (a[j + 1] / a[j] != r){
				gpe = j;
				break;
			}
		}
		if (gps != -1 && gpe != -1 && (gpe - gps != 1))
			break;
	}
	res[4] = gps;
	res[5] = gpe;
}

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (arr == NULL || len == 0)
		return NULL;

	int res[6];

	find_aps(arr, len, res);
	find_gp(arr, len, res);
	return res;
}