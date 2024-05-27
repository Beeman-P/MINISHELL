#include<stdio.h>
#include"main.h"

void execute_internal_commands(char *input_string)
{
	if(strncmp("exit",input_string,4)==0)
	{
		exit(2);
	}
	if(strncmp("pwd",input_string,3)==0)
	{
		system("pwd");
	}
	if(strncmp("cd",input_string,2)==0)
	{
		int i,count=0;
		for(i=2;input_string[i]==' ';i++)
		{
			count++;
		}
		chdir(&input_string[2+count]);
	}
}


