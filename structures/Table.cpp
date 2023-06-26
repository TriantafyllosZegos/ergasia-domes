#include "Table.h"
#include "../helpers/Pair.h"
#include "../helpers/CPair.h"
#include <iostream>
#include <string>
using namespace std;

Table::Table()
{
    this->cap = 1024;
    this->size = 0;
    a = new (nothrow) CPair<string>[cap]();
    if (a == NULL)
        cout << "TABLE MEMORY ERROR" << endl;
}
/*
Table::~Table()
{
    delete[] a;
}
*/
void Table::print()
{
    cout << "############## TABLE ##############" << endl;
    for (unsigned int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
}

unsigned int Table::getSize()
{
    return size;
}

unsigned int Table::search(const Pair<string> &p)
{
    for (unsigned int i = 0; i < size; i++)
    {
        if (a[i].first == p.first && a[i].second == p.second)
        {
            return a[i].count;
        }
    }
    return 0;
}

void Table::checkResize()
{
    if (size == cap)
    {
        // If the array is full, increase its capacity
        this->cap *= 2;
        //a = (CPair<string>*)realloc(a,cap*sizeof(CPair<string>));
        CPair<string> *newLines = new (nothrow) CPair<string>[cap]();
        if (newLines == NULL)
            cout << "Table MEMORY ERROR || size : " << size << endl;

        // Copy the existing lines to the new array
        for (unsigned int i = 0; i < size; i++)
        {
            newLines[i] = a[i];
        }
        // Delete the old array
        delete[] a;
        // Update the lines pointer to point to the new array
        a = newLines;
    }
}
void Table::insert(const Pair<string> &p)
{
    for (unsigned int i = 0; i < size; i++)
    {
        if (a[i].first == p.first && a[i].second == p.second)
        {
            a[i].count++;
            return;
        }
    }
    checkResize();
    // Store the new line
    a[size] = CPair(p.first,p.second);
    size++;
}