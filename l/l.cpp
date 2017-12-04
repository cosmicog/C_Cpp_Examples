#include <iostream>
#include <math.h>

using namespace std;

float calcEntropyOneAttr(int count0, int count1)
{
   float p0, p1;
   float tot = count0 + count1;
   p0 = count0 / tot;
   p1 = count1 / tot;
   float ret_neg = (log2(p0)*p0 ) + (log2(p1)*p1);
   return -1* ret_neg;
}
int main()
{
    cout << "ENT(5,9) = " << calcEntropyOneAttr(5, 9) << endl; 
}

