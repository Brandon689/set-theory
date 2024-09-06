#include <stdio.h>
#include <stdbool.h>
#include "../Project1/sets.h"

bool areDisjoint(Set* s1, Set* s2) {
    for (int i = 0; i < s1->size; i++) {
        for (int j = 0; j < s2->size; j++) {
            if (s1->elements[i] == s2->elements[j]) {
                return false;  // Found a common element
            }
        }
    }
    return true;  // No common elements found
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

    addElement(&B, 4);
    addElement(&B, 5);
    addElement(&B, 6);

    addElement(&C, 3);
    addElement(&C, 4);
    addElement(&C, 5);

    printf("Set A: ");
    printSet(&A);
    printf("\n");

    printf("Set B: ");
    printSet(&B);
    printf("\n");

    printf("Set C: ");
    printSet(&C);
    printf("\n\n");

    printf("Are A and B disjoint? %s\n", areDisjoint(&A, &B) ? "Yes" : "No");
    printf("Are A and C disjoint? %s\n", areDisjoint(&A, &C) ? "Yes" : "No");
    printf("Are B and C disjoint? %s\n", areDisjoint(&B, &C) ? "Yes" : "No");

    return 0;
}
