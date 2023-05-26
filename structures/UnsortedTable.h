
#include <string>
#include "../helpers/Pair.h"
using namespace std;

class UnsortedTable {
    private:
        Pair<string> a[1000];
        int z;


    public:
        UnsortedTable();
        void add(Pair<string> p);
        Pair<string>* get();
        void print();
};