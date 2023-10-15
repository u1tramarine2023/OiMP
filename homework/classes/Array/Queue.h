#include <iostream>

template <class T>
class Queue
{
public:
    Queue(const Queue<T>& QueueObj);
    Queue() : top{ 0 }, queue{ Array<T>() } {}//конструктор по умолчанию
    ~Queue()
    {
        if (top > 0)
            queue.~Array<T>();;
    }

    void push(T);//вставить элемент на вершину очереди
    T pop();//достать элемент с вершины очереди
    void ShowQueue();
    int GetSize();//количество элементов в очереди
    bool IsEmpty();

private:
    //можно хранить capacity(сколько выделено памяти)
    int top;//Вершина очереди
    Array<T> queue;

public:
    Queue& operator=(const Queue<T>& QueueObj);


};
template <class Type>
void Queue<Type>::push(Type element)
{
    queue.InsertAt(0, element);
    top++;
}

template <class Type>
Type Queue<Type>::pop()
{
    if(this->IsEmpty()){
        throw std::runtime_error("Queue is empty!");
    }
    Type value=queue.GetAt(top-1);
    queue.RemoveAt(top-1);
    top--;
    return value;

}
template <class Type>
void Queue<Type>::ShowQueue()
{
    queue.Print();
}
template <class Type>
int Queue<Type>::GetSize()
{
    return this->top;
}
template <class Type>
bool Queue<Type>::IsEmpty()
{
        return top == 0;
}
template <class Type>
Queue<Type>::Queue(const Queue<Type>& QueueObj)
{
    queue=QueueObj.queue;
    top=QueueObj.top;
}
template <class Type>
Queue<Type>& Queue<Type>::operator=(const Queue<Type>& QueueObj)
{
    queue.RemoveAll();
    queue=QueueObj.queue;
    top=QueueObj.top;
    return *this;
}

