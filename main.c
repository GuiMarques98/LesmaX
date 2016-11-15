/*
Projeto de PDS Grupo 3
Membros:
	Guilherme Marques Moreira da Silva	
	Gustavo Cavalcante Linhares
	Gustavo 
*/
//Includes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

//Defines ATOR
#define ATORMAXNOME 30
#define ATORMAXFILMES 200
#define ATORMAXNACIONALIDADE 20
//Defines SALAS
#define SALAMAXNOME 30
#define SALACARTAZ 3
#define SALACODIGO 100

//Structs

//Structs para salas de cinema
typedef struct{
	char local[SALAMAXNOME];
	int codigo;
	int numero;
	int entra_cartaz[SALACARTAZ]; // 0 - dia, 1- mes e 2- ano
	int sai_cartaz[SALACARTAZ];  
	char nome_filme[SALAMAXNOME];
}Salas;
//Struct para atores
typedef struct{
	char nome[ATORMAXNOME];
	int matricula;
	int idade;
	int profissao;
	char filmes_feitos[ATORMAXFILMES];
	char nacionalidade[ATORMAXNACIONALIDADE];
}Atores;

//Cabeçalhos

void menuSalasCinema(int tipo);//1 - Nova Sala,2 - Editar Sala , 3 - Apagar Sala ,4 - Exluir Sala e 5 menu de opcao

//Principal
int main()
{
	//Declarações 
	char opcao;
	int validaOpcaoMain(int opcao);
	void salasCinema();
	//Instruções
	setlocale(LC_ALL, "");
	
	do
	{
		printf("PRINCIPAL\n______________________________________________________________________\n\n");
		do
		{
			printf("\nEscolha o menu que deseja entrar:\n1-Filmes\n2-Salas de Cinema\n3-Atores\n0-Para encerrar o programa\nInsira a opção:");
			opcao = getch();
			
		}while(!validaOpcaoMain(opcao));
		
		
		switch(opcao)
		{
			case '1':
				
				break;
			case '2':
				salasCinema();
				break;
			case '3':
				
				break;
		}
		system("cls");
	}while(opcao != '0');
	
    return 0;
}

//================================================SUBPROGRAMAS==================================================
//=================================MENU PRINCIPAL====================================
//Objetivo : Validar opção do menu principaç 
//Parametro: Opção 
//Retorno  : Situação da validação 
int validaOpcaoMain(int opcao)
{
	//Instruções 
	
	if(opcao < 48 || opcao > 51)
	{
		printf("Opção inválida!\n");
		return 0;
	}
	else
	{
		return 1;
	}
}

//====================================ATORES=========================================


//===================================FILMES==========================================


//===================================SALAS DE CINEMA ================================
//Objetivo : Marter salas de cinema
//Parametro: nenhum
//Retorno  : nenhum 
//Funçoes gerais
void apresentaSala(Salas *novaSala, int numeroCadastros );
void validaCodigoSala(int *codigoSala);
void validaNomeSala(char *nomeSala);
int validaNumeroSala(int numeroSala,char *localSala);
void validaDataSala(int *data,int tipo);
int validaDataSalaSaida (int *dataSaiCartaz,int *dataCartaz);

void salasCinema(){
	//Declarações
	void cadastraSala();
	void editarSala();
	void apagaSala();
	void listarSala();
	char opcao;
	//Instruções 
	do{
		system("cls");
		menuSalasCinema(5);
		printf("\nDigite a opcao escolhida: ");
		opcao = getche();
		switch(opcao){
			case '1':
				system("cls");
				cadastraSala();
				break;
			case '2':
				system("cls");
				editarSala();
				break;
			case '3':
				system("cls");
				apagaSala();
				break;
			case '4':
				system("cls");
				listarSala();
				break;
			case '5':
				break;
			default :
				system("cls");
				printf("Opcao invalida. Precione qualquer tecla");
				getche();
		}
	}while(opcao != '5');
	
}
//======================CADASTRAR===========================
//Objetivo : cadastrar sala de cinema
//Parametro: nenhum
//Retorno  : nenhum 
void cadastraSala(){
	//Declarações 
	Salas novaSala;
	FILE *pArquivo;
	//Instruções 
	menuSalasCinema(1);
	if((pArquivo=fopen("salasCinema.bin","ab"))!=NULL){
		printf("Digite o codigo da sala, valores maiores que %d: ",SALACODIGO);
		scanf("%d",&novaSala.codigo);
		validaCodigoSala(&novaSala.codigo);
		
		fflush(stdin);
		printf("Digite o local da sala : ");
		fgets(novaSala.local, SALAMAXNOME ,stdin);
		validaNomeSala(novaSala.local);
		
		printf("Digite o nome do filme : ");
		fgets(novaSala.nome_filme, SALAMAXNOME ,stdin);
		validaNomeSala(novaSala.nome_filme);
		fflush(stdin);
		
		printf("Digite o numero da sala, valores maiores que 0: ");
		scanf("%d",&novaSala.numero);
		novaSala.numero = validaNumeroSala(novaSala.numero,novaSala.local);
		
		system("cls");
		menuSalasCinema(1);
		
		printf("Digite o ano que entrou em cartaz: ");
		scanf("%d",&novaSala.entra_cartaz[2]);
		validaDataSala(&novaSala.entra_cartaz[2],2);
		
		printf("Digite o mes que entrou em cartaz: ");
		scanf("%d",&novaSala.entra_cartaz[1]);
		validaDataSala(&novaSala.entra_cartaz[1],1);
			
		printf("Digite o dia que entrou em cartaz: ");
		scanf("%d",&novaSala.entra_cartaz[0]);
		validaDataSala(&novaSala.entra_cartaz[0],0);
		
		do{
			printf("Digite o ano que saiu de cartaz: ");
			scanf("%d",&novaSala.sai_cartaz[2]);
			validaDataSala(&novaSala.sai_cartaz[2],2);
			
			printf("Digite o mes que saiu de cartaz: ");
			scanf("%d",&novaSala.sai_cartaz[1]);
			validaDataSala(&novaSala.sai_cartaz[1],1);
				
			printf("Digite o dia que saiu de cartaz: ");
			scanf("%d",&novaSala.sai_cartaz[0]);
			validaDataSala(&novaSala.sai_cartaz[0],0);
		}while(validaDataSalaSaida(novaSala.sai_cartaz,novaSala.entra_cartaz)!=0);
		
		system("cls");
		apresentaSala(&novaSala,1);
		if(fwrite(&novaSala,sizeof(novaSala),1,pArquivo)==1){
			printf("O cadastro foi salvo. Precione qualquer tecla.");
		}
		else{
			printf("Nao foi possivel salvar o cadastro. Precione qualquer tecla");
		}
	}
	else{
		printf("O arquivo nao pode ser aberto. Precione qualquer tecla");
	}
	getche();
	fclose(pArquivo);
	system("cls");
}
//Objetivo : validar o codigo da sala
//Parametro: codigo da sala
//Retorno  : nenhum 
void validaCodigoSala(int *codigoSala){
	//Declarações 
	int flag;
	FILE *pArquivo;
	Salas novaSala;
	//Instruções
	do{
		flag=0;
		while(*codigoSala <= SALACODIGO ){
			printf("Numero invalido. Digite um numero maior que %d: ",SALACODIGO);
			scanf("%d",codigoSala);
			flag=1;
		}
		if((pArquivo=fopen("salasCinema.bin","rb"))!=NULL){
			while(!feof(pArquivo)){
				if(fread(&novaSala,sizeof(novaSala),1,pArquivo)==1){
					if(novaSala.codigo == *codigoSala){
						printf("Esse codigo ja existe. Digite outro: ");
						scanf("%d",codigoSala);
						flag=1;
					}
				}
			}
		}
		fclose(pArquivo);
	}while(flag == 1);
	
}
//Objetivo : validar o nome digitado
//Parametro: nome digitado 
//Retorno  : nenhum 
void validaNomeSala(char *nomeSala){
	//Declarações 
	
	//Instruções
	if(nomeSala[strlen(nomeSala)-1]=='\n'){
		nomeSala[strlen(nomeSala)-1] = '\0';
	}     
    while(strlen(nomeSala) <= 0  || strcmp(nomeSala," ") == 0){
    	printf("Nome invalido.Insira o nome sem espaço no primeiro caracter:");
    	fgets(nomeSala, SALAMAXNOME, stdin);
		if(nomeSala[strlen(nomeSala)-1]=='\n'){
			nomeSala[strlen(nomeSala)-1] = '\0';
		}	
	}
    
}
//Objetivo : validar o numero da sala
//Parametro: numero da sala e o local da sala
//Retorno  : numero da sala valido 
int validaNumeroSala(int numeroSala,char *localSala ){
	//Declarações 
	int flag;
	FILE *pArquivo;
	Salas novaSala;
	//Instruções
	do{
		flag=0;
		while(numeroSala <= 0){
			printf("Numero invalido.Digite um numero maior que 0:");
			scanf("%d",&numeroSala);
		}
		
		if((pArquivo=fopen("salasCinema.bin","rb"))!=NULL){
			while(!feof(pArquivo)){
				if(fread(&novaSala,sizeof(novaSala),1,pArquivo)==1){
					if((stricmp(localSala , novaSala.local))==0){
						if(novaSala.numero == numeroSala){
							printf("Esse sala ja existe. Digite outra: ");
							scanf("%d",&numeroSala);
							flag=1;
						}
					}
				}
			}
		}
		fclose(pArquivo);
	}while(flag == 1);
	return numeroSala;
}
//Objetivo : validar a data de cartaz
//Parametro: numero da data e o tipo da data // 0 - dia, 1 - mes e 2 - ano
//Retorno  : nenhum
void validaDataSala(int *data,int tipo){
	//Declarações 

	//Instruções
	switch(tipo){
		case 0:
			while(*data <=0 || *data >31 ){
				printf("Data invalida.Digite valores entre 1 e 31: ");
				scanf("%d",data);
			}
			break;
		case 1:
			while(*data<=0 || *data >12 ){
				printf("Data invalida.Digite valores entre 1 e 12: ");
				scanf("%d",data);
			}
			break;
		case 2:
			while(*data < 1900 ){
				printf("Data invalida.Digite uma data maior que 1900 : ");
				scanf("%d",data);
			} 
	
	}
}
//Objetivo : validar a data de saida de cartaz
//Parametro: numero da data  e a data de estreia 
//Retorno  : nenhum
int validaDataSalaSaida (int *dataSaiCartaz,int *dataCartaz){
	//Declarações 
	int flag=0;
	//Instruções
	if(dataSaiCartaz[2] < dataCartaz[2]){	 
		printf("A data de saida de cartaz precisa ser depois da data de entrada.\n");
		flag=1;
	}
	if(dataSaiCartaz[2]==dataCartaz[2] ){
		if(dataSaiCartaz[1] < dataCartaz[1] ){
			printf("A data de saida de cartaz precisa ser depois da data de entrada.\n");
			flag=1;
		}
		if(dataSaiCartaz[1]==dataCartaz[1] ){
			if(dataSaiCartaz[0] <= dataCartaz[0] ){
				printf("A data de saida de cartaz precisa ser depois da data de entrada.\n");
				flag=1;
			}	
		}
	}
	return flag;
}
//======================EDITAR===========================
//Objetivo : editar um cadastro
//Parametro: nenhum
//Retorno  : nenhum
void editarSala(){
	//Declarações 
	FILE *pArquivo;
	Salas procuraSala;
	int posicaoArquivo,codigo,modificaOpcao,flag=0;
	void validaModificacao(int *escolha);
	//Instruções
	menuSalasCinema(2);
	printf("Digite o codigo da sala a ser modificada: ");
	scanf("%d",&codigo);
	if((pArquivo=fopen("salasCinema.bin","rb"))!=NULL){
		while(!feof(pArquivo)){
			if(fread(&procuraSala,sizeof(procuraSala),1,pArquivo)==1){
				if(procuraSala.codigo == codigo){
					posicaoArquivo = ftell(pArquivo);
					posicaoArquivo+= -sizeof(procuraSala);
					flag=1;
					break;
				}
			}
		}
		fclose(pArquivo);
		if(flag==1){
			system("cls");
			menuSalasCinema(2);
			apresentaSala(&procuraSala,1);
			printf("1 - Nome do Filme \n");
			printf("2 - Local \n");
			printf("3 - Numero da Sala \n");
			printf("4 - Entrada em Cartaz  \n");
			printf("5 - Saida de Cartaz \n");
			printf("6 - Sair sem modificar \n");
			printf("Digite o que deseja modificar: ");
			scanf("%d",&modificaOpcao);
			validaModificacao(&modificaOpcao);
			switch(modificaOpcao){
				case 1:
					fflush(stdin);
					printf("Digite o novo nome do filme : ");
					fgets(procuraSala.nome_filme, SALAMAXNOME ,stdin);
					validaNomeSala(procuraSala.nome_filme);
					fflush(stdin);
					break;
				case 2:
					fflush(stdin);
					printf("Digite o novo local da sala : ");
					fgets(procuraSala.local, SALAMAXNOME ,stdin);
					validaNomeSala(procuraSala.local);
					fflush(stdin);
					break;
				case 3:
					printf("Digite o novo numero da sala, valores maiores que 0: ");
					scanf("%d",&procuraSala.numero);
					procuraSala.numero = validaNumeroSala(procuraSala.numero,procuraSala.local);
					break;
				case 4:
					printf("Digite o ano que entrou em cartaz: ");
					scanf("%d",&procuraSala.entra_cartaz[2]);
					validaDataSala(&procuraSala.entra_cartaz[2],2);
					
					printf("Digite o mes que entrou em cartaz: ");
					scanf("%d",&procuraSala.entra_cartaz[1]);
					validaDataSala(&procuraSala.entra_cartaz[1],1);
						
					printf("Digite o dia que entrou em cartaz: ");
					scanf("%d",&procuraSala.entra_cartaz[0]);
					validaDataSala(&procuraSala.entra_cartaz[0],0);
					break;
				case 5:
					do{
						printf("Digite o ano que saiu de cartaz: ");
						scanf("%d",&procuraSala.sai_cartaz[2]);
						validaDataSala(&procuraSala.sai_cartaz[2],2);
						
						printf("Digite o mes que saiu de cartaz: ");
						scanf("%d",&procuraSala.sai_cartaz[1]);
						validaDataSala(&procuraSala.sai_cartaz[1],1);
							
						printf("Digite o dia que saiu de cartaz: ");
						scanf("%d",&procuraSala.sai_cartaz[0]);
						validaDataSala(&procuraSala.sai_cartaz[0],0);
					}while(validaDataSalaSaida(procuraSala.sai_cartaz,procuraSala.entra_cartaz)!=0);
					break;
				case 6:
					printf("Nenhum dado foi alterado.Precione qualquer tecla.");
			}	
			if((pArquivo=fopen("salasCinema.bin","r+b"))!=NULL){
				if((fseek(pArquivo,posicaoArquivo,SEEK_SET))==0){
					if(fwrite(&procuraSala,sizeof(procuraSala),1,pArquivo)==1){
						if(modificaOpcao!= 6){
							printf("\nO cadastro foi alterado. Precione qualquer tecla.");
						}
					}
				}
			}
			fclose(pArquivo);
		}
		if(flag == 0){
			printf("Nao existe cadastro com esse codigo. Precione qualquer tecla.");
		}
	}
	else{
		printf("O arquivo nao pode ser aberto. Precione qualquer tecla.");
	}
	getche();

}
//Objetivo:validar escolha da modificação
//Parametros: opcao escolhida
//Retorno: sem retorno
void validaModificacao(int *escolha){
	while(*escolha<1 || *escolha > 6){
		printf("Opcao invalida. Digite novamente:");
		scanf("%d",escolha);
	}
	
}
//=======================APAGAR============================
//Objetivo:apagar uma sala cadastrada
//Parametros: nenhum
//Retorno: nenhum
void apagaSala(){
	//Declarações 
	FILE *pArquivo ,*pArquivoTemporario;
	int codigo,flag=0;
	char continua;
	Salas procuraSala;
	char validaOpcaoExlusaoSala (char opcao);
	//Instruções 
	menuSalasCinema(3);
	printf("Digite o codigo da sala a ser modificada: ");
	scanf("%d",&codigo);
	if((pArquivo=fopen("salasCinema.bin","rb"))!=NULL){
		while(!feof(pArquivo)){
			if(fread(&procuraSala,sizeof(procuraSala),1,pArquivo)==1){
				if(procuraSala.codigo == codigo){
					flag=1;
					break;
				}
			}
		}
		fclose(pArquivo);
		if(flag==1){
			system("cls");
			menuSalasCinema(3);
			apresentaSala(&procuraSala,1);
			printf("\nDigite S para exluir ou N para manter salvo:  ");
			continua = toupper(getch());
			continua = validaOpcaoExlusaoSala(continua);
			if(continua=='S'){
				if((pArquivo=fopen("salasCinema.bin","rb"))!=NULL){
					if((pArquivoTemporario=fopen("temporario.bin","wb"))!=NULL){
						while(!feof(pArquivo)){
							if(fread(&procuraSala,sizeof(procuraSala),1,pArquivo)==1){
								if(procuraSala.codigo != codigo){
									if((fwrite(&procuraSala,sizeof(procuraSala),1,pArquivoTemporario))!=1){
										printf("Erro ao exluir cadastro. Precione qualquer tecla.");
										remove("temporario.bin");
										getche();
										break;
									}
								}
							}	
						}
					}
				}
				fclose(pArquivo);
				fclose(pArquivoTemporario);
				if(remove("salasCinema.bin")!=0){
					printf("Erro ao exluir sala.");
				}
				else{
					if(rename("temporario.bin","salasCinema.bin")!=0){
						printf("Erro ao exluir sala.");
					}
					else{
						printf("\nSala foi exluida com sucesso. Precione qualquer tecla.");
					}
				}
			}
			else{
				printf("\nCancelada a exlulsao da sala. Precione qualquer tecla.");
			}
		
		}
		if(flag == 0){
			printf("Nao existe cadastro com esse codigo. Precione qualquer tecla.");
		}
	}
	else{
		printf("O arquivo nao pode ser aberto. Precione qualquer tecla.");
		fclose(pArquivo);
	}
	getche();
}

