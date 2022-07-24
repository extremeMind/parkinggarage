/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include "LP_Utils.h"
#include "LP_Leitura.h"
#include "Variaveis.h"
#include "Login.h"
#include "Admin.h"
#include "informacao.h"
#include "abreficheiros.h"
#include "funcoes_g.h"
#include "fechaficheiros.h"


/*PROCURAR MATRICULA- Função que pede uma matrícula
 e indica o lugar onde esta o veiculo*/

void admin_procurarmatricula(void) {
    int i = 0;
    int u = 0, Z = 1;

    pede_mat();

    for (i = 0; i < MAX; i++) {
        if ((matrizMAT[i][0] != matricula[0]) || (matrizMAT[i][1] != matricula[1]) || (matrizMAT[i][2] != matricula[2]) || (matrizMAT[i][3] != matricula[3]) || (matrizMAT[i][4] != matricula[4]) || (matrizMAT[i][5] != matricula[5]))
            Z++;
        else
            u = i + 1;
    }

    if (u != 0)
        printf("Está no lugar: %d\n", u);
    else
        printf("Este carro não existe\n\n");
teclacontinuar();
}

//PROCURAR CARRO POR LUGAR

void admin_procurarporlugar(void) {
    int i = 0;
    do {
        printf("Insira o lugar: ");
        scanf("%d", &L);
    } while (L < 0 && L > MAX + 1);

    i = L - 1;
    printf("Matrícula:\n");
    printf("%c%c-%c%c-%c%c\n", matrizMAT[i][0], matrizMAT[i][1], matrizMAT[i][2], matrizMAT[i][3], matrizMAT[i][4], matrizMAT[i][5]);

    teclacontinuar();
}

/*Função que permite ao administrador remover um veículo*/

void rem_adm(void) {
    int z = 0, i = 0;
    int flag = 0;
    do {
        do {


            imprimetabela_admin();
            printf("Insira o lugar: ");
            scanf("%d", &L);
        } while (L < 0 && L > MAX + 1);
        if (vetorOD[L - 1] == 'L') {
            flag = 1;
        } else if (vetorOD[L - 1] == 'O') {
            flag = 2;
        }
    } while (flag != 2);

    vetorOD[L - 1] = 'L';
    vetorHoraE[L - 1] = 0;
    vetorMinE[L - 1] = 0;
    vetorTIPO[L - 1] = 'T';
    vetorDIAE[L - 1] = 0;
    vetorMESE[L - 1] = 0;
    vetorANOE[L - 1] = 0;
    vetorlavagem_1 [L - 1] = 'N';
    vetorlavagem[L - 1] = 0;
    i = L - 1;
    for (z = 0; z < 6; z++) {
        matrizMAT[i][z] = '0';
    }
    ++lugareslivres;
    ocupado = MAX - lugareslivres;
}

/*Função que permite ao administrador remover um veículo*/
void admin_removercarro(void) {
    int opcao_7;
    imprimetabela_admin();
    do {
        do {
            printf("\n1-Retirar Veículos\n");
            printf("0-Sair\n");
            scanf("%d", &opcao_7);
        } while (opcao_7 < 0 || opcao_7 > 2);
        switch (opcao_7) {
            case 1:
                 clear();

                rem_adm();
                break;

        }


    } while (opcao_7 != 0);



}
//Imprime uma tabela com todas as informações
void imprimetabela_admin(void) {
    int i = 0;
    ocupado = MAX - lugareslivres;
    printf("Lugar: Ocupação: Data.D/M/A:  \tH.Entrada:  \tTipo:   \tMatrícula:   \tLavagem: \n ");
    for (i = 0; i < MAX; i++) {
        printf("%3d    %c          %.2d/%.2d/%.2d             %.2d:%.2d         %c            %c%c-%c%c-%c%c            %c\n ", vetorLugares[i], vetorOD[i], vetorDIAE[i], vetorMESE[i], vetorANOE[i], vetorHoraE[i], vetorMinE[i], vetorTIPO[i], matrizMAT[i][0], matrizMAT[i][1], matrizMAT[i][2], matrizMAT[i][3], matrizMAT[i][4], matrizMAT[i][5], vetorlavagem_1[i]);
    }
    printf("\nLugares totais 100 , Lugares livres %d, Lugares ocupados %d\n\n", lugareslivres, ocupado);



}

