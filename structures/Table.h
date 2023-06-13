#ifndef TABLE_H
#define TABLE_H

#include <string>
#include "../helpers/Pair.h"
using namespace std;

class Table {
    public:
        Pair<string>* a;
    protected:
        
        unsigned int size;
        unsigned int cap;


    public:
        Table();
        ~Table();
        void insert(const Pair<string>& p);
        unsigned int search(const Pair<string>& p);
        void print();
        unsigned int getSize();
        Pair<string> operator[](int x){
            return this->a[x];
        }
};

#endif