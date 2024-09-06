#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define MAX_PARTITIONS 10

typedef struct {
    int elements[MAX_SIZE];
    int size;
} Set;

typedef struct {
    Set subsets[MAX_PARTITIONS];
    int count;
} Partition;

void initSet(Set* s) {
    s->size = 0;
}

void addElement(Set* s, int element) {
    if (s->size < MAX_SIZE) {
        s->elements[s->size++] = element;
    }
}

void initPartition(Partition* p) {
    p->count = 0;
}

// Add a new subset to the partition
void addSubset(Partition* p, Set* subset) {
    if (p->count < MAX_PARTITIONS) {
        p->subsets[p->count] = *subset;
        p->count++;
    }
}

// Check if the partition is valid
bool isValidPartition(Set* originalSet, Partition* p) {
    bool* found = (bool*)calloc(originalSet->size, sizeof(bool));

    // Check if each element is in exactly one subset
    for (int i = 0; i < p->count; i++) {
        for (int j = 0; j < p->subsets[i].size; j++) {
            int element = p->subsets[i].elements[j];
            for (int k = 0; k < originalSet->size; k++) {
                if (originalSet->elements[k] == element) {
                    if (found[k]) {
                        free(found);
                        return false; // Element found in multiple subsets
                    }
                    found[k] = true;
                    break;
                }
            }
        }
    }

    // Check if all elements are in some subset
    for (int i = 0; i < originalSet->size; i++) {
        if (!found[i]) {
            free(found);
            return false; // Element not found in any subset
        }
    }

    free(found);
    return true;
}

void printSet(Set* s) {
    printf("{");
    for (int i = 0; i < s->size; i++) {
        printf("%d", s->elements[i]);
        if (i < s->size - 1) printf(", ");
    }
    printf("}");
}

void printPartition(Partition* p) {
    printf("{\n");
    for (int i = 0; i < p->count; i++) {
        printf("  ");
        printSet(&p->subsets[i]);
        printf("\n");
    }
    printf("}\n");
}

int main() {
    Set originalSet;
    initSet(&originalSet);
    addElement(&originalSet, 1);
    addElement(&originalSet, 2);
    addElement(&originalSet, 3);
    addElement(&originalSet, 4);

    Partition partition;
    initPartition(&partition);

    // Create subsets for the partition
    Set subset1, subset2;
    initSet(&subset1);
    initSet(&subset2);

    addElement(&subset1, 1);
    addElement(&subset1, 2);
    addElement(&subset2, 3);
    addElement(&subset2, 4);

    addSubset(&partition, &subset1);
    addSubset(&partition, &subset2);

    printf("Original Set: ");
    printSet(&originalSet);
    printf("\n\nPartition:\n");
    printPartition(&partition);

    if (isValidPartition(&originalSet, &partition)) {
        printf("This is a valid partition.\n");
    }
    else {
        printf("This is not a valid partition.\n");
    }

    // Try an invalid partition
    Set subset3;
    initSet(&subset3);
    addElement(&subset3, 2);  // 2 is already in subset1
    addSubset(&partition, &subset3);

    printf("\nModified Partition:\n");
    printPartition(&partition);

    if (isValidPartition(&originalSet, &partition)) {
        printf("This is a valid partition.\n");
    }
    else {
        printf("This is not a valid partition.\n");
    }

    return 0;
}
