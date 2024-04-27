#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>


int nfilho;

void proc_filho()
{
	printf("Processo FILHO %d iniciado\n",nfilho);
	printf("Vair dormir por %d segundos\n",nfilho*10);
	sleep(nfilho*10);
	printf("Processo FILHO %d encerrado\n",nfilho);
}

void main()
{
	pid_t pid1, pid2, pid3, pid4;
	nfilho+=1;
	pid1 = fork();
	
	if(pid1>0)
	{
		printf("Processo PAI iniciado\n");
		nfilho+=1;
		wait(NULL);
		pid2 = fork();
		if(pid2>0)
		{
			nfilho+=1;
			wait(NULL);
			pid3 = fork();
			
			if(pid3>0)
			{
				nfilho+=1;
				wait(NULL);
				pid4 = fork();
				
				if(pid4>0)
				{
					wait(NULL);
					printf("Processo PAI encerrado\n");
				} else if (pid4==0)
				{
					proc_filho();
				} else
				{
					exit(-1);
				}
			} else if (pid3==0)
			{
				proc_filho();
			} else
			{
				exit(-1);
			}
		} else if (pid2==0)
		{
			proc_filho();
		} else
		{
			exit(-1);
		}	
	} else if (pid1==0)
	{
		proc_filho();
	} else
	{
		exit(-1);
	}
}
