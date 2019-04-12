/*
CH08-320143
a4p6.cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include <map>
class Access
{
public:
  void activate(unsigned long code, unsigned int level);
  void deactivate(unsigned long code);
  void change(unsigned long code, unsigned long level);
  bool isactive(unsigned long code, unsigned int level) const;

private:
  // add properties and/or method(s) if necessary
  std::map<unsigned long, unsigned long> passCodes;
};