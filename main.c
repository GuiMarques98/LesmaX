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


//Defines ATOR
#define ATORMAXNOME 30
#define ATORMAXFILMES 200
#define ATORMAXNACIONALIDADE 20
//Defines SALAS
#define SALAMAXNOME 30
#define SALACARTAZ 3
#define SALACODIGO 100


//Structs

//Structs para Filmes

typedef struct{
	
}Filmes;

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

//Sala Cinema
void menuSalasCinema(int tipo);//1 - Nova Sala,2 - Editar Sala , 3 - Apagar Sala ,4 - Exluir Sala e 5 menu de opcao

//USEM ESSAS DUAS FUNÇÕES PRA ABRIR E FECHAR O ARQUIVO
FILE *abreArquivo(const char *tipo, const char *nome_arq);
void fechaArquivo(FILE *arquivo);

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
		system("cls");
		
		switch(opcao)
		{
			case '1':
				
				break;
			case '2':
				salasCinema();
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
//Objetivo : Validar opção do menu principal
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

//Objetivo : Abrir arquivo
//Parametro: Tipo de abertura, nome do arquivo
//Retorno  : Ponteiro para o inicio do arquivo
FILE *abreArquivo(const char *tipo, const char *nome_arq)
{
	FILE *arquivo;
	
	arquivo = fopen(nome_arq, tipo);
	if(ferror(arquivo))
	{
		printf("Arquivo não pode ser aberto!\n");
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
		printf("Arquivo não pode ser fechado!\n");
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
	//Declarações Funções
	int validaOpcaoAtoresPrincipal(int opcao);
	void cadastraAtores(const char *arq_nome_atores);
	void editaAtores(const char *arq_nome_atores);
	void listaAtores(const char *arq_nome_atores);
	void deletaAtores(const char *arq_nome_atores);
	
	//Declarações Variaveis
	FILE *arq_atores;
	const char nome_arq_atores[] = "atores.bin";
	char opcao;
	
	//Instruções
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
			case '4':
				deletaAtores(nome_arq_atores);
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
	//Declarações Funções
	int validaOpcaoAtoresCadastro(int opcao);
	int leMatriculaAtores(const char *arq_nome_atores);
	
	//Declarações 
	FILE *arq_atores;
	Atores ator;
	char opcao;
	
	//Instruções
	
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
			printf("Deseja cadastrar outra pessoa? Digite 'S' para sim e 'N' para não. ");
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
		if(strlen(nome) < 3 || strstr(nome, "0123456789") != NULL)
			printf("Nome invalido. ");
	}while(strlen(nome)< 3 || strstr(nome, "0123456789") != NULL);
	system("cls");
}

//Objetivo : Le a idade do ator
//Parametro: Sem parametro
//Retorno  : Retorna idade do ator
int leIdadeAtores()
{
	//Declaração
	int idade = 0, valida = 0;
	
	do
	{
		printf("Digite a idade da pessoa: ");
		valida = scanf("%d", &idade);
		fflush(stdin);
		if(!valida || idade>1 || idade < 200)
		{
			printf("Idade inválida! ");
		}
	}while(!valida || idade < 1 || idade > 200);
	return idade;
}

//Objetivo : Lê a idade do ator
//Parametro: Sem parametro
//Retorno  : Profissão do ator
int leProfissaoAtores()
{
	//Declarações
	char profissao;
	
	//Instruções
	do
	{
		printf("Digite a opção correspondente à profissão:\n1-Ator\n2-Diretor\n3-Roteirista\n4-Produtor\nDigite a opção: ");
		profissao = getch();
	}while(profissao < 49 && profissao > 52);//32561 se refere ao numero 1 com o getch e assim por diante ate o 21565 que se refere ao numero 5
	
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
			printf("Nacionalidade inválida! ");
		}
	}while(strlen(nacionalidade) < 3);
}

