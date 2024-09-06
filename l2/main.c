#include <stdio.h>
#include <stdbool.h>
#include "../Project1/sets.h"


// New function: Set Intersection
Set setIntersection(Set* s1, Set* s2) {
    Set result;
    initSet(&result);
    for (int i = 0; i < s1->size; i++) {
        for (int j = 0; j < s2->size; j++) {
            if (s1->elements[i] == s2->elements[j]) {
                addElement(&result, s1->elements[i]);
                break;
            }
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
    addElement(&set2, 6);

    printf("Set 1: ");
    printSet(&set1);
    printf("Set 2: ");
    printSet(&set2);

    Set intersection = setIntersection(&set1, &set2);
    printf("Intersection: ");
    printSet(&intersection);

    return 0;
}
