#ifndef __poverb__
#define __poverb__

#include <fstream>

# include "Random.h"
#include "Phrase.h"

using namespace std;

class Poverb : public Phrase {
public:
    virtual ~Poverb() {}

    virtual void In(ifstream& ifst);

    virtual void InRnd();

    virtual void Out(ofstream& ofst);

    virtual void Generate(ofstream& ofst);

    virtual double MainFunc();
};

#endif