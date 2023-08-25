/*
----------------------------------------------------------------------------

struct Base {
    virtual void foo();
};
struct SubClass: Base {
    void foo();
};

SubClass::foo may not be a programmer trying to overload a virtual function, just adding a
function with the same name. Another possible scenario is that when the virtual function of the base
class is deleted, the subclass owns the old function and no longer overloads the virtual function and turns
it into a normal class method, which has catastrophic consequences.

C++11 introduces the two keywords override and final to prevent this from happening.

----------------------------------------------------------------------------

struct Base {
    virtual void foo(int);
};

struct SubClass: Base {
    virtual void foo(int) override; // legal
    virtual void foo(float) override; // illegal, no virtual function in super class
};

----------------------------------------------------------------------------

#include <iostream>

struct Base {
    virtual void foo() final;
};

struct SubClass1 final: Base {

}; // legal

struct SubClass2 : SubClass1 {

}; // illegal, SubClass1 has final

struct SubClass3: Base {
    void foo(); // illegal, foo has final
};

*/