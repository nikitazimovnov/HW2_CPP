#ifndef __puzzle__
#define __puzzle__

#include <fstream>

# include "Random.h"
#include "Phrase.h"

using namespace std;

class Puzzle : public Phrase {
public:
    virtual ~Puzzle() {}

    virtual void In(ifstream& ifst);

    virtual void InRnd();

    virtual void Out(ofstream& ofst);

    virtual void Generate(ofstream& ofst);

    virtual double MainFunc();
};

#endif
