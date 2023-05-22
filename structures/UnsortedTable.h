
#include <string>
using namespace std;

class UnsortedTable {
    private:
        pair<string,string>* ptr;


    public:
        UnsortedTable();
        void add(pair<string,string> pair);
};