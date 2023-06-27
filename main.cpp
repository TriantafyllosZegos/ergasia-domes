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

int main(int argc, char *argv[])
{
    const string FILE_PATH = argc < 2 ? "small-file.txt" : argv[1];    // DEFAULT "small-file.txt"
    const int NUMBER_OF_SEARCH = argc < 3 ? 1000 : stoi(argv[2]);   // DEFAULT 1000

    const Pair<string> *ARRAY_Q = generateQ(FILE_PATH, NUMBER_OF_SEARCH);

    const Pair<string> test("a","little");

    Table *t = new Table();
    runStructure(t, FILE_PATH, ARRAY_Q, NUMBER_OF_SEARCH);
    cout << t->search(test) << endl;
    delete t;

    SortedTable *st = new SortedTable();
    runStructure(st, FILE_PATH, ARRAY_Q, NUMBER_OF_SEARCH);
    cout << st->search(test) << endl;
    delete st;

    HashTable *ht = new HashTable();
    runStructure(ht, FILE_PATH, ARRAY_Q, NUMBER_OF_SEARCH);
    cout << ht->search(test) << endl;
    delete ht;

    BinaryTree *bt = new BinaryTree();
    runStructure(bt, FILE_PATH, ARRAY_Q, NUMBER_OF_SEARCH);
    cout << bt->search(test) << endl;
    delete bt;

    Avl *avl = new Avl();
    runStructure(avl, FILE_PATH, ARRAY_Q, NUMBER_OF_SEARCH);
    cout << avl->search(test) << endl;
    delete avl;

    return 0;
}
