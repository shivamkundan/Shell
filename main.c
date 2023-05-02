#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/resource.h>
#include "queue.h"

struct queue pid_list;
int fg_pid=0;
int fg_suspended=0;
int run=1;

int main (int argc, char const *argv[])
{
	const char* args[] = { "p","10","100"};
	printf("%s\n",args[0]);
	//strcpy(input,"p3");

	int i,t,status;
	// char *args[10];
	// char *temp;
	// struct node *p;

	// for (i = 0; i < 10; i++)
	// {
	// 	args[i]=(char *)malloc(10*sizeof(char));
	// }

	// strcpy(args[0],strtok(input,"(,"));
	// for (i=1; (temp=strtok(NULL,",)"))!=NULL; i++) 
	// 	strcpy(args[i],temp);
	// printf("\n");
	// if (strcmp(args[i-1],"&")==0)
	// {
	// 	args[i-1]=NULL;
	// }
	// else
	// 	args[i]=NULL;

	if ((t=fork())==0)
	{
		execl(args[0],args[1],args[2],NULL);
		//execv(args[0],args);
	}

	// kill(pid_list.head->pid,SIGQUIT);
	// sleep(1);
	// kill(pid_list.head->pid,SIGTSTP);


	return 0;
}