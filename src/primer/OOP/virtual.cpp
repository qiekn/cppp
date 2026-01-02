#include <iostream>

// ----------------------------------------------------------------------------: test 1

class Base {
public:
  Base() { std::cout << "Base constructor\n"; }

  virtual ~Base() { std::cout << "Base destructor\n"; }
};

class Derived : public Base {
public:
  Derived() { std::cout << "Derived constructor\n"; }

  virtual ~Derived() { std::cout << "Derived destructor\n"; }
};

// ----------------------------------------------------------------------------: test 2


class Base2 {
public:
  Base2() { std::cout << "Base2 constructor\n"; }

  ~Base2() { std::cout << "Base2 destructor\n"; }
};

class Derived2 : public Base2 {
public:
  Derived2() { std::cout << "Dervied2 constructor\n"; }

  virtual ~Derived2() { std::cout << "Dervied2 destrcutor\n"; }
};

// ----------------------------------------------------------------------------: main

int main() {
  // Test 1
  Base* p = new Derived();
  delete p;
  // Test 2
  std::cout << "\n";
  Base2* p2 = new Derived2();
  delete p2;
}

/* --------------------------------- output --------------------------------- *
   Base constructor
   Derived constructor
   Derived destructor
   Base destructor

   Base2 constructor
   Dervied2 constructor
   Base2 destructor
 * -------------------------------------------------------------------------- */
