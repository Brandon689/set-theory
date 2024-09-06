#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 20

typedef struct {
    int elements[MAX_SIZE];
    int size;
} Set;

void initSet(Set* s) {
    s->size = 0;
}

void addElement(Set* s, int element) {
    if (s->size < MAX_SIZE) {
        s->elements[s->size++] = element;
    }
}

void printSet(Set* s) {
    printf("{");
    for (int i = 0; i < s->size; i++) {
        printf("%d", s->elements[i]);
        if (i < s->size - 1) printf(", ");
    }
    printf("}");
}

// Function to print a subset based on a bit mask
void printSubset(Set* s, int mask) {
    printf("{");
    int first = 1;
    for (int i = 0; i < s->size; i++) {
        if (mask & (1 << i)) {
            if (!first) printf(", ");
            printf("%d", s->elements[i]);
            first = 0;
        }
    }
    printf("}");
}

// Function to iterate through the power set
void iteratePowerSet(Set* s) {
    unsigned int powerSetSize = pow(2, s->size);

    printf("Power Set:\n");
    for (unsigned int i = 0; i < powerSetSize; i++) {
        printSubset(s, i);
        printf("\n");
    }
}

int main() {
    Set set;
    initSet(&set);

    // Create a sample set
    addElement(&set, 1);
    addElement(&set, 2);
    addElement(&set, 3);

    printf("Original Set: ");
    printSet(&set);
    printf("\n\n");

    iteratePowerSet(&set);

    return 0;
}
