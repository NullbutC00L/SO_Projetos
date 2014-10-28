# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# define FILHOS 10
# define EXECUTAVEL "escritor"


int main()
{
	int Pid, status;
	int i;
	time_t init,fim;	


	init= time(NULL);	/*obtem os segundos do computador neste momento*/
	for (i = 0; i < FILHOS; i++)	/*ciclo que vai criar os N processos filhos neste caso 10*/
	{

		if((fork())==0){	

			printf("O processo filho vai-se executar o escritor... \n");
			execl(EXECUTAVEL,EXECUTAVEL,0);	/* executa um certo ficheiro dentro de cada processo filho */
				
			perror("ocorreu um erro com o processo filho");	/* caso o execl nao se execute por causa de algum erro o codigo chegará aqui e executara esta linha retornando um erro */
			exit(-1);
			}

		else if(Pid==-1)	/*caso o pid retorne -1 deverá retornar um erro*/
			return -1;
	}

	
	for (i = 0; i < FILHOS; i++) 	/*lança no sistema N waits para esperarem pelos respectivos processos filhos neste caso 10 */
	{
		wait(&status);
	}

	fim= time(NULL);		/*obtem os segundos do computador neste momento*/
	printf("\nO tempo total de execucao: %ld\n",fim-init );	/* tiramos os segundos iniciais aos finais para termos o tempo que demorou a executar os processos*/



	return 1;
}
