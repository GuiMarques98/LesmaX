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
void imprimeProfissaoAtor(int profissao);


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

//===========================================================================SUBPROGRAMAS========================================================================
//======================================================================MENU PRINCIPAL=========================================================
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


//================================================================================ATORES====================================================================================
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
				system("cls");
				break;
			case '2':
				editaAtores(nome_arq_atores);
				system("cls");
				break;
			case '3':
				listaAtores(nome_arq_atores);
				system("cls");
				break;
			//case '4':
				//deletaAtores(nome_arq_atores);
				system("cls");
		}
	}while(opcao != '0');
	
}

//=====================================================================SUBPROGRAMA ATORES=========================================================
//==============================================================CADASTRO ATORES====================================================
//Objetivo : Cadastrar atores 
//Parametro: Nome com o arquivo de todos os atores
//Retorno  : Sem retorno
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
		}while(!validaOpcaoAtoresCadastro(opcao));
		system("cls");
	}while(toupper(opcao) != 'N');

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
	int valida;
	char profissao;
	
	//Instru��es
	do
	{
		printf("Digite a op��o correspondente � profiss�o:\n1-Ator\n2-Diretor\n3-Roteirista\n4-Produtor\nDigite a op��o: ");
		profissao = getch();
	}while(valida || profissao < 49 && profissao > 52);//32561 se refere ao numero 1 com o getch e assim por diante ate o 21565 que se refere ao numero 5
	
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

//Objetivo : Ler a matricula da pessoa
//Parametro: Nome com os arquivos dee todos os atores
//Retorno  : Sem retorno
int leMatriculaAtores(const char *arq_nome_atores)
{
	//Declara��es
	int validaMatricula(const char *arq_nome_atores, int matricula);
	int matricula, valida;
	
	//Instru��es
	do
	{
		printf("Digite a matr�cula da pessoa: ");
		valida = scanf("%d", &matricula);
		fflush(stdin);
		if(!valida || !validaMatricula(arq_nome_atores, matricula))
		{
			printf("Matr�cula inv�lida! ");	
		}
	}while(!valida || !validaMatricula(arq_nome_atores, matricula));
}

//============================================EDITA ATORES======================================================
//Objetivo : Editar atores ja cadastrados 
//Parametro: Nome do arquivo com todas as variaveis
//Retorno  : Sem Retorno
void editaAtores(const char *arq_nome_atores)
{
	//Declara��es Fun��es
	int validaOpcaoAtoresEdita(int opcao);
	
	//Declara��o Variaveis
	FILE *arq_atores;
	char opcao;
	Atores ator;
	int matricula = 0, aux = 0, contador = 0, valida = 0, nro_atores = 1;
	
	//Instru��es
	imprimeMenusAtores('e');
	
	nro_atores = achaNroAtores(arq_nome_atores);
	
	imprimeMenusAtores('e');
	if(!nro_atores)
	{
		printf("\nN�o existe nem uma pessoa cadastrada!\n");
		system("pause");
		system("cls");
		return;
	}
	
	do
	{
		printf("Digite a matr�cula da pessoa que deseja editar: ");
		valida = scanf("%d", &matricula);
		fflush(stdin);
		if(!valida || !temMatriculaIgualAtor(matricula, arq_nome_atores) || temMatriculaIgualAtor(matricula, arq_nome_atores) != -1)
		{
			printf("Matr�cula n�o encontrada! ");	
		}
	}while(!valida || !temMatriculaIgualAtor(matricula, arq_nome_atores) || temMatriculaIgualAtor(matricula, arq_nome_atores) != -1);
	system("cls");
	
	imprimeMenusAtores('e');
	
	while(!contador)
	{
		arq_atores = abreArquivo("rb", arq_nome_atores);
		fseek(arq_atores, (aux * sizeof(Atores)), SEEK_SET);
		fread(&ator, sizeof(Atores), 1, arq_atores);
		contador = feof(arq_atores);
		
		if(ator.matricula == matricula)
		{
			printf("1-NOME: %s\n2-IDADE: %d\n3-PROFISS�O:");
			imprimeProfissaoAtor(ator.profissao);
			printf("\n4-FILMES FEITOS: %s\n5-NACIONALIDADE: %s\n0-VOLTAR AO MENU PRINCIPAL\n");
			
			do
			{
				printf("Digite a op��o que deseja editar:");
				opcao = getch();
			}while(!validaOpcaoAtoresEdita(opcao));
			
			switch(opcao)
			{
				case '1':
					leNomeAtores(ator.nome);
					break;
				case '2':
					ator.idade = leIdadeAtores();
					break;
				case '3':
					ator.profissao = leProfissaoAtores();
					break;
				case '4':
					leFilmesFeitosAtores(ator.filmes_feitos);
					break;
				case '5':
					leNacionalidadeAtores(ator.nacionalidade);
					break;
				case '0':
					return;
			}
			
			arq_atores = abreArquivo("r+b", arq_nome_atores);
			fseek(arq_atores, ((aux) * sizeof(Atores)), SEEK_SET);
			fwrite(&ator, sizeof(Atores), 1, arq_atores);
			fechaArquivo(arq_atores);
			printf("\n\nAtor editado com sucesso!\n\n");
			system("pause");
			return;
		}
		else
		{
			aux++;
		}
	}
	
}

//============================================LISTAGEM ATORES===================================================
//Objetivo : Listar os atores
//Parametro: Nome do arquivo contendo todos os atores
//Retorno  : Sem retorno
void listaAtores(const char *arq_nome_atores)
{
	//Declara��es fun��es
	void organizaAtores(Atores *atores, int inicio, int fim);
	int validaOpcaoAtoresListar(int opcao);
	void imprimeOrdem(Atores *atores, int ordem, int nro_atores);
	void imprimeProfissao(Atores *atores, int nro_atores);
	
	//Declara��es vari�veis
	FILE *arq_atores;
	int nro_atores = 0;
	Atores *atores;
	char opcao;
	
	//Instru��es
	nro_atores = achaNroAtores(arq_nome_atores);
	
	imprimeMenusAtores('l');
	if(nro_atores == 0)
	{
		printf("Nenhuma pessoa cadastrada!\n");
		system("pause");
		system("cls");
		return;
	}
	
	atores = malloc(sizeof(Atores) * nro_atores);
	
	arq_atores = abreArquivo("rb", arq_nome_atores);
	fread(atores, sizeof(Atores), nro_atores, arq_atores);
	fechaArquivo(arq_atores);
	
	
	
	do
	{
		printf("Escolha op��o de listagem:\n1-Ordem Alfab�tica\n2-De Z � A\n3-Profiss�o\n0-Voltar ao menu anterior\nDigite a op��o: ");
		opcao = getche();
	}while(!validaOpcaoAtoresListar(opcao));
	system("cls");
	
	switch(opcao)
	{
		case '1':
			imprimeOrdem(atores, 0, nro_atores);
			break;
		case '2':
			imprimeOrdem(atores, 1, nro_atores);
			break;
		case '3':
			imprimeProfissao(atores, nro_atores);
	}
	system("cls");
	free(atores);
}

//Objetivo : 
//Parametro: 
//Retorno  : 
void imprimeOrdem(Atores *atores, int ordem, int nro_atores)
{
	//Declara��es
	int aux, opcao = 0, valida = 0, aux2;
	char opcao1;
	
	//Instu��es
	
	//Se for 0 ordem alfab�tica se for 1 de A-Z
	aux2 = ((!ordem)? nro_atores : 0);
	do
	{
		imprimeMenusAtores('l');
		if(!ordem)
		{
			for(aux = 0; aux != nro_atores; aux++)
			{
				printf("\n%d- %s /", aux+1, strupr(atores[aux].nome));
				imprimeProfissaoAtor(atores[aux].profissao);
			}
		}
		else
		{
			for(aux = nro_atores; aux != 0; aux--)
			{
				printf("\n%d- %s /", (nro_atores - aux) + 1, strupr(atores[aux].nome));
				imprimeProfissaoAtor(atores[aux].profissao);
			}
		}
		
		printf("\n0-Voltar ao menu anterior\n");
		do
		{
			printf("Digite o n�mero correspondente � op��o: ");
			valida = scanf("%d", &opcao);
			fflush(stdin);
			if(!valida || opcao < 0 && opcao > nro_atores)
			{
				printf("Op��o inv�lida! ");
			}
		}while(!valida || opcao < 0 && opcao > nro_atores);
		
		system("cls");
		if(opcao == 0)
		{
			return;
		}
		
		imprimeMenusAtores('l');
		
		printf("NOME: %s\nMATRICULA: %d\nIDADE: %d\n PROFISSAO: ", atores[opcao-1].nome, atores[opcao-1].matricula, atores[opcao-1].idade);
		imprimeProfissaoAtor(atores[opcao-1].profissao);
		printf("\nFILMES FEITOS: %s\nNACIONALIDADE: %s\n", atores[opcao-1].filmes_feitos, atores[opcao-1].nacionalidade);
		
		printf("Digite 'S' para voltar e listar outra pessoa ou qualquer outra tecla para continuar: ");
		opcao1 = getch();
		system("cls");
		
	}while(toupper(opcao1) == 'S');
}

//Objetivo : 
//Parametro: 
//Retorno  : 
void imprimeProfissao(Atores *atores, int nro_atores)
{
	//Declara��es
	int profissao, aux, posicao = 0, opcao = 0, valida = 0;
	char opcao1;
	Atores atores_prof[nro_atores];
	
	//Instru��es
	imprimeMenusAtores('l');
	
	do
	{
		profissao = leProfissaoAtores();
		system("cls");
		
		imprimeMenusAtores('l');
		for( aux = 0 ; aux =! nro_atores; aux++)
		{
			if(atores[aux].profissao == profissao)
			{
				atores_prof[posicao] = atores[aux];
				printf("\n%d- %s /", posicao+1, strupr(atores_prof[posicao].nome));
				imprimeProfissaoAtor(atores_prof[posicao].profissao);
				posicao++;
			}
		}
		
		printf("\n0-Voltar ao menu anterior\n");
		do
		{
			printf("Digite o n�mero correspondente � op��o: ");
			valida = scanf("%d", &opcao);
			fflush(stdin);
			if(!valida || opcao < 0 && opcao > posicao)
			{
				printf("Op��o inv�lida! ");
			}
		}while(!valida || opcao < 0 && opcao > posicao);
		
		system("cls");
		if(opcao == 0)
		{
			return;
		}
		
		imprimeMenusAtores('l');
		
		printf("NOME: %s\nMATRICULA: %d\nIDADE: %d\n PROFISSAO: ", atores_prof[opcao-1].nome, atores_prof[opcao-1].matricula, atores_prof[opcao-1].idade);
		imprimeProfissaoAtor(atores_prof[opcao-1].profissao);
		printf("\nFILMES FEITOS: %s\nNACIONALIDADE: %s\n", atores[opcao-1].filmes_feitos, atores_prof[opcao-1].nacionalidade);
		
		
		printf("Digite 'S' para voltar e listar outra pessoa ou qualquer outra tecla para continuar: ");
		opcao1 = getch();
		system("cls");
	}while(toupper(opcao1) == 'S');
	
}

//Objetivo : 
//Parametro: 
//Retorno  : 

//============================================OUTRASFUNCOES=====================================================
//Objetivo : Imprime as op��es de cadastro referente so menu
//Parametro: Qual o tipo de menu
//Retorno  : Sem retorno
void imprimeMenusAtores(char tipo)
{
	/*
	'P' = menu principal dos atores
	'C' = menu de cadastro de atores
	'E' = menu de edi��o de atores
	'L' = menu de listagem de atores
	*/
	
	printf("PRINCIPAL/ATORES");
	switch(toupper(tipo))
	{
		case 'P':
			printf("\n________________________________________________________________________________________________________________________\n");
			printf("Escolha a op��o que deseja entrar:\n1-Cadastrar\n2-Editar\n3-Listar\n4-Deletar\n0-Voltar ao menu anterior\nDigite uma op��o: ");
			return;
		case 'C':
			printf("/CADASTRAR\n_________________________________________________________________________________________________________________________\n");
			return;
		case 'E':
			printf("/EDITAR\n____________________________________________________________________________________________________________________\n");
			return;
		case 'L':
			printf("/LISTAR\n____________________________________________________________________________________________________________________\n");
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


//Objetivo : Imprime na tela a profiss�o do ator
//Parametro: Profiss�o do ator
//Retorno  : Sem retorno
void imprimeProfissaoAtor(int profissao)
{
	switch(profissao)
	{
		case '1':
			printf("Ator");
			return;
		case '2':
			printf("Diretor");
			return;
		case '3':
			printf("Roteirista");
			return;
		case '4':
			printf("Produtor");
			return;
		
	}
}

//Objetivo : Organizar atores em ordem alfab�tica
//Parametro: Vetor de atores, inicio do vetor, final do vetor
//Retorno  : Sem retorno
void organizaAtores(Atores *atores, int inicio, int fim)
{
	//Declara��es
	int aux, aux1;
    char troca[ATORMAXNOME], troca2[ATORMAXNOME];
    char troca_filmes[ATORMAXFILMES], troca_nacionalidade[ATORMAXNACIONALIDADE];
    int troca_matricula, troca_profissao, troca_idade;

	//Instru��es
    aux = inicio;
    aux1 = fim;
    strcpy(troca2, atores[(inicio + fim) / 2].nome);

    while(aux <= aux1)
        {
        while(stricmp(atores[aux].nome, troca2) == -1 && aux < fim) {
            aux++;
        }
        while(stricmp(atores[aux1].nome , troca2) == -1 && aux1 > inicio)
        {
            aux1--;
        }
        if(aux <= aux1)
        {
            strcpy(troca, atores[aux].nome);
            strcpy(atores[aux].nome, atores[aux1].nome);
            strcpy(atores[aux1].nome, troca);
            
            strcpy(troca_filmes, atores[aux].filmes_feitos);
            strcpy(atores[aux].filmes_feitos, atores[aux1].filmes_feitos);
            strcpy(atores[aux1].filmes_feitos, troca_filmes);
            
            troca_matricula = atores[aux].matricula;
            atores[aux].matricula = atores[aux1].matricula;
            atores[aux1].matricula = troca_matricula;
            
			troca_profissao = atores[aux].profissao;
            atores[aux].profissao = atores[aux1].profissao;
            atores[aux1].profissao = troca_profissao;
            
            strcpy(troca_filmes, atores[aux].filmes_feitos);
            strcpy(atores[aux].filmes_feitos, atores[aux1].filmes_feitos);
            strcpy(atores[aux1].filmes_feitos, troca_filmes);
            
            strcpy(troca, atores[aux].nome);
            strcpy(atores[aux].nome, atores[aux1].nome);
            strcpy(atores[aux1].nome, troca);
            aux++;
            aux1--;
        }
    }

    if(aux1 > inicio) {
        organizaAtores(atores, inicio, aux1);
    }
    if(aux < fim) {
        organizaAtores(atores, aux1, fim);
    }
}

//Objetivo : 
//Parametro: 
//Retorno  : 

//=======================================VALIDACOES=================================================================
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

//Objetivo : Validar matricula
//Parametro: Nome do arquivo que contem todos os atores, matricula digitada
//Retorno  : Situa��o da valida��o
int validaMatricula(const char *arq_nome_atores, int matricula)
{
	//Declara��es
	FILE *arq_atores;
	int aux;
	Atores atores;
	
	//Instru��es
	
	if(!temMatriculaIgualAtor(matricula, arq_nome_atores) || temMatriculaIgualAtor(matricula, arq_nome_atores) == -1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	
}

//Objetivo : Valida a op��o do menu atores editar
//Parametro: Op��o
//Retorno  : Situa��o da Valida��o
int validaOpcaoAtoresEdita(int opcao)
{
	if(opcao < 48 || opcao > 53)
	{
		printf("Op��o inv�lida! ");
		return 0;
	}
	else 
	{
		return 1;
	}
}

//Objetivo : Validar op��o do menu atores listar
//Parametro: Op��o
//Retorno  : Situa��o da valida��o
int validaOpcaoAtoresListar(int opcao)
{
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

//Objetivo : 
//Parametro: 
//Retorno  : 

//===================================FILMES==========================================


//===================================SALAS DE CINEMA ================================
