#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

//Variavel global número de processo filhos
int nfilho;

//Método inicializador de processso filho
void cria_ProcFilho()
{
	printf("Processo FILHO %d iniciado\n",nfilho);
	printf("Vair dormir por %d segundos\n",nfilho*10);
	sleep(nfilho*10);
	printf("Processo FILHO %d encerrado\n",nfilho);
}

void main()
{
	//Variaveis pid para os processos filhos
	pid_t pid;
	
	for(int i=0;i<4;i+=1)
	{
		nfilho+=1;
		
		//Criação do primeiro processo filho
		pid = fork();
		if(pid>0)
		{
			wait(NULL);
		}else if
		{
			cria_ProcFilho();
		}else
		{
			exit(-1);
		}
	}
}
