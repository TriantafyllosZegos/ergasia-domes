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

#include "structures/Table.h"
#include "structures/SortedTable.h"
#include "structures/HashTable.h"

using namespace std;



int main()
{
    Pair<string> * arrayQ = generateQ();

    ofstream md("markdown.md",std::ios_base::app);
    md << "---" << endl;
    md.close();

    Pair<string> p = arrayQ[990];
    cout << p << endl;

 /*
    Table t;
    t = buildPairs(t);
    cout << "Table | " << p << " : " << t.search(p) << endl;

    SortedTable st = SortedTable(t);
    st = buildPairs(st);
    st.sort();
    cout << "SortedTable | " << p << " : " << st.search(p) << endl;
*/
/*
    BinaryTree bt;
    bt = buildPairs(bt);
    //cout << "BinaryTree | " << p << " : " << bt.search(p) << endl;
    bt.print();
*/
    Avl avl;
    avl = buildPairs(avl);
    //cout << "Avl | " << p << " : " << avl.search(p) << endl;
    avl.print();

    
    return 0;
}
