template <typename T>
class LinearIter{
public:
    LinearIter(node<T>* n = nullptr){
        this->curr = n;
    }
    node<T>* get(){
        return bottom();
    }
    virtual T& data(){
        return (curr->data);
    }
    LinearIter* next(){
        this->curr = this->curr->next;
        return this;
    }
    LinearIter* prev(){
        this->curr = this->curr->prev;
        return this;
    }
    bool empty(){
        return !curr;
    }
    bool member(T const& x) {
        return member_r(x, bottom());
    }
    T* find(T const& x) {
        return find_r(x, bottom());
    }
    bool condition(bool cond(T)){
        return condition_r(cond, bottom());
    }
    void delete_condition(bool cond(T)){
        delete_condition_r(cond, bottom()); 
    }
    bool condition_all(bool cond(T)){
        return condition_r(cond, bottom()) == lenght() ;
    }
    int lenght() {
        if(empty()) return 0;
        return length_r(bottom());
    }
    void print(){
        print_r(bottom());
    }
    void to_stream(ostream& output){
        output << type_char() << ' '; 
        to_stream_r(bottom(), output);
    }
    string to_string(){
        string result;
        to_string_r(bottom(), result);
        return result;
    }
    virtual node<T>* bottom(){
        node<T>* elem = curr;
        while(elem->prev) elem = elem->prev;
        return elem;
    }
    virtual void sort(){
        for(node<T>* i = this->bottom(); i; i=i->next){
            for(node<T>* x = i; x; x=x->next){
                if(!(i->data < x->data)){
                    swap(i->data, x->data);
                }
            }
        }
    }
    virtual LinearIter* push(T data) = 0;
    virtual void pop() = 0;
protected:
    node<T>* curr;
    uint8_t type = _L;
private:
    char type_char(){
        if(type == _L) return 'l';
        if(type == _S) return 's';
        if(type == _Q) return 'q';
        if(type == _D) return 'd';
    }
    bool member_r(T const& x, node<T>* c) {
        if(x == c->data) return true;
        if(c->next) return member_r(x, c->next);
        return false;
    }
    T* find_r(T const& x, node<T>* c) {
        if(x == c->data) return &(c->data);
        if(c->next) return find_r(x, c->next);
        return nullptr;
    }
    int condition_r(bool cond(T), node<T>* c) {
        if(!c->next) return cond(c->data);
        if(cond(c->data)) return 1 + condition_r(cond, c->next);
        return condition_r(cond, c->next);
    }
    int length_r(node<T>* c) {
        if(c->next) return 1 + length_r(c->next);
        return 1;
    }
    void print_r(node<T>* c) {
        cout << c->data;
        if(c->next) cout << " ", print_r(c->next);
    }
    void to_stream_r(node<T>* c, ostream& output) {
        output << c->data;
        if(c->next) output << " ", to_stream_r(c->next, output);
    }
    string to_string_r(node<char>* c, string& s) {
        // cout << c->data << endl;
        s += c->data;
        s += ' ';
        if(c->next) to_string_r(c->next, s);
    }
};


template <typename T>
class QueueIter: public LinearIter<T>{
public:
    QueueIter(node<T>* n = nullptr): LinearIter<T>(n){
        this->type = _Q;
        this->first = this->curr;
    }
    virtual LinearIter<T>* push(T data){
        node<T>* elem = new node<T>(data);
        if(this->curr){
            this->curr->next = elem;
        }else{
            this->first = elem;
        }
        this->curr = elem;
        return this;
    }
    virtual void pop(){
        node<T>* elem = this->first;
        this->first = this->first->next;
        delete elem;
        if(!this->first){
            this->curr = nullptr;
        }
    }
    virtual T& data(){
        return (this->first->data);
    }
    node<T>* bottom(){
        return this->first;
    }
private:
    node<T>* first;
};


template <typename T>
class StackIter: public LinearIter<T>{
public:
    StackIter(node<T>* n = nullptr): LinearIter<T>(n){
        this->type = _S;
    }
    virtual LinearIter<T>* push(T data){
        this->curr = new node<T>(data, this->curr);
        return this;
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
    DlistIter(node<T>* n = nullptr): LinearIter<T>(n){
        this->type = _D;
    }
    virtual LinearIter<T>* push(T data){
        if(!this->curr) {this->curr = new node<T>(data); return this;}
        node<T>* elem = new node<T>(data, this->curr->next);
        this->curr->next = elem;
        elem->prev = this->curr;
        if(elem->next) elem->next->prev = elem;
        this->curr = elem;
        return this;
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
