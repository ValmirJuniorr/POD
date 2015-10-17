#include<stdio.h>
#include <stdlib.h>
#include "linked_List.h"

List *createNode() {
    List *newList = (List *) malloc(sizeof (List));
    newList->number = 0;
    newList->next = NULL;
    return newList;
}

void add(List *list, int number) {
    List *last;
    last = getLastElement(list);
    if (last->number == 0) {
        last->number = number;
    } else {

        last->next = createNode();
        last->next->number = number;
    }
}

void show(List *list) {
    List *aux = list;
    while (aux != NULL) {
        printf("[%d] ", aux->number);
        aux = aux->next;
    }
    printf("\n");

}

void change(List *list1, List *list2) {
    int aux = list1->number;
    list1->number = list2->number;
    list2->number = aux;
}

void positionChange(List *list, int position1, int position2) {
    List *aux1 = get(list, position1);
    List *aux2 = get(list, position2);
    change(aux1, aux2);
}

int getListSize(List *list) {
    int size = 0;
    List *last = list;
    while (last != NULL) {
        last = last->next;
        size++;
    }
    return size;
}

List *get(List *list, int index) {
    int i = 0;
    List *aux = list;
    while (i < index) {
        aux = aux->next;
        i++;
    }
    return aux;
}

int getNumber(List *list, int indice) {
    return get(list, indice)->number;
}

List *getLastElement(List *list) {
    List *last = list;
    while (last->next != NULL) {
        last = last->next;
    }
    return last;
}

void emptyList(List* list) {
    List *next, *atual;
    if (getListSize(list) > 1) {
        atual = list->next;
        while (atual != NULL) {
            next = atual->next;
            free(atual);
            atual = next;
        }
    }
}

void setList(List *list, int size) {
    emptyList(list);
    int i;
    srand((unsigned) time(NULL));
    for (i = 0; i < size; i++) {
        add(list, ((rand() % size) + 1));
    }
}

void setNeatlyList(List *list, int size) {
    emptyList(list);
    int i;
    for (i = 0; i < size; i++) {
        add(list, (i + 1));
    }

}

void setDisorderlyList(List *list, int size) {
    emptyList(list);
    int i;
    for (i = 0; i < size; i++) {
        add(list, (size - i));
    }
}

void copyLinkedList(List *listOrigin, List *listDestination) {
    emptyList(listDestination);

    while (listOrigin != NULL) {
        add(listDestination, listOrigin->number);
        listOrigin = listOrigin->next;
    }
}