template <typename T>
class LinearIter{
public:
    LinearIter(node<T>* self = nullptr){
        this->self = self;
    }
    T& data(){
        return (self->data);
    }
private:
    node<T>* self;
};