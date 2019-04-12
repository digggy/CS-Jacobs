#include <bits/stdc++.h>
#include "BST.h"
class Element
{
  public:
    //Properties
    int info;
    Element *next;

    //Constructor
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

  public:
    LinkedList()
    {
        this->first = NULL;
    };

    //Method to push a new element in the list.
    void push(int src)
    {
        Element *newel = new Element(src);

        if (this->first != NULL)
        {
            Element *current = this->first;

            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newel;
        }
        else
        {
            this->first = newel;
        }
    };

    //Method to get all the elements
    void toBTS(BST &src)
    {
        Element *current;
        current = this->first;
        while (current != NULL)
        {
            src.insert(current->info);
            current = current->next;
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
