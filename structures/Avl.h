#ifndef AVL_H
#define AVL_H

class Avl {
protected:
  int maxKM;
  int year;

public:
  Avl();
  Avl(int km, int year);
  double getPollutionScore();
  int getMaxKM();
  int getYear();
  virtual double getTaxes();
};

#endif
