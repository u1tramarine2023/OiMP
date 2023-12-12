#include<iostream>
template<class T>
class List
{
public:
    //узел(элемент списка)
    struct Node
    {
        T data;
        Node* prev;
        Node* next;
        Node() = default;
        Node(const T& data_, Node* prev_=nullptr,Node* next_=nullptr):
                data{data_},prev{prev_}, next{next_}{}
        ~Node() = default;
    };
    List();
    List(const std::initializer_list<T>&);
    void push_back(const T&);
    T pop_back();
    T pop_front();
    size_t getSize() { return size; }
    void push_front(const T&);
    void insert(const T&, size_t);
    void remove(const T&);
    ~List();
    class Iterator
    {
    public:
        Iterator() = default;
        Iterator(Node* ptr_) :ptr(ptr_) {};
        //префиксная форма
        Iterator operator++()
        {
            ptr = ptr->next;
            return *this;
        }
        //постфиксная форма
        Iterator operator++(int)
        {
            Iterator temp(*this);
            this->operator++();
            return temp;
        }
        T& operator*() { return  (* ptr).data; }
        const T& operator*()const { return  (*ptr).data; }
        bool operator!=(const Iterator& it) const
        {
            return ptr != it.ptr;
        }
        bool operator==(const Iterator& it) const
        {
            return ptr == it.ptr;
        }

    private:
        Node* ptr;
    };
    Iterator Begin() { return this->head; }
    Iterator End() { return this->tail->next; }
    class Reverse_Iterator
    {
    public:
        Reverse_Iterator()= default;
        Reverse_Iterator(Node* ptr_) :ptr(ptr_) {};
        //префиксная форма
        Reverse_Iterator operator++()
        {
            ptr = ptr->prev;
            return *this;
        }
        //постфиксная форма
        Reverse_Iterator operator++(int)
        {
            Reverse_Iterator temp(*this);
            this->operator++();
            return temp;
        }
        T& operator*() { return  (* ptr).data; }
        const T& operator*()const { return  (*ptr).data; }
        bool operator!=(const Reverse_Iterator& it) const
        {
            return ptr != it.ptr;
        }
        bool operator==(const Reverse_Iterator& it) const
        {
            return ptr == it.ptr;
        }
        ~Reverse_Iterator()= default;
    private:
        Node* ptr;
    };
    Reverse_Iterator RBegin(){return Reverse_Iterator(tail);}
    Reverse_Iterator REnd(){return Reverse_Iterator(head->prev);}
private:
    size_t size;
    Node* head;//указатель на первый
    Node* tail;//указатель на последний

};

template<class T>
void List<T>::remove(const T& index) {
    if (index < 0 or index > size-1) {
        std::cout << "Index is incorrect!";
        return;
    }
    if (index == size-1){
        pop_back();}
    else
    if (index==0)
       pop_front();
    else {
        Node* current = this->head;
        for (size_t i = 0; i < index-1; i++) {
            current = current->next;
        }
      Node* temp= current->next;
        current->next = temp->next;
        temp->next->prev = current;
        delete (temp);
        this->size--;
    }
}

template<class T>
void List<T>::insert(const T& key, size_t index) {

    Node* newNode = new Node(key);
    if (index == 0) {
      push_front(key);
    }
   if (index==size) {
       push_back(key);
   }
    else {
        Node *current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        this-> size++;
    }
}


template<class T>
List<T>::List(const std::initializer_list<T>&list):List()
{
    for (T i : list)
    {
        this->push_back(i);
    }
}
template<class T>
void List<T>::push_front(const T& key) {
    Node* temp = new Node(key, nullptr, this->head);
    if (this->size==0)
    {
        this->tail = temp;
    }
    else
    {
        this->head->prev =temp;
    }
    this->head = temp;
    this->size++;
}

template<class T>
void List<T>::push_back(const T& key)
{
    Node* temp = new Node(key, this->tail, nullptr);
    if (this->size==0)
    {
        this->head = temp;
    }
    else
    {
        this->tail->next = temp;
    }
    this->tail = temp;
    this->size++;
}
template<class T>
List<T>::List():size(0),head(nullptr),tail(nullptr){}
template<class T>
List<T>::~List()
{
    while (size)
    {
        pop_back();
    }
}
template<class T>
T List<T>::pop_front() {
    Node* Temp = this->head;
    T ReturnValue = this->head->data;
    if(this->size==0)
    {
        std::cout << "Error : list is empty\n";
        return T();
    }
    if(this->size==1)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        this->head = Temp->next;
        head->prev = nullptr;
    }
    delete Temp;
    size--;
    return ReturnValue;
}

template<class T>
T List<T>::pop_back()
{
    Node* Temp = this->tail;
    T ReturnValue = this->tail->data;
    if(this->size==0)
    {
        std::cout << "Error : list is empty\n";
        return T();
    }
    if(this->size==1)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        this->tail = Temp->prev;
        tail->next = nullptr;
    }
    delete Temp;
    size--;
    return ReturnValue;
}
