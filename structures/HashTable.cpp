#include "Hashtable.h"

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
    unsigned long long int num1 = 0;
    unsigned long long int num2 = 0;
    unsigned long long int i = 1;

    for (char ch : key.first) {
        num1 = num1 + static_cast<int>(ch) * i;
        i *= 10;
    }

    i = 1;
    for (char ch : key.second) {
        num2 = num2 + static_cast<int>(ch) * i;
        i *= 10;
    }
    return (num1 + num2 ) % size;
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

    Node* newNode = new Node(key);
    newNode->next = buckets[index];
    buckets[index] = newNode;


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
