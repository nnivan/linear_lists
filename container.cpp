#include <vector>

template <typename T>
class Container{
public:
    Container(){}
    
    LinearIter<T>* create_container(char type = 'd'){
        LinearIter<T>* curr = nullptr;
        if(type == 'q') curr = new QueueIter<T>;
        else if(type == 's') curr = new StackIter<T>;
        else if(type == 'd') curr = new DlistIter<T>;
        if(!curr) return nullptr;
        list.push_back(curr);
        return curr;
    }

    void print(){
        for(int i = 0; i < this->list.size(); i++){
            list[i]->print();
            cout << endl;
        }
    }

    T &operator[] (int i){
        return list[i];
    }

    node<T>* begin(){
        index = 0;
        iter = list[0]->get();
        return iter;
    }

    node<T>* current(){
        return iter;
    }

    node<T>* next(){
        iter = iter->next;
        if(!iter){
            index++;
            if(index >= list.size()) return nullptr;
            iter = list[index]->get();
        }
        return iter;
    }

private:
    vector<LinearIter<T>* > list;
    node<T>* iter;
    int index;
};