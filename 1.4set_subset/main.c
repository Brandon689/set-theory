#include <stdio.h>
#include <stdbool.h>
#include "../Project1/sets.h"


bool contains(Set* s, int element) {
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == element) return true;
    }
    return false;
}

// New function: Check if set1 is a subset of set2
bool isSubset(Set* set1, Set* set2) {
    for (int i = 0; i < set1->size; i++) {
        if (!contains(set2, set1->elements[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    Set set1, set2, set3;
    initSet(&set1);
    initSet(&set2);
    initSet(&set3);

    // Populate set1
    addElement(&set1, 1);
    addElement(&set1, 2);

    // Populate set2
    addElement(&set2, 1);
    addElement(&set2, 2);
    addElement(&set2, 3);
    addElement(&set2, 4);

    // Populate set3
    addElement(&set3, 5);
    addElement(&set3, 6);

    printf("Set 1: ");
    printSet(&set1);
    printf("Set 2: ");
    printSet(&set2);
    printf("Set 3: ");
    printSet(&set3);

    printf("Is Set 1 a subset of Set 2? %s\n", isSubset(&set1, &set2) ? "Yes" : "No");
    printf("Is Set 2 a subset of Set 1? %s\n", isSubset(&set2, &set1) ? "Yes" : "No");
    printf("Is Set 3 a subset of Set 2? %s\n", isSubset(&set3, &set2) ? "Yes" : "No");

    return 0;
}
