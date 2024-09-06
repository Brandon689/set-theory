#include <stdio.h>
#include <stdbool.h>
#include "../Project1/sets.h"

bool contains(Set* s, int element) {
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == element) return true;
    }
    return false;
}

// New function: Set Difference
Set setDifference(Set* s1, Set* s2) {
    Set result;
    initSet(&result);
    for (int i = 0; i < s1->size; i++) {
        if (!contains(s2, s1->elements[i])) {
            addElement(&result, s1->elements[i]);
        }
    }
    return result;
}

int main() {
    Set set1, set2;
    initSet(&set1);
    initSet(&set2);

    // Populate set1
    addElement(&set1, 1);
    addElement(&set1, 2);
    addElement(&set1, 3);
    addElement(&set1, 4);

    // Populate set2
    addElement(&set2, 3);
    addElement(&set2, 4);
    addElement(&set2, 5);

    printf("Set 1: ");
    printSet(&set1);
    printf("Set 2: ");
    printSet(&set2);

    Set difference = setDifference(&set1, &set2);
    printf("Set 1 \\ Set 2: ");
    printSet(&difference);

    return 0;
}
