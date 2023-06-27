#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <cctype>
#include "Pair.h"
#include "CPair.h"
#include "IOHandler.h"
#include "../structures/Avl.h"
#include "../structures/BinaryTree.h"
#include "../structures/Table.h"
#include "../structures/SortedTable.h"
#include "../structures/HashTable.h"

std::string removeNonAlphaNumeric(const std::string &input)
{
    std::string result;
    bool previousSpace = false;

    for (char ch : input)
    {
        if (std::isalpha(ch) || std::isspace(ch))
        {
            if (!(previousSpace && std::isspace(ch)))
            {
                result += std::tolower(ch);
            }
            previousSpace = std::isspace(ch);
        }
    }

    // Exclude the last space character, if present
    if (!result.empty() && result.back() == ' ')
    {
        result.pop_back();
    }

    return result;
};

void tokenizeString(const std::string &input, std::string tokens[], int &count)
{
    std::stringstream ss(input);
    std::string token;

    count = 0;
    while (ss >> token)
    {
        tokens[count] = token;
        count++;
    }
};

template <typename STRC>
void buildPairs(STRC *strc, const string FILE_PATH)
{
    unsigned long z = 0;
    string myline;
    std::ifstream myfile;
    myfile.open(FILE_PATH);
    if (myfile.is_open())
    {
        while (myfile)
        {
            getline(myfile, myline);
            string newl = removeNonAlphaNumeric(myline);
            std::string tokens[10000];
            int tokenCount = 0;
            tokenizeString(newl, tokens, tokenCount);

            for (int i = 0; i < tokenCount - 1; i++)
            {
                Pair<string> p = Pair(tokens[i], tokens[i + 1]);
                strc->insert(p); // Insert is mutual method to every structure
                z++;
                if (z % 1000000 == 0)
                {
                    cout << z << " inserts" << endl;
                }
            }
        }
    }
    cout << z << endl;
    myfile.close();
};

template void buildPairs<Table>(Table *, const string);
template void buildPairs<SortedTable>(SortedTable *, const string);
template void buildPairs<BinaryTree>(BinaryTree *, const string);
template void buildPairs<Avl>(Avl *, const string);
template void buildPairs<HashTable>(HashTable *, const string);

template <typename STRC>
void runStructure(STRC *strc, const string FILE_PATH, const Pair<string> *Q, const int NUMBER_OF_SEARCH)
{
    chrono::system_clock::time_point start, end;
    double time;
    start = chrono::high_resolution_clock::now();
    buildPairs(strc, FILE_PATH);
    end = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(end - start).count() * 1e-9;
    ofstream out("output.txt", std::ios_base::app);
    out << setprecision(8);
    string name = removeNonAlphaNumeric(typeid(*strc).name());
    name[0] = (char)name[0] - 32; // to start with Uppercase
    out << setw(12) << name;
    out << " | Construction : " << time << " sec | ";
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < NUMBER_OF_SEARCH; i++)
    {
        strc->search(Q[i]);
    }
    end = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(end - start).count() * 1e-9;
    out << "Search : " << setw(10) << time << " sec" << endl;
    out.close();
};

template void runStructure<Table>(Table *, const string, const Pair<string> *Q, const int);
template void runStructure<SortedTable>(SortedTable *, const string, const Pair<string> *Q, const int);
template void runStructure<BinaryTree>(BinaryTree *, const string, const Pair<string> *Q, const int);
template void runStructure<Avl>(Avl *, const string, const Pair<string> *Q, const int);
template void runStructure<HashTable>(HashTable *, const string, const Pair<string> *Q, const int);

const Pair<string> *generateQ(const string FILE_PATH, const int NUMBER_OF_SEARCH)
{
    int z = 0;
    Pair<string> *aQ = new (nothrow) Pair<string>[NUMBER_OF_SEARCH]();
    string myline;
    std::ifstream myfile;
    myfile.open(FILE_PATH);
    if (myfile.is_open())
    {
        while (myfile && z < NUMBER_OF_SEARCH)
        {
            getline(myfile, myline);
            string newl = removeNonAlphaNumeric(myline);
            std::string tokens[10000]; // Assuming maximum of 100 tokens
            int tokenCount = 0;

            tokenizeString(newl, tokens, tokenCount);
            for (int i = 0; i < tokenCount - 1; i++)
            {
                int random = rand() % 10000;
                if (random == 7)
                {
                    Pair<string> p(tokens[i], tokens[i + 1]);
                    aQ[z] = p;
                    z++;
                    if (z == NUMBER_OF_SEARCH)
                        break;
                }
            }
        }
    }
    myfile.close();
    return aQ;
};
