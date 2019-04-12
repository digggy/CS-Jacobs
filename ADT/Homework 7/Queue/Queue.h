#include "Stack.h"

template <class T>

class Queue
{
  private:
    Stack<T> A;
    Stack<T> B;
    int size;

  public:
    Queue()
    {
        size = 0;
    }

    //Service Methods
    void enqueue(T element)
    {
        A.push(element);
        this->size++;
    }

    T dequeue()
    {
        if (B.isEmpty())
        {
            while (!A.isEmpty())
            {
                B.push(A.pop());
            }
        }
        return B.pop();
    };

    bool isEmpty()
    {
        if (this->size == 0)
        {
            return true;
        }
        return false;
    };
    int getSize()
    {
        return this->size;
    };
};