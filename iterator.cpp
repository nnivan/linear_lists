template <typename T>
class LinearIter{
public:
    LinearIter(node<T>* self = nullptr){
        this->self = self;
    }
    LinearIter(LinearIter<T>* li){
        while(li){
            this->self = li->self;
            li = li->next;
        }
    }
    T& data(){
        return (self->data);
    }
    void next(){
        this->self = this->self->next;
    }
    bool empty(){
        return !self;
    }
    virtual T back() = 0;
    virtual void push(T data) = 0;
    virtual void pop() = 0;
protected:
    node<T>* self;
};

template <typename T>
class StackIter: public LinearIter<T>{
public:
    StackIter(node<T>* self = nullptr): LinearIter<T>(self){}
    StackIter(LinearIter<T>* li ): LinearIter<T>(li){}
    virtual T back(){
        return this->self->data;
    }
    virtual void push(T data){
        node<T>* elem = new node<T>(data, this->self);
        this->self = elem;
    }
    virtual void pop(){
        node<T>* buff = this->self->next;
        delete this->self;
        this->self = buff;
    }
};