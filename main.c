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

//Defines
#define ATORMAXNOME 30
#define ATORMAXFILMES 200
#define ATORMAXNACIONALIDADE 20

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

//Cabeçalhos
void menuAtores();

//Principal
int main()
{
	//Declarações 
	char opcao;
	int validaOpcaoMain(int opcao);
	
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
				
				break;
			case '3':
				menuAtores();
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
//===============MENU=====================
//Objetivo : 
//Parametro: 
//Retorno  : 
void menuAtores()
{
	//Declarações
	FILE *arq_atores;
	const char nome_arq_atores[] = "atores.bin";
	char opcao;
	
	//Instruções
	
	
	
}

//Objetivo : 
//Parametro: 
//Retorno  : 

//===================================FILMES==========================================


//===================================SALAS DE CINEMA ================================
