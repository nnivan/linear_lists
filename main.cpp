#include <iostream>
using namespace std;

#include "linear.h"

// d 0 1 2 3 7
// s 0 1 2 3 4
// q 5 6 7 8 9

string data = "d 0 3 2 1 4\ns 0 1 2 3 4\nq 5 6 7 8 9";
istringstream is_data(data);

bool is25(int x){
    return x == 25;
}
bool is0(int x){
    return x == 0;
}

bool isPrime(int x){
    for(int i = 2; i < x; i++){
        if(x%i==0) return false;
    }
    return true;
}

int main (){
    Container<int> c;
    // c.create_from_string(data);
    // cout << c.to_string() << endl;
    c.create_from_stream(is_data);
    cout << "---------->to_stream(cout)<----------" << endl;
    c.to_stream(cout);
    cout << "---------->pop, push<----------" << endl;
    cout << c[2]->data() << endl;
    c[2]->pop();
    c[2]->push(11);
    cout << c[2]->data() << endl;
    c[1]->pop();
    c[1]->push(10);
    cout << "---------->member<----------" << endl;
    cout << c.to_string() << endl;
    cout << bool(c.member(11)) << endl;
    cout << bool(c.member(12)) << endl;
    cout << "---------->load balancing<----------" << endl;
    c.load_balancing(20);
    c.load_balancing(21);
    c.load_balancing(22);
    c.to_stream(cout);
    cout << "---------->condition<----------" << endl;
    // c.to_stream(cout);
    cout << bool(c.condition(is0)) << endl;
    cout << bool(c.condition(is25)) << endl;
    cout << "---------->sort<----------" << endl;
    c.sort_all();
    c.to_stream(cout);
    cout << "---------->iter<----------" << endl;
    c.begin();
    while(c.current()){
        cout << c.current()->data << " ";
        c.next();
    }
    cout << endl;
    cout << "---------->end<----------" << endl;
    return 0;
}