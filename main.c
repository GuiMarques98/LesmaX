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
			printf("\nEscolha o menu que deseja entrar:\n1-Filmes\n2-Salas de Cinema\n3-Atores\nInsira a op��o:");
			opcao = getch();
			
		}while(!validaOpcaoMain(opcao));
		
		
		switch(opcao)
		{
			case '1':
				
				break;
			case '2':
				
				break;
			case '3':
				
				break;
		}
		
	}while(opcao != 0);
	
    return 0;
}

//================================================SUBPROGRAMAS==================================================
//=================================MENU PRINCIPAL====================================
//Objetivo : Validar op��o do menu principa� 
//Parametro: Op��o 
//Retorno  : Situa��o da valida��o 
int validaOpcaoMain(int opcao)
{
	//Instru��es 
	
	if(toupper(opcao) != 83 && toupper(opcao) != 78)
	{
		printf("Op��o inv�lida!\n");
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
