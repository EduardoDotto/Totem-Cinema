#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include <dos.h>
#include "cinema.h"

/*
CINEMA BIOPARK
*/


//INICIANDO P PROGRAMA PRINCIPAL
int main()
{
    // Colocando cores
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    SetConsoleTextAttribute(hConsole, 15);  //128 cinza-preto 32 verde-preto 64 vermelho-preto 96 amarelo-preto 15 PRETO-BRANCO
    int tamanho=120;                        // DEFININDO A QUANTIDADE DE LUGARES
    struct ingresso vendas[tamanho];
    setlocale(LC_ALL, "Portuguese");        // ACEITANDO ACENTUAÇÃO BR
    preparavenda(vendas,tamanho);           // LIBERANDO VENDAS
    menu(vendas,tamanho);                   //ABRINDO MENU
    return 0;
}


