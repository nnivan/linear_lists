#include <iostream>
#include <vector>
using namespace std;

#include "linear.h"

bool a(int k){
    return k % 10 == 0;
}

int main (){
    Container<int> c;
    c.create_container(_D)
        ->push(2)
        ->push(4)
        ->push(10)
        ->push(3);
    c.create_container(_Q)
        ->push(20)
        ->push(4)
        ->push(1)
        ->push(3);
    c.create_container(_S)
        ->push(2)
        ->push(4)
        ->push(1)
        ->push(30);
    c.create_container(_D)
        ->push(2)
        ->push(40)
        ->push(1)
        ->push(3);
    c.print();
    vector<int> v;
    c.toVector(v);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ",  ";
    }
    return 0;
}

    // while(c.current()){
    //     // cout << c.current()->data << endl;
    //     c.next();
    // }