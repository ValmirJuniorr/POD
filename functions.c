#include <stdio.h>

#include "functions.h"
#include "linked_List.h"

void insertionSort(List *list) {
    int key, i, j, mudou = 0;
    int size = getListSize(list);
    for (j = 1; j < size; j++) {
        key = getNumber(list, j);
        i = j - 1;
        while (i >= 0 && getNumber(list, i) > key) {
            positionChange(list, (i + 1), i);
            i = i - 1;
            mudou = 1;
        }
        get(list, i + 1)->number = key;
        if (mudou) {
            mudou = 0;
            show(list);
        }

    }
}

void selectionSort(List *list) {
    int menor, i, j, aux, mudou = 0;
    int size = getListSize(list);
    for (i = 0; i < size - 1; i++) {
        menor = i;
        for (j = i + 1; j < size; j++) {
            if (getNumber(list, menor) > getNumber(list, j)) {
                menor = j;
                mudou = 1;
            }
        }
        positionChange(list, menor, i);
        if (mudou) {
            show(list);
            mudou = 0;
        }

    }
}

void bubbleSort(List *list) {
    int swap, i, j;
    int size = getListSize(list);
    swap = 1;
    while (swap) {
        swap = 0;
        for (j = 0; j < size - 1; j++) {
            if (getNumber(list, j) > getNumber(list, (j + 1))) {
                positionChange(list, (j + 1), (j));
                swap = 1;
            }
        }
        if (swap)
            show(list);
    }
}

void shellSort(List *list, int size) {
    int size = getListSize(list);
    int i = size/2;
    int chave, k, mudou;
    while (i != 0) {
        do {
            chave = 1;
            mudou = 0;
            for (k = 0; k < size - i; k++) {
                if (getNumber(list, k) > getNumber(list, (k + 1))) {
                    positionChange(list, k, (k + 1));
                    chave = 0;
                    mudou = 1;
                }
            }
            if (mudou)
                show(list);
        } while (chave == 0);
        i = i / 2;
    }
}

void merge(int vetor[], int size) {
    int mid;
    int i, j, k;
    int temp[size];
    mid = size / 2;
    i = 0;
    j = mid;
    k = 0;
    while (i < mid && j < size) {
        if (vetor[i] <= vetor[j]) {
            temp[k] = vetor[i++];
        } else {
            temp[k] = vetor[j++];
        }
        ++k;
    }

    if (i == mid) {
        while (j < size) {
            temp[k++] = vetor[j++];
        }
    } else {
        while (i < mid) {
            temp[k++] = vetor[i++];

        }
    }

    for (i = 0; i < size; ++i) {
        vetor[i] = temp[i];
    }

    free(temp);
}

void mergeSort(int vetor[], int size) {
    int mid;

    if (size > 1) {
        mid = size / 2;
        mergeSort(vetor, mid);
        mergeSort(vetor + mid, size - mid);
        merge(vetor, size);
    }
}