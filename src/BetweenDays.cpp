/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int checkSame(struct node *date1head, struct node *date2head){
	struct node* temp1 = date1head;
	struct node* temp2 = date2head;
	while (temp1){
		if (temp1->data != temp2->data)
			return -1;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return 0;
}

int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return -1;

	if (checkSame(date1head, date2head) == 0){
		return 0;
	}
	
	return -1;
}