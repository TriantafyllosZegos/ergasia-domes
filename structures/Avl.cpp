#include "structures/Avl.h"
#include <cmath>

Avl::Avl() {
  this->maxKM = 0;
  this->year = 0;
};
Avl::Avl(int km, int year) {
  this->maxKM = km;
  this->year = year;
};

int Avl::getMaxKM() { return maxKM; };

int Avl::getYear() { return year; };

double Avl::getPollutionScore() { return (float)(maxKM * 250) / 365; };

double Avl::getTaxes() { return (2022 - year) * 12.5; };
