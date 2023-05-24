
#include <string>
using namespace std;

class UnsortedTable {
    private:
        pair<string,string> a[10000];


    public:
        int z;
        UnsortedTable();
        void add(pair<string,string> pair);
        void print();
};