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
    const int NUMBER_OF_SEARCH = 1000;

    ofstream md("markdown.md",std::ios_base::app);
    md << "---" << endl;
    md.close();

    chrono::system_clock::time_point start,end;
    double time;

/*
    Table * t = new Table();
    runStructure(t,NUMBER_OF_SEARCH);
    //delete t;
    
    
    SortedTable * st = new SortedTable();
    runStructure(st,NUMBER_OF_SEARCH);
    //delete st;

*/
    HashTable * ht = new HashTable();
    runStructure(ht,NUMBER_OF_SEARCH);
    //delete ht;

    BinaryTree * bt = new BinaryTree();
    runStructure(bt,NUMBER_OF_SEARCH);
    //delete bt;


    Avl * avl = new Avl();
    runStructure(avl,NUMBER_OF_SEARCH);
    //delete avl;

    return 0;
}
