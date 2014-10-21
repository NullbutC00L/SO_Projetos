# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# define FILHOS 10
# define EXECUTAVEL "escritor"


int main()
{
	int Pid,PidTerminou, status;
	int i;
	time_t init,fim;	


	init= time(NULL);
	for (i = 0; i < FILHOS; i++)
	{

		if((Pid=fork())==0){

			printf("O processo filho vai-se executar o escritor... \n");
			execl(EXECUTAVEL,EXECUTAVEL,0);
				
			perror("ocorreu um erro com o processo filho");
			exit(-1);
			}

		else if(Pid==-1)
			return -1;
	}

	
	for (i = 0; i < FILHOS; i++)
	{
		PidTerminou= wait(&status);
	}

	fim= time(NULL);
	printf("\nO tempo total de execucao: %ld\n",fim-init );



	return 1;
}
