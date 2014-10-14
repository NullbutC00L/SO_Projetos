# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>



int Pid,PidTerminou, status;
time_t init,fim;
int main()
{	


	init= time(NULL);
	printf("tempo inicial-%ld\n",init);
	for (int i = 0; i < 10; ++i)
	{

			if((Pid=fork())==0){

				printf("sou o processo filho\n");
				execl("escritor","escritor",0);
				printf("\n");
				printf("\n");

				exit(-1);
			}

			else{

				
				printf("\n");

				printf("criou um subprocesso de indentificador = %d\n",Pid);
				PidTerminou= wait(&status);

				printf("terminou um subprocesso de indentificador = %d\n",PidTerminou);
				

				
			}
	}

	fim= time(NULL);
	printf("tempo final-%ld\n",fim);
	printf("tempo total-%ld\n",fim-init );
	return 0;
	

}