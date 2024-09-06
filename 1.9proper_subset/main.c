#include <stdio.h>
#include <stdbool.h>
#include "../Project1/sets.h"

bool contains(Set* s, int element) {
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == element) return true;
    }
    return false;
}

// Function to check if set1 is a subset of set2
bool isSubset(Set* set1, Set* set2) {
    for (int i = 0; i < set1->size; i++) {
        if (!contains(set2, set1->elements[i])) {
            return false;
        }
    }
    return true;
}

// New function: Check if set1 is a proper subset of set2
bool isProperSubset(Set* set1, Set* set2) {
    return isSubset(set1, set2) && (set1->size < set2->size);
}

int main() {
    Set A, B, C;
    initSet(&A);
    initSet(&B);
    initSet(&C);

    // Populate sets
    addElement(&A, 1);
    addElement(&A, 2);

    addElement(&B, 1);
    addElement(&B, 2);
    addElement(&B, 3);

    addElement(&C, 1);
    addElement(&C, 2);

    printf("Set A: ");
    printSet(&A);
    printf("\n");

    printf("Set B: ");
    printSet(&B);
    printf("\n");

    printf("Set C: ");
    printSet(&C);
    printf("\n\n");

    printf("Is A a proper subset of B? %s\n", isProperSubset(&A, &B) ? "Yes" : "No");
    printf("Is A a proper subset of C? %s\n", isProperSubset(&A, &C) ? "Yes" : "No");
    printf("Is B a proper subset of A? %s\n", isProperSubset(&B, &A) ? "Yes" : "No");

    return 0;
}
