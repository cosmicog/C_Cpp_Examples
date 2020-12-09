#include <iostream>

using namespace std;

typedef struct
{
    int i;
    bool b;
} IBs;

typedef struct
{
    int i;
    char c;
} ICs;

void printRandomStruct(IBs * s, bool ibs = true)
{
    if (ibs)
    {
        IBs ibs = *(IBs*)s;
        cout << "i: " << ibs.i << ", b: " << ibs.b << endl;
    }
    else
    {
        ICs ics = *(ICs*)s;
        cout << "i: " << ics.i << ", c: " << ics.c << endl;
    }
}

int main ()
{
	IBs s;
    s.i = 13;
    s.b = true;

    ICs c;
    c.i = 9;
    c.c = '>';

    printRandomStruct(&s);
    printRandomStruct((IBs*)&c, false);


return 0;
}
