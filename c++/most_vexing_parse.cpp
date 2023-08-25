struct A
{
    void doSomething(){}
};
 
int main()
{    
    /* 
    A a();  // is interpreted as a function declaration:
            // it would be a function called a, that takes no parameters 
            // (hence the empty parentheses) and that return an object of type A by value.
    
    a.doSomething(); // ===> compile error in this line
    */

    A a;
    a.doSomething();
    return 0;
}