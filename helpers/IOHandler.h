#ifndef IOHANDLER_h
#define IOHANDLER_H

#include <string>
#include "Pair.h"

template <typename STRC>
void buildPairs(STRC * strc,const string FILE_PATH);

template <typename STRC>
void runStructure(STRC * strc,const string FILE_PATH,const Pair<string> * Q,const int);

const Pair<string> * generateQ(const string FILE_PATH,const int NUMBER_OF_SEARCH);

#endif