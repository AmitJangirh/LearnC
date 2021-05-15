//
//  main.c
//  LearnC
//
//  Created by Amit Jangirh on 15/05/21.
//

#include <stdio.h>
#include <stdlib.h>

/*
Created to understand Malloc and calloc initialing 
 */

void printArray(int array[]) {
    printf("***** Printing Array array \n");
    int size = sizeof array / sizeof array[0];
    for(int i=0; i<size; i++) {
        printf("%d\n", array[i]);
    }
}

void getSizeOfArray(int *n) {
    // ask to create size of array
    printf("Enter size of array\n");
    scanf("%d", n);
}

void initialiseArray(int array[]) {
    printf("***** initialising \n");
    int size = sizeof array / sizeof array[0];
    for(int i=0; i<size; i++) {
        array[i] = i+1;
    }
}

void createAndPrintArrayUsingMalloc() {
    printf("***** MALLOC \n");
    int n;
    getSizeOfArray(&n);
    int *array = (int*) malloc(n*sizeof(int));   // Dynamic allocation of array
    printArray(array);                          // Before initialisation, prints garbage value
    initialiseArray(array);
    printArray(array);
}

void createAndPrintArrayUsingCalloc() {
    printf("***** CALLOC \n");
    int n;
    getSizeOfArray(&n);
    int *array = (int*) calloc(n, sizeof(int)); // Dynamic allocation of array
    printArray(array);                          // Before initialisation, prints 0
    initialiseArray(array);
    printArray(array);
}

int main(int argc, const char * argv[]) {
    createAndPrintArrayUsingMalloc();
    createAndPrintArrayUsingCalloc();
    return 0;
}
