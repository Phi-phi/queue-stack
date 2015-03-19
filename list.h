#ifndef _list_h
#define _list_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct List_box{
	int data;

	struct List_box *first;
	struct List_box *prev;
	struct List_box *next;
}List;

void new_list(List **l){
	(*l) = (List*)malloc(sizeof(List));
	(*l) -> first = NULL;
	(*l) -> prev = NULL;
	(*l) -> next = NULL;
}

void push(List *l, int num){
	List *new = (List*)malloc(sizeof(List));
	new -> data = num;
	new -> next = l -> next;
	new -> prev = l;
	if(l -> first == NULL){
		l -> first = new;
		new -> first = new;
	}else{
		l -> next -> prev = new;
	}
	l -> next = new;
}

bool shift(List *l, int *popped){
	List *del;
	if(l -> next != NULL){
		del = l -> first;
		*popped = del -> data;
		l -> first = del -> prev;
		del -> prev -> next = NULL;
		free(del);

		return true;
	}
	return false;
}

bool pop(List *l, int *popped){
	List *del;
	if(l -> next != NULL){
		del = l -> next;
		*popped = del -> data;
		l -> next = l -> next -> next;
		free(del);
		return true;
	}
	return false;
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
