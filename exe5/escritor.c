# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <sys/file.h>
# include <errno.h>
# include <stdio.h>


int escritor(char *file_vect[],char *text_vect[],int tam_file,int tam_text);
int rnd(int i);

int main()
{
	
	char *texts_vect[]={"aaaaaaaaa\n","bbbbbbbbb\n","ccccccccc\n","ddddddddd\n",
		"eeeeeeeee\n","fffffffff\n","ggggggggg\n","hhhhhhhhh\n","iiiiiiiii\n","jjjjjjjjj\n"};
	
	char *files_vect[]={"SO2014-0.txt","SO2014-1.txt","SO2014-2.txt","SO2014-3.txt","SO2014-4.txt"};
	
	int pos_file = sizeof(files_vect)/sizeof(char*); 					
	int pos_text = sizeof(texts_vect)/sizeof(char*);

	
	escritor(files_vect,texts_vect,pos_file,pos_text);
	
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
	int numb=0;

	for(;a<512;a++){ 
	
		pos_file = rnd(tam_file); 		/*atribuimos valores random que escolheram na lista o nome do ficheiro a atribuir*/			
		pos_text = rnd(tam_text);							

				
		file=open(file_vect[pos_file],O_WRONLY |O_TRUNC|O_CREAT,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); /*faz-se uma chamada de sistema para abrir o ficheiro com as respectivas permissoes*/
		
		if (flock(file,LOCK_EX|LOCK_NB) == -1) {
               int errsv = errno;
               numb++;

               printf("flock failed numb=  %d\n",numb);
 
           }

       flock(file,LOCK_EX);

		if(file < 0)		/*verifica se o ficheiro foi aberto com sucesso*/
	        return -1;
		for(i=0;i<1024;i++){		
		
			if (write(file,text_vect[pos_text],strlen(text_vect[pos_text]))!=strlen(text_vect[pos_text])){		/*faz-se uma chamada de sistema para escrever no ficheiro */

				write(2,"Houve um erro na escrita do ficheiro\n",37);
		        return -1;														/*caso ocorra um erro ao escrever no ficheiro e escrito no ficheiro a menssagem = da return de -1 */
				}

		}
		flock(file,LOCK_UN);
		close(file);			/*fecha o ficheiro para guardar as alterações efectuadas*/
	}


	return 1;
}

int rnd(int i){		/*funcao que gera um numero random com o intuito de escolher a frase a escrever ou o nome doficheiro a abrir*/
	int r;
	r = rand()%i;

	return r;
}
