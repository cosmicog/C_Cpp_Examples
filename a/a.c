#include <stdio.h>
#include </home/gazi/C_Cpp_Examples/a/a.h>

void setA1()
{
	a1 = 30;
}

char* getCstrBack1 (char* cstr)
{
	cstr = "Melabaaa?";
	return cstr;
}

char* getCstrBack2 (char* cstr, int some_number)
{
	cstr = "Yes You!";
	a1 = some_number;
	return cstr;
}

int main()
{
	setA1();
	printf("Heyyy!\n");
	printf("%s\n", getCstrBack1("Hello world"));
	printf("A1 --> %d\n", a1);
	printf("-----------------------\n");
	printf("%s\n", getCstrBack2("Hello world", 1309));
	printf("A1 --> %d\n", a1);

return 0;
}