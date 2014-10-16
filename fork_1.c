# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

int main()
{
	int Pid,PidTerminou, status;
	time_t init,fim;	


	init= time(NULL);
	for (int i = 0; i < 10; i++)
	{

		if((Pid=fork())==0){

			printf("O processo filho vai-se executar o escritor... \n");
			execl("escritor","escritor",0);
				

			exit(-1);
			}

		else if(Pid==-1)
			return -1;
	}
	
	
	for (int i = 0; i < 10; i++)
	{
		PidTerminou= wait(&status);
	}

	fim= time(NULL);
	printf("\nO tempo total de execucao: %ld\n",fim-init );



	return 1;
}
