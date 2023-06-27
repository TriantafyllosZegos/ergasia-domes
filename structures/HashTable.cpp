#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    // Initialize the capacity of the hash table to 1024
    this->cap = 1024;

    // Allocate memory for the hash table array
    a = new (nothrow) HashItem[cap]();

    // Check if memory allocation was successful
    if (a == NULL)
        cout << "HASHTABLE MEMORY ERROR" << endl;

    // Initialize each element in the hash table array to an empty HashItem
    for (unsigned long i = 0; i < cap; i++)
    {
        a[i] = HashItem();
    }

    // Initialize the number of elements in the hash table to 0
    this->numElements = 0;
}

HashTable::~HashTable()
{
    
    delete[] a;
}

unsigned long HashTable::getSize(){
    return numElements;
}

unsigned long HashTable::hash(const Pair<string> &key)
{
    // Constants used for hashing
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

    // Compute and combine the hash values with the second string in the pair
    for (char ch : key.second)
    {
        hash1 = (hash1 * p1 + (ch - 'a' + 1)) % m1;
        hash2 = (hash2 * p2 + (ch - 'a' + 1)) % m2;
    }

    // Combine the hash values using a simple addition and apply modulo to fit within the hash table size
    unsigned long hashValue = (hash1 + hash2) % cap;

    return hashValue;
}

void HashTable::insert(const Pair<string> &key)
{
    // Calculate the load factor
    double loadFactor = static_cast<double>(numElements) / cap;

    // Compute the initial index for insertion
    unsigned long index = hash(key);

    // Linear probing until an empty slot is found
    while (a[index].value != 0)
    {
        // If the key already exists, increment its value and return
        if (a[index].key == key)
        {
            a[index].value++;
            return;
        }

        // Move to the next index using linear probing
        index = (index + 1) % cap;

        // Check if the load factor exceeds the threshold of 0.7
        if (loadFactor > 0.7)
        {
            // Resize the hash table and rehash the elements
            resize();
            return insert(key);
        }
    }

    // Else insert the key-value pair at the determined index 
    a[index] = HashItem(key);
    numElements++; // Increase the count of elements stored in the hash table
}

void HashTable::resize()
{
    // Double the capacity of the hash table
    this->cap *= 2;

    // Create a new temporary hash table array with the doubled capacity
    HashItem *temp = new (nothrow) HashItem[cap]();

    // Initialize each element in the new hash table array to an empty HashItem
    for (unsigned long i = 0; i < cap; i++)
    {
        temp[i] = HashItem();
    }

    // Rehash the elements from the original hash table to the new hash table
    for (unsigned long i = 0; i < cap / 2; i++) {
        if (a[i].value > 0) {
            // Compute the new index using a hash function based on the new capacity
            unsigned long index = hash(a[i].key);

            // Linear probing until an empty slot is found in the new hash table
            while (temp[index].value != 0) {
                index = (index + 1) % cap;
            }

            // Insert the element at the new index in the new hash table
            temp[index].key = a[i].key;
            temp[index].value = a[i].value;
        }
    }


    // Deallocate the memory used by the original hash table array
    delete[] a;

    // Update the hash table array to point to the new hash table array
    this->a = temp;
}


int HashTable::search(const Pair<string> &key)
{
    // Compute the initial index for search
    unsigned long index = hash(key);
    unsigned long originalIndex = index;

    // Linear probing until the key is found or an empty slot is encountered
    while (a[index].value != 0)
    {
        // If the key is found, return its value
        if (a[index].key == key)
        {
            return a[index].value;
        }

        // Move to the next index using linear probing
        index = (index + 1) % cap;

        // Check if we have reached back to the original index, indicating that the key was not found
        if (index == originalIndex)
        {
            // Reached back to the original index, indicating the key was not found
            return 0;
        }
    }

    // Key not found
    return 0;
}
