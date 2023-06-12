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



    Table * t = new Table();
    buildPairs(t); 
    cout << "Table SEARCH" << endl;
    for (int i = 0;i<10;i++){
        cout << "Table       | " << arrayQ[i] << " : " << t->search(arrayQ[i]) << endl;
    }
    

    SortedTable * st = new SortedTable(*t);
    buildPairs(st);
    st->sort();
    cout << "SortedTable SEARCH" << endl;
    for (int i = 0;i<10;i++){
        cout << "SortedTable | " << arrayQ[i] << " : " << st->search(arrayQ[i]) << endl;
    }
    delete t;

    HashTable * ht = new HashTable();
    buildPairs(ht);
    cout << "HashTable SEARCH" << endl;
    for (int i = 0;i<10;i++){
        cout << "HashTable   | " << arrayQ[i] << " : " << ht->search(arrayQ[i]) << endl;
    }
    delete ht;

    BinaryTree * bt = new BinaryTree();
    buildPairs(bt);
    cout << "BinaryTree SEARCH" << endl;
    for (int i = 0;i<10;i++){
        cout << "BinaryTree  | " << arrayQ[i] << " : " << bt->search(arrayQ[i]) << endl;
    }
    //delete bt;


    Avl * avl = new Avl();
    buildPairs(avl);
    cout << "Avl SEARCH" << endl;
    for (int i = 0;i<10;i++){
        cout << "Avl         | " << arrayQ[i] << " : " << avl->search(arrayQ[i]) << endl;
    }
    //delete avl;

    return 0;
}
