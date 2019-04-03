
/*
CH08-320143
a2p3.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

template <class T>
class Queue
{
  private:
    int size;
    int current;
    T *arr;

  public:
    // Constructors
    Queue()
    {
        size = 10;
        arr = new T[size];
        current = 0;
    };

    Queue(int length)
    {
        size = length;
        arr = new T[length];
        current = 0;
    };

    //Copy constructor
    Queue(const Queue &src)
    {
        this->size = src.size;
        this->arr = new T[this->size];
        for (int i = 0; i < this->size; i++)
        {
            this->arr[i] = src.arr[i];
        }
        this->current = src.current;
    };

    //Destructor
    ~Queue()
    {
        delete[] this->arr;
    }

    //Getter Method to returns the max size
    int getSize()
    {
        return this->size;
    }

    //Resize method
    void resize(int size)
    {
        T *newarr;
        newarr = new T[size];
        for (int i = 0; i < size; i++)
        {
            newarr[i] = this->arr[i];
        }
        delete[] this->arr;
        if (this->current > size)
        {
            this->current = size;
        }
        this->arr = newarr;
        this->size = size;
    }

    //Service methods push
    bool push(T element)
    {
        if (this->current == this->size)
        {
            std::cout << "Queue Full" << std::endl;
            return false;
        }
        this->arr[this->current++] = element;
        return true;
    };

    //Service method pop
    bool pop(T &out)
    {
        if (this->current == 0)
        {
            std::cout << "Queue already empty" << std::endl;
            return false;
        }
        out = this->arr[0];
        for (int i = 0; i < this->current; i++)
        {
            this->arr[i] = this->arr[i + 1];
        }
        this->current = this->current - 1;
        return true;
    }
    //This returns the last element
    T back()
    {
        return this->arr[this->current - 1];
    };
    //This returns the first element
    T front()
    {
        return this->arr[0];
    };
    //This returns the number of elements
    int getNumEntries()
    {
        return this->current;
    };
};
