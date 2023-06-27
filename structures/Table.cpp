#include "Table.h"
#include "../helpers/Pair.h"
#include "../helpers/CPair.h"
#include <iostream>
#include <string>

using namespace std;

Table::Table()
{
    cap = 1024; // Set the initial capacity of the table to 1024
    size = 0; // Initialize the size of the table to 0
    a = new (nothrow) CPair<string>[cap](); // Dynamically allocate memory for the array of CPair objects
    if (a == NULL)
        cout << "TABLE MEMORY ERROR" << endl; // Display an error message if memory allocation fails
}

Table::~Table()
{
    delete[] a; // Deallocate the memory for the array
}

void Table::print()
{
    cout << "############## TABLE ##############" << endl;
    for (unsigned int i = 0; i < size; i++)
    {
        cout << a[i] << endl; // Print each CPair object in the array
    }
}

unsigned int Table::getSize()
{
    return size; // Return the current size of the table
}

unsigned int Table::search(const Pair<string> &p)
{
    for (unsigned int i = 0; i < size; i++)
    {
        if (a[i].first == p.first && a[i].second == p.second)
        {
            return a[i].count; // If a matching CPair object is found, return its count value
        }
    }
    return 0; // If no matching CPair object is found, return 0
}

void Table::checkResize()
{
    if (size == cap)
    {
        // If the array is full, increase its capacity
        this->cap *= 2; // Double the capacity of the table
        CPair<string> *newLines = new (nothrow) CPair<string>[cap](); // Create a new array with the updated capacity
        if (newLines == NULL)
            cout << "Table MEMORY ERROR || size : " << size << endl; // Display an error message if memory allocation fails

        // Copy the existing lines to the new array
        for (unsigned int i = 0; i < size; i++)
        {
            newLines[i] = a[i]; // Copy each CPair object from the old array to the new array
        }
        delete[] a; // Deallocate the memory for the old array
        a = newLines; // Update the pointer to point to the new array
    }
}

void Table::insert(const Pair<string> &p)
{
    for (unsigned int i = 0; i < size; i++)
    {
        if (a[i].first == p.first && a[i].second == p.second)
        {
            a[i].count++; // If a matching CPair object is found, increment its count value and return
            return;
        }
    }
    checkResize(); // Check if resizing of the array is needed
    // Store the new line at the end of the array
    a[size] = CPair(p.first, p.second); // Create a new CPair object with the given values and assign it to the next available position in the array
    size++; // Increment the size of the table
}