//Objetivo: Validar a opcao de exclusao de cadastro 
//Parametros: opcao escolhida
//Retorno: opcao escolhida validada
char validaOpcaoExlusaoSala (char opcao){
	//Declarações

	//Instruções
	while(opcao != 'S' && opcao!='N'){
		printf("\nCaracter invalido. Digite novamente: ");
		opcao = getch();
		opcao = toupper(opcao);
	}
	return opcao;
}
//=======================LISTAR============================
//Objetivo : Listar os cadastros de sala
//Parametro: nunhum
//Retorno  : nenhum 
void listarSala(){
	//Declarações
	char continua;
	int tamanhoArquivo;
	void ordenaLista(int tamanho, int ordem);
	//Instruções 
	menuSalasCinema(4);
	printf("Digite S para listar os nomes dos filmes de (A-Z) ou N para listar de (Z-A):  ");
	continua = toupper(getch());
	continua = validaOpcaoExlusaoSala(continua);
	tamanhoArquivo = tamanhoArquivoSalas();
	if(continua =='S'){
		ordenaLista(tamanhoArquivo,1);
	}
	else{
		ordenaLista(tamanhoArquivo,2);
	}
	
}

//Objetivo: ordenar o lista de alunos 
//Parametros: tamanho do arquivo, e a ordem escolhida
//Retorno: sem retorno
void ordenaLista(int tamanho, int ordem){
	//Declarações
	FILE *pArquivo;
	int comparado , escolhido,totalLido;
	Salas troca;
	int numeroCadastros = tamanho/(sizeof(troca));
	Salas salasTotal[numeroCadastros];
	

	//Instruções 
	if((pArquivo=fopen("salasCinema.bin","rb"))!=NULL){
		fread(salasTotal,sizeof(troca),numeroCadastros,pArquivo);
	}
	fclose(pArquivo);
	if(ordem == 1){
		for(comparado=0;comparado<numeroCadastros-1;comparado++){
			for(escolhido=comparado+1;escolhido<numeroCadastros;escolhido++){
				if(stricmp(salasTotal[escolhido].nome_filme,salasTotal[comparado].nome_filme) < 0){
					
					strcpy(troca.nome_filme , salasTotal[comparado].nome_filme);
					strcpy(salasTotal[comparado].nome_filme , salasTotal[escolhido].nome_filme);
					strcpy(salasTotal[escolhido].nome_filme , troca.nome_filme);
						
					strcpy(troca.local , salasTotal[comparado].local);
					strcpy(salasTotal[comparado].local , salasTotal[escolhido].local);
					strcpy(salasTotal[escolhido].local , troca.local);
				
					troca.codigo = salasTotal[comparado].codigo;
					salasTotal[comparado].codigo = salasTotal[escolhido].codigo;
					salasTotal[escolhido].codigo = troca.codigo;
					
					troca.numero = salasTotal[comparado].numero;
					salasTotal[comparado].numero = salasTotal[escolhido].numero;
					salasTotal[escolhido].numero = troca.numero;
					
					troca.entra_cartaz[0] = salasTotal[comparado].entra_cartaz[0];
					salasTotal[comparado].entra_cartaz[0] = salasTotal[escolhido].entra_cartaz[0];
					salasTotal[escolhido].entra_cartaz[0] = troca.entra_cartaz[0];
					
					troca.entra_cartaz[1] = salasTotal[comparado].entra_cartaz[1];
					salasTotal[comparado].entra_cartaz[1] = salasTotal[escolhido].entra_cartaz[1];
					salasTotal[escolhido].entra_cartaz[1] = troca.entra_cartaz[1];
					
					troca.entra_cartaz[2] = salasTotal[comparado].entra_cartaz[2];
					salasTotal[comparado].entra_cartaz[2] = salasTotal[escolhido].entra_cartaz[2];
					salasTotal[escolhido].entra_cartaz[2] = troca.entra_cartaz[2];
				
					troca.sai_cartaz[0] = salasTotal[comparado].sai_cartaz[0];
					salasTotal[comparado].sai_cartaz[0] = salasTotal[escolhido].sai_cartaz[0];
					salasTotal[escolhido].sai_cartaz[0] = troca.sai_cartaz[0];
					
					troca.sai_cartaz[1] = salasTotal[comparado].sai_cartaz[1];
					salasTotal[comparado].sai_cartaz[1] = salasTotal[escolhido].sai_cartaz[1];
					salasTotal[escolhido].sai_cartaz[1] = troca.sai_cartaz[1];
					
					troca.sai_cartaz[2] = salasTotal[comparado].sai_cartaz[2];
					salasTotal[comparado].sai_cartaz[2] = salasTotal[escolhido].sai_cartaz[2];
					salasTotal[escolhido].sai_cartaz[2] = troca.sai_cartaz[2];
					
					
				}	
			}
		}
	}
	else{
		for(comparado=0;comparado<numeroCadastros-1;comparado++){
			for(escolhido=comparado+1;escolhido<numeroCadastros;escolhido++){
					if(stricmp(salasTotal[escolhido].nome_filme,salasTotal[comparado].nome_filme) > 0){
					
				
					strcpy(troca.nome_filme , salasTotal[comparado].nome_filme);
					strcpy(salasTotal[comparado].nome_filme , salasTotal[escolhido].nome_filme);
					strcpy(salasTotal[escolhido].nome_filme , troca.nome_filme);
						
					strcpy(troca.local , salasTotal[comparado].local);
					strcpy(salasTotal[comparado].local , salasTotal[escolhido].local);
					strcpy(salasTotal[escolhido].local , troca.local);
				
					troca.codigo = salasTotal[comparado].codigo;
					salasTotal[comparado].codigo = salasTotal[escolhido].codigo;
					salasTotal[escolhido].codigo = troca.codigo;
					
					troca.numero = salasTotal[comparado].numero;
					salasTotal[comparado].numero = salasTotal[escolhido].numero;
					salasTotal[escolhido].numero = troca.numero;
					
					troca.entra_cartaz[0] = salasTotal[comparado].entra_cartaz[0];
					salasTotal[comparado].entra_cartaz[0] = salasTotal[escolhido].entra_cartaz[0];
					salasTotal[escolhido].entra_cartaz[0] = troca.entra_cartaz[0];
					
					troca.entra_cartaz[1] = salasTotal[comparado].entra_cartaz[1];
					salasTotal[comparado].entra_cartaz[1] = salasTotal[escolhido].entra_cartaz[1];
					salasTotal[escolhido].entra_cartaz[1] = troca.entra_cartaz[1];
					
					troca.entra_cartaz[2] = salasTotal[comparado].entra_cartaz[2];
					salasTotal[comparado].entra_cartaz[2] = salasTotal[escolhido].entra_cartaz[2];
					salasTotal[escolhido].entra_cartaz[2] = troca.entra_cartaz[2];
				
					troca.sai_cartaz[0] = salasTotal[comparado].sai_cartaz[0];
					salasTotal[comparado].sai_cartaz[0] = salasTotal[escolhido].sai_cartaz[0];
					salasTotal[escolhido].sai_cartaz[0] = troca.sai_cartaz[0];
					
					troca.sai_cartaz[1] = salasTotal[comparado].sai_cartaz[1];
					salasTotal[comparado].sai_cartaz[1] = salasTotal[escolhido].sai_cartaz[1];
					salasTotal[escolhido].sai_cartaz[1] = troca.sai_cartaz[1];
					
					troca.sai_cartaz[2] = salasTotal[comparado].sai_cartaz[2];
					salasTotal[comparado].sai_cartaz[2] = salasTotal[escolhido].sai_cartaz[2];
					salasTotal[escolhido].sai_cartaz[2] = troca.sai_cartaz[2];
				}	
			}
		}	
	}
	system("cls");
	apresentaSala(salasTotal,numeroCadastros);
	printf("\nPrecione qualquer tecla para sair.");
	getche();
	system("cls");
}


//=======================FUNÇOES SALA DE CINEMA GERAIS================
//Objetivo : apresentar menu
//Parametro: tipo de menu 1 - Nova Sala,2 - Editar Sala , 3 - Apagar Sala , 4 - Exluir Sala e 5 menu de opcao
//Retorno  : nenhum 
void menuSalasCinema(int tipo){
	//Instruções 
	switch(tipo){
	case 1:
		printf("PRINCIPAL \\ SALAS CINEMA\\ NOVA SALA \n______________________________________________________________________\n\n");
		break;
	case 2:
		printf("PRINCIPAL \\ SALAS CINEMA\\ EDITAR SALA \n______________________________________________________________________\n\n");
		break;
	case 3:
		printf("PRINCIPAL \\ SALAS CINEMA\\ APAGAR SALA \n______________________________________________________________________\n\n");
		break;
	case 4:
		printf("PRINCIPAL \\ SALAS CINEMA\\ LISTAR SALA \n______________________________________________________________________\n\n");
		break;
	case 5:
		printf("PRINCIPAL \\ SALAS CINEMA\n______________________________________________________________________\n\n");
		printf("1 - Nova Sala\n");
		printf("2 - Editar Sala\n");
		printf("3 - Apagar Sala\n");
		printf("4 - Listar Sala\n");
		printf("5 - Voltar ao menu anterior\n");
	}
}
//Objetivo: achar o tamanho do arquivo
//Parametros: sem parametros
//Retorno: temanho do arquivo
int tamanhoArquivoSalas(){
	FILE *pArquivo;
	int tamanho;
	if((pArquivo = fopen("salasCinema.bin","rb"))!=0){
		fseek(pArquivo,0,SEEK_END);
		if((tamanho = ftell(pArquivo))!=-1){
			tamanho = ftell(pArquivo);
			
		}
	}
	fclose(pArquivo);
	return tamanho;
}
//Objetivo : mostrar o cadastro
//Parametro: todos os dados do cadastro
//Retorno  : nenhum
void apresentaSala(Salas *novaSala, int numeroCadastros){
	//Declarações 
	int contador,flag=0;
	//Instruções
	if(numeroCadastros!=0){
		for(contador =0;contador<numeroCadastros;contador++){
			printf("Nome   - %s\n",novaSala[contador].nome_filme);
			printf("Local  - %s\n",novaSala[contador].local);
			printf("Codigo - %d\n",novaSala[contador].codigo);
			printf("Numero - %d\n",novaSala[contador].numero);
			printf("Entra Cartaz  - %d/%d/%d\n",novaSala[contador].entra_cartaz[0],novaSala[contador].entra_cartaz[1],novaSala[contador].entra_cartaz[2]);
			printf("Sai de Cartaz - %d/%d/%d\n\n",novaSala[contador].sai_cartaz[0],novaSala[contador].sai_cartaz[1],novaSala[contador].sai_cartaz[2]);
			flag++;
			if(flag >= 4){
				printf("Precione qualquer tecla para continuar");
				getche();
				system("cls");
				flag = 0;
			}
		}
	}
	else{
		system("cls");
		printf("Nao existem cadastros");
	}
}

