#include<stdio.h>
#include"main.h"
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

pid_t pid;

int main()
{
	char prom[] = ANSI_COLOR_YELLOW"MINISHELL";
	char istr[100];
      system("clear");
      scan_input(prom,istr);
      return 0;
}
void scan_input(char *prompt,char *input_string)
{
	char *command;
	int type,status;
	while(1)
	{
		//print the prompt message
		printf("%s$",prompt);
               //read the input from user
		scanf(" %[^\n]",input_string);
                   
		//validate the command
		if(strstr(input_string,"Ps1=")!=0)
	          {
			  if(strstr(input_string," ")==0)
		         	  strcpy(prompt,input_string+4);
			  else
				  printf("Command not fount\n");
		  }
	    	  command = get_command(input_string);
		  type = check_command_type(command);
		
		 if(type == EXTERNAL)
		 {
			 pid = fork();

			 if(pid > 0)
			 {
				 wait(&status);
				 if(WIFEXITED(status))
				 {
					 printf("Child process is terminated %d\n",pid);
				 }
			 }
			 else if(pid==0)
			 {
				 int res_status = system(input_string);
				 if(res_status==0)
				 {
					 exit(1);
				 }
			 }
			 else
			 {
				 perror("Fork : Failed");
				 exit(1);
			 }
		 }
		 echo(input_string,status);

		 execute_internal_commands(input_string);
	}
}	
char *get_command(char *input_string)
{
      static char command[20];
      int i=0;
	while(1)
	{
	    if(*input_string ==' ' || *input_string =='\0')
		    break;

	    command[i++]=*input_string;
	    input_string++;
	}
	command[i]='\0';
	return command;
}
