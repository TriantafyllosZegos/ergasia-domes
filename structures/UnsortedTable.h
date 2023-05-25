
#include <string>
using namespace std;

class UnsortedTable {
    private:
        pair<string,string> a[1000];


    public:
        int z = 0;
        UnsortedTable();
        void add(pair<string,string>p);
        void printFirst();
        pair<string,string>* get();
        void print();
};