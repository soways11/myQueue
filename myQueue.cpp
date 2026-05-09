template <typename type> struct element{
    element* pointer;
    type value;
};
template <typename type> class queue{
  private:
    element<type>* firstElement;
    element<type>* lastElement;
    long long int size;
  public:
    queue();
    ~queue();
    void push(type x);
    void pop();
    type front();
    type back();
    long long int getSize();
    bool empty();
};
template <typename type> queue<type>::queue(){
    firstElement = nullptr;
    lastElement = nullptr;
    size = 0;
}
template <typename type> queue<type>::~queue(){
    for (int i = 0; i < size; i++){
        element<type>* cur = firstElement;
        firstElement = (*cur).pointer;
        delete cur;
    }
}
template <typename type> void  queue<type>::push(type x){
    element<type>* cur = new element<type>;
    (*cur).value = x;
    (*cur).pointer = nullptr;
    if (size > 0){
        (*lastElement).pointer = cur;
    }
    lastElement = cur;
    if (size == 0){
        firstElement = lastElement;
    }
    size++;
}
template <typename type> void queue<type>::pop(){
    element<type>* cur = firstElement;
    firstElement = (*cur).pointer;
    delete cur;
    if (size <= 1){
        lastElement = nullptr;
    }
    size--;
}
template <typename type> type queue<type>::front(){
    return (*firstElement).value;
}
template <typename type> type queue<type>::back(){
    return (*lastElement).value;
}
template <typename type> long long int queue<type>::getSize(){
    return size;
}
template <typename type> bool queue<type>::empty(){
    if (size == 0){
        return 1;
    }else{
        return 0;
    }
}