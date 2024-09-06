#include <stdio.h>
#include <stdbool.h>
#include "../Project1/sets.h"

#define UNIVERSAL_SET_SIZE 10  // Defining a small universal set for simplicity


bool contains(Set* s, int element) {
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == element) return true;
    }
    return false;
}

Set setUnion(Set* s1, Set* s2) {
    Set result;
    initSet(&result);
    for (int i = 0; i < s1->size; i++) {
        addElement(&result, s1->elements[i]);
    }
    for (int i = 0; i < s2->size; i++) {
        addElement(&result, s2->elements[i]);
    }
    return result;
}

Set setIntersection(Set* s1, Set* s2) {
    Set result;
    initSet(&result);
    for (int i = 0; i < s1->size; i++) {
        if (contains(s2, s1->elements[i])) {
            addElement(&result, s1->elements[i]);
        }
    }
    return result;
}

Set setComplement(Set* s, Set* universal) {
    Set result;
    initSet(&result);
    for (int i = 0; i < universal->size; i++) {
        if (!contains(s, universal->elements[i])) {
            addElement(&result, universal->elements[i]);
        }
    }
    return result;
}

bool areSetsEqual(Set* s1, Set* s2) {
    if (s1->size != s2->size) return false;
    for (int i = 0; i < s1->size; i++) {
        if (!contains(s2, s1->elements[i])) return false;
    }
    return true;
}

int main() {
    Set U, A, B;
    initSet(&U);
    initSet(&A);
    initSet(&B);

    // Define universal set
    for (int i = 1; i <= UNIVERSAL_SET_SIZE; i++) {
        addElement(&U, i);
    }

    // Populate sets
    addElement(&A, 1);
    addElement(&A, 2);
    addElement(&A, 3);
    addElement(&A, 4);

    addElement(&B, 3);
    addElement(&B, 4);
    addElement(&B, 5);
    addElement(&B, 6);

    printf("Universal Set U: ");
    printSet(&U);
    printf("\n");

    printf("Set A: ");
    printSet(&A);
    printf("\n");

    printf("Set B: ");
    printSet(&B);
    printf("\n\n");

    // Demonstrate first De Morgan's Law: (A ∪ B)' = A' ∩ B'
    Set unionAB = setUnion(&A, &B);
    Set complementUnionAB = setComplement(&unionAB, &U);
    Set complementA = setComplement(&A, &U);
    Set complementB = setComplement(&B, &U);
    Set intersectionComplementAB = setIntersection(&complementA, &complementB);

    printf("(A ∪ B)': ");
    printSet(&complementUnionAB);
    printf("\n");

    printf("A' ∩ B': ");
    printSet(&intersectionComplementAB);
    printf("\n");

    printf("(A ∪ B)' = A' ∩ B': %s\n\n", areSetsEqual(&complementUnionAB, &intersectionComplementAB) ? "True" : "False");

    // Demonstrate second De Morgan's Law: (A ∩ B)' = A' ∪ B'
    Set intersectionAB = setIntersection(&A, &B);
    Set complementIntersectionAB = setComplement(&intersectionAB, &U);
    Set unionComplementAB = setUnion(&complementA, &complementB);

    printf("(A ∩ B)': ");
    printSet(&complementIntersectionAB);
    printf("\n");

    printf("A' ∪ B': ");
    printSet(&unionComplementAB);
    printf("\n");

    printf("(A ∩ B)' = A' ∪ B': %s\n", areSetsEqual(&complementIntersectionAB, &unionComplementAB) ? "True" : "False");

    return 0;
}
