template <typename T>
class LinearIter{
public:
    LinearIter(node<T>* n = nullptr){
        this->curr = n;
    }
    T& data(){
        return (curr->data);
    }
    void next(){
        this->curr = this->curr->next;
    }
    void prev(){
        this->curr = this->curr->prev;
    }
    bool empty(){
        return curr;
    }
    virtual void push(T data) = 0;
    virtual void pop() = 0;
protected:
    node<T>* curr;
};


template <typename T>
class QueueIter: public LinearIter<T>{
public:
    QueueIter(node<T>* n = nullptr): LinearIter<T>(n){
        this->first = this->curr;
    }
    virtual void push(T data){
        node<T>* elem = new node<T>(data);
        if(this->curr){
            this->curr->next = elem;
        }else{
            this->first = elem;
        }
        this->curr = elem;
    }
    virtual void pop(){
        node<T>* elem = this->first;
        this->first = this->first->next;
        delete elem;
        if(!this->first){
            this->curr = nullptr;
        }
    }
    T& data(){
        return (this->first->data);
    }
private:
    node<T>* first;
};


template <typename T>
class StackIter: public LinearIter<T>{
public:
    StackIter(node<T>* n = nullptr): LinearIter<T>(n){}
    virtual void push(T data){
        this->curr = new node<T>(data, this->curr);
    }
    virtual void pop(){
        node<T>* elem = this->curr;
        this->curr = this->curr->next;
        delete elem;
    }
};


template <typename T>
class DlistIter: public LinearIter<T>{
public:
    DlistIter(node<T>* n = nullptr): LinearIter<T>(n){}
    virtual void push(T data){
        if(!this->curr) {this->curr = new node<T>(data); return;}
        node<T>* elem = new node<T>(data, this->curr->next);
        this->curr->next = elem;
        elem->prev = this->curr;
        if(elem->next) elem->next->prev = elem;
        this->curr = elem;
        
    }
    virtual void pop(){
        node<T>* elem = this->curr;
        if(this->curr->prev) this->curr->prev->next = this->curr->next;
        if(this->curr->next) this->curr->next->prev = this->curr->prev;
        if(this->curr->next) this->curr = this->curr->next;
        else if(this->curr->prev) this->curr = this->curr->prev;
        else this->curr = nullptr;
        delete elem;
    }
};
