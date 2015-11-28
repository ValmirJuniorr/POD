/* 
 * File:   functions.h
 * Author: Valmir
 *
 * Created on 10 de Outubro de 2015, 19:46
 */
#include"linked_List.h"

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

void insertionSort(List *list);
void selectionSort(List *list);
void bubbleSort(List *list);
void shellSort(List *list);
void quickSort(int valor[], int esquerda, int direita);
void showArray(int array[],int size);
void swap(int *orig, int *dest);
void minHeap(int heap[], int size, int index);
void heapSort(int array[], int size);
#endif	/* FUNCTIONS_H */

