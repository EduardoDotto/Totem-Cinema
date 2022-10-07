#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include <dos.h>
#include "cinema.h"

void menu(struct ingresso vendas[], int tamanho)
{
    int i=0, poltrona, nlivres=120, nreservadas=0, ncompradas=0;
    char aux[500];
    while (i!=5)
    {
        printf("|=============  BEM VINDO AO CINEMA BIOPARK  ===============|\n");
        printf("| FAVOR INFORMAR A AÇÃO DESEJADA!                           |\n");
        printf("| 1 - RESERVAR                                              |\n");
        printf("| 2 - COMPRAR                                               |\n");
        printf("| 3 - CANCELAR                                              |\n");
        printf("| 4 - CONFIRMAR RESERVA                                     |\n");
        printf("| 5 - SAIR                                                  |\n");
        printf("|===========================================================|\n");
        scanf("%d",&i);
        system("cls");
        if (i==5)
        {
            printf("OBRIGADO PELA PREFERÊNCIA E UM ÓTIMO FILME!!!\n");
            video ();
            relatorio(vendas,tamanho);
            return 0;
        }
        switch (i)
        {
        case 1:
        {
            do
            {
                system("cls");
                mostrapoltronas(vendas,tamanho);
                printf("FAVOR ESCOLHER UMA POLTRONA DISPONIVEL PARA RESERVA: ");
                scanf("%d",&poltrona);
            }
            while (vendas[poltrona].ocupado!=0);
            printf("   INFORME SEU NOME: ");
            fflush(stdin);
            gets(vendas[poltrona].nome);
            vendas[poltrona].ocupado=2;
            system("cls");
            mostrapoltronas(vendas,tamanho);
            vendas[poltrona].poltrona=poltrona;
            printf("POLTRONA %d RESERVADA EM NOME DE: %s\n",poltrona,vendas[poltrona].nome);
            nreservadas++;
            nlivres--;
            break;
        }

        case 2:
        {
            do
            {
                mostrapoltronas(vendas,tamanho);
                printf("FAVOR ESCOLHER UMA POLTRONA DISPONIVEL PARA COMPRAR: ");
                scanf("%d",&poltrona);

            }
            while (vendas[poltrona].ocupado!=0);
            printf("   INFORME SEU NOME:");
            fflush(stdin);
            gets(vendas[poltrona].nome);
            vendas[poltrona].ocupado=1;
            system("cls");
            mostrapoltronas(vendas,tamanho);
            vendas[poltrona].poltrona=poltrona;
            printf("POLTRONA %d COMPRADE EM NOME DE: %s\n",poltrona,vendas[poltrona].nome);
            ncompradas++;
            nlivres++;

            break;
        }

        case 3:
        {
            if (nreservadas==0)
            {
                mostrapoltronas(vendas,tamanho);
                printf("NENHUMA POLTRONA RESERVADA!\n");
                sleep(2);
                system("cls");
                break;
            }
            else
            {
                do
                {
                    system("cls");
                    mostrapoltronas(vendas,tamanho);
                    printf("FAVOR ESCOLHER RESERVADA PARA CANCELAR: \n");
                    scanf("%d",&poltrona);
                }
                while (vendas[poltrona].ocupado!=2);
                system("cls");
                vendas[poltrona].ocupado=0;
                nreservadas--;
                mostrapoltronas(vendas,tamanho);
                printf("POLTRONA %d ESTA VAGA\n",poltrona);
                break;
            }
        }

        case 4:
        {
            if (nreservadas==0)
            {
                mostrapoltronas(vendas,tamanho);
                printf("NENHUMA POLTRONA RESERVADA!\n");
                sleep(2);
                system("cls");
                break;

            }
            else
            {
                system("cls");
                do
                {
                    mostrapoltronas(vendas,tamanho);
                    printf("FAVOR ESCOLHER A POLTRONA RESERVADA PARA CONFIRMAR A COMPRA: ");
                    scanf("%d",&poltrona);
                }
                while (vendas[poltrona].ocupado!=2);
                printf("   INFORME SEU NOME: ");
                fflush(stdin);
                gets(aux);
                if (strcmp(vendas[poltrona].nome,aux)==0)
                {
                    vendas[poltrona].ocupado=1;
                    system("cls");
                    mostrapoltronas(vendas,tamanho);
                    vendas[poltrona].poltrona=poltrona;
                    printf("POLTRONA %d CONFIRMADA EM NOME DE: %s\n",poltrona,vendas[poltrona].nome);
                    nreservadas++;
                    nlivres--;
                    break;
                }

                else
                    system("cls");
                printf("POLTRONA %d RESERVADA POR OUTRA PESSOA\n",poltrona);
                break;
            }
        }

        default:
        {
            printf("|=============  BEM VINDO AO CINEMA BIOPARK  ===============|\n");
            printf("| FAVOR INFORMAR A AÇÃO DESEJADA!                           |\n");
            printf("| 1 - RESERVAR                                              |\n");
            printf("| 2 - COMPRAR                                               |\n");
            printf("| 3 - CANCELAR                                              |\n");
            printf("| 4 - SAIR                                                  |\n");
            printf("|===========================================================|\n");
            scanf("%d",&i);
            system("cls");
        }
        }
    }
}

