template <typename T>
struct node{
    T data;
    node* next;
    node(T d = T(), node* n = nullptr){
        data = d;
        next = n;
    }
};

template <typename T>
struct list: public node<T> {
    node<T>* prev;
    list(T d = T(), node<T>* n = nullptr, node<T>* p = nullptr) 
        : node<T>(d, n) 
    {
        prev = p;
    }
};
