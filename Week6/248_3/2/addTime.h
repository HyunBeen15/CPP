#include <iostream>

struct MyTime 
{
    int hour, min, sec;
};

MyTime addTime ( MyTime t1, MyTime t2 );
void addTime( MyTime t1, MyTime t2, MyTime& t3 );
void addTime( MyTime t1, MyTime t2, MyTime* pt );