#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char*argv[])
{
	FILE*f;
	char fname[100];
	printf("파일이름:");
	scanf("%s", &fname);
	printf("<Count Result>\n");

	int lineCount = 1;
	f = fopen(fname, "r");
	if (f != NULL)
	{
		char buffer[1000];
		char *delimiter = "\n";
		while (!feof(f))
		{
			fgets(buffer, sizeof(buffer), f);
			char*ptoken = strtok(buffer, delimiter);
			while (ptoken != NULL)
			{
				lineCount++;
				ptoken = strtok(NULL, delimiter);
			}
		}
		printf("Line count: %d\n", lineCount - 1);
		fclose(f);
	}
	else
	{
		printf("파일이 열리지 않습니다.\n");
		return;
	}

	int wordCount = 1;
	f = fopen(fname, "r");
	if (f != NULL)
	{
		char buffer[300];
		char *delimiter = " \n";
		while (!feof(f))
		{
			fgets(buffer, sizeof(buffer), f);
			char*ptoken = strtok(buffer, delimiter);
			while (ptoken != NULL)
			{
				wordCount++;
				ptoken = strtok(NULL, delimiter);
			}
		}
		printf("Word count: %d\n", wordCount - 1);
		fclose(f);
	}
	else
	{
		printf("파일이 열리지 않습니다.\n");
		return;
	}

	int characterCount = 0;
	f = fopen(fname, "r");
	if (f != NULL)
	{
		char buffer[300];
		char *delimiter = " \n";
		while (!feof(f))
		{
			fgets(buffer, sizeof(buffer), f);
			char*ptoken = strtok(buffer, delimiter);
			while (ptoken != NULL)
			{
				characterCount += strlen(ptoken);
				ptoken = strtok(NULL, delimiter);
			}
		}
		printf("Character count:%d\n", characterCount);
		fclose(f);
	}
	else
	{
		printf("파일이 열리지 않습니다.\n");
		return;
	}

	FILE *frev;

	if ((f = fopen(fname, "r")) == NULL)
	{
		printf("f1파일이 열리지 않습니다.\n");
		exit(1);
	}
	if ((frev = fopen("infile.rev", "w")) == NULL)
	{
		printf("f2파일이 열리지 않습니다.\n");
		fclose(f);
		exit(1);
	}

	char a;
	while ((a = getc(f)) != EOF)
	{
		if (isalpha(a))
		{
			if (islower(a))
				a = toupper(a);
			else if (isupper(a))
				a = tolower(a);
		}
		putc(a, frev);
	}
	fclose(f);
	fclose(frev);
	printf("File saved in infile.rev\n");
	return 0;

}
