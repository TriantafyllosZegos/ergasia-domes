#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cctype>
#include "Pair.h"
#include "CPair.h"
#include "IOHandler.h"
#include "../structures/Avl.h"
#include "../structures/BinaryTree.h"
#include "../structures/Table.h"
#include "../structures/SortedTable.h"
#include "../structures/HashTable.h"

const string FILE_PATH = "gutenberg.txt";

std::string removeNonAlphaNumeric(const std::string& input) {
    std::string result;
    bool previousSpace = false;

    for (char ch : input) {
        if (std::isalpha(ch) || std::isspace(ch)) {
            if (!(previousSpace && std::isspace(ch))) {
                result += std::tolower(ch);
            }
            previousSpace = std::isspace(ch);
        }
    }

    // Exclude the last space character, if present
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
};

void tokenizeString(const std::string& input, std::string tokens[], int& count) {
    std::stringstream ss(input);
    std::string token;

    count = 0;
    while (ss >> token) {
        tokens[count] = token;
        count++;
    }
};

template <typename STRC>
void buildPairs(STRC * strc) {
    unsigned long z = 1;
    chrono::system_clock::time_point start,end;
    double time;
    start = chrono::high_resolution_clock::now();
    string myline;
    std::ifstream myfile;
    myfile.open(FILE_PATH);
    if ( myfile.is_open() ) {
        while ( myfile ) {
            getline (myfile, myline);
            string newl = removeNonAlphaNumeric(myline);
            if (newl == "") continue;
            std::string tokens[30];  
            int tokenCount = 0;
            tokenizeString(newl, tokens, tokenCount);

            for (int i = 0; i < tokenCount-1; i++) {
                Pair<string> p = Pair(tokens[i],tokens[i+1]);
                strc->insert(p); // Insert is mutual method to every structure
                z++;
                if (z % 100000 == 0){
                    cout << z << " inserts" <<endl;
                }
            }
            
        }
    }
    cout << z << endl;
    myfile.close();
    end = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(end-start).count() * 1e-9;
    ofstream out("output.txt",std::ios_base::app);
    out << "Construction Time of <" << removeNonAlphaNumeric(typeid(*strc).name()) << "> : " << time << " sec" << endl;
    out.close();
    ofstream md("markdown.md",std::ios_base::app);
    md << "- <**" << removeNonAlphaNumeric(typeid(*strc).name()) << "**> : `" << time << " sec`" << endl;
    md.close();
};

template void buildPairs<Table>(Table*);
template void buildPairs<SortedTable>(SortedTable*);
template void buildPairs<BinaryTree>(BinaryTree*);
template void buildPairs<Avl>(Avl*);
template void buildPairs<HashTable>(HashTable*);



Pair<string>* generateQ() {
    int z = 0;
    Pair<string>* aQ = new(nothrow) Pair<string>[1000];
    if (aQ == NULL) cout << "aQ MEMORY ERROR" << endl;
    string myline;
    std::ifstream myfile;
    myfile.open(FILE_PATH);
    if ( myfile.is_open() ) {
        while ( myfile && z < 1000) {
            getline (myfile, myline);
            string newl = removeNonAlphaNumeric(myline);
            std::string tokens[25];  // Assuming maximum of 100 tokens
            int tokenCount = 0;

            tokenizeString(newl, tokens, tokenCount);
            for (int i = 0; i < tokenCount-1; i++) {
                int random = rand() % 10;
                if (random == 7){
                    Pair<string> p(tokens[i],tokens[i+1]);
                    aQ[z] = p;
                    z++;
                    if (z == 1000) break;
                }
            }
        }
    }
    myfile.close();
    return aQ;
};
