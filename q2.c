#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	int commentcheck = 0,lineno = 0,comment = 0,open = 0,close = 0,openlineno = 0,closelineno = 0,i;
	char line[100];
	fp = fopen("testcom", "r");
	if (fp == NULL){
		printf("File cant be opened\n");
		exit(0);
	}
	printf("File opened correctly!\n");
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		lineno++;
		commentcheck = comment = 0;
		if (strstr(line, "/*") && open == 0)
		{
			close = 0;
			open = comment = 1;
			openlineno = lineno;
		}
		if (strstr(line, "*/") && close == 0 && open == 1)
		{
			closelineno = lineno;
			if (open == 1 && close == 0)
			{
				close = 1;
				open = 0;
				printf("Comment opened in line no %d and closed in line no %d\n", openlineno, closelineno);
			}
		}
	}
	if (open == 1 && close == 0)
	{
		printf("Unterminated comment in begin in line no %d. It Has to be closed\n", openlineno);
		commentcheck = 1;
	}
	else if (comment == 1 && commentcheck == 0)
	{
		printf("Comment usage in line %d is validated!\n", lineno);
	}
	return 0;
}
