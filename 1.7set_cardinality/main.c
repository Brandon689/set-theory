#include <stdio.h>
#include <stdbool.h>
#include "../Project1/sets.h"

// New function: Get Set Cardinality
int getCardinality(Set* s) {
    return s->size;
}

int main() {
    Set A, B, C;
    initSet(&A);
    initSet(&B);
    initSet(&C);

    // Populate set A
    addElement(&A, 1);
    addElement(&A, 2);
    addElement(&A, 3);
    addElement(&A, 4);

    // Populate set B
    addElement(&B, 10);
    addElement(&B, 20);

    // Set C remains empty

    printf("Set A: ");
    printSet(&A);
    printf("\nCardinality of A: %d\n\n", getCardinality(&A));

    printf("Set B: ");
    printSet(&B);
    printf("\nCardinality of B: %d\n\n", getCardinality(&B));

    printf("Set C: ");
    printSet(&C);
    printf("\nCardinality of C: %d\n", getCardinality(&C));

    return 0;
}
