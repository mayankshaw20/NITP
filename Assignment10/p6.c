// // 6. Write a program in C to implement Open Addressing Linear Probing to handle
// collisions. Perform following tasks: (a) Insert Keys, (b) Search for a key, and (c)
// Delete a key.

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

typedef struct HashTable {
    int* table;
} HashTable;

HashTable* createHashTable() {
    HashTable* ht = malloc(sizeof(HashTable));
    ht->table = malloc(TABLE_SIZE * sizeof(int));
    for (int i = 0; i < TABLE_SIZE; i++) ht->table[i] = EMPTY;
    return ht;
}

int hash(int key) { return key % TABLE_SIZE; }

void insert(HashTable* ht, int key) {
    int index = hash(key);
    while (ht->table[index] != EMPTY) index = (index + 1) % TABLE_SIZE;
    ht->table[index] = key;
}

int search(HashTable* ht, int key) {
    int index = hash(key);
    while (ht->table[index] != EMPTY) {
        if (ht->table[index] == key) return index;
        index = (index + 1) % TABLE_SIZE;
    }
    return -1;
}

void deleteKey(HashTable* ht, int key) {
    int index = search(ht, key);
    if (index != -1) {
        ht->table[index] = DELETED;
        printf("Key %d deleted.\n", key);
    } else {
        printf("Key %d not found.\n", key);
    }
}

void displayHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        if (ht->table[i] == EMPTY) printf("EMPTY\n");
        else if (ht->table[i] == DELETED) printf("DELETED\n");
        else printf("%d\n", ht->table[i]);
    }
}

int main() {
    HashTable* ht = createHashTable(); int choice, key;
    while (1) {
        printf("\n1. Insert Key\n2. Search Key\n3. Delete Key\n4. Display Hash Table\n5. Exit\n");
        printf("Enter your choice: "); scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter key to insert: "); scanf("%d", &key); insert(ht, key); break;
            case 2: printf("Enter key to search: "); scanf("%d", &key); 
                    printf("Key %d %s.\n", key, search(ht, key) != -1 ? "found" : "not found"); break;
            case 3: printf("Enter key to delete: "); scanf("%d", &key); deleteKey(ht, key); break;
            case 4: displayHashTable(ht); break;
            case 5: free(ht->table); free(ht); return 0;
            default: printf("Invalid choice.\n");
        }
    }
}