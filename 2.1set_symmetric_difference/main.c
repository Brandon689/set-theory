#include <stdio.h>
#include <stdbool.h>
#include "../Project1/sets.h"

bool contains(Set* s, int element) {
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == element) return true;
    }
    return false;
}

Set symmetricDifference(Set* s1, Set* s2) {
    Set result;
    initSet(&result);

    // Add elements from s1 that are not in s2
    for (int i = 0; i < s1->size; i++) {
        if (!contains(s2, s1->elements[i])) {
            addElement(&result, s1->elements[i]);
        }
    }

    // Add elements from s2 that are not in s1
    for (int i = 0; i < s2->size; i++) {
        if (!contains(s1, s2->elements[i])) {
            addElement(&result, s2->elements[i]);
        }
    }

    return result;
}

int main() {
    Set A, B;
    initSet(&A);
    initSet(&B);

    // Populate sets
    addElement(&A, 1);
    addElement(&A, 2);
    addElement(&A, 3);
    addElement(&A, 4);

    addElement(&B, 3);
    addElement(&B, 4);
    addElement(&B, 5);
    addElement(&B, 6);

    printf("Set A: ");
    printSet(&A);
    printf("\n");

    printf("Set B: ");
    printSet(&B);
    printf("\n");

    Set symDiff = symmetricDifference(&A, &B);
    printf("Symmetric Difference (A △ B): ");
    printSet(&symDiff);
    printf("\n");

    return 0;
}
