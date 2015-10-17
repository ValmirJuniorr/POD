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


void menu(List *list, List *listAux, int listSize);

int main(void) {/*
    printf("\n\n*************************Vetor ordenado************************************\n\n");
    printf("\n\n*********************Vetor inversamente ordenado***************************\n\n");
    printf("\n\n************************Vetor aleatorio************************************\n\n");*/
    int op, listSize = 10;
    List *list, *listAux;
    list = createNode();
    listAux = createNode();
    setDisorderlyList(list,listSize);
    //setNeatlyList(list,listSize);
    //insertionSort(list);
    //selectionSort(list);        
    bubbleSort(list);
    //shellSort(list);

    
    return (0);
}

void menu(List *list,List *listAux, int listSize){
    int op;
    do {
        printf("Esocolha a opcao: \n"
                "[1]-Ordenada [2]-Desordenada [3]- Aleatorio [0]-Sair\n");
        scanf("%d", &op);
        emptyList(list);
        emptyList(listAux);
        switch (op) {
            case 1:
            {
                setNeatlyList(list, listSize);
                copyLinkedList(list, listAux);
                break;
            }

            case 2:
            {
                setDisorderlyList(list, 10);
                copyLinkedList(list, listAux);
                break;
            }
            case 3:
            {
                setList(list, 10);
                copyLinkedList(list, listAux);
                break;
            }
            default:
            {
                printf("Escolha invalida \n");
            }
        }
        printf("\nOriginal -> ");
        show(list);
        printf("\nClone   ->  ");
        show(listAux);
        printf(" SizeOrigin: %d || SizeClone: %d\n", getListSize(list), getListSize(listAux));
    } while (op != 0);

}

