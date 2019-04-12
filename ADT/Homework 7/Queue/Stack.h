#include <iostream>
using namespace std;

template <class T>
class Stack
{
  private:
    struct StackNode // linked list
    {
        T data;
        StackNode *next;
    };

    // Top of stack
    StackNode *top;
    //Max size of the stack
    int size;
    //Current size of the stack
    int current_size;

  public:
    // Constructors

    Stack()
    {
        this->size = -1;
        this->current_size = 0;
        this->top = NULL;
    };

    Stack(int new_size)
    {
        this->size = new_size;
        current_size = 0;
        top = NULL;
    };

    // Service Methods

    //Method to push the elements to the stack
    void push(T input)
    {
        StackNode *newel = new StackNode;
        newel->data = input;
        if (this->current_size == 0)
        {
            top = newel;
            this->current_size++;
        }
        else
        {
            // If size set, check for overflow
            if (this->current_size + 1 <= this->size || this->size == -1)
            {
                newel->next = top;
                this->current_size++;
                top = newel;
            }
            else
            {
                cout << "\nStack Overflow : Stack Maximum size exceeded" << endl;
            }
        }
    }

    // Method to pop the elements out of the stack
    T pop()
    {
        if (this->current_size == 0)
        {
            cout << "Stack Underflow : Stack Minimum size exceeded" << endl;
            return this->top->data;
        }
        else
        {
            StackNode *temp = this->top;
            T val = this->top->data;
            top = top->next;
            delete temp;
            this->current_size--;
            return val;
        }
    }

    // True if empty, false otherwise
    bool isEmpty()
    {
        if (this->current_size == 0)
        {
            return true;
        }
        return false;
    }
};