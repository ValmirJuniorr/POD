/* 
 * File:   linked_List.h
 * Author: Valmir
 *
 * Created on 9 de Outubro de 2015, 22:45
 */

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H



typedef struct List{
	int number;
	struct List *next;
}List;

void add(List *list,int number);
void show(List *list);
void change(List *list1, List *list2);
void positionChange(List* list, int position1, int position2);



List *get(List *list,int index);
List *getLastElement(List *list);
int getNumber(List *list,int index);
int getListSize(List *list);


List *createNode();


void emptyList(List *list);
void setList(List *list,int size);
void setNeatlyList(List *list,int size);
void setDisorderlyList(List *list,int size);

void copyLinkedList(List *listOrigin,List *listDestination);
 

#endif	/* LINKED_LIST_H */