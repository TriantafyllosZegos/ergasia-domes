#ifndef TABLE_H
#define TABLE_H

#include <string>
#include "../helpers/Pair.h"
#include "../helpers/CPair.h"
using namespace std;

class Table {
    public:
        CPair<string>* a;
    protected:
        
        unsigned int size;
        unsigned int cap;


    public:
        Table();
        ~Table();
        virtual void insert(const Pair<string>& p);
        unsigned int search(const Pair<string>& p);
        void checkResize();
        void print();
        unsigned int getSize();
        CPair<string> operator[](int x){
            return this->a[x];
        }
};

#endif