#include"Array.h"
#include "Stack.h"
#include "Queue.h"
int main()
{
    Array<int> arr;
    std::cout << arr.IsEmpty()<< std::endl;
    arr.Add(6);
    arr.Add(7);
    arr.Add(3);
    arr.Add(2);
  Array<int> b;
  b.Add (22);
  b.Add (21);
arr[0]=100;
  std::cout<< "arr[0]=" <<arr[0]<<std::endl;
  arr.InsertAt(4, b);

arr.FreeExtra();
arr.SetAt(1,12);
std::cout << arr.GetAt(3);

arr.Append(b);
arr.Print();
arr.RemoveAt(2,2);
arr.Print();
    Queue <int> s1;
    s1.ShowQueue();
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    s1.push(5);
    s1.push(9);
    s1.push(13);
    s1.push(7);
    s1.ShowQueue();
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << s1.pop() << "\n";
    std::cout << s1.pop() << "\n";
    s1.push(45);
    std::cout << s1.pop() << "\n";
    std::cout << s1.pop() << "\n";
    std::cout << s1.pop() << "\n";

    return 0;
}