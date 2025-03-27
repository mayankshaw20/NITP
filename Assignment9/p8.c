// 8. Write a program in C to implement create a hash table to store integer keys using
// modulo hashing.
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct HashNode {
    int key;
    struct HashNode* next;
};

struct HashTable {
    struct HashNode* table[TABLE_SIZE];
};

struct HashTable* createHashTable() {
    struct HashTable* ht = malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) ht->table[i] = NULL;
    return ht;
}

int hash(int key) { return key % TABLE_SIZE; }

void insert(struct HashTable* ht, int key) {
    struct HashNode* newNode = malloc(sizeof(struct HashNode));
    newNode->key = key;
    newNode->next = ht->table[hash(key)];
    ht->table[hash(key)] = newNode;
}

void display(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        for (struct HashNode* node = ht->table[i]; node; node = node->next)
            printf("%d -> ", node->key);
        printf("NULL\n");
    }
}

void freeHashTable(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct HashNode* node = ht->table[i];
        while (node) {
            struct HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(ht);
}

int main() {
    struct HashTable* ht = createHashTable();
    insert(ht, 10); insert(ht, 20); insert(ht, 30); insert(ht, 25); 
    insert(ht, 5);insert(ht,56);insert(ht,57);
    insert(ht,32);insert(ht,88);insert(ht,194);insert(ht,163);
    display(ht);
    freeHashTable(ht);
    return 0;
}