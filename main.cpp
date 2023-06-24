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


    Table * t = new Table();
    buildPairs(t);

    start = chrono::high_resolution_clock::now();
    for (int i = 0;i<NUMBER_OF_SEARCH;i++){
        t->search(arrayQ[i]);
    }
    end = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(end-start).count() * 1e-9;
    cout << "Table:       "<< time << " secs " << t->search(Pair<string>("i","am"))  << endl;
    //delete t;
    
    
    SortedTable * st = new SortedTable();
    buildPairs(st);
    start = chrono::high_resolution_clock::now();
    for (int i = 0;i<NUMBER_OF_SEARCH;i++){
        st->search(arrayQ[i]);
    }
    end = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(end-start).count() * 1e-9;
    cout << "SortedTable: "<< time << " secs " << st->search(Pair<string>("i","am"))  << endl;
    //delete st;


    HashTable * ht = new HashTable();
    buildPairs(ht);
    start = chrono::high_resolution_clock::now();
    for (int i = 0;i<NUMBER_OF_SEARCH;i++){
         ht->search(arrayQ[i]);
    }
    end = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(end-start).count() * 1e-9;
    cout << "HashTable:   "<< time << " secs " << ht->search(Pair<string>("this","is")) << endl;
    //delete ht;

    BinaryTree * bt = new BinaryTree();
    buildPairs(bt);
    start = chrono::high_resolution_clock::now();
    for (int i = 0;i<NUMBER_OF_SEARCH;i++){
        bt->search(arrayQ[i]);
    }
    end = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(end-start).count() * 1e-9;
    cout << "BinaryTree:  "<< time << " secs " <<  bt->search(Pair<string>("this","is")) << endl;
    //delete bt;


    Avl * avl = new Avl();
    buildPairs(avl);
    start = chrono::high_resolution_clock::now();
    for (int i = 0;i<NUMBER_OF_SEARCH;i++){
        avl->search(arrayQ[i]);
    }
    end = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(end-start).count() * 1e-9;
    cout << "Avl:         "<< time << " secs " << avl->search(Pair<string>("this","is")) << endl ;
    //delete avl;

    return 0;
}
