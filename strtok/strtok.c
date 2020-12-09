
#include <stdio.h>
#include <string.h>

int main ()
{
	char str_send[] = "Hello Mina's Street. I'm Gandalf.";
	
	char* str_part = strtok(str_send, " ");
	int i = 0;
	while(str_part != NULL)
	{
		printf("[%d] ---> %s \n", i, str_part);
		str_part = strtok(NULL, " ");
		i++;
	}
	
	
	
return 0;
}