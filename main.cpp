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

    Pair<string> p = arrayQ[0];
    Pair<string> p1("hi","bye");
    Pair<string> p2("hi2","by2e");
    Pair<string> p3("h3i","b3ye");
    Pair<string> p4("h4i","by4e");
    Pair<string> p5("h5i","b5ye");
    cout << p << endl;

 
    //Table t;
    //t = buildPairs(t);
    //cout << "Table | " << p << " : " << t.search(p) << endl;
 
    HashTable ht(4000);
    //ht = buildPairs(ht);
    ht.insert(p1);
    ht.insert(p2);
    ht.insert(p3);
    ht.insert(p4);
    ht.insert(p5);
    cout << "HashTable | " << p4 << " : " << ht.search(p4) << endl;
/*
    SortedTable st = SortedTable(t);
    st = buildPairs(st);
    st.sort();
    cout << "SortedTable | " << p << " : " << st.search(p) << endl;

    BinaryTree bt;
    bt = buildPairs(bt);
    cout << "BinaryTree | " << p << " : " << bt.search(p) << endl;

    Avl avl;
    avl = buildPairs(avl);
    cout << "Avl | " << p << " : " << avl.search(p) << endl;
*/
    
    return 0;
}
