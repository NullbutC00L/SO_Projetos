# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include <stdlib.h>
# include <string.h>
# include <sys/file.h>
# define TAM_BUFF 11
# define LINE_SIZE 10

int leitor(char *file_vect[],int tam_file);
int rnd(int i);

int main()
{
	
	char *files_vect[]={"SO2014-0.txt","SO2014-1.txt","SO2014-2.txt","SO2014-3.txt","SO2014-4.txt"};
	
	int pos_file = sizeof(files_vect)/sizeof(char*); 					
	

	
	
	leitor(files_vect,pos_file);

	return 0;


}

/***************************************************************************
**																		  **	
**						Funcao leitor	                                  **
**																		  **		
***************************************************************************/


int leitor(char *file_vect[],int tam_file){
	char buff[TAM_BUFF];
	char buff_cmp[TAM_BUFF];
	int file,rd,pos_file ;
	int p;

	srand(time(NULL));	
							
	pos_file = rnd(tam_file);


	file=open(file_vect[pos_file],O_RDONLY,S_IRUSR|S_IRGRP|S_IROTH|S_IXUSR|S_IXGRP|S_IXOTH);
	/*faz-se uma chamada de sistema para abrir o ficheiro com as respectivas permissoes*/
	flock(file,1);
	if(file < 0)
        return -1;

	rd=read(file,buff_cmp,LINE_SIZE);	/*chamada de sistema para ler o ficheiro*/
	
	if (rd<=0)
		return -1;

	for(p=0;p<1023;p++){

		strcpy(buff," ");
		rd=read(file,buff,LINE_SIZE);
		if (rd<=0)
			return -1;

		if (memcmp(buff,buff_cmp,LINE_SIZE)!=0){	/*caso nao sejam iguais retorna -1*/
			
			return -1;
		}
	


	
	}
	flock(file,8);
	close(file);
	
	
	return 0;



}


int rnd(int i){	/*funcao que gera um numero random com o intuito de escolher a frase a escrever ou o nome doficheiro a abrir*/		
	int r;
	r = rand()%i;

	return r;
}
