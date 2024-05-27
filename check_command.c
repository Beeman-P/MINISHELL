#include<stdio.h>
#include<string.h>
#include"main.h"


int check_command_type(char *command)
{
	char *builtins[] = {"echo", "printf", "read", "cd", "pwd", "pushd", "popd", "dirs", "let", "eval",
						"set", "unset", "export", "declare", "typeset", "readonly", "getopts", "source",
						"exit", "exec", "shopt", "caller", "true", "type", "hash", "bind", "help", NULL};
	int i=0;
	char ch;
	char buffer[20];
       if(*command=='\0')
	       return NO_COMMAND;

	for(i=0;builtins[i]!=NULL;i++)
	{
		if(strcmp(builtins[i],command)==0)
			return BUILTIN;
	}
        
       int fp = open("external.txt",O_RDONLY);i=0;



       while(read(fp,&ch,1)>0)
       {
	       if(ch!='\n')
	       {
		       buffer[i++]=ch;
	       }
	       else
	       {
		       buffer[i]='\0';i=0;
		       if(strcmp(buffer,command)==0)
			       return EXTERNAL;
	       }
       }



}

