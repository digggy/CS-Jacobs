#include <iostream>
#include "LinkedList.h"
class Node
{
  public:
    // Properties of a Node
    int info;
    Node *right;
    Node *left;

    //Constructor of Node
    Node(int info)
    {
        this->info = info;
        this->right = NULL;
        this->left = NULL;
    }
};

class BST
{
  private:
    Node *root;

  public:
    //Constructor of BST
    BST()
    {
        this->root = NULL;
    };

    //Method to traverse through the list and insert at the correct position
    void rec_ins(Node *cur, int input)
    {
        if (cur->info >= input)
        {
            if (cur->left == NULL)
            {
                cur->left = new Node(input);
            }
            else
            {
                this->rec_ins(cur->left, input);
            }
        }
        else
        {
            if (cur->right == NULL)
            {
                cur->right = new Node(input);
            }
            else
            {
                this->rec_ins(cur->right, input);
            }
        }
    };

    //Method to insert element to the Binary Search Tree
    void insert(int input)
    {
        Node *newel = new Node(input);

        if (this->root == NULL)
        {
            this->root = newel;
        }
        else
        {
            this->rec_ins(this->root, input);
        }
    };

    //Recursive function to traverse through the tree printing the the info in the Nodes
    void rec_print(Node *cur)
    {
        if (cur->left != NULL)
        {
            rec_print(cur->left);
        }
        std::cout << cur->info << " ";
        if (cur->right != NULL)
        {
            rec_print(cur->right);
        }
    }

    //Print the elements in the BST in the order
    void printBST()
    {
        if (this->root != NULL)
        {
            rec_print(this->root);
        }
        else
        {
            std::cout << "The BST in Empty" << std::endl;
        }
    }

    //Function to travese through the list and push to the Linked list
    void rec_addtolist(Node *cur, LinkedList &src)
    {
        if (cur->left != NULL)
        {
            rec_addtolist(cur->left, src);
        }
        src.push(cur->info);
        if (cur->right != NULL)
        {
            rec_addtolist(cur->right, src);
        }
    }
    //Method to convert the binary tree to sorted linked list
    void BSTtoList(LinkedList &src)
    {
        if (this->root != NULL)
        {
            rec_addtolist(this->root, src);
        }
        else
        {
            std::cout << "The BST in Empty" << std::endl;
        }
    }
};