// 5. Write a program in C to implement Direct Chaining to handle collisions. Perform
// following tasks: (a) Insert Keys, (b) Search for a key, and (c) Delete a key.

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key; struct Node* next;
} Node;

typedef struct HashTable {
    Node* table[TABLE_SIZE];
} HashTable;

HashTable* createHashTable() {
    HashTable* ht = malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) ht->table[i] = NULL;
    return ht;
}

int hash(int key) { return key % TABLE_SIZE; }

void insert(HashTable* ht, int key) {
    Node* newNode = malloc(sizeof(Node));
    newNode->key = key; newNode->next = ht->table[hash(key)];
    ht->table[hash(key)] = newNode;
}

Node* search(HashTable* ht, int key) {
    for (Node* current = ht->table[hash(key)]; current; current = current->next)
        if (current->key == key) return current;
    return NULL;
}

void deleteKey(HashTable* ht, int key) {
    int index = hash(key); Node *current = ht->table[index], *prev = NULL;
    while (current) {
        if (current->key == key) {
            if (prev) prev->next = current->next;
            else ht->table[index] = current->next;
            free(current); printf("Key %d deleted.\n", key); return;
        }
        prev = current; current = current->next;
    }
    printf("Key %d not found.\n", key);
}

void displayHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        for (Node* current = ht->table[i]; current; current = current->next)
            printf("%d -> ", current->key);
        printf("NULL\n");
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
                    printf("Key %d %s.\n", key, search(ht, key) ? "found" : "not found"); break;
            case 3: printf("Enter key to delete: "); scanf("%d", &key); deleteKey(ht, key); break;
            case 4: displayHashTable(ht); break;
            case 5: free(ht); return 0;
            default: printf("Invalid choice.\n");
        }
    }
}