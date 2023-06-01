#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <thread>
#include <future>
#include <typeinfo>
#include "helpers/Pair.h"
#include "helpers/IOHandler.h"

#include "structures/Avl.h"
#include "structures/BinaryTree.h"
#include "structures/SortedTable.h"
#include "structures/Table.h"

using namespace std;



int main()
{
    Pair<string> * arrayQ = generateQ();

    ofstream md("markdown.md",std::ios_base::app);
    md << "---" << endl;
    md.close();

   
    Table t;
    t = buildPairs(t);
    cout << t.search(arrayQ[50]) << endl;

    SortedTable st = SortedTable(t);
    st = buildPairs(st);
    st.sort();
    cout << st.search(arrayQ[50]) << endl;

    BinaryTree bt;
    bt = buildCPairs(bt);
    //cout << bt.search(arrayQ[50]) << endl;

    Avl avl;
    avl = buildCPairs(avl);
    //cout << avl.search(arrayQ[50]) << endl;

    
    return 0;
}
