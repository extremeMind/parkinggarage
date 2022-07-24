/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: MRM,LDA
 *
 * Created on 23 de Novembro de 2017, 14:56
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




void login_admin(void) {
    int opcao;
    do {
        clear();

        printf("1-Consultar todos os logins existentes\n");
        printf("2-Limpar um login\n");
        printf("0-Sair\n");
        readInt(&opcao, 0, 2, "Introduza a opcão:");

        switch (opcao) {
            case 1:
                mostrar_login(carro_registado);
                break;

            case 2:
                limpar_login();
                break;
        }



    } while (opcao != 0);

}

void admin_mode(void) {
    int opcao10;
    int opcaoadmin;
    int pw=0;
    do {
        clear();
        printf("\t**ADMIN**\t");
        printf("\n1.Entrar\n");
        printf("0.Sair\n");
        readInt(&opcao10, 0, 1, "Introduza a opcão:");
        switch (opcao10) {
            case 1:
                 clear();

                printf("Password de administrador\n");
                scanf("%d", &pw);
                if (pw == 1234) {
                    abreficheiros();

                    do {
                         clear();

                        printf("1.Apresentar tabela do parque de estacionamento\n");
                        printf("2.Procurar um lugar através da matricula\n");
                        printf("3.Procurar a matrícula através do lugar\n");
                        printf("4.Remover carro do lugar\n");
                        printf("5.Alterar login\n");
                        printf("0.Sair\n");

                        printf("Opção:");
                        readInt(&opcaoadmin, 0, 5, "Introduza a opção:");
                        switch (opcaoadmin) {
                            case 1:
                                clear();

                                imprimetabela_admin();
                                teclacontinuar();
                                break;
                            case 2:
                                 clear();
                                if (lugareslivres != 100){
                                    admin_procurarmatricula();
                                    }
                                
                                else{ 
                                    printf("\nO parque está vazio\n");
                                    teclacontinuar();
                                }
                                
                                 
                                break;
                            case 3:
                                 clear();
                                if (lugareslivres != 100){
                                    admin_procurarporlugar();
                                    }
                                
                                else{ 
                                    printf("\nO parque está vazio\n");
                                    teclacontinuar();
                                }
                                    
                                break;
                            case 4:
                                   clear();
                                if (lugareslivres == 100) {
                                    printf("O parque encontra - se vazio!!");
                                    teclacontinuar();
                                } else {
                                    admin_removercarro();
                                    fechaficheiros();
                                }
                                break;
                            case 5:
                                login_admin();
                                break;

                        }
                    } while (opcaoadmin != 0);
                    fechaficheiros();
                }
        }




    } while (opcao10 != 0);

}

void f_saida(void) {

    int opcao_6;
   
    
    abreficheiros();


    


    do {
        printf("\n");
        imprimetabela_user();
        printf("\n1-Retirar Veículos\n");
        printf("0-Sair\n");
        readInt(&opcao_6, 0, 1, "Introduza a opção:");
        switch (opcao_6) {
            case 1:
                if (lugareslivres == 100) {
                    printf("O parque encontra - se vazio!!");
                    teclacontinuar();
                    break;
                } else {
                    saida_p();
                }
                break;

        }


    } while (opcao_6 != 0);
}



void menu_login(void) {
    abreficheiros();

    int opcao20;

    do {


        printf("1-Registar veiculo\n");
        printf("2-Criar um login\n");
        printf("3-Usar login\n");
        printf("0-Sair\n");
        readInt(&opcao20, 0, 3, "Introduza a opção:");

        switch (opcao20) {
            case 1:
                if (lugareslivres > 0) {
                    criar_veiculo();
                } else
                    printf("Não existem lugares livres\n\n");
                break;
            case 2:
                criar_login_novo();
                break;
            case 3:
                if (lugareslivres > 0) {
                    criar_vei_Login();
                } else
                    printf("Não existem lugares livres\n\n");
                break;
        }

    } while (opcao20 != 0);
}



//menus

void menu2(void) {

    int opcao2;
    do {

         clear();

        printf("\nServiços de estacionamento\n ");
        printf("\n\n\t1-Entrada no parque\n ");
        printf("\t2-Saída do parque\n");
        printf("\t0-Voltar atrás\n ");
        readInt(&opcao2, 0, 2, "Introduza a opção:");

        switch (opcao2) {
            case 1:
                 clear();
                menu_login();

                break;

            case 2:
                 clear();
                f_saida();


                break;
        }

    } while (opcao2 != 0);




}






int main(int argc, char** argv) {
    int opcao;

    


    do {
         
        clear();
        printf("\t**Bem - Vindo ao parque MRM,Lda**\t\n\n");
        printf("\t1-Serviços de estacionamento\n ");
        printf("\t2-Modo de admin\n ");
        printf("\t3-Normas do parque\n ");
        printf("\t0-Saída do programa\n ");
        readInt(&opcao, 0, 3, "Introduza a opção:");

        switch (opcao) {
            case 1:

                menu2();
                 clear();
                break;

            case 2:
                 clear();

                admin_mode();

                break;

            case 3:
                clear();

                informacao();
                break;
        }


    } while (opcao != 0);



    return (EXIT_SUCCESS);
}












