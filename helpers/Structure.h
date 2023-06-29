#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <iostream>
#include <utility>
#include "Pair.h"

// Interface for Structure

class Structure
{
public:
    virtual void insert(const Pair<string> &value){return;};
    virtual unsigned int search(const Pair<string>& p){return 0;};
    virtual void print(){return;};
};

#endif