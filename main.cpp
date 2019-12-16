#include <iostream>
#include "linear.h"
using namespace std;

int main (){
    StackIter<int> l;
    l.push(20);
    l.push(30);
    l.push(40);
    l.push(50);
    cout << l.empty() << endl;
    cout << l.back() << endl;
    l.pop();
    cout << l.data() << endl;
    cout << l.back() << endl;
    StackIter<int> k(l);
    l.pop();
    l.pop();
    l.pop();
    cout << l.empty() << endl;
    cout << k.empty() << endl;
    cout << k.back() << endl;
    k.next();
    cout << k.back() << endl;
    k.next();
    cout << k.back() << endl;
    k.next();
    cout << k.empty() << endl;
    return 0;
}