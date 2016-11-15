/*
Projeto de PDS Grupo 3
Membros:
	Guilherme Marques Moreira da Silva	
	Gustavo Cavalcante Linhares
	Gustavo Carvalho
*/
//Includes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

//Defines
#define ATORMAXNOME 31
#define ATORMAXFILMES 201
#define ATORMAXNACIONALIDADE 21

//Structs

//Structs para Filmes

typedef struct{
	
}Filmes;

//Structs para salas de cinema
typedef struct{
	
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

//Cabe�alhos
void mainAtores();
void leNomeAtores(char *nome);
int leIdadeAtores();
int leProfissaoAtores();
void leFilmesFeitosAtores(char *filmes_feitos);
void leNacionalidadeAtores(char *nacionalidade);
void imprimeMenusAtores(char tipo);
int temMatriculaIgualAtor(int matricula, const char *nome_arq);
int achaNroAtores(const char *arq_nome);


//USEM ESSAS DUAS FUN��ES PRA ABRIR E FECHAR O ARQUIVO
FILE *abreArquivo(const char *tipo, const char *nome_arq);
void fechaArquivo(FILE *arquivo);

//Principal 
int main()
{
	//Declara��es 
	char opcao;
	int validaOpcaoMain(int opcao);
	
	//Instru��es
	setlocale(LC_ALL, "");
	
	do
	{
		printf("PRINCIPAL\n______________________________________________________________________\n\n");
		do
		{
			printf("\nEscolha o menu que deseja entrar:\n1-Filmes\n2-Salas de Cinema\n3-Atores\n0-Para encerrar o programa\nInsira a op��o:");
			opcao = getch();
			
		}while(!validaOpcaoMain(opcao));
		system("cls");
		
		switch(opcao)
		{
			case '1':
				
				break;
			case '2':
				
				break;
			case '3':
				mainAtores();
				break;
		}
		system("cls");
	}while(opcao != '0');
	
    return 0;
}

//================================================SUBPROGRAMAS==================================================
//=================================MENU PRINCIPAL====================================
//Objetivo : Validar op��o do menu principal
//Parametro: Op��o 
//Retorno  : Situa��o da valida��o 
int validaOpcaoMain(int opcao)
{
	//Instru��es 
	
	if(opcao < 48 || opcao > 51)
	{
		printf("Op��o inv�lida!\n");
		return 0;
	}
	else
	{
		return 1;
	}
}

//Objetivo : Abrir arquivo
//Parametro: Tipo de abertura, nome do arquivo
//Retorno  : Ponteiro para o inicio do arquivo
FILE *abreArquivo(const char *tipo, const char *nome_arq)
{
	FILE *arquivo;
	
	arquivo = fopen(nome_arq, tipo);
	if(ferror(arquivo))
	{
		printf("Arquivo n�o pode ser aberto!\n");
		system("pause");
		exit(1);
	}
	else
	{
		return arquivo;
	}
	
}

//Objetivo : Fechar arquivo
//Parametro: Arquico
//Retorno  : Sem retorno
void fechaArquivo(FILE *arquivo)
{
	fclose(arquivo);
	if(ferror(arquivo))
	{
		printf("Arquivo n�o pode ser fechado!\n");
		system("pause");
		exit(1);
	}
}


//====================================ATORES=========================================
//Objetivo : Menu onde o cadastrar, listar, editar, e deletar atores acontecem
//Parametro: Sem parametro
//Retorno  : Sem retorno
void mainAtores()
{
	//Declara��es Fun��es
	int validaOpcaoAtoresPrincipal(int opcao);
	void cadastraAtores(const char *arq_nome_atores);
	void editaAtores(const char *arq_nome_atores);
	void listaAtores(const char *arq_nome_atores);
	void deletaAtores(const char *arq_nome_atores);
	
	//Declara��es Variaveis
	FILE *arq_atores;
	const char nome_arq_atores[] = "atores.bin";
	char opcao;
	
	//Instru��es
	arq_atores = fopen(nome_arq_atores, "rb");
	if(!arq_atores)
	{
		arq_atores = abreArquivo("wb", nome_arq_atores);
	}
	fechaArquivo(arq_atores);
	
	do
	{
		imprimeMenusAtores('p');
		do
		{
			opcao = getch();
		}while(!validaOpcaoAtoresPrincipal(opcao));
		
		system("cls");
		
		switch(opcao)
		{
			case'1':
				cadastraAtores(nome_arq_atores);
				break;
			case '2':
				//editaAtores(nome_arq_atores);
				break;
			case '3':
				//listaAtores(nome_arq_atores);
				break;
			//case '4':
				//deletaAtores(nome_arq_atores);
		}
	}while(opcao != '0');
	
}

//=====================SUBPROGRAMA ATORES========================
//=====================CADASTRO ATORES===================
//Objetivo : 
//Parametro: 
//Retorno  : 
void cadastraAtores(const char *arq_nome_atores)
{
	//Declara��es Fun��es
	int validaOpcaoAtoresCadastro(int opcao);
	int leMatriculaAtores(const char *arq_nome_atores);
	
	//Declara��es 
	FILE *arq_atores;
	Atores ator;
	char opcao;
	
	//Instru��es
	
	do
	{
		imprimeMenusAtores('c');
		leNomeAtores(ator.nome);
		system("cls");
		fflush(stdin);
		
		imprimeMenusAtores('c');
		ator.matricula = leMatriculaAtores(arq_nome_atores);
		system("cls");
		fflush(stdin);
		
		imprimeMenusAtores('c');
		ator.idade = leIdadeAtores();
		system("cls");
		fflush(stdin);
		
		imprimeMenusAtores('c');
		ator.profissao = leProfissaoAtores();
		system("cls");
		fflush(stdin);
		
		imprimeMenusAtores('c');
		leFilmesFeitosAtores(ator.filmes_feitos);
		system("cls");
		fflush(stdin);
		
		imprimeMenusAtores('c');
		leNacionalidadeAtores(ator.nacionalidade);
		system("cls");
		fflush(stdin);
		
		arq_atores = abreArquivo("ab", arq_nome_atores);
		fwrite(&ator, sizeof(Atores), 1, arq_atores);
		fechaArquivo(arq_atores);
		
		imprimeMenusAtores('c');
		do
		{
			printf("Deseja cadastrar outra pessoa? Digite 'S' para sim e 'N' para n�o. ");
			opcao = getch();
		}while(validaOpcaoAtoresCadastro(opcao));
		system("cls");
	}while(opcao != 'N');

}

//Objetivo : Ler o nome do ator
//Parametro: Nome do ator
//Retorno  : Sem retorno
void leNomeAtores(char* nome)
{ 	
	do
	{
		printf("Digite o nome da pessoa: ");
		fflush(stdin);
		fgets(nome, ATORMAXNOME, stdin);
		nome[strlen(nome)-1] = '\0';
		if(strlen(nome) < 3)
			printf("Nome invalido. ");
	}while(strlen(nome)< 3);
	system("cls");
}

//Objetivo : Le a idade do ator
//Parametro: Sem parametro
//Retorno  : Retorna idade do ator
int leIdadeAtores()
{
	//Declara��o
	int idade = 0, valida = 0;
	
	do
	{
		printf("Digite a idade da pessoa: ");
		valida = scanf("%d", &idade);
		fflush(stdin);
		if(!valida || idade>1 || idade < 200)
		{
			printf("Idade inv�lida! ");
		}
	}while(!valida || idade < 1 || idade > 200);
	return idade;
}

//Objetivo : L� a idade do ator
//Parametro: Sem parametro
//Retorno  : Profiss�o do ator
int leProfissaoAtores()
{
	//Declara��es
	int profissao, valida;
	
	//Instru��es
	do
	{
		printf("");
		profissao = getch();
	}while(valida || profissao < 32561 && profissao < 32565);//32561 se refere ao numero 1 com o getch e assim por diante ate o 21565 que se refere ao numero 5
	
	return profissao;
}

//Objetivo : Le os filmes ja feitos
//Parametro: String onde guardar o filme
//Retorno  : Sem retorno
void leFilmesFeitosAtores(char *filmes_feitos)
{
	printf("Digite os filmes ja feitos pela pessoa: ");
	fgets(filmes_feitos, ATORMAXFILMES, stdin);
}

//Objetivo : Le a Nacionalidade da pessoa
//Parametro: String onde guarda a nascionalidade
//Retorno  : Sem retorno
void leNacionalidadeAtores(char *nacionalidade)
{
	do
	{
		printf("Digite a nacionalidade da pessoa: ");
		fgets(nacionalidade, ATORMAXNACIONALIDADE, stdin);
		nacionalidade[strlen(nacionalidade) - 1] = '\0';
		if(strlen(nacionalidade) < 3)
		{
			printf("Nacionalidade inv�lida! ");
		}
	}while(strlen(nacionalidade) < 3);
}

//Objetivo : 
//Parametro: 
//Retorno  : 
int leMatriculaAtores(const char *arq_nome_atores)
{
	
}

//===========OUTRASFUNCOES====================
//Objetivo : Imprime as op��es de cadastro referente so menu
//Parametro: Qual o tipo de menu
//Retorno  : Sem retorno
void imprimeMenusAtores(char tipo)
{
	/*
	'P' = menu principal dos atores
	*/
	
	printf("PRINCIPAL/ATORES");
	switch(toupper(tipo))
	{
		case 'P':
			printf("\n_____________________________________________________________________________________________________\n");
			printf("Escolha a op��o que deseja entrar:\n1-Cadastrar\n2-Editar\n3-Listar\n4-Deletar\n0-Voltar ao menu anterior\nDigite uma op��o: ");
			return;
		case 'C':
			printf("/CADASTRAR\n______________________________________________________________________________________________________\n");
			return;
	}
}

//Objetivo : Verifica se h� matriculas iguais 
//Parametro: Vetor de deputados, matricula, numero de deputados cadastrados
//Retorno  : Um se n�o houver, zero se houver erro na matricula, -1 se houver matricula igual
int temMatriculaIgualAtor(int matricula, const char *nome_arq)
{
	FILE *arq_ator;
	Atores *atores;
	int nro_atores;
	int aux;
	
	nro_atores = achaNroAtores(nome_arq);
	
	if(nro_atores == 0)
	{
		return 1;
	}
	
	atores = malloc(sizeof(Atores) * nro_atores);
	
	arq_ator = abreArquivo("rb", nome_arq);
	fread(atores, sizeof(Atores), nro_atores, arq_ator);
	fechaArquivo(arq_ator);
	
	if(matricula < 10 || matricula > 999999)
	{
		return 0;
	}
	
	for(aux=0;aux!=nro_atores;aux++)
	{
		if(atores[aux].matricula == matricula)
		{
			return -1;
		}
	}
	return 1;
}

//Objetivo : Achar quantos atores foram gravados no arquivo
//Parametro: Nome do arquivo
//Retorno  : Numero de atores no arquivo;
int achaNroAtores(const char *arq_nome)
{
	int nro_atores;
	FILE *arquivo;
	
	arquivo = abreArquivo("rb", arq_nome);
	fseek(arquivo, 0, SEEK_END);
	nro_atores = ftell(arquivo);
	fseek(arquivo, 0, SEEK_SET);
	fechaArquivo(arquivo);
	
	if(nro_atores == -1)
	{
		return 0;
	}
	else
	{
		return(nro_atores / (sizeof(Atores)));
	}
	
}

//Objetivo : 
//Parametro: 
//Retorno  : 

//============VALIDACOES==================
//Objetivo : Validar op��o do menu principal de atores
//Parametro: Op��o
//Retorno  : Situa��o da valida��o
int validaOpcaoAtoresPrincipal(int opcao)
{
	//Instru��es 
	
	if(opcao < 48 || opcao > 52)
	{
		printf("Op��o inv�lida!\n");
		return 0;
	}
	else
	{
		return 1;
	}
}

//Objetivo : Validar op��o do menu de cadastro de atores
//Parametro: Op��o
//Retorno  : Situa��o da valida��o
int validaOpcaoAtoresCadastro(int opcao)
{
	//Instru��es
	opcao = toupper(opcao);
	if(opcao != 83 && opcao != 78)
	{
		printf("Op��o inv�lida!\n");
		return 0;
	}
	else
	{
		return 1;
	}
}

//Objetivo : 
//Parametro: 
//Retorno  : 

//===================================FILMES==========================================


//===================================SALAS DE CINEMA ================================
