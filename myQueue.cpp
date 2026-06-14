template <typename type> struct element{ // struct, that will be used as element of stack
    element* pointer;
    type value;
};
template <typename type> class queue{
  private:
    element<type>* firstElement;
    element<type>* lastElement;
    long long int size;
  public:
    queue(); // constructor
    ~queue(); // destructor
    void push(type x ); // add new element to the end of the queue
    void pop(); // delete first element
    type front(); // return first element of queue
    type back(); // return last element of queue
    long long int getSize(); // return size
    bool empty(); // check if queue is empty
};
template <typename type> queue<type>::queue(){
    firstElement = nullptr;
    lastElement = nullptr;
    size = 0;
}
template <typename type> queue<type>::~queue(){
    for (int i = 0; i < size; i++){ // delete size elements, because queue include size elements, when we delete size elements, queue becomes empty
        element<type>* cur = firstElement;
        firstElement = (*cur).pointer;
        delete cur; // deallocate memory of first element
    }
}
template <typename type> void  queue<type>::push(type x){
    if (size <= 0){ // if size == 0, i have to set the same value for lastElement and firstElement
        element<type>* cur = new element<type>; // allocate memory for new element
        (*cur).value = x;
        (*cur).pointer = nullptr;
        firstElement = cur;
        lastElement = cur;
        size++;
    }else{
        element<type>* cur = new element<type>; // allocate memory for new element
        (*cur).value = x;
        (*cur).pointer = nullptr;
        (*lastElement).pointer = cur;
        lastElement = cur;
        size++;
    }
}
template <typename type> void queue<type>::pop(){
    if (size <= 0){ // if size == 0 return
        return;
    }else if (size == 1){ // if size == 1, queue becomes void
        delete firstElement; // deallocate memory of first element
        firstElement = nullptr;
        lastElement = nullptr;
        size = 0;
    }else{
        element<type>* cur = firstElement;
        firstElement = (*cur).pointer;
        delete cur; // deallocate memory of first element
        size = size - 1;
    }
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
