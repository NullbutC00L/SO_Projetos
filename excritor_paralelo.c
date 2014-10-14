# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <stdio.h>


int escritor(char *file_vect[],char *text_vect[],int tam_file,int tam_text);
int rnd(int i);

int main()
{
	int Pid,PidTerminou, Estado;
	
	char *texts_vect[]={"aaaaaaaaa\n","bbbbbbbbb\n","ccccccccc\n","ddddddddd\n",
		"eeeeeeeee\n","fffffffff\n","ggggggggg\n","hhhhhhhhh\n","iiiiiiiii\n","jjjjjjjjj\n"};
	
	char *files_vect[]={"SO2014-0.txt","SO2014-1.txt","SO2014-2.txt","SO2014-3.txt","SO2014-4.txt"};
	
	int pos_file = sizeof(files_vect)/sizeof(char*); 					
	int pos_text = sizeof(texts_vect)/sizeof(char*);

	
	for (int i = 0; i < 3; ++i) {

		if((Pid=fork())==0){
			printf("sou o processo filho - %d\n",i);
			escritor(files_vect,texts_vect,pos_file,pos_text);
			
		}

		else{
			printf("criou um subprocesso de indentificador = %d\n",Pid);
			PidTerminou= waitpid(Pid, NULL, WNOHANG);
			printf("terminou um subprocesso de indentificador = %d\n",PidTerminou);

		}
	}
	

	return 0;


}



/***************************************************************************
**																		  **	
**						Funcao escritor                                   **
**																		  **		
***************************************************************************/
int escritor(char *file_vect[],char *text_vect[],int tam_file,int tam_text){
	int a=0;
	int pos_text,pos_file;
	int file;
	int i;
	srand(time(NULL));
	
	for(;a<512;a++){ 
	
		pos_file = rnd(tam_file); 		/*atribuimos valores random que escolheram na lista o nome do ficheiro a atribuir*/			
		pos_text = rnd(tam_text);							

		
		
		
			
		file=open(file_vect[pos_file],O_WRONLY | O_APPEND|O_TRUNC|O_CREAT,
				S_IRUSR|S_IRGRP|S_IROTH|S_IWUSR|S_IWGRP|S_IWOTH|S_IXUSR|S_IXGRP|S_IXOTH); /*faz-se uma chamada de sistema para abrir o ficheiro com as respectivas permissoes*/
		if(file < 0)		/*verifica se o ficheiro foi aberto com sucesso*/
	        return -1;
		for(i=0;i<1024;i++){		
		
			if (write(file,text_vect[pos_text],strlen(text_vect[pos_text]))!=strlen(text_vect[pos_text])){		/*faz-se uma chamada de sistema para escrever no ficheiro */

				write(2,"Houve um erro na escrita do ficheiro\n",37);
		        return -1;														/*caso ocorra um erro ao escrever no ficheiro e escrito no ficheiro a menssagem = da return de -1 */
				}

		}
		close(file);			/*fecha o ficheiro para guardar as alterações efectuadas*/
	}


	return 1;
}

int rnd(int i){		/*funcao que gera um numero random com o intuito de escolher a frase a escrever ou o nome doficheiro a abrir*/
	int r;
	r = rand()%i;

	return r;
}
