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



int main(int argc, char* argv[])
{
    string file;
    if (argc == 1){
        file = "small-file"; //DEFAULT VALUE WITHOUT ARGS
    }else{
        file = argv[1];
    }
    const string FILE_PATH = file + ".txt";
    const int NUMBER_OF_SEARCH = 1000;
    const Pair<string> * Q = generateQ(FILE_PATH,NUMBER_OF_SEARCH);

    Table * t = new Table();
    runStructure(t,FILE_PATH,Q,NUMBER_OF_SEARCH);
    //delete t;
    
    SortedTable * st = new SortedTable();
    runStructure(st,FILE_PATH,Q,NUMBER_OF_SEARCH);
    //delete st;

    HashTable * ht = new HashTable();
    runStructure(ht,FILE_PATH,Q,NUMBER_OF_SEARCH);
    //delete ht;

    BinaryTree * bt = new BinaryTree();
    runStructure(bt,FILE_PATH,Q,NUMBER_OF_SEARCH);
    //delete bt;

    Avl * avl = new Avl();
    runStructure(avl,FILE_PATH,Q,NUMBER_OF_SEARCH);
    //delete avl;

    return 0;
}
