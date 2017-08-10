#include <stdio.h>
#include <string.h>

int main ()
{
	char* read = "This is stringnggg and that is the MOVE=0<3M\r command";
	char* command = "MOVE";
	char response[64];
	
	char bufcomm[64];
    sprintf ( bufcomm, "%s=", command);
    char *comptr = strstr ( read, bufcomm );
    if ( comptr == NULL )return -1;
	
	char *startptr = comptr + (strlen(command) + 1); // komutun bittiği yerde eşittirden itibaren
	
	char *endptr = strstr(read, "\r");
    if ( endptr == NULL )return -1;
	
	int diff = (endptr - startptr);
	
	int i;
	for (i = 0; i < diff; i++)
	{
		response[i] = *(char*)( startptr + i );
	}
	char* end_of_str = "\0";
	response[diff] = (char)*end_of_str;
	printf("%s\n", response);
// 	printf("%c", response[0]);
// 	printf("%c", response[1]);
// 	printf("%c", response[2]);
// 	printf("%c\n", response[3]);
	
	//char *(*arrptr) = &indptr;
// 	while (indptr < find2)
// 	{
// 		sprintf(response, "%s", *indptr);
// 		indptr++;
// 		sprintf(response, "%s", *indptr);
// 		indptr++;
// 	}
// 	sprintf(response, "%s", *(indptr+1));
// 	printf("%s", *response);
return 0;
}