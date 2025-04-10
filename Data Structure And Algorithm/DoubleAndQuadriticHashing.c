#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define EMPTY -1

int* initHashTable(int size) {
    int* table = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        table[i] = EMPTY;
    }
    return table;
}


int hash1(int key) {
    return key % SIZE;
}


int hash2(int key) {
    return 7 - (key % 7);
}

void insertDoubleHash(int* table, int key) {
    int index = hash1(key);
    int step = hash2(key);

    if (table[index] == EMPTY) {
        table[index] = key;
        return;
    }

    for (int i = 1; i < SIZE; i++) {
        int newIndex = (index + i * step) % SIZE;
        if (table[newIndex] == EMPTY) {
            table[newIndex] = key;
            return;
        }
    }
    printf("Unable to insert %d - Hash table full!\n", key);
}

void insertQuadratic(int* table, int key) {
    int index = hash1(key);

    if (table[index] == EMPTY) {
        table[index] = key;
        return;
    }

    for (int i = 1; i < SIZE; i++) {
        int newIndex = (index + i * i) % SIZE;
        if (table[newIndex] == EMPTY) {
            table[newIndex] = key;
            return;
        }
    }
    printf("Unable to insert %d - Hash table full!\n", key);
}

void display(int* table) {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] != EMPTY) {
            printf("Index %d: %d\n", i, table[i]);
        } else {
            printf("Index %d: EMPTY\n", i);
        }
    }
    printf("\n");
}

int main() {
    int* doubleHash = initHashTable(SIZE);
    int* quadraticHash = initHashTable(SIZE);
    
    int n;
    printf("Enter the size of number\n");
    scanf("%d", &n);
    
    int values[n];  
    printf("Enter the data\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]); 
    }

    printf("\nDouble Hashing\n");
    for (int i = 0; i < n; i++) {
        insertDoubleHash(doubleHash, values[i]);
    }
    display(doubleHash);

    printf("Quadratic Probing\n");
    for (int i = 0; i < n; i++) {
        insertQuadratic(quadraticHash, values[i]);
    }
    display(quadraticHash);

    free(doubleHash);
    free(quadraticHash);
    
    return 0;
}
