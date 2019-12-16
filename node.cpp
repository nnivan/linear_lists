template <typename T>
struct node{
    T data;
    node* next;
    node* prev;
    node<T>(T d = T(), node* n = nullptr, node* p = nullptr){
        data = d;
        next = n;
        prev = p;
    }
};
