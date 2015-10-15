/* 
 * File:   main.c
 * Author: Valmir
 *
 * Created on 9 de Outubro de 2015, 11:39
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* My header files */
#include "linked_List.h"
#include "functions.h"



double initialTime, fineshTime, pastTime;

void startCount() {
    initialTime = clock();
}

double stopCount() {
    fineshTime = clock();
    pastTime = (double) (fineshTime - initialTime) / (CLOCKS_PER_SEC / 1000);
    return pastTime;
}



int main(void) {/*
    printf("\n\n*************************Vetor ordenado************************************\n\n");
    printf("\n\n*********************Vetor inversamente ordenado***************************\n\n");
    printf("\n\n************************Vetor aleatorio************************************\n\n");*/       
   
    
    int listSize=10;
    List *list,*listAux;  
    list=createNode();
    listAux=createNode();
    
    
    setNeatlyList(list,listSize);
    copyLinkedList(list,listAux);
    printf("\nOriginal -> ");
    show(list);
    
    printf("\nClone   ->  ");
    show(listAux);
    
    printf(" SizeOrigin: %d || SizeClone: %d\n",getListSize(list),getListSize(listAux));
    
    
    return (0);
}

