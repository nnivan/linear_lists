#include <iostream>
#include "linear.h"
using namespace std;

int main (){
    list<int> p(137);
    LinearIter<int> l(&p);
    l.data() = 50;
    int* k = &l.data();
    *k = 30;
    cout << (l.data()) << endl;
    return 0;
}