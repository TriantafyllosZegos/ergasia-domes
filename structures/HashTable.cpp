#include "HashTable.h"

using namespace std;

HashTable::HashTable(unsigned long long int size) {
    this->size = size;
    buckets = new Node*[size];
    for (int i = 0; i < size; i++) {
        buckets[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < size; i++) {
        Node* curr = buckets[i];
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    delete[] buckets;
}

unsigned long long int HashTable::hash(const Pair<string>& key) {
    const int prime = 31;
    int hashValue = 0;

    // Compute the hash value for the first string in the pair
    for (char ch : key.first) {
        hashValue = (hashValue * prime) + ch;
    }

    // Combine the hash value with the second string in the pair
    for (char ch : key.second) {
        hashValue = (hashValue * prime) + ch;
    }

    // Ensure the hash value is non-negative and within the range of the hash table
    hashValue = hashValue % size;
    if (hashValue < 0) {
        hashValue += size;
    }
    return hashValue;
}

void HashTable::insert(const Pair<string>& key) {
    int index = hash(key);
    int originalIndex = index;
    while (buckets[index] != nullptr) {
        if (buckets[index]->data == key) {
            buckets[index]->count++;
            return;
        }
        index = (index + 1) % size;
        if (index == originalIndex) {
            // Reached back to the original index, indicating the hash table is full
            // You may want to handle this case accordingly, e.g., by resizing the hash table
            return;
        }
    }
    buckets[index] = new Node(key);
}

int HashTable::search(const Pair<string>& key) {
    int index = hash(key);
    int originalIndex = index;
    while (buckets[index] != nullptr) {
        if (buckets[index]->data == key) {
            return buckets[index]->count;
        }
        index = (index + 1) % size;
        if (index == originalIndex) {
            // Reached back to the original index, indicating the key was not found
            return 0;
        }
    }
    return 0;
}

void HashTable::remove(const Pair<string>& key) {
    int index = hash(key);
    int originalIndex = index;
    while (buckets[index] != nullptr) {
        if (buckets[index]->data == key) {
            delete buckets[index];
            buckets[index] = nullptr;
// Rehash and reinsert any elements that were previously probed from this position
            index = (index + 1) % size;
            while (buckets[index] != nullptr) {
                Node* nodeToRehash = buckets[index];
                buckets[index] = nullptr;
                insert(nodeToRehash->data);
                delete nodeToRehash;
                index = (index + 1) % size;
            }
            return;
        }
        index = (index + 1) % size;
        if (index == originalIndex) {
// Reached back to the original index, indicating the key was not found
            return;
        }
    }
}