void preparavenda(struct ingresso vendas[], int tamanho)
{
    for (int i=1; i<tamanho; i++)
    {
        vendas[i].ocupado=0;// 0 para poltronas livres
        //printf("%d",vendas[i].ocupado);
    }
}

void mostrapoltronas(struct ingresso vendas[], int tamanho)
{
//IMPRIME COLORIDO
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n ");
    SetConsoleTextAttribute(hConsole, 240);
    printf("                               TELA                            \n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("   ");

    for (int i=1; i<=120; i++)
    {
        //printf("[%d] ",vendas[i].ocupado);
        //ALINHANDO AS COLUNAS
        //LIVRES
        if(vendas[i].ocupado==0)
        {
            SetConsoleTextAttribute(hConsole, 32);
            if (i<10)
            {
                printf("[  %d]",i);
            }
            if (i>=10 && i<=99)
            {
                printf("[ %d]",i);
            }
            if (i>=100)
            {
                printf("[%d]",i);
            }
        }
        //RESERVADAS
        else if (vendas[i].ocupado==2)
        {
            SetConsoleTextAttribute(hConsole, 96);
            if (i<10)
                printf("[  %d]",i);
            if (i>=10 && i<=99)
                printf("[ %d]",i);
            if (i>=100)
                printf("[%d]",i);
        }
        //OCUPADAS
        else if (vendas[i].ocupado==1)
        {
            SetConsoleTextAttribute(hConsole, 64);
            if (i<10)
                printf("[  %d]",i);
            if (i>=10 && i<=99)
                printf("[ %d]",i);
            if (i>=100)
                printf("[%d]",i);
        }

        SetConsoleTextAttribute(hConsole, 15);
        if (i%10==0)
        {
            printf("\n");
        }
        if (i==20)
        {
            printf("\n");
        }
        if (i%5==0)
        {
            printf("  ");
        }
        printf(" ");
    }
}

void video ()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    for (int i=0; i<10; i++)
    {

       SetConsoleTextAttribute(hConsole, 64);
        printf("  /888888  /888888 /88   /88 /88888888 /88      /88  /888888 \n");
        Sleep(100);
        SetConsoleTextAttribute(hConsole, 192);
        printf(" /88__  88|_  88_/| 888 | 88| 88_____/| 888    /888 /88__  88\n");
        Sleep(100);
        SetConsoleTextAttribute(hConsole, 96);
        printf("| 88  \__/   | 88  | 8888| 88| 88      | 8888  /8888| 88  \  88\n");
        Sleep(100);
        SetConsoleTextAttribute(hConsole, 32);
        printf("| 88        | 88  | 88 88 88| 88888   | 88 88/88 88| 88888888\n");
        Sleep(100);
        SetConsoleTextAttribute(hConsole, 44);
        printf("| 88        | 88  | 88  8888| 88__/   | 88  88 | 88| 88__  88\n");
        Sleep(100);
        SetConsoleTextAttribute(hConsole, 16);
        printf("| 88    88  | 88  | 88\   888| 88      | 88\  8  | 88| 88  | 88\n");
        Sleep(100); // Espera um segundo
        SetConsoleTextAttribute(hConsole, 208);
        printf("|  888888/ /888888| 88 \   88| 88888888| 88 \/   | 88| 88  | 88\n");
        Sleep(100); // Espera um segundo
        SetConsoleTextAttribute(hConsole, 128);
        printf(" \______/ |______/|__/  \__/|________/|__/     |__/|__/    |__/\n");
        Sleep(100); // Espera um segundo
        SetConsoleTextAttribute(hConsole, 15);
        system("cls");

    }
}

void relatorio(struct ingresso vendas[], int tamanho){
    FILE *arquivo = fopen("Relatório.txt", "w");
    char frase[200];
    char situacao[50];

    // grava no arquivo
    fprintf(arquivo, "RELATÓRIO DE VENDAS\n");
    fprintf(arquivo, "-----------------------------------------------------------------------\n");
    for(int i=1; i<=tamanho; i++){
        if (vendas[i].ocupado != 0){
                if (vendas[i].ocupado == 1)
                strcpy(situacao,"Comprado");
                if (vendas[i].ocupado == 2)
                strcpy(situacao,"Reservado");
            fprintf(arquivo, "Nome: %s - Poltrona %d - Situação %s \n",vendas[i].nome,vendas[i].poltrona,situacao);
           }

    }
    //fprintf(arquivo, "Hello world!\n");

    // fecha o arquivo aberto no modo gravacao
    fclose(arquivo);


    // abre o arquivo no modo leitura
    arquivo = fopen("Relatório.txt", "r");

    // le do arquivo e grava na variavel frase
    fscanf(arquivo, "%[^\n]", frase);

    // imprime na tela o que foi gravado na var. frase
    printf("LIDO: %s\n", frase);

    // fecha o arquivo que estava no modo leitura
    fclose(arquivo);


    return 0;
}
