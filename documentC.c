#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char str[80] = "This is - www.tutorialspoint.com - website";
   const char s[2] = "-";
   char *token;
   char** result = (char **)malloc(sizeof(char*));
   *result = strtok(str,s);
   puts(result[0]);
   result = realloc(result, 1 * sizeof(char*));
result[1] = strtok(NULL,s); 
   puts(result[1]);
   puts(result[0]);

   result = realloc(result, 1 * sizeof(char*));
result[2] = strtok(NULL,s); 
   puts(result[2]);
   /* get the first token */
   /*token = strtok(str, s);
   puts(token);
   puts(strtok(NULL, s));
   printf("\n%s\n", s); */
   return 0;
}
