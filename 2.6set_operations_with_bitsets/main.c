#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_ELEMENTS 64  // Using 64 as it's the number of bits in unsigned long long
typedef unsigned long long bitset;

// Function to add an element to the set
void addElement(bitset* set, int element) {
    *set |= (1ULL << element);
}

// Function to remove an element from the set
void removeElement(bitset* set, int element) {
    *set &= ~(1ULL << element);
}

// Function to check if an element is in the set
int containsElement(bitset set, int element) {
    return (set & (1ULL << element)) != 0;
}

// Function to perform union of two sets
bitset setUnion(bitset set1, bitset set2) {
    return set1 | set2;
}

// Function to perform intersection of two sets
bitset setIntersection(bitset set1, bitset set2) {
    return set1 & set2;
}

// Function to perform difference of two sets (set1 - set2)
bitset setDifference(bitset set1, bitset set2) {
    return set1 & (~set2);
}

// Function to print a set
void printSet(bitset set) {
    printf("{");
    int first = 1;
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (containsElement(set, i)) {
            if (!first) printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("}\n");
}

int main() {
    bitset set1 = 0, set2 = 0;

    // Populate set1
    addElement(&set1, 1);
    addElement(&set1, 3);
    addElement(&set1, 5);

    // Populate set2
    addElement(&set2, 3);
    addElement(&set2, 4);
    addElement(&set2, 5);

    printf("Set 1: ");
    printSet(set1);

    printf("Set 2: ");
    printSet(set2);

    printf("Union: ");
    printSet(setUnion(set1, set2));

    printf("Intersection: ");
    printSet(setIntersection(set1, set2));

    printf("Difference (Set1 - Set2): ");
    printSet(setDifference(set1, set2));

    // Demonstrate element removal
    removeElement(&set1, 3);
    printf("Set 1 after removing 3: ");
    printSet(set1);

    return 0;
}
