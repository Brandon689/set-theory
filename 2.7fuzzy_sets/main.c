#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100

typedef struct {
    float elements[MAX_ELEMENTS];
    float memberships[MAX_ELEMENTS];
    int size;
} FuzzySet;

void initFuzzySet(FuzzySet* fs) {
    fs->size = 0;
}

// Add an element to the fuzzy set with its membership degree
void addElement(FuzzySet* fs, float element, float membership) {
    if (fs->size < MAX_ELEMENTS && membership >= 0 && membership <= 1) {
        fs->elements[fs->size] = element;
        fs->memberships[fs->size] = membership;
        fs->size++;
    }
}

// Print the fuzzy set
void printFuzzySet(FuzzySet* fs) {
    printf("{");
    for (int i = 0; i < fs->size; i++) {
        printf("%.2f(%.2f)", fs->elements[i], fs->memberships[i]);
        if (i < fs->size - 1) printf(", ");
    }
    printf("}\n");
}

// Find the membership degree of an element
float getMembership(FuzzySet* fs, float element) {
    for (int i = 0; i < fs->size; i++) {
        if (fs->elements[i] == element) {
            return fs->memberships[i];
        }
    }
    return 0; // Element not found
}

// Perform union of two fuzzy sets (using max operator)
FuzzySet fuzzyUnion(FuzzySet* fs1, FuzzySet* fs2) {
    FuzzySet result;
    initFuzzySet(&result);

    // Add all elements from fs1
    for (int i = 0; i < fs1->size; i++) {
        addElement(&result, fs1->elements[i], fs1->memberships[i]);
    }

    // Add elements from fs2, taking max membership if element already exists
    for (int i = 0; i < fs2->size; i++) {
        float existingMembership = getMembership(&result, fs2->elements[i]);
        float newMembership = fs2->memberships[i] > existingMembership ?
            fs2->memberships[i] : existingMembership;
        addElement(&result, fs2->elements[i], newMembership);
    }

    return result;
}

// Perform intersection of two fuzzy sets (using min operator)
FuzzySet fuzzyIntersection(FuzzySet* fs1, FuzzySet* fs2) {
    FuzzySet result;
    initFuzzySet(&result);

    for (int i = 0; i < fs1->size; i++) {
        float membership2 = getMembership(fs2, fs1->elements[i]);
        if (membership2 > 0) {
            float minMembership = fs1->memberships[i] < membership2 ?
                fs1->memberships[i] : membership2;
            addElement(&result, fs1->elements[i], minMembership);
        }
    }

    return result;
}

int main() {
    FuzzySet youngAge, middleAge;
    initFuzzySet(&youngAge);
    initFuzzySet(&middleAge);

    // Define "young age" fuzzy set
    addElement(&youngAge, 20, 1.0);
    addElement(&youngAge, 30, 0.8);
    addElement(&youngAge, 40, 0.5);
    addElement(&youngAge, 50, 0.2);

    // Define "middle age" fuzzy set
    addElement(&middleAge, 30, 0.2);
    addElement(&middleAge, 40, 0.8);
    addElement(&middleAge, 50, 1.0);
    addElement(&middleAge, 60, 0.8);

    printf("Young Age: ");
    printFuzzySet(&youngAge);

    printf("Middle Age: ");
    printFuzzySet(&middleAge);

    FuzzySet unionSet = fuzzyUnion(&youngAge, &middleAge);
    printf("Union of Young and Middle Age: ");
    printFuzzySet(&unionSet);

    FuzzySet intersectionSet = fuzzyIntersection(&youngAge, &middleAge);
    printf("Intersection of Young and Middle Age: ");
    printFuzzySet(&intersectionSet);

    return 0;
}
