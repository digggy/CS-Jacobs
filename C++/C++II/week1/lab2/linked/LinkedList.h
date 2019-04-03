/*
CH08-320143
a2p4.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
using namespace std;

template <class T>
class Element
{
  public:
    T value;
    Element *next;
    Element *prev;

  public:
    Element(T &value)
    {
        this->value = value;
    }
};

template <class T>
class LinkedList
{
  private:
    Element<T> *start;
    Element<T> *end;
    int counter;

  public:
    //Constructor for the Dlinkedlist
    LinkedList()
    {
        start = NULL;
        end = NULL;
        counter = 0;
    }

    //Destructor for the Dlinkedlist
    ~LinkedList()
    {
        if (start != NULL)
        {
            Element<T> *del;
            Element<T> *temp = this->start;

            while (temp != NULL)
            {
                del = temp;
                temp = temp->next;
                delete del;
            }
        }
    }

    T front()
    {
        return start->value;
    }

    T back()
    {
        return end->value;
    }

    void pushFront(T value)
    {
        Element<T> *newel = new Element<T>(value);
        newel->next = this->start;
        newel->prev = NULL;
        this->counter++;

        //If the list is initially starting with 1 element
        if (this->counter == 1)
        {
            this->start = this->end = newel;
        }
        else
        {
            newel->next->prev = newel;
        }
        //Setting the main start pointer to the start element
        this->start = newel;
    }

    void pushBack(T value)
    {
        Element<T> *newel = new Element<T>(value);
        newel->next = NULL;
        newel->prev = this->end;
        this->counter++;

        //If the list is initially ending with 1 element
        if (this->counter == 1)
        {
            this->start = this->end = newel;
        }
        else
        {
            newel->prev->next = newel;
        }
        //Setting the main end pointer to the end element
        this->end = newel;
    }

    //To delete the element in the last
    T delBack()
    {
        Element<T> *temp = NULL;

        if (this->counter > 0)
        {
            temp = this->end;
            this->end = temp->prev;
            T val = temp->value;
            delete temp;
            this->counter--;
            return val;
        }
        else
        {
            cout << "Error : Size less than 1 " << endl;
            this->start = NULL;
            return this->start->value;
        }
    }

    //To delete the element in the front
    T delFront()
    {
        Element<T> *temp = NULL;

        if (this->counter > 0)
        {
            temp = this->start;
            this->start = temp->next;
            T val = temp->value;
            delete temp;
            this->counter--;
            return val;
        }
        else
        {
            cout << "Error : Size less than 1 " << endl;
            this->start = NULL;
            return this->start->value;
        }
    }

    //Find the number of elements
    int getSize()
    {
        return this->counter;
    }
};