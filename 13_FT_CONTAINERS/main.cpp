//#include <iostream>
/*
#include "test.hpp"

int		main(){
	ft::list<int>	lst;
	
	std::cout << &(*lst.tmp) << std::endl;
	return 0;
}

*/

#include <iostream>
#include <list>

void print_container(std::list<int>& c)
{
    for (std::list<int>::iterator i = c.begin(); i != c.end(); i++) {
        std::cout << *i << ", " << &(*i) << "\n";
    }
    std::cout << '\n';
}

int main ()
{
  std::list<int> mylist;
  std::list<int>::iterator it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) mylist.push_back(i*10);
  std::cout << "first = " << &(*mylist.begin()) << std::endl;
  std::cout << "end = " << &(*mylist.end()) << std::endl;
                              // 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist.begin(); // ^^
  advance (it2,6);            // ^                 ^
  ++it1;                      //    ^              ^

  print_container(mylist);
  it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
                              //    ^           ^

  print_container(mylist);
  it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
                              //    ^          
  print_container(mylist);
  it2 = mylist.insert(it2, 20);
  it2 = mylist.insert(it2, 100);
  print_container(mylist);

  ++it1;                      //       ^        ^
  --it2;                      //       ^     ^

  mylist.erase (it1,it2);     // 10 30 60 80 90
  print_container(mylist);
                              //        ^
  it2++;
  it2++;
  it2 = mylist.erase (it2);     // 10 30 60 80 90
  print_container(mylist);

  std::cout << "it2 next = " << &(*it2) << std::endl;
  std::cout << "mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';

  std::cout << "first = " << &(*mylist.begin()) << std::endl;
  std::cout << "end = " << &(*mylist.end()) << std::endl;

  // set some values:
  mylist.clear();
  for (int i=1; i<10; ++i) mylist.push_back(i*10);
  std::cout << "first = " << &(*mylist.begin()) << std::endl;
  std::cout << "end = " << &(*mylist.end()) << std::endl;
                              // 10 20 30 40 50 60 70 80 90
  //it1 = it2 = mylist.begin(); // ^^
  //advance (it2,6);            // ^                 ^
  //++it1;                      //    ^              ^

  print_container(mylist);
  mylist.remove(20);   // 10 30 40 50 60 70 80 90
                              //    ^           ^

  print_container(mylist);
  mylist.remove(70);   // 10 30 40 50 60 80 90
                              //    ^          
  print_container(mylist);
  //it2 = mylist.insert(it2, 20);
  //it2 = mylist.insert(it2, 100);
  //print_container(mylist);

  //++it1;                      //       ^        ^
  //--it2;                      //       ^     ^

  //mylist.erase (it1,it2);     // 10 30 60 80 90
  //print_container(mylist);
                              //        ^

  std::cout << "mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';

  std::cout << "first = " << &(*mylist.begin()) << std::endl;
  std::cout << "end = " << &(*mylist.end()) << std::endl;
  return 0;
}
