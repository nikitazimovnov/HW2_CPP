#include "Aphorism.h"
#include "Random.h"

void Aphorism::In(ifstream& ifst) {
    ifst >> special_length >> text_length >> signs_count;
}

void Aphorism::InRnd() {
    string text = Phrase::rnd.Random_text();
    text_length = text.length();
    special_length = Phrase::rnd.Random_special().length();
    int count = 0;
    for (char sym : text){
        if (sym == '.' || sym == ',' || sym == '-')
            count++;
    }
    signs_count = count;
}

void Aphorism::Out(ofstream& ofst) {
    ofst << "It is Aphorism \n"
         << "Author's name length: " << special_length << "\n"
         << "Text length: " << text_length << "\n" << "signs count:" << signs_count << "\n"
         << "main_func = " << MainFunc() << "\n" << "\n";
}

void Aphorism::Generate(ofstream& ofst) {
    ofst << 1 << " " << special_length << " " << special_length << " " << signs_count;
}

double Aphorism::MainFunc() {
    return ((double)signs_count)/(text_length);
}