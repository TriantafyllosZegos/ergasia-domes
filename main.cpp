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



    Table * t = new Table();
    buildPairs(t); 
    cout << endl << "Table SEARCH" << endl;
    for (int i = 0;i<NUMBER_OF_SEARCH;i++){
        cout << "Table       | " << arrayQ[i] << " : " << t->search(arrayQ[i]) << endl;
    }
    

    SortedTable * st = new SortedTable(t);
    buildPairs(st);
    st->sort();
    cout << endl << "SortedTable SEARCH" << endl;
    for (int i = 0;i<NUMBER_OF_SEARCH;i++){
        cout << "SortedTable | " << arrayQ[i] << " : " << st->search(arrayQ[i]) << endl;
    }
    delete st;

    HashTable * ht = new HashTable();
    buildPairs(ht);
    cout << endl << "HashTable SEARCH" << endl;
    for (int i = 0;i<NUMBER_OF_SEARCH;i++){
        cout << "HashTable   | " << arrayQ[i] << " : " << ht->search(arrayQ[i]) << endl;
    }
    delete ht;

    BinaryTree * bt = new BinaryTree();
    buildPairs(bt);
    cout << endl << "BinaryTree SEARCH" << endl;
    for (int i = 0;i<NUMBER_OF_SEARCH;i++){
        cout << "BinaryTree  | " << arrayQ[i] << " : " << bt->search(arrayQ[i]) << endl;
    }
    //delete bt;


    Avl * avl = new Avl();
    buildPairs(avl);
    cout << endl << "Avl SEARCH" << endl;
    for (int i = 0;i<NUMBER_OF_SEARCH;i++){
        cout << "Avl         | " << arrayQ[i] << " : " << avl->search(arrayQ[i]) << endl;
    }
    //delete avl;

    return 0;
}
