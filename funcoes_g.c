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

//Função para meter o programa em pausa
void teclacontinuar(void) {
    printf("\n\nPrima enter para continuar:");
    getchar();
    getchar();
}
//Função que compara matriculas 
int compara(char matrizMAT[][6], char matricula[]) { 
    int k = 0;
    int i = 0;
    while ((i < MAX) && (!k)) //se encrontrar para 
    {
        if ((matrizMAT[i][0] == matricula[0]) && (matrizMAT[i][1] == matricula[1]) && (matrizMAT[i][2] == matricula[2]) && (matrizMAT[i][3] == matricula[3]) && (matrizMAT[i][4] == matricula[4]) && (matrizMAT[i][5] == matricula[5]))
            k = 1;
        i++;
    }
    return (k);
}
//Imprime uma tabela diferente do admin, com menos informação
void imprimetabela_user(void) {
    int i = 0;
    ocupado = MAX - lugareslivres;
    printf("Lugar: Ocupação: Data.D/M/A:  \tTipo:   \tLavagem: \n ");
    for (i = 0; i < MAX; i++) {
        printf("%3d        %c       %.2d/%.2d/%.2d       %c            %c\n ", vetorLugares[i], vetorOD[i], vetorDIAE[i], vetorMESE[i], vetorANOE[i], vetorTIPO[i], vetorlavagem_1[i]);
    }
    printf("\nLugares totais 100 , Lugares livres %d, Lugares ocupados %d\n\n", lugareslivres, ocupado);
}
//Função para pedir matricula ao utilizador
void pede_mat(void) {
    int j = 0;
    printf("AVISO:Ao utilizar uma matrícula errada ou falsa estará sujeito a coima\n");
    printf("Se o fizer terá ainda assim de utilizar essa matrícula para retirar o seu veículo\n");
    teclacontinuar();
    printf("\n***** MATRICULA *****\n\n");
    printf("Por favor insira a sua matricula sem os '-'\n");
    for (j = 0; j < 6; j++) {

        scanf(" %c", &matricula[j]);
        matricula[j] = toupper(matricula[j]); //passa as letras minusculas para maiusculas.

    }
}
//Função para verificar se essa matrículas já existe no parque, evitando assim duas matrículas iguais no mesmo período de tempo
void verifica_existe(void) {
    int i = 0, r=0;
    r = compara(matrizMAT, matricula);

    while (r == 1) {

        pede_mat();

        r = compara(matrizMAT, matricula);
    }

    for (i = 0; i < 6; i++) {
        matrizMAT[L - 1][i] = toupper(matricula[i]);

    }
}
//Função para pedir o tipo de veiculo
char tipo_veic() {
    char tipo;
    do {
        printf("\nInsira o tipo do seu veiculo (L-Ligeiro; P-Pesado; M-Motociclo)\n");
        scanf(" %c", &tipo);
        tipo = toupper(tipo); //passa as letras minusculas para maiusculas
    } while ((tipo != 'P') && (tipo != 'L') && (tipo != 'M'));

    return (tipo);
}

void criar_veiculo(void) {
    char gpl;



    int opcao5;


    abreficheiros(); //funcao que abre ficheiros



    do {
        printf("O seu veículo utiliza gás de petróleo liquefeito(GPL)? : Sim(S)/Não(N)\n");
        scanf(" %c", &gpl);
    } while (gpl != 's' && gpl != 'S' && gpl != 'n' && gpl != 'N');
    if (gpl == 's' || gpl == 'S') {
        printf("VEÍCULOS GPL NÃO PODEM ESTACIONAR AQUI!\n");
        printf("Pedimos desculpa pelo incómodo.");
        teclacontinuar();

    } else if (gpl == 'n' || gpl == 'N') {





        //ocupado = 100 - lugareslivres;

        imprimetabela_user();

        do {
            printf("1-Lugares normais\n");
            printf("2-Lugares prioritários\n");
            printf("0-Sair\n\n");
            readInt(&opcao5, 0, 2, "Introduza a opcão:");
            switch (opcao5) {
                case 1:

                    do {//inserir veiculo no parque -lugares normais
                        printf("Os lugares 90 ao 100 são lugares prioritarios/reservados!");
                        printf("\nEscolha o lugar disponível: ");
                        scanf("%d", &L);
                    } while (vetorOD[L - 1] == 'O' || L > 89 || L < 1);
                    inserir_veiculos();


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
                    inserir_veiculos();

                    break;

            }


        } while (opcao5 != opcao5);




    }
}
//Função que permite introduzir no parque um carro sem login, pedindo as informações
void inserir_veiculos(void) {
      
    
    
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

    // pergunta se quer lavagem
    sistemalavagem();
    //tipo de veiculo
    tipo = tipo_veic();


    //PEDIR MATRICULA
    pede_mat();


    //verificar se a matricula existe
    verifica_existe();





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

//Função lavagem permite o utilizador escolher o tipo de lavagem
int lavagem() {
    int opcao11;
    int precolavagem=0;
    do {
        printf("\n1 - Lavagem completa 10€;");
        printf("\n2 - Lavagem só por fora 5€;");
        printf("\n3 - Lavagem só por dentro 6€;");
        printf("\nEscolha uma opção:\n");
        readInt(&opcao11, 1, 3, "Introduza a opção:");

        switch (opcao11) {
            case 1:

                printf("Escolheu opção de lavagem completa.");
                printf("\nO serviço terá um preço de 10€\n");
                precolavagem = 10;

                break;
            case 2:

                printf("Escolheu opção de lavagem só por fora.");
                printf("\nO serviço terá um preço de 5€\n");
                precolavagem = 5;

                break;
            case 3:

                printf("Escolheu opção de lavagem só por dentro.");
                printf("\nO serviço terá um preço de 6€\n");
                precolavagem = 6;

                break;


        }
    } while (opcao11 != opcao11);

    return (precolavagem);
}
//Função para perguntar ao utilizador se quer usufruir da lavagem ou não
void sistemalavagem(void) {

    char opcao12;
    int precolavagem=0;

    abreficheiros();
    do {
        printf("Deseja usufruir dos serviços de lavagem pagos? : Sim(S)/Não(N)\n");
        scanf(" %c", &opcao12);
    } while (opcao12 != 's' && opcao12 != 'S' && opcao12 != 'n' && opcao12 != 'N');
    if (opcao12 == 's' || opcao12 == 'S') {
        precolavagem = lavagem();



    } else if (opcao12 == 'n' || opcao12 == 'N')
        precolavagem = 0;





    vetorlavagem_1[L - 1] = toupper(opcao12);
    vetorlavagem[L - 1] = precolavagem;



    fechaficheiros();
}

//Função para retirar um veiculo do parque 
void saida_p(void) {
    int i = 0;
    int z = 0;
    char tipo;
    float preco = 0, troco = 0;
    int tempoestacionamento = 0;
    int diastotais = 0;

    int horaentrada=0, minutoentrada=0;
    int minutostotais=0;

    int horasaida=0, minutosaida=0, minutostotaisS=0;
    int precolavagem = 0;

    int diaentrada=0;

    abreficheiros();
    //horas de saida


    int diasaida, messaida, anosaida;
    printf("***Hora de Saida***\n");
    time_t tempoexe;
    struct tm *info;
    char horasS[MAX], minutosS[MAX];
    char diasS[MAX], mesS[MAX], anoS[MAX];
    time(&tempoexe);
    info = localtime(&tempoexe);
    strftime(horasS, MAX, "%H", info);
    printf("Hora de saída : %s\n", horasS);
    strftime(minutosS, MAX, "%M", info);
    printf("Minutos de saída: %s\n", minutosS);
    horasaida = atoi(horasS);
    minutosaida = atoi(minutosS);

    // DIA MES ANO
    strftime(diasS, MAX, "%d", info);
    printf("Dia : %s\n", diasS);
    strftime(mesS, MAX, "%m", info);
    printf("Mes : %s\n", mesS);
    strftime(anoS, MAX, "%y", info);
    printf("Ano : %s\n", anoS);
    diasaida = atoi(diasS);
    messaida = atoi(mesS);
    anosaida = atoi(anoS);

    // escolha do lugar ocupado

    do {
        printf("Escolha o lugar ocupado: ");
        scanf("%d", &L);
    } while (vetorOD[L - 1] != 'O' || L > 100 || L < 1);

    //variaveis para calculo do preço
    horaentrada = vetorHoraE[L - 1];
    minutoentrada = vetorMinE[L - 1];
    diaentrada = vetorDIAE[L - 1];
    precolavagem = vetorlavagem[L - 1];
    // CALCULO DO PREÇO
    

    tipo = vetorTIPO[L - 1];
    minutostotaisS = (horasaida * 60) + minutosaida;
    minutostotais = (horaentrada * 60) + minutoentrada;

    

    switch (tipo) {
        case 'L':

            if (diaentrada != diasaida) {
                diastotais = diasaida - diaentrada;
                tempoestacionamento = ((diastotais * 1440) - minutostotais) + minutostotaisS;
                preco = tempoestacionamento * 0.05 + precolavagem;
            } else {
                if (minutostotais < minutostotaisS) {
                    tempoestacionamento = minutostotais - minutostotaisS;
                    preco = tempoestacionamento * 0.05;
                    preco = preco*-1 + precolavagem;
                } else {
                    tempoestacionamento = minutostotais - minutostotaisS;
                    preco = tempoestacionamento * 0.05 + precolavagem;
                }

            }





            break;

        case 'M':

            if (diaentrada != diasaida) {
                diastotais = diasaida - diaentrada;
                tempoestacionamento = ((diastotais * 1440) - minutostotais) + minutostotaisS;
                preco = tempoestacionamento * 0.02 + precolavagem;
            } else {
                if (minutostotais < minutostotaisS) {
                    tempoestacionamento = minutostotais - minutostotaisS;
                    preco = tempoestacionamento * 0.02;
                    preco = preco*-1 + precolavagem;
                } else {
                    tempoestacionamento = minutostotais - minutostotaisS;
                    preco = tempoestacionamento * 0.02 + precolavagem;
                }

            }


            break;

        case 'P':

            if (diaentrada != diasaida) {
                diastotais = diasaida - diaentrada;
                tempoestacionamento = ((diastotais * 1440) - minutostotais) + minutostotaisS;
                preco = tempoestacionamento * 0.08 + precolavagem;
            } else {
                if (minutostotais < minutostotaisS) {
                    tempoestacionamento = minutostotais - minutostotaisS;
                    preco = tempoestacionamento * 0.08;
                    preco = preco*-1 + precolavagem;
                } else {
                    tempoestacionamento = minutostotais - minutostotaisS;
                    preco = tempoestacionamento * 0.08 + precolavagem;
                }

            }

            break;

    }


    //pagamento
    printf("Tem de pagar:%.2f€\n", preco);
    float dinheiro = 0;


    do {
        printf("Introduza o dinheiro:\n");
        scanf("%f", &dinheiro);

        if (dinheiro > preco) {
            troco = dinheiro - preco;
            printf("\nRetire o troco\n");
            printf("Troco: %.2f€\n", troco);
        } else {
            troco = 0;
        }



    } while (dinheiro < preco);




    minutostotaisS = (horasaida * 60) + minutosaida;
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

    fechaficheiros();

    printf("Volte sempre!!!");
    exit(0);
}