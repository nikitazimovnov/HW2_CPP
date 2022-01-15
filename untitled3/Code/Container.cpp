#include "Container.h"

Container::Container() : len{ 0 }
{
}

Container::~Container() {
    Clear();
}

void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

void Container::In(ifstream& ifst) {
    while (!ifst.eof()) {
        if ((storage[len] = Phrase::StaticIn(ifst)) != 0) {
            len++;
        }
    }
}

void Container::InRnd(int size) {
    while (len < size) {
        if ((storage[len] = Phrase::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

void Container::Out(ofstream& ofst) {
    ofst << "Container contains " << len << " elements.\n";
    for (int i = 0; i < len; i++) {
        ofst << i + 1 << ": ";
        storage[i]->Out(ofst);
    }
}

void Container::Generate(ofstream& ofst) {
    for (int i = 0; i < len; i++) {
        storage[i]->Generate(ofst);
        if (i != len - 1) {
            ofst << "\n";
        }
    }
}

void Container::ShakeSort() {
    int i, j, k;
    int m = len;
    for (i = 0; i < m;) {
        for (j = i + 1; j < m; j++) {
            if (storage[j]->MainFunc() < storage[j - 1]->MainFunc())
                swap(storage[j], storage[j - 1]);
        }
        m--;
        for (k = m - 1; k > i; k--) {
            if (storage[k]->MainFunc() < storage[k - 1]->MainFunc())
                swap(storage[k], storage[k - 1]);
        }
        i++;
    }
}