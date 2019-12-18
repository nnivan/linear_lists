#include <vector>

template <typename T>
class Container{
public:
    Container(){}
    
    LinearIter<T>* create_container(unsigned type = _D){
        LinearIter<T>* curr = nullptr;
        if(type == _Q) curr = new QueueIter<T>;
        else if(type == _S) curr = new StackIter<T>;
        else if(type == _D) curr = new DlistIter<T>;
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

    LinearIter<T>* &operator[] (int i){
        return list[i];
    }

    node<T>* bottom(int i){
        return list[i]->bottom();
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

    void toVector(vector<T>& v){
        node<T>* it = list[0]->bottom();
        int ind = 0;
        while(it){
            v.push_back(it->data);
            it = it->next;
            if(!it){
                ind++;
                if(ind >= list.size()) it = nullptr;
                else it = list[ind]->bottom();
            }
        }
    }

private:
    vector<LinearIter<T>* > list;
    node<T>* iter;
    int index;
};