// factorial calculator updated 8th Dec
// add extra line from lxplus
// add one more line from laptop
// add one more line from ui2 machine

#include <iostream>
using namespace std;

long factorial (long a)
{
  if (a > 1)
   return (a * factorial (a-1));
  else
   return (1);
}

int main ()
{
  long number;
  cout << "Enter maximum number 12 " << endl;
  cout << "Please type a number: ";
  cin >> number;
  cout << number << "! = " << factorial (number) << endl;
  return 0;
}
