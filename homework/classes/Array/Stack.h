#include <iostream>

template <class T>
class Stack
{
public:
    Stack(const Stack<T>& StackObj);
    Stack() : top{ 0 }, stack{ Array<T>() } {}//конструктор по умолчанию
    ~Stack()
    {
        if (top > 0)
            stack.~Array<T>();;
    }

    void push(T);//вставить элемент на вершину стека
    T pop();//достать элемент с вершины стека
    void ShowStack();
    int GetSize();//количество элементов в стеке
    bool IsEmpty();

private:
    //можно хранить capacity(сколько выделено памяти)
    int top;//Вершина стека
    Array<T> stack;

public:
    Stack& operator=(const Stack<T>& StackObj);

};
template <class Type>
void Stack<Type>::push(Type element)
{
    stack.InsertAt(top++, element);
}

template <class Type>
Type Stack<Type>::pop()
{
    if(this->IsEmpty()){
        throw std::runtime_error("Stack is empty!");
    }
    Type value=stack.GetAt(top-1);
    stack.RemoveAt(top-1);
    top--;
    return value;

}
template <class Type>
void Stack<Type>::ShowStack()
{
    stack.Print();
}
template <class Type>
int Stack<Type>::GetSize()
{
    return this->top;
}
template <class Type>
bool Stack<Type>::IsEmpty()
{
        return top == 0;
}
template <class Type>
Stack<Type>::Stack(const Stack<Type>& StackObj)
{
    stack=StackObj.stack;
    top=StackObj.top;
}
template <class Type>
Stack<Type>& Stack<Type>::operator=(const Stack<Type>& StackObj)
{
    stack.RemoveAll();
    stack=StackObj.stack;
    top=StackObj.top;
    return *this;
}