//Objetivo : Ler a matricula da pessoa
//Parametro: Nome com os arquivos dee todos os atores
//Retorno  : Sem retorno
int leMatriculaAtores(const char *arq_nome_atores)
{
	//Declarações
	int validaMatricula(const char *arq_nome_atores, int matricula);
	int matricula, valida;
	
	//Instruções
	do
	{
		printf("Digite a matrícula da pessoa: ");
		valida = scanf("%d", &matricula);
		fflush(stdin);
		if(!valida || !validaMatricula(arq_nome_atores, matricula))
		{
			printf("Matrícula inválida! ");	
		}
	}while(!valida || !validaMatricula(arq_nome_atores, matricula));
	return matricula;
}

//============================================EDITA ATORES======================================================
//Objetivo : Editar atores ja cadastrados 
//Parametro: Nome do arquivo com todas as variaveis
//Retorno  : Sem Retorno
void editaAtores(const char *arq_nome_atores)
{
	//Declarações Funções
	int validaOpcaoAtoresEdita(int opcao);
	
	//Declaração Variaveis
	FILE *arq_atores;
	char opcao;
	Atores ator;
	int matricula = 0, aux = 0, contador = 0, valida = 0, nro_atores = 1;
	
	//Instruções
	imprimeMenusAtores('e');
	
	nro_atores = achaNroAtores(arq_nome_atores);
	
	if(!nro_atores)
	{
		printf("\Nenhuma pessoa cadastrada!\n");
		system("pause");
		system("cls");
		return;
	}
	
	do
	{
		printf("Digite a matrícula da pessoa que deseja editar: ");
		valida = scanf("%d", &matricula);
		fflush(stdin);
		if(!valida || !temMatriculaIgualAtor(matricula, arq_nome_atores) || temMatriculaIgualAtor(matricula, arq_nome_atores) != -1)
		{
			printf("Matrícula não encontrada! ");	
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
			printf("1-NOME: %s\n2-IDADE: %d\n3-PROFISSÃO:", ator.nome, ator.idade);
			imprimeProfissaoAtor(ator.profissao);
			printf("\n4-FILMES FEITOS: %s\n5-NACIONALIDADE: %s\n0-VOLTAR AO MENU PRINCIPAL\n", ator.filmes_feitos, ator.nacionalidade);
			
			do
			{
				printf("Digite a opção que deseja editar:");
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
	//Declarações funções
	void organizaAtores(Atores *atores, int inicio, int fim);
	int validaOpcaoAtoresListar(int opcao);
	void imprimeOrdem(Atores *atores, int ordem, int nro_atores);
	void imprimeProfissao(Atores *atores, int nro_atores);
	
	//Declarações variáveis
	FILE *arq_atores;
	int nro_atores = 0;
	Atores *atores;
	char opcao;
	
	//Instruções
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
		printf("Escolha opção de listagem:\n1-Ordem Alfabética\n2-De Z à A\n3-Profissão\n0-Voltar ao menu anterior\nDigite a opção: ");
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

//Objetivo : Imprime os atores em ordem alfabética
//Parametro: Vetor com atores em ordem alfabética
//Retorno  : Sem retorno
void imprimeOrdem(Atores *atores, int ordem, int nro_atores)
{
	//Declarações
	int aux, opcao = 0, valida = 0, aux2;
	char opcao1;
	
	//Instuções
	
	//Se for 0 ordem alfabética se for 1 de A-Z
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
			printf("Digite o número correspondente à opção: ");
			valida = scanf("%d", &opcao);
			fflush(stdin);
			if(!valida || opcao < 0 && opcao > nro_atores)
			{
				printf("Opção inválida! ");
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
	//Declarações
	int profissao, aux, posicao = 0, opcao = 0, valida = 0;
	char opcao1;
	Atores atores_prof[nro_atores];
	
	//Instruções
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
		if(!posicao)
		{
			printf("Nenhuma pessoa com a profissao ");
			imprimeProfissaoAtor(profissao);
			printf(" encontrado!\n");
			system("pause");
			system("cls");
			return;
		}
		
		printf("\n0-Voltar ao menu anterior\n");
		do
		{
			printf("Digite o número correspondente à opção: ");
			valida = scanf("%d", &opcao);
			fflush(stdin);
			if(!valida || opcao < 0 && opcao > posicao)
			{
				printf("Opção inválida! ");
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


//==============================================DELETAR ATORES======================================================
//Objetivo : Deletar ator
//Parametro: Nome do arquivo com todos os atores
//Retorno  : Sem retorno
void deletaAtores(const char *arq_nome_atores)
{
	//Declarações
	int validaOpcaoAtoresDeletar(int opcao);
	FILE *arq_substituto, *arq_atores;
	const char arq_nome_substituto[] = "substituto.bin";
	int matricula, nro_atores;
	char opcao, nome[ATORMAXNOME];
	int aux = 0, valida;
	Atores ator;
	
	
	//Instruções
	imprimeMenusAtores('D');
	nro_atores = achaNroAtores(arq_nome_atores);
	if(!nro_atores)
	{
		printf("Nenhuma pessoa cadastrada!\n");
		system("pause");
		return;
	}
	//Este do while é para verificar se a matricula existe
	do
	{
		printf("Digite a matrícula da pessoa que deseja excuir: ");
		valida = scanf("%d", &matricula);
		fflush(stdin);
		if(!valida || !temMatriculaIgualAtor(matricula, arq_nome_atores) || temMatriculaIgualAtor(matricula, arq_nome_atores) != -1)
		{
			printf("Matrícula não encontrada! ");	
		}
	}while(!valida || !temMatriculaIgualAtor(matricula, arq_nome_atores) || temMatriculaIgualAtor(matricula, arq_nome_atores) != -1);
	system("cls");
	
	imprimeMenusAtores('D');
	arq_substituto = abreArquivo("a+b", arq_nome_substituto);
	arq_atores = abreArquivo("r+b", arq_nome_atores);
	
	while(!(feof(arq_atores)))
	{
		fread(&ator, sizeof(Atores), 1, arq_atores);
		if(ator.matricula == matricula)
		{
			printf("1-NOME: %s\n2-IDADE: %d\n3-PROFISSÃO:", ator.nome, ator.idade);
			imprimeProfissaoAtor(ator.profissao);
			printf("\n4-FILMES FEITOS: %s\n5-NACIONALIDADE: %s", ator.filmes_feitos, ator.nacionalidade);
			do
			{
				printf("Deseja excluir a pessoa %s ? 'S' para sim e 'N' para não. ");
				opcao = getch();
			}while(!validaOpcaoAtoresDeletar(opcao));
			system("cls");
			if(toupper(opcao) == 'S')
			{
				strcpy(nome, ator.nome);
				aux++;
			}
			else
			{
				fwrite(&ator, sizeof(Atores), 1, arq_substituto);
				aux++;
			}
		}
		else
		{
			fwrite(&ator, sizeof(Atores), 1, arq_substituto);
			aux++;
		}
	}
	
	fechaArquivo(arq_substituto);
	fechaArquivo(arq_atores);
	
	if(!remove(arq_nome_atores) && toupper(opcao) == 'S')
	{
		rename(arq_nome_substituto, arq_nome_atores);
		printf("%s apagado com sucesso!\n\n", strupr(nome));
		system("pause");
		system("cls");
		return;
	}
	
}

//============================================OUTRASFUNCOES=====================================================
//Objetivo : Imprime as opções de cadastro referente so menu
//Parametro: Qual o tipo de menu
//Retorno  : Sem retorno
void imprimeMenusAtores(char tipo)
{
	/*
	'P' = menu principal dos atores
	'C' = menu de cadastro de atores
	'E' = menu de edição de atores
	'L' = menu de listagem de atores
	'D' = menu de listagem de atores
	*/
	
	printf("PRINCIPAL/ATORES");
	switch(toupper(tipo))
	{
		case 'P':
			printf("\n________________________________________________________________________________________________________________________\n");
			printf("Escolha a opção que deseja entrar:\n1-Cadastrar\n2-Editar\n3-Listar\n4-Deletar\n0-Voltar ao menu anterior\nDigite uma opção: ");
			return;
		case 'C':
			printf("/CADASTRAR\n_________________________________________________________________________________________________________________________\n");
			return;
		case 'E':
			printf("/EDITAR\n____________________________________________________________________________________________________________________\n");
			return;
		case 'L':
			printf("/LISTAR\n____________________________________________________________________________________________________________________\n");
			return;
		case 'D':
			printf("/DELETAR\n_________________________________________________________________________________________________________________________\n");
			return;
	}
}

//Objetivo : Verifica se há matriculas iguais 
//Parametro: Vetor de deputados, matricula, numero de deputados cadastrados
//Retorno  : Um se não houver, zero se houver erro na matricula, -1 se houver matricula igual
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


//Objetivo : Imprime na tela a profissão do ator
//Parametro: Profissão do ator
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

//Objetivo : Organizar atores em ordem alfabética
//Parametro: Vetor de atores, inicio do vetor, final do vetor
//Retorno  : Sem retorno
void organizaAtores(Atores *atores, int inicio, int fim)
{
	//Declarações
	int aux, aux1;
    char troca[ATORMAXNOME], troca2[ATORMAXNOME];
    char troca_filmes[ATORMAXFILMES], troca_nacionalidade[ATORMAXNACIONALIDADE];
    int troca_matricula, troca_profissao, troca_idade;

	//Instruções
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
//Objetivo : Validar opção do menu principal de atores
//Parametro: Opção
//Retorno  : Situação da validação
int validaOpcaoAtoresPrincipal(int opcao)
{
	//Instruções 
	
	if(opcao < 48 || opcao > 52)
	{
		printf("Opção inválida!\n");
		return 0;
	}
	else
	{
		return 1;
	}
}

//Objetivo : Validar opção do menu de cadastro de atores
//Parametro: Opção
//Retorno  : Situação da validação
int validaOpcaoAtoresCadastro(int opcao)
{
	//Instruções
	opcao = toupper(opcao);
	if(opcao != 83 && opcao != 78)

	{
		printf("Opção inválida!\n");
		return 0;
	}
	else
	{
		return 1;
	}
}

//Objetivo : Validar matricula
//Parametro: Nome do arquivo que contem todos os atores, matricula digitada
//Retorno  : Situação da validação
int validaMatricula(const char *arq_nome_atores, int matricula)
{
	//Declarações
	FILE *arq_atores;
	int aux;
	Atores atores;
	
	//Instruções
	
	if(!temMatriculaIgualAtor(matricula, arq_nome_atores) || temMatriculaIgualAtor(matricula, arq_nome_atores) == -1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	
}

//Objetivo : Valida a opção do menu atores editar
//Parametro: Opção
//Retorno  : Situação da Validação
int validaOpcaoAtoresEdita(int opcao)
{
	if(opcao < 48 || opcao > 53)
	{
		printf("Opção inválida! ");
		return 0;
	}
	else 
	{
		return 1;
	}
}

//Objetivo : Validar opção do menu atores listar
//Parametro: Opção
//Retorno  : Situação da validação
int validaOpcaoAtoresListar(int opcao)
{
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

//Objetivo : Validar opção do menu atores deletar
//Parametro: Opção
//Retorno  : Situação da validação
int validaOpcaoAtoresDeletar(int opcao)
{
	opcao = toupper(opcao);
	if(opcao != 83 && opcao != 78)
	{
		printf("Opção inválida!\n");
		return 0;
	}
	else
	{
		return 1;
	}	
	
}
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

