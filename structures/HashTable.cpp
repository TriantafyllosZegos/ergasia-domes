#include "HashTable.h"

using namespace std;

HashTable::HashTable(int size) {
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

int HashTable::hash(const Pair<string>& key) {
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
    cout << "Hash value: " << hashValue << endl;
    return hashValue;
}

void HashTable::insert(const Pair<string>& key) {
    int index = hash(key);
    Node* curr = buckets[index];
    while(curr != nullptr) {
        if (curr->data == key){
            curr->count++;
            return;
        }
        curr = curr->next;
    }
    curr = new Node(key);

    /*Node* newNode = new Node(key);
    newNode->next = buckets[index];
    buckets[index] = newNode;*/

    
}

int HashTable::search(const Pair<string>& key) {
    int index = hash(key);
    Node* curr = buckets[index];
    while (curr != nullptr) {
        if (curr->data == key) {
            return curr->count;
        }
        curr = curr->next;
        
    }
    return 0;
}

void HashTable::remove(const Pair<string>& key) {
    int index = hash(key);
    Node* curr = buckets[index];
    Node* prev = nullptr;
    while (curr != nullptr) {
        if (curr->data == key) {
            if (prev == nullptr) {
                buckets[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
