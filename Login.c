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





//Pede o número de utilizador para o login
int inserir_n_utilizador() {
    int x = 0;
     
        printf("Insira um número de utilizador:");
        scanf("%d", &x);
    

    return (x);
}

//Função que verifica se o numero de utilizador existe
int verifica_n_utilizador(LOGIN carro_logado[], int n_utili, int *p) { 
    int k = 0;
    int i = 0;

    while ((i < N_login) && (!k)) { // se encrontrar para
        if (n_utili == carro_logado[i].n_utilizador) {
            k = 1;
            *p = i;
        }

        i++;
    }

    return (k);
}
//Funçao que verifica se um login existe 
int verifica_existelogin(int n_utili, int *p) {
    int ce = 0;
    ce = verifica_n_utilizador(carro_registado, n_utili, p);

    while (ce != 1) {

        n_utili = inserir_n_utilizador();

        ce = verifica_n_utilizador(carro_registado, n_utili, p);
    }

    return (n_utili);
}
/*Funcao que permite criar um login novo
 * Tem um maximo de logins*/

void criar_login_novo(void) {
    abreficheiros(); //funcao que abre ficheiros
    int j=0, i = 0;
    char opcao;
    int pagar_login=0;

    printf("Os nossos logins são restritos a um determinado número de utilizadores\n");
    printf("Para usufruir deste serviço terá de pagar uma modesta quantia de 10€\n");

     while (carro_registado[i].n_utilizador != 0) { //verifica quantos registos existem 
            i++;
        }

        if (i >= N_login){
            printf("\n\n\nRegistos não disponíveis\n");
            teclacontinuar();
        }

        else {
    
    do {
        printf("Deseja criar o seu login? : Sim(S)/Não(N)\n");
        scanf(" %c", &opcao);
    } while (opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N');
    if (opcao == 's' || opcao == 'S') {



       
        


        printf("Introduza a quantia exata de 10€:\n");
        scanf("%d", &pagar_login);

        while (pagar_login != 10) {

            printf("\nRetire o dinheiro\n");
            printf("Introduza a quantia exata:\n");
            scanf("%d", &pagar_login);
        }

        



        carro_registado[i].n_utilizador = i + 1;
        printf("O seu número de ultilizador:%d\n", i + 1);




        do {
            printf("Palavra-Passe:");
            scanf("%d", &carro_registado[i].passe);
        } while (carro_registado[i].passe <= 999 || carro_registado[i].passe > 9999);

        do {
            printf("Tipo veículo (L-Ligeiro; P-Pesado; M-Motociclo):");
            scanf(" %c", &carro_registado[i].tipo_veiculo);
            carro_registado[i].tipo_veiculo = toupper(carro_registado[i].tipo_veiculo);
        } while ((carro_registado[i].tipo_veiculo != 'P') && (carro_registado[i].tipo_veiculo != 'L') && (carro_registado[i].tipo_veiculo != 'M'));


        printf("Matrícula:");

        for (j = 0; j < 6; j++) {

            scanf(" %c", &carro_registado[i].matt[j]);
        }
        for (j = 0; j < 6; j++) {
            carro_registado [i].matt[j] = toupper(carro_registado[i].matt[j]);
        }

    } else if (opcao == 'n' || opcao == 'N')
    teclacontinuar();
        }
              
    fechaficheiros();





}
// Usar um login para registar um veículo no parque, entra com o login e escolhe o lugar
void criar_vei_Login(void) {
    int n_utili = 0;
    int opcao5;
    int pass_logar=0;

    int u;
    int *p = &u; 
    //Apontador para saber em que posição esta o n_utilizador inserido para ir buscar as informações


    abreficheiros(); 



    n_utili = inserir_n_utilizador();

    if(n_utili==0){
        printf("Este utilizador não existe\n");
        teclacontinuar();
    }
    else {
    verifica_existelogin(n_utili, p);

    printf("Insira a password:");
    scanf("%d", &pass_logar);




    if (pass_logar == carro_registado[u].passe) {


        imprimetabela_user();

        do {
            printf("1-Lugares normais\n");
            printf("2-Lugares prioritários\n");
            printf("0-Sair\n\n");
            readInt(&opcao5, 0, 2, "Introduza a opção:");
            switch (opcao5) {
                case 1:
                    do {//inserir veiculo no parque -lugares normais
                        printf("Os lugares 90 ao 100 são lugares prioritários/reservados!");
                        printf("\nEscolha o lugar disponível: ");
                        scanf("%d", &L);
                    } while (vetorOD[L - 1] == 'O' || L > 89 || L < 1);
                    sistemalavagem();
                    inserir_vei_Login(u);
                    break;
                case 2://inserir veiculo no parque -lugares prioritarios
                    printf("Lugares para pessoas portadoras de deficiência ou mobilidade reduzida\n");
                    printf("Lugares: 90-98\n");
                    printf("Estações de carregamento de carros elétricos\n");
                    printf("Lugares: 99-100\n");
                    do {
                        printf("Escolha o lugar disponível: ");
                        scanf("%d", &L);
                    } while (vetorOD[L - 1] == 'O' || L > MAX || L < 1);
                    sistemalavagem();
                    inserir_vei_Login(u);
                    break;

            }


        } while (opcao5 != opcao5);

    } else
        printf("Password errada\n");}
}
// Usar um login para registar um veículo no parque
void inserir_vei_Login(int u) {
    int i = 0;
    int horaentrada=0, minutoentrada=0;
    char tipo;
    int diaentrada=0, mesentrada=0, anoentrada=0;


    //HORA DE ENTRADA 
    printf("***Hora de entrada***\n");
    time_t tempoexe;
    struct tm *info;
    time(&tempoexe);
    info = localtime(&tempoexe);
    //HORAS MINUTOS
    strftime(horas, MAX, "%H", info);
    printf("Hora : %s\n", horas);
    strftime(minutos, MAX, "%M", info);
    printf("Minutos: %s\n", minutos);
    horaentrada = atoi(horas);
    minutoentrada = atoi(minutos);

    // DIA MES ANO
    strftime(dias, MAX, "%d", info);
    printf("Dia : %s\n", dias);
    strftime(mes, MAX, "%m", info);
    printf("Mes : %s\n", mes);
    strftime(ano, MAX, "%y", info);
    printf("Ano : %s\n", ano);
    diaentrada = atoi(dias);
    mesentrada = atoi(mes);
    anoentrada = atoi(ano);

    //////////////////////////////////////////////////////////////////////////


    //Tipo de veiculo
    tipo = carro_registado[u].tipo_veiculo;


    //MATRICULA
    for (i = 0; i < 6; i++) {
        matrizMAT[L - 1][i] = carro_registado[u].matt[i];
    }







    vetorOD[L - 1] = 'O';

    vetorHoraE[L - 1] = horaentrada;
    vetorMinE[L - 1] = minutoentrada;
    vetorDIAE[L - 1] = diaentrada;
    vetorMESE[L - 1] = mesentrada;
    vetorANOE[L - 1] = anoentrada;
    vetorTIPO[L - 1] = tipo;
    --lugareslivres;
    ocupado = MAX - lugareslivres;




    imprimetabela_user();
    fechaficheiros(); 
}
// Função para ver todos os logins
void mostrar_login(LOGIN carro_logado[]) {

    for (int i = 0; i < N_login; i++) {

        printf("Número de utilizador:%d\n", carro_logado[i].n_utilizador);
        printf("Palavra-passe:%d\n", carro_logado[i].passe);
        printf("Tipo de veículo: %c \n", carro_logado[i].tipo_veiculo);
        printf("Matrícula:%c%c-%c%c-%c%c\n", carro_logado[i].matt[0], carro_logado[i].matt[1], carro_logado[i].matt[2], carro_logado[i].matt[3], carro_logado[i].matt[4], carro_logado[i].matt[5]);
        printf("\n");
    }
    teclacontinuar();
   

}
//Função que permite eliminar um login
void limpar_login(void) {
    int i, k;
    int posicao=0;
    abreficheiros();
    for (i = 0; i < N_login; i++) {
        printf("Número de utilizador:%d\n", carro_registado[i].n_utilizador);
    }
    printf("Escola o utilizador a apagar:");
    scanf("%d", &posicao);

    carro_registado[posicao - 1].n_utilizador = 0;
    carro_registado[posicao - 1].passe = 0;
    carro_registado[posicao - 1].tipo_veiculo = 'T';
    for (k = 0; k < 6; k++) {
        carro_registado[posicao - 1].matt[k] = '0';
    }

    fechaficheiros();



}
