// 8. Write a program in C to implement Open Addressing Double Hashing to handle
// collisions. Perform following tasks: (a) Insert Keys, (b) Search for a key, and (c)
// // Delete a key.\

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11
#define DELETED -1

typedef struct {
    int *table;
    int size;
} HashTable;

int hash1(int key) { return key % TABLE_SIZE; }
int hash2(int key) { return 1 + (key % (TABLE_SIZE - 1)); }

HashTable* createHashTable() {
    HashTable *ht = malloc(sizeof(HashTable));
    ht->size = TABLE_SIZE;
    ht->table = malloc(TABLE_SIZE * sizeof(int));
    for (int i = 0; i < TABLE_SIZE; i++) ht->table[i] = -1;
    return ht;
}

void insert(HashTable *ht, int key) {
    int index = hash1(key), step = hash2(key), i = 0;
    while (ht->table[(index + i * step) % TABLE_SIZE] != -1) {
        if (ht->table[(index + i * step) % TABLE_SIZE] == key) return;
        i++;
        if (i >= TABLE_SIZE) return;
    }
    ht->table[(index + i * step) % TABLE_SIZE] = key;
}

int search(HashTable *ht, int key) {
    int index = hash1(key), step = hash2(key), i = 0;
    while (ht->table[(index + i * step) % TABLE_SIZE] != -1) {
        if (ht->table[(index + i * step) % TABLE_SIZE] == key) return (index + i * step) % TABLE_SIZE;
        i++;
        if (i >= TABLE_SIZE) break;
    }
    return -1;
}

void deleteKey(HashTable *ht, int key) {
    int index = search(ht, key);
    if (index != -1) ht->table[index] = DELETED;
}

void display(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] == -1) printf("[%d]: -\n", i);
        else if (ht->table[i] == DELETED) printf("[%d]: DELETED\n", i);
        else printf("[%d]: %d\n", i, ht->table[i]);
    }
}

int main() {
    HashTable *ht = createHashTable();
    int keys[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) insert(ht, keys[i]);
    display(ht);
    
    printf("Key 15 %sfound.\n", search(ht, 15) != -1 ? "" : "not ");
    deleteKey(ht, 22);
    display(ht);
    
    free(ht->table);
    free(ht);
    return 0;
}