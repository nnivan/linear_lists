template <typename T>
struct node{
    T data;
    node<T>* next;
    node<T>(T d = T(), node<T>* n = nullptr){
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
