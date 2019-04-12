/*
CH08-320143
a3p5.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <deque>
using namespace std;

class WindGauge
{
  public:
    WindGauge(int period = 10);
    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;
    void dump();

  private:
    // add properties and/or method(s) here
    int period;
    deque<int> A;
};