#include <stdio.h>
#include <stdbool.h>
#include "../Project1/sets.h"

bool removeElement(Set* s, int element) {
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == element) {
            // Element found, remove it by shifting all following elements
            for (int j = i; j < s->size - 1; j++) {
                s->elements[j] = s->elements[j + 1];
            }
            s->size--;
            return true;  // Element successfully removed
        }
    }
    return false;  // Element not found in the set
}
// Function to print the set
void printSet(Set* s) {
    printf("{");
    for (int i = 0; i < s->size; i++) {
        printf("%d", s->elements[i]);
        if (i < s->size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

int main() {
    Set mySet;
    initSet(&mySet);

    printf("Adding elements to the set:\n");
    addElement(&mySet, 5);
    addElement(&mySet, 2);
    addElement(&mySet, 8);
    addElement(&mySet, 2);  // Duplicate, won't be added

    printf("Set contents: ");
    printSet(&mySet);

    printf("Set size: %d\n", mySet.size);

    for (int i = 0; i < mySet.size; i++) {
        if (mySet.elements[i] == 5) {
            printf("found existing:");
            printf("5");
        }
    }
    int elementToRemove = 2;
    if (removeElement(&mySet, elementToRemove)) {
        printf("Removed %d from the set.\n", elementToRemove);
    }
    else {
        printf("%d not found in the set.\n", elementToRemove);
    }

    printf("Set after removal: ");
    printSet(&mySet);

    // Try to remove an element that's not in the set
    elementToRemove = 10;
    if (removeElement(&mySet, elementToRemove)) {
        printf("Removed %d from the set.\n", elementToRemove);
    }
    else {
        printf("%d not found in the set.\n", elementToRemove);
    }
    return 0;
}
