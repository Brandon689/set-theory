#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "../Project1/sets.h"



// New function: Generate and print power set
void printPowerSet(Set* s) {
    unsigned int powerSetSize = pow(2, s->size);

    printf("Power Set:\n");
    for (unsigned int i = 0; i < powerSetSize; i++) {
        printf("{");
        bool first = true;
        for (int j = 0; j < s->size; j++) {
            if (i & (1 << j)) {
                if (!first) printf(", ");
                printf("%d", s->elements[j]);
                first = false;
            }
        }
        printf("}\n");
    }
}

int main() {
    Set set;
    initSet(&set);

    // Populate set
    addElement(&set, 1);
    addElement(&set, 2);
    addElement(&set, 3);

    printf("Original Set: ");
    printSet(&set);
    printf("\n\n");

    printPowerSet(&set);

    return 0;
}
