#include<stdio.h>
#include"main.h"


void echo(char *input_string,int status)
{
	if(strncmp("echo $?",input_string,7)==0)
	{
		printf("%d\n",status);
	}
	if(strncmp("echo $$",input_string,7)==0)
	{
		printf("%d\n",getpid());
	}
	if(strncmp("echo $SHELL",input_string,11)==0)
	{
		system("pwd");
	}
}
