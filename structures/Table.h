#ifndef TABLE_H
#define TABLE_H

#include <string>
#include "../helpers/Pair.h"
using namespace std;

class Table {
    public:
        Pair<string>* a;
    protected:
        
        unsigned long long int size;
        unsigned long long int cap;


    public:
        Table();
        //~Table();
        void insert(const Pair<string>& p);
        virtual int search(const Pair<string>& p);
        void print();
        unsigned long long int getSize();
        Pair<string> operator[](int x){
            return this->a[x];
        }
};

#endif