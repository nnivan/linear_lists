#include <iostream>
#include <vector>
#include <sstream>

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

    LinearIter<T>* create_from_stream(istream& input){
        string to;
        while(getline(input, to)){
            istringstream line(to);
            char c;
            line >> c;
            LinearIter<T>* i;
            if(c == 'd') i = this->create_container(_D);
            else if(c == 's') i = this->create_container(_S);
            else if(c == 'q') i = this->create_container(_Q);
            else return nullptr;
            T data;
            while(line >> data){
                i->push(data);
            }
        }
    }

    LinearIter<T>* create_from_string(string s){
        istringstream data(s);
        create_from_stream(data);
    }
    
    void to_stream(ostream& output){
        for(int i = 0; i < this->list.size(); i++){
            list[i]->to_stream(output);
            output << endl;
        }
    }

    string to_string(){
        ostringstream result;
        to_stream(result);
        return result.str();
    }

    void print(){
        to_stream(cout);
    }

    LinearIter<T>* member(T const& x){
        for(int i = 0; i < list.size(); i++){
            if(list[i]->member(x)) return list[i];
        }
        return nullptr;
    }
    LinearIter<T>* condition(bool cond(T)){
        for(int i = 0; i < list.size(); i++){
            if(list[i]->condition(cond)) return list[i];
        }
        return nullptr;
    }
    LinearIter<T>* delete_condition(bool cond(T)){
        for(int i = 0; i < list.size(); i++){
            if(list[i]->delete_condition(cond)) return list[i];
        }
        return nullptr;
    }
    void sort_all(){
        for(int i = 0; i < list.size(); i++){
           list[i]->sort();
        }
    }

    LinearIter<T>* load_balancing(T const& x){
        if(list.empty()) return nullptr;
        LinearIter<T>* mll = list[0];
        int ml = list[0]->lenght(), cml;
        for(int i = 0; i < list.size(); i++){
            cml = list[i]->lenght();
            if(ml > cml){
                ml = cml;
                mll = list[i];
            }
        }
        mll->push(x);
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