//
//  main.c
//  LearnC
//
//  Created by Amit Jangirh on 15/05/21.
//

#include <stdio.h>
#include <stdlib.h>


void createAndPrintArray() {
    // ask to create size of array
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    int *array = (int*) malloc(sizeof(int));
    for(int i=0; i<n; i++) {
        array[i] = i+1;
    }
    for(int i=0; i<n; i++) {
        printf("%d\n", array[i]);
    }
}

int main(int argc, const char * argv[]) {
    createAndPrintArray();
    return 0;
}
