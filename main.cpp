#include <iostream>
#include "linear.h"
using namespace std;

int main (){
    DlistIter<int> l;
    l.push(20); 
    l.push(30);
    l.push(40);
    l.push(50);
    cout << l.empty() << endl;
    cout << l.data() << endl;
    l.pop();
    l.prev();
    l.prev();
    cout << l.data() << endl;
    l.pop();
    cout << l.data() << endl;
    l.next();
    l.pop();
    cout << l.data() << endl;
    l.pop();
    cout << l.empty() << endl;
    return 0;
}