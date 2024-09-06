#pragma once
#include <stdio.h>

#define MAX_SIZE 100

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