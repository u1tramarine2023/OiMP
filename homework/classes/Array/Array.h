#pragma once
#include<iostream>
#include <stdexcept>
template <class T>
class Array {
public:
    Array();
    explicit Array(size_t);//не будет неявного приведения типов
    Array(const Array<T>&);
    //конструктор перемещения
    Array(Array<T>&& a);//&& - rvalue
    //оператор перемещения
    Array<T>& operator=(Array<T>&&);
    Array<T>& operator=(const Array<T>&);
    T& operator[](const int&);
    const T& operator[](const int&)const;
    size_t GetSize();
    void SetSize(size_t, int grow = 0);
    size_t GetUpperBound();
    bool IsEmpty();
    void Add(T);
    T GetAt(size_t);
    void FreeExtra();
    void RemoveAll();
    void SetAt(const size_t&, T);
    void Append(Array<T>);
    void InsertAt(const int&, T);
    void InsertAt(const int & index, const Array<T>& );
    void RemoveAt(const size_t&);
    void RemoveAt(const int &index, int count);
    void Print();
    ~Array();
private:
    size_t size;//заполнено
    size_t capacity;//выделено
    T* data;


};

template<class T>
void Array<T>::RemoveAt(const size_t &index) {
    if (index < 0 && index > this->size) {
        throw std::runtime_error("Wrong index!");
    }
    for (int i = index; i < this->size-1; i++) {
        this->data[i]=this->data[i+1];
    }
    this->size--;
}
template<class T>
void Array<T>::RemoveAt(const int & index, int count){
    if (index < 0 && index > this->size) {
        throw std::runtime_error("Wrong index!");
    }
    for (int i = index; i < this->size - count - 1; i++) {
        this->data[i]=this->data[i+count];
    }
    this->size-=count;
}
template<class T>
void Array<T>::Append(Array<T> a) {
    this->capacity=this->size+a.size;
    for (int i = this->size; i <this->size+a.size; i++) {
        this->data[i] = a.data[i-this->size];
    }
    this->size+=a.size;
}

template<class T>
void Array<T>::RemoveAll() {
this->size=0;
this->capacity=0;
this->data=nullptr;
}
template<class T>
T& Array<T>::operator[](const int& index)
{
    if (index < 0 && index > this->size) {
        throw std::runtime_error("Wrong index!");
    }
    return this->data[index];
}

template<class T>
const T& Array<T>::operator[](const int& index)const
{
    if (index < 0 && index > this->size) {
        throw std::runtime_error("wrong index!");
    }
    return this->data[index];
}
template<class T>
void Array<T>::SetAt(const size_t &index, T value) {
    (*this)[index]=value;
}
template<class T>
T Array<T>::GetAt(size_t index) {
   return (*this)[index];
}

template<class T>
size_t Array<T>::GetUpperBound() {
    return this->size-1;
}
template<class T>
void Array<T>::FreeExtra() {
this->capacity= this->size;
}

template<class T>
bool Array<T>::IsEmpty() {
    return this->data == nullptr or this->size==0;
}

template<class T>
size_t Array<T>::GetSize() {
  return this->size;
}

template<class T>
Array<T>& Array<T>:: operator=(Array<T>&& a)
{
    if (this != &a) {
        delete[]data;
        size = a.size;
        capacity = a.capacity;
        data = a.data;
        a.size = 0;
        a.capacity = 0;
        a.data = nullptr;
    }
    return *this;
}
template<class T>
Array<T>::Array( Array<T>&& a) :size(a.size), capacity(a.capacity), data(a.data)
{
    a.size = 0;
    a.capacity = 0;
    a.data = nullptr;
}
template<class T>
Array<T>& Array<T>:: operator=(const Array<T>&a)
{
    if (this != &a) {
        delete[]data;
        size = a.size;
        capacity = a.capacity;
        data = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = a.data[i];
        }
    }
    return *this;
}
template<class T>
Array<T>::Array(const Array<T>& a):size(a.size),capacity(a.capacity),data(new T[a.capacity])
{
    for (size_t i = 0; i < size; i++)
    {
        data[i] = a.data[i];
    }
}
template<class T>
Array<T>::Array(size_t _size) :size(0), capacity(_size), data(new T[_size]) {}

template<class T>
Array<T>::Array():size(0),capacity(0),data(nullptr){}

template<class T>
Array<T>::~Array()
{
    delete[]data;
}

template <class T>
void Array<T>::SetSize(size_t _size, int grow) {
    if (this->capacity == _size + grow) {
        return;
    }
    T* temp = new T[_size + grow];
    if (_size > this->size) {
        for (size_t i = 0; i < this -> size; i++) {
            temp[i] = this->data[i];
        }
    }
    else {
        for (size_t i = 0; i < _size; i++) {
            temp[i] = this->data[i];
        }
        this->size = _size;
    }
    delete[] this->data;
    this->data = temp;
    this->capacity = _size + grow;
}

template <class T>
void Array<T>::InsertAt(const int & index, T key) {
    if (index < 0 && index > this->size) {
        throw std::runtime_error("Wrong index!");
    }

    if (this->capacity == this->size) {
        SetSize(this->size + 1, 5);
    }
    for (int i = this->size - 1; i >= index; i--) {
        this->data[i + 1] = this->data[i];
    }
    this->data[index] = key;
    this->size++;
}
template <class T>
void Array<T>::InsertAt(const int & index, const Array<T>& a){
    if (index < 0 && index > this->size) {
        throw std::runtime_error("Wrong index!");
    }
    if (this->capacity < this->size+a.size) {
        SetSize(this->size + a.size, 5);
    }
    for (int i = this->size - 1; i >= index; i--) {
        this->data[i + a.size] = this->data[i];
    }
    for (int i = index; i <index+a.size; i++) {
                 this->data[i] = a.data[i-index];
        }
    this->size+=a.size;
}
template <class T>
void Array<T>::Add(T key) {
    if (this->capacity == this->size) {
        SetSize(this->size + 1, 5);
    }
    this->data[this->size] = key;
    this->size++;
}
template <class T>
void Array<T>::Print() {
    for (size_t i = 0; i < this->size; i++)	{
        std::cout << this->data[i] << " ";
    }
    std::cout << std::endl;
}
