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

void fechaficheiros(void) {
    int i = 0, j = 0;

    // MATRICULA LOGIN
    FILE *fout11;
    fout11 = fopen("matt.txt", "w");
    for (i = 0; i < N_login; i++) {
        for (j = 0; j < 6; j++) {
            fprintf(fout11, "%c", carro_registado[i].matt[j]);
        }
    }

    fclose(fout11);


    //n_utilizador

    FILE *fout2;
    fout2 = fopen("n_utilizador.txt", "w");


    for (i = 0; i < N_login; i++) {

        fprintf(fout2, "%d ", carro_registado[i].n_utilizador);

    }

    fclose(fout2);
    // passe loginnnn


    FILE *flout3;
    flout3 = fopen("passe.txt", "w");
    for (i = 0; i < N_login; i++) {

        fprintf(flout3, "%d ", carro_registado[i].passe);

    }
    fclose(flout3);

    //TIPO VEICULO LOGIN

    FILE *flout4;
    flout4 = fopen("tipo_veiculo.txt", "w");
    for (i = 0; i < N_login; i++) {

        fprintf(flout4, "%c ", carro_registado[i].tipo_veiculo);

    }
    fclose(flout4);



    //////////////////////////////////////////////////////////////////




    FILE *fout;
    fout = fopen("Matricula.txt", "w");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < 6; j++) {
            fprintf(fout, "%c", matrizMAT[i][j]);
        }
    }
    fclose(fout);

    FILE *flout;
    flout = fopen("Lugares.txt", "w");
    for (i = 0; i < MAX; i++) {

        fprintf(flout, "%d ", vetorLugares[i]);

    }
    fclose(flout);

    FILE *flivresout;
    flivresout = fopen("Livres.txt", "w");


    fprintf(flivresout, "%d", lugareslivres);


    fclose(flivresout);

    FILE *odout;
    odout = fopen("OD.txt", "w");
    for (i = 0; i < MAX; i++) {

        fprintf(odout, "%c,", vetorOD[i]);

    }
    fclose(odout);

    FILE *heout;
    heout = fopen("Horaentrada.txt", "w");
    for (i = 0; i < MAX; i++) {

        fprintf(heout, "%d ", vetorHoraE[i]);

    }
    fclose(heout);

    FILE *meout;
    meout = fopen("Minutosentrada.txt", "w");
    for (i = 0; i < MAX; i++) {

        fprintf(meout, "%d ", vetorMinE[i]);

    }
    fclose(meout);

    FILE *tout;
    tout = fopen("Tipo.txt", "w");
    for (i = 0; i < MAX; i++) {

        fprintf(tout, "%c,", vetorTIPO[i]);

    }
    fclose(tout);



    //Dia
    FILE *diaeout;
    diaeout = fopen("diaentrada.txt", "w");
    for (i = 0; i < MAX; i++) {

        fprintf(diaeout, "%d ", vetorDIAE[i]);

    }
    fclose(diaeout);

    //mes

    FILE *meseout;
    meseout = fopen("mesentrada.txt", "w");
    for (i = 0; i < MAX; i++) {

        fprintf(meseout, "%d ", vetorMESE[i]);

    }
    fclose(meseout);

    //ano
    FILE *anoeout;
    anoeout = fopen("anoentrada.txt", "w");
    for (i = 0; i < MAX; i++) {

        fprintf(anoeout, "%d ", vetorANOE[i]);

    }
    fclose(anoeout);
    //fecha lavagem preço
    FILE *plout;
    plout = fopen("precolavagem.txt", "w");
    for (i = 0; i < MAX; i++) {

        fprintf(plout, "%d ", vetorlavagem[i]);

    }
    fclose(plout);
    //fecha lavagem
    FILE *pout;
    pout = fopen("Lavagem.txt", "w");
    for (i = 0; i < MAX; i++) {

        fprintf(pout, "%d ", vetorlavagem_1[i]);

    }
    fclose(pout);
}//fecha ficheiros