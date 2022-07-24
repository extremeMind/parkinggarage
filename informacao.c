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

void informacao(void) {
    int opcao;
    do {
         clear();

        printf("\n\nNormas de utilização do parque\n");
        printf("\n\n\t1-Características do parque de estacionamento\n ");
        printf("\t2-Utilizadores\n ");
        printf("\t3-Controlo de acesso e condições de utilização\n ");
        printf("\t4-Restrições de utilização\n");
        printf("\t5-Horário de funcionamento\n");
        printf("\t6-Segurança do parque de estacionamento\n");
        printf("\t7-Regras de boa utilização\n");
        printf("\t8-Tabela de preços\n");
        printf("\t0-Saída\n ");
        readInt(&opcao, 0, 8, "Introduza a opção:");

        switch (opcao) {
            case 1:
                 clear();

                printf("\nEscolheu características do parque de estacionamento\n");
                printf("\n\t1-O parque de estacionamento é propriedade da MMR,Lda e destina- se ao uso público;");
                printf("\n\t2-A gerência não assume a responsabilidade por eventuais prejuízos causados a viaturas no interior do parque;");
                printf("\n\t3-O parque tem uma capacidade total de %d lugares.",MAX);
                teclacontinuar();
                break;

            case 2:
                 clear();
                printf("\nEscolheu utilizadores\n");
                printf("\n\t1-O parque de estacionamento destina -se a uso público/utilizadores premium.");
                
                teclacontinuar();
                break;

            case 3:
                 clear();

                printf("\nEscolheu controlo de acesso e condições de utilização\n");
                printf("\n\t1-O controlo do acesso de viaturas é efetuado por seguranças contratados e pelas cancelas automáticas;");
                printf("\n\t2-Durante o período de utilização do parque, o ticket deve ser colocado em local bem visível dentro da viatura;");
                printf("\n\t4-O estacionamento só é permitido nos locais devidamente assinalados para o efeito;");
                printf("\n\t5-No acesso e no interior do parque vigoram as normas de circulação aplicáveis na via pública;");
                printf("\n\t6-Existem dez lugares de estacionamento, devidamente assinalados, para utilizadores com mobilidade condicionada;");
                printf("\n\t7-Relativamente ao serviço de lavagem automóvel, explorada por uma empresa externa, do qual não nos responsabilizamos por qualquer dano ou furto.");
                teclacontinuar();
                break;

            case 4:
                 clear();

                printf("\nEscolheu restrições de utilização\n");
                printf("\n\t1-Não é autorizada a entrada no parque de viaturas que não estejam registadas na base de dados do parque;");
                printf("\n\t2-Nos termos da lei em vigor, é proibido o estacionamento de viaturas utilizando gases de petróleo liquefeito (GPL) como carburante;");
                printf("\n\t3-A velocidade máxima no acesso e no interior do parque são 20km/h.");
                teclacontinuar();
                break;

            case 5:
                 clear();

                printf("\nEscolheu horário de funcionamento\n");
                printf("\n\t1-O parque funciona em permanência todos os dias do ano;");
                teclacontinuar();
                break;


            case 6:
                 clear();

                printf("\nEscolheu segurança do parque de estacionamento\n");
                printf("\n\t1-A segurança no interior do parque é efetuada, em permanência, pela presença de elementos de seguranças contratados;");
                printf("\n\t2-O parque possui:");
                printf("\n\t\ta)Sinalização e plantas de emergência, bem como caminhos de evacuação assinalados;");
                printf("\n\t\tb)Extintores de incêndio, em locais devidamente assinalados;");
                printf("\n\t\td)Deteção e extinção automática de incêndios;");
                printf("\n\t\te)Deteção de monóxido de carbono;");

                teclacontinuar();
                break;

            case 7:
                 clear();

                printf("\nEscolheu regras de boa utilização\n");
                printf("\n\t1-A circulação e manobras devem ser efetuadas com prudência. O estacionamento deve fazer -se dentro dos limites dos lugares pintados no solo;");
                printf("\n\t2-Os motores das viaturas devem ser mantidos em funcionamento apenas pelo período necessário para o acesso e estacionamento;");
                printf("\n\t3-A circulação deve ser feita com os médios ligados;");
                teclacontinuar();
                break;
            case 8:
                 clear();
                preco_inf();
                break;
        }

    } while (opcao != 0);
}

void preco_inf(void) {
    int opcao_18;

    do {
         clear();

        printf("\n\t1 - Preços do parque\n");
        printf("\t2 - Preços da lavagem\n");
        printf("\t0 - Sair\n");
        readInt(&opcao_18, 0, 2, "Introduza a opcão:");

        switch (opcao_18) {
            case 1:
                 clear();

                printf("\n Tipo:         Preço:\n\n ");
                printf("Ligeiro       0.05€/min\n\n");
                printf(" Pesado        0.08€/min\n\n");
                printf(" Motociclo     0.02€/min\n\n");
                teclacontinuar();
                break;
            case 2:
                 clear();

                printf("\n Lavagem:         Preço:\n\n ");
                printf("Completa           10€\n\n");
                printf(" Por fora            5€\n\n");
                printf(" Por dentro          6€\n\n");

                teclacontinuar();
                break;
        }
    } while (opcao_18 != 0);
}
