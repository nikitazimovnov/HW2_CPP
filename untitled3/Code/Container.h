#ifndef __container__
#define __container__

#include "Phrase.h"

class Container {
public:
    Container();
    ~Container();

    void In(ifstream& ifst);

    void InRnd(int size);

    void Out(ofstream& ofst);

    void Generate(ofstream& ofst);

    void ShakeSort();
private:
    void Clear();
    int len;
    Phrase* storage[10000];
};

#endif
