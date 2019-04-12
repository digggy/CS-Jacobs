/*
CH08-320143
a4p4.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <set>
class Access
{
public:
  void activate(unsigned long code);
  void deactivate(unsigned long code);
  bool isactive(unsigned long code) const;

private:
  // add properties and/or method(s) if necessary
  std::set<unsigned long> passCodes;
};