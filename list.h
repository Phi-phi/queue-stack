#ifndef _list_h
#define _list_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct List_box{
	int data;
	
	struct List_box *next;
}List;

void push(List *l, int num){
	List *new = (List*)malloc(sizeof(List));
	new -> data = num;
	new -> next = l -> next;
	l -> next = new;
}

bool shift(List *l, int *popped){
	List *del;
	bool ret = 0;
	if(l -> next != NULL){
		while(l -> next -> next != NULL){
			l = l -> next;
		}
		del = l -> next;
		*popped = del -> data;
		l -> next = l -> next -> next;
		free(del);

		ret = 1;
	}
	return ret;
}

bool pop(List *l, int *popped){
	List *del;
	bool ret = 0;
	if(l -> next != NULL){
		del = l -> next;
		*popped = del -> data;
		l -> next = l -> next -> next;
		free(del);
		ret = 1;
	}
	return ret;
}

void delete(List *l){
	List *del;
	while(l != NULL){
		del = l;
		l = l -> next;
		free(del);
	}
}

#endif
