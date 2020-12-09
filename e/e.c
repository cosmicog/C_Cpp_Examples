
#include <stdio.h>
#include <string.h>

int main ()
{
	char* str = "I'm Gandalf :p";
	printf("%s\n", str );
	str = "Hello Mina's Street. I'm Gandalf :P";
	printf("%s\n", str );
	
	printf("\nFirst part is succesful...\n\nTrying to sconde one...\n");
	
	strcat(str, "Hello Mina's Street. I'm Gandalf :P. - Gandalf the white.. Gandalf the fool. I'm the real White Wizard.\n");
	
	
return 0;
}