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

//Cabeçalhos


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
			printf("\nEscolha o menu que deseja entrar:\n1-Filmes\n2-Salas de Cinema\n3-Atores\nInsira a opção:");
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
//Objetivo : Validar opção do menu principaç 
//Parametro: Opção 
//Retorno  : Situação da validação 
int validaOpcaoMain(int opcao)
{
	//Instruções 
	
	if(toupper(opcao) != 83 && toupper(opcao) != 78)
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
