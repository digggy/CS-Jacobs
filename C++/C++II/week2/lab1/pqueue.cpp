/*
CH08-320143
a3p6.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Student
{
private:
  string name;
  double marks;

public:
  Student(string name, double marks)
  {
    this->name = name;
    this->marks = marks;
  }

  //Getter method
  int getmarks()
  {
    return this->marks;
  }
  friend ostream &operator<<(ostream &out, const Student &src)
  {
    out << "------------------------\n";
    out << "Name : " << src.name << endl;
    out << "     |-> Marks : " << src.marks;
    return out;
  }
};

//Compare class
class Compare
{
public:
  bool operator()(Student A, Student B)
  {
    if (A.getmarks() < B.getmarks())
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

//Template function to print the queue
template <class T>
void print_queue(T &src)
{
  while (!src.empty())
  {
    cout << src.top() << endl;
    src.pop();
  }
}
int main(int argc, char **argv)
{

  priority_queue<Student, vector<Student>, Compare> list;

  //Adding Students to the pqueue
  list.push(Student("John", 88));
  list.push(Student("Steve", 90));
  list.push(Student("Daniel", 30));
  list.push(Student("Ron", 21));
  list.push(Student("Rohan", 99));
  list.push(Student("Rohan", 82));

  cout << "The students are arranged from highest to lowest marks \n";
  print_queue(list);

  return 0;
}
