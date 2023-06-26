#ifndef IOHANDLER_h
#define IOHANDLER_H

#include <string>
#include "Pair.h"

template <typename STRC>
void buildPairs(STRC * strc);

template <typename STRC>
void runStructure(STRC * strc,const int);

Pair<string> * generateQ();

#endif