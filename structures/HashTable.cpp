#include "Hashtable.h"

using namespace std;

Hashtable::Hashtable(int size) {
    this->size = size;
    buckets = new Node*[size];
    for (int i = 0; i < size; i++) {
        buckets[i] = nullptr;
    }
}

Hashtable::~Hashtable() {
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

int Hashtable::hash(const Pair<string>& key) {
    int num1 = 0;
    int num2 = 0;
    int i = 1;

    for (char ch : key.first) {
        num1 = num1 + static_cast<int>(ch) * i;
        i *= 10;
    }

    i = 1;
    for (char ch : key.second) {
        num2 = num2 + static_cast<int>(ch) * i;
        i *= 10;
    }

    return (num1 * num2 + num1) % size;
}

void Hashtable::insert(const Pair<string>& key) {
    int index = hash(key);
    Node* newNode = new Node(key);
    newNode->next = buckets[index];
    buckets[index] = newNode;
}

int Hashtable::search(const Pair<string>& key) {
    int index = hash(key);
    Node* curr = buckets[index];
    int position = 0;
    while (curr != nullptr) {
        if (curr->data == key) {
            return position;
        }
        curr = curr->next;
        position++;
    }
    return -1;
}

void Hashtable::remove(const Pair<string>& key) {
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
