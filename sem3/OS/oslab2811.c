
	/*for(int i=0;i<=5;i++)
	{
		for(int j=0;j<=4-i;j++)
		{
			printf(" ");
		}
		for(int k=0;k<=i;k++)
		printf("*");
		for(int k=5;k<10-i;k++)
		printf("*");
		printf("\n");
	}
	     *****
	    *****
	   *****
	  *****
	 *****
	 
 
	 for(int i=0;i<=5;i++)
	{
		for(int j=0;j<=4-i;j++)
		{
			printf(" ");
		}
		for(int k=0;k<=i;k++)
		printf("*");
		for(int k=1;k<=i;k++)
		printf("*");
		printf("\n");
	}*/
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//#include<sys/wait.h>
#include<stdbool.h>
 
int main()
{
	pid_t child_pid;
	child_pid=fork();
 
	if(child_pid==-1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(child_pid==0)
	{
		printf("Child with PID(%d): is running\n",getpid());
		execl("/bin/date","date",NULL);
		exit(0);//for status 0
		//abort();//for signal
		//return(-1);//for status 255
		execl("/bin/date","date",NULL);
 
	}
	else
	{
		printf("Parent with PID(%d) waiting for child to terminate.\n",getpid());
 
		int status;
		wait(&status);
		printf("Parent resumes\n");
 
		if(WIFSIGNALED(status))
		printf("Child with PID(%d): has terminated by signal %d \n",child_pid,WTERMSIG(status));
		else if(WIFEXITED(status))
		printf("Child with PID(%d): has terminated by status %d.\n",child_pid,WEXITSTATUS(status));
		else
		printf("Child process terminated abnormally %d.\n",child_pid);
 
	}
	return 0;
 
}