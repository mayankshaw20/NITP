// 7. Write a program in C to implement Open Addressing Quadratic Probing to handle
// collisions. Perform following tasks: (a) Insert Keys, (b) Search for a key, and (c)
// Delete a key

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11
#define DELETED -1

typedef struct {
    int *table;
    int size;
} HashTable;

int hash(int key, int size) {
    return key % size;
}

HashTable* createHashTable(int size) {
    HashTable *ht = malloc(sizeof(HashTable));
    ht->size = size;
    ht->table = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) ht->table[i] = -1;
    return ht;
}

void insert(HashTable *ht, int key) {
    int index = hash(key, ht->size), i = 0;
    while (ht->table[(index + i * i) % ht->size] != -1) {
        if (ht->table[(index + i * i) % ht->size] == key) return;
        i++;
        if (i >= ht->size) return;
    }
    ht->table[(index + i * i) % ht->size] = key;
}

int search(HashTable *ht, int key) {
    int index = hash(key, ht->size), i = 0;
    while (ht->table[(index + i * i) % ht->size] != -1) {
        if (ht->table[(index + i * i) % ht->size] == key) return (index + i * i) % ht->size;
        i++;
        if (i >= ht->size) break;
    }
    return -1;
}

void deleteKey(HashTable *ht, int key) {
    int index = search(ht, key);
    if (index != -1) ht->table[index] = DELETED;
}

void display(HashTable *ht) {
    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i] == -1) printf("[%d]: -\n", i);
        else if (ht->table[i] == DELETED) printf("[%d]: DELETED\n", i);
        else printf("[%d]: %d\n", i, ht->table[i]);
    }
}

int main() {
    HashTable *ht = createHashTable(TABLE_SIZE);
    int keys[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) insert(ht, keys[i]);
    display(ht);
    
    int keyToSearch = 15;
    printf("Key %d %sfound.\n", keyToSearch, search(ht, keyToSearch) != -1 ? "" : "not ");
    
    deleteKey(ht, 22);
    display(ht);
    
    free(ht->table);
    free(ht);
    return 0;
}