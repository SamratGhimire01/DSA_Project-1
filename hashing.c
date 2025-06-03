#include <stdio.h>
#define TABLE_SIZE 10  // Size of the hash table

int hashTable[TABLE_SIZE];  // Our hash table array

// Initialize the hash table with -1 to indicate empty slots
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;  // -1 means empty slot
    }
}

// Simple hash function: key mod table size
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert a key into the hash table using linear probing
void insert(int key) {
    int index = hashFunction(key);  // Get initial hash index
    int originalIndex = index;       // Remember original index to avoid infinite loop

    while (hashTable[index] != -1) { // While slot is not empty (collision)
        index = (index + 1) % TABLE_SIZE; // Move to next slot (wrap around)
        if (index == originalIndex) {      // If we circled back to start, table is full
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }

    hashTable[index] = key;  // Insert key in empty slot
    printf("Inserted %d at index %d\n", key, index);
}

// Search for a key in the hash table
int search(int key) {
    int index = hashFunction(key);  // Get initial index
    int originalIndex = index;

    while (hashTable[index] != -1) {   // While slot is not empty
        if (hashTable[index] == key)   // If key found, return index
            return index;

        index = (index + 1) % TABLE_SIZE;  // Check next slot
        if (index == originalIndex)         // If back to start, key not found
            break;
    }

    return -1;  // Key not found
}

int main() {
    initHashTable();  // Set all slots to empty

    // Insert some keys
    insert(5);
    insert(15);
    insert(25);

    int keyToFind = 15;
    int foundIndex = search(keyToFind);  // Search for key

    if (foundIndex != -1)
        printf("Key %d found at index %d\n", keyToFind, foundIndex);
    else
        printf("Key %d not found in the hash table\n", keyToFind);

    return 0;
}
