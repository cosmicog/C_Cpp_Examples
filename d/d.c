#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void appendString(char* main_str_, char* str_)
{
	size_t length_of_appendix = strlen(str_);
	size_t length_of_main = strlen(main_str_);
	main_str_ = (char*) realloc( 
							main_str_, 
							(sizeof(char) * length_of_appendix) +
							(sizeof(char) * length_of_main)
						);
	strcat( main_str_, str_ );
}

int main ()
{
	char* str_send = "*";
	char* main_str = (char*) malloc ( sizeof(char) * sizeof(str_send) );
	int i;
	for (i = 0; i < 50; i++ )
	{
		appendString(main_str, str_send);
		printf( "%s\n", main_str);
	}
	
	printf("\n\n");
	
	char* last_str = " <-- Final string...";
	appendString(main_str, last_str);
	printf( "%s\n", main_str);
	
	printf("\n\n");
	
	char* first = (char*) malloc ( sizeof(char) * 64 );
	char* second = "World\n";
	
	
	//first = "Hello "; 
	
	
	appendString(first, second);
	
	printf("%s", first);
	
return 0;
}