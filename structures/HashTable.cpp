#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    this->cap = 1024;
    a = new (nothrow) HashItem[cap]();
    if (a == NULL)
        cout << "HASHTABLE MEMORY ERROR" << endl;
    for (unsigned long i = 0; i < cap; i++)
    {
        a[i] = HashItem();
    }
    numElements = 0;
}
/*
HashTable::~HashTable()
{
    delete[] a;
}
*/
unsigned long HashTable::hash(const Pair<string> &key)
{
    const unsigned long p1 = 31;
    const unsigned long p2 = 37;
    const unsigned long m1 = 1e9 + 9;
    const unsigned long m2 = 1e9 + 7;
   

    unsigned long hash1 = 0;
    unsigned long hash2 = 0;

    // Compute the hash value for the first string in the pair
    for (char ch : key.first)
    {
        hash1 = (hash1 * p1 + (ch - 'a' + 1)) % m1;
        hash2 = (hash2 * p2 + (ch - 'a' + 1)) % m2;
    }

    // Combine the hash values with the second string in the pair
    for (char ch : key.second)
    {
        hash1 = (hash1 * p1 + (ch - 'a' + 1)) % m1;
        hash2 = (hash2 * p2 + (ch - 'a' + 1)) % m2;
    }

    // Combine the hash values using a simple addition
    unsigned long hashValue = (hash1 + hash2) % cap;

    return hashValue;
}


void HashTable::insert(const Pair<string> &key)
{
    unsigned long index = hash(key);
    //unsigned long originalIndex = index;
    double loadFactor = static_cast<double>(numElements) / cap; // Calculate load factor
    
    while (a[index].value != 0)
    {
        if (a[index].key == key)
        {
            a[index].value++;
            return;
        }

        index = (index + 1) % cap;

        if (loadFactor > 0.7) // Adjust the threshold as needed
        {
            resize();
            return insert(key);
        }
    }

    a[index] = HashItem(key);
    numElements++; // Increase the count of elements stored
}

void HashTable::resize()
{
   
    this->cap *= 2;
    HashItem *temp = new (nothrow) HashItem[cap]();

    for (unsigned long i = 0; i < cap; i++)
    {
        temp[i] = HashItem();
    }

    for (unsigned long i = 0; i < cap / 2; i++)
    {
        unsigned long  index = hash(a[i].key);
        unsigned long  originalIndex = index;
        while (temp[index].value != 0)
        {
            if (temp[index].key == a[i].key)
            {
                temp[index].value++;
                break;
            }
            index = (index + 1) % cap;
            if (index == originalIndex)
            {
                cout << " error " << endl;
                return ;
            }
        }
        temp[index] = HashItem(a[i].key);
    }

    delete[] a;
    this->a = temp;
}

int HashTable::search(const Pair<string> &key)
{
    unsigned long index = hash(key);
    unsigned long originalIndex = index;
    while (a[index].value != 0)
    {
        if (a[index].key == key)
        {
            return a[index].value;
        }
        index = (index + 1) % cap;
        if (index == originalIndex)
        {
            // Reached back to the original index, indicating the key was not found
            return 0;
        }
    }
    return 0;
}
/*
void HashTable::remove(const Pair<string>& key) {
    int index = hash(key);
    int originalIndex = index;
    while (a[index].value != 0) {
        if (a[index].key == key) {
            delete a[index];
            a[index] = nullptr;
// Rehash and reinsert any elements that were previously probed from this position
            index = (index + 1) % cap;
            while (a[index] != nullptr) {
                HashItem * nodeToRehash = a[index];
                a[index] = nullptr;
                insert(nodeToRehash->key);
                delete nodeToRehash;
                index = (index + 1) % cap;
            }
            return;
        }
        index = (index + 1) % cap;
        if (index == originalIndex) {
// Reached back to the original index, indicating the key was not found
            return;
        }
    }
}*/
