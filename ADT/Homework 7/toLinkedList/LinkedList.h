#include <iostream>
class Element
{
  public:
    // Properties
    int info;
    Element *next;

    // Constructor
    Element(int info)
    {
        this->info = info;
        this->next = NULL;
    }
};

class LinkedList
{
  private:
    Element *first;
    Element *last;

  public:
    LinkedList()
    {
        this->first = NULL;
        this->last = NULL;
    };

    // Method to push a new element in the list.
    void push(int src)
    {
        Element *newel = new Element(src);

        if (this->last != NULL)
        {
            Element *current = this->last;
            current->next = newel;
            this->last = newel;
        }
        else
        {
            this->first = newel;
            this->last = newel;
        }
    };

    //Method to all the elements in the list
    void print_All()
    {
        Element *current;
        current = this->first;
        while (current != NULL)
        {
            std::cout << current->info << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }
};