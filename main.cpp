#include <iostream>
using namespace std;

#include "linear.h"

bool a(int k){
    return k % 10 == 0;
}

int main (){
    Container<int> c;
    c.create_container('d')
        ->push(11)
        ->push(12)
        ->push(13)
        ->push(14);
    c.create_container('d')
        ->push(21)
        ->push(22)
        ->push(23)
        ->push(24);
    c.create_container('s')
        ->push(31)
        ->push(32)
        ->push(33)
        ->push(34);
    c.create_container('q')
        ->push(41)
        ->push(42)
        ->push(43)
        ->push(44);
    // c.print();
    c.begin();
    while(c.current()){
        cout << c.current()->data << endl;
        c.next();
    }
    return 0;
}