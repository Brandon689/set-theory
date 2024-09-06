#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int elements[MAX_SIZE];
    int size;
} Set;

void initSet(Set* s) {
    s->size = 0;
}

bool addElement(Set* s, int element) {
    if (s->size >= MAX_SIZE) return false;
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == element) return false;
    }
    s->elements[s->size++] = element;
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

// New function: Print Cartesian Product
void printCartesianProduct(Set* A, Set* B) {
    printf("Cartesian Product A × B:\n");
    printf("{");
    bool first = true;
    for (int i = 0; i < A->size; i++) {
        for (int j = 0; j < B->size; j++) {
            if (!first) printf(", ");
            printf("(%d, %d)", A->elements[i], B->elements[j]);
            first = false;
        }
    }
    printf("}\n");
}

int main() {
    Set A, B;
    initSet(&A);
    initSet(&B);

    // Populate set A
    addElement(&A, 1);
    addElement(&A, 2);

    // Populate set B
    addElement(&B, 3);
    addElement(&B, 4);
    addElement(&B, 5);

    printf("Set A: ");
    printSet(&A);
    printf("\n");

    printf("Set B: ");
    printSet(&B);
    printf("\n\n");

    printCartesianProduct(&A, &B);

    return 0;
}
