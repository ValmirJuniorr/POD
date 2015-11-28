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


void menu();
void exec(List *list, List *listAux);

int main(void) {/*
    /*printf("\n\n*************************Vetor ordenado************************************\n\n");
    printf("\n\n*********************Vetor inversamente ordenado***************************\n\n");
    printf("\n\n************************Vetor aleatorio************************************\n\n");
    //menu();
    int size = 5;
    int vetor[] = {7, 5, 3, 5, 2};
    printf("ola, \n");
    quickSort(vetor, 0, size-1);,
    int i;
     
    for (i = 0; i < size; i++) {
        printf("%d , ", vetor[i]);

    }
    printf("\n , ");
    */
    int arraiySize=3;
    int array[arraiySize];
    array[0]=15;
    array[1]=10;
    array[2]=20;
    
    showArray(array,arraiySize); 
    heapSort(array,arraiySize);
    //minHeap(array,arraiySize,1);
    showArray(array,arraiySize);
    
    return (0);
}

void menu() {
    int op;
    List *list, *listAux;
    list = createNode();
    listAux = createNode();
    int listSize = 10;
    do {
        printf("Esocolha a opcao: \n"
                "[1]-Ordenada [2]-Desordenada [3]- Aleatorio [0]-Sair\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
            {
                setNeatlyList(list, listSize);
                exec(list, listAux);
                break;
            }

            case 2:
            {
                setDisorderlyList(list, 10);
                exec(list, listAux);
                break;
            }
            case 3:
            {
                setList(list, 10);
                exec(list, listAux);
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

void exec(List *list, List *listAux) {
    copyLinkedList(list, listAux);
    insertionSort(listAux);

    copyLinkedList(list, listAux);
    selectionSort(listAux);

    copyLinkedList(list, listAux);
    bubbleSort(listAux);

    copyLinkedList(list, listAux);
    shellSort(listAux);
}
