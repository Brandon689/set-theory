#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int element;
    int count;
} MultisetElement;

typedef struct {
    MultisetElement elements[MAX_SIZE];
    int size;
} Multiset;

void initMultiset(Multiset* ms) {
    ms->size = 0;
}

// Add an element to the multiset or increase its count if it already exists
void addElement(Multiset* ms, int element) {
    for (int i = 0; i < ms->size; i++) {
        if (ms->elements[i].element == element) {
            ms->elements[i].count++;
            return;
        }
    }
    if (ms->size < MAX_SIZE) {
        ms->elements[ms->size].element = element;
        ms->elements[ms->size].count = 1;
        ms->size++;
    }
}

// Remove one instance of an element from the multiset
void removeElement(Multiset* ms, int element) {
    for (int i = 0; i < ms->size; i++) {
        if (ms->elements[i].element == element) {
            ms->elements[i].count--;
            if (ms->elements[i].count == 0) {
                // Remove the element entirely if count reaches 0
                for (int j = i; j < ms->size - 1; j++) {
                    ms->elements[j] = ms->elements[j + 1];
                }
                ms->size--;
            }
            return;
        }
    }
}

// Get the count of an element in the multiset
int getCount(Multiset* ms, int element) {
    for (int i = 0; i < ms->size; i++) {
        if (ms->elements[i].element == element) {
            return ms->elements[i].count;
        }
    }
    return 0;
}

void printMultiset(Multiset* ms) {
    printf("{");
    for (int i = 0; i < ms->size; i++) {
        printf("%d(%d)", ms->elements[i].element, ms->elements[i].count);
        if (i < ms->size - 1) printf(", ");
    }
    printf("}\n");
}

int main() {
    Multiset ms;
    initMultiset(&ms);

    addElement(&ms, 1);
    addElement(&ms, 2);
    addElement(&ms, 2);
    addElement(&ms, 3);
    addElement(&ms, 3);
    addElement(&ms, 3);

    printf("Multiset: ");
    printMultiset(&ms);

    printf("Count of 2: %d\n", getCount(&ms, 2));
    printf("Count of 3: %d\n", getCount(&ms, 3));

    removeElement(&ms, 2);
    removeElement(&ms, 3);

    printf("After removing one 2 and one 3: ");
    printMultiset(&ms);

    return 0;
}
