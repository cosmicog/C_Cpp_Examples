
#include <stdio.h>
#include <string.h>

void printString(char* str)
{
	printf("%s\n", str);
}

int main ()
{
	char* str_send = "Hello Mina's Street. I'm Gandalf.";
	printString(str_send);
return 0;
}