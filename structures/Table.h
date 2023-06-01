#ifndef TABLE_H
#define TABLE_H

#include <string>
#include "../helpers/Pair.h"
using namespace std;

class Table {
    public:
        Pair<string>* a;
    protected:
        
        long int size;
        long int cap;


    public:
        Table();
        //~Table();
        void insert(Pair<string>& p);
        virtual int search(Pair<string>& p);
        void print();
        int getSize();
};

#endif