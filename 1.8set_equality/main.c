#include <stdio.h>
#include <stdbool.h>
#include "../Project1/sets.h"

bool contains(Set* s, int element) {
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == element) return true;
    }
    return false;
}

// New function: Check Set Equality
bool areEqual(Set* s1, Set* s2) {
    if (s1->size != s2->size) return false;

    for (int i = 0; i < s1->size; i++) {
        if (!contains(s2, s1->elements[i])) return false;
    }

    return true;
}

int main() {
    Set A, B, C;
    initSet(&A);
    initSet(&B);
    initSet(&C);

    // Populate sets
    addElement(&A, 1);
    addElement(&A, 2);
    addElement(&A, 3);

    addElement(&B, 2);
    addElement(&B, 1);
    addElement(&B, 3);

    addElement(&C, 1);
    addElement(&C, 2);
    addElement(&C, 4);

    printf("Set A: ");
    printSet(&A);
    printf("\n");

    printf("Set B: ");
    printSet(&B);
    printf("\n");

    printf("Set C: ");
    printSet(&C);
    printf("\n\n");

    printf("Is A equal to B? %s\n", areEqual(&A, &B) ? "Yes" : "No");
    printf("Is A equal to C? %s\n", areEqual(&A, &C) ? "Yes" : "No");

    return 0;
}
