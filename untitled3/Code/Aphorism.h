#ifndef __aphorism__
#define __aphorism__

#include <fstream>

# include "Random.h"
#include "Phrase.h"

using namespace std;

class Aphorism : public Phrase {
public:
    virtual ~Aphorism() {}

    virtual void In(ifstream& ifst);

    virtual void InRnd();

    virtual void Out(ofstream& ofst);

    virtual void Generate(ofstream& ofst);

    virtual double MainFunc();

};

#endif
