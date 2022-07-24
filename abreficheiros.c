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


void abreficheiros(void) {
    int i = 0, j = 0;

    //Matt login
    FILE *mp2;
    mp2 = fopen("matt.txt", "r");

    if (mp2 == NULL) {
        printf("Erro a abrir ficheiro matt login\n");
        exit(0);
    }

    for (i = 0; i < N_login; i++) {
        for (j = 0; j < 6; j++) {
            fscanf(mp2, "%c", &carro_registado[i].matt[j]);
        }
    }

    fclose(mp2);


    // n_utilizador

    FILE *mp3;
    mp3 = fopen("n_utilizador.txt", "r");

    if (mp3 == NULL) {
        printf("Erro a abrir ficheiro n_utilizador\n");
        exit(0);
    }

    for (i = 0; i < N_login; i++) {

        fscanf(mp3, "%d ", &carro_registado[i].n_utilizador);

    }

    fclose(mp3);

    //passe


    FILE *mp4;
    mp4 = fopen("passe.txt", "r");

    if (mp4 == NULL) {
        printf("Erro a abrir ficheiro passe\n");
        exit(0);
    }

    for (i = 0; i < N_login; i++) {

        fscanf(mp4, "%d ", &carro_registado[i].passe);

    }

    fclose(mp4);

    // TIPO VEICULO LOGIN


    FILE *mp5;
    mp5 = fopen("tipo_veiculo.txt", "r");

    if (mp5 == NULL) {
        printf("Erro a abrir ficheiro login tipo\n");
        exit(0);
    }

    for (i = 0; i < N_login; i++) {

        fscanf(mp5, "%c ", &carro_registado[i].tipo_veiculo);

    }

    fclose(mp5);

    //////////////////////////////////////////////////////



    FILE *lo;
    lo = fopen("Livres.txt", "r+");


    if (lo == NULL) {
        printf("Erro a abrir ficheiro lugares totais\n");
        exit(0);
    }


    fscanf(lo, "%d,", &lugareslivres);



    fclose(lo);

    //Lugares
    FILE *myFile;
    myFile = fopen("Lugares.txt", "r");

    if (myFile == NULL) {
        printf("Erro a abrir ficheiro Lugares\n");
        exit(0);
    }

    for (i = 0; i < MAX; i++) {
        fscanf(myFile, "%d,", &vetorLugares[i]);
    }


    fclose(myFile);

    //Ocupado/Disponível
    FILE *fp;
    fp = fopen("OD.txt", "r");





    if (fp == NULL) {
        printf("Erro a abrir ficheiro Ocupados/Disponiveis\n");
        exit(0);
    }

    for (i = 0; i < MAX; i++) {
        fscanf(fp, "%c,", &vetorOD[i]);
    }
    fclose(fp);

    //Hora de entrada 
    FILE *f;
    f = fopen("Horaentrada.txt", "r");





    if (f == NULL) {
        printf("Erro a abrir ficheiro hora de entrada\n");
        exit(0);
    }

    for (i = 0; i < MAX; i++) {
        fscanf(f, "%d", &vetorHoraE[i]);
    }
    fclose(f);

    //Minutos de entrada 
    FILE *me;
    me = fopen("Minutosentrada.txt", "r");





    if (me == NULL) {
        printf("Erro a abrir ficheiro minutos de entrada\n");
        exit(0);
    }

    for (i = 0; i < MAX; i++) {
        fscanf(me, "%d", &vetorMinE[i]);
    }
    fclose(me);

    //Tipo
    FILE *cp;
    cp = fopen("Tipo.txt", "r");





    if (cp == NULL) {
        printf("Erro a abrir ficheiro tipo de carro\n");
        exit(0);
    }

    for (i = 0; i < MAX; i++) {
        fscanf(cp, "%c,", &vetorTIPO[i]);
    }
    fclose(cp);

    //Matricula
    FILE *mp;
    mp = fopen("Matricula.txt", "r");





    if (mp == NULL) {
        printf("Erro a abrir ficheiro matricula\n");
        exit(0);
    }



    for (i = 0; i < MAX; i++) {
        for (j = 0; j < 6; j++) {
            fscanf(mp, "%c", &matrizMAT[i][j]);

        }

    }


    fclose(mp);

    //Dia de entrada 
    FILE *diae;
    diae = fopen("diaentrada.txt", "r");

    if (diae == NULL) {
        printf("Erro a abrir ficheiro dia de entrada\n");
        exit(0);
    }

    for (i = 0; i < MAX; i++) {
        fscanf(diae, "%d", &vetorDIAE[i]);
    }
    fclose(diae);


    //Mes de entrada 
    FILE *mese;
    mese = fopen("mesentrada.txt", "r");





    if (mese == NULL) {
        printf("Erro a abrir ficheiro mes de entrada\n");
        exit(0);
    }

    for (i = 0; i < MAX; i++) {
        fscanf(mese, "%d", &vetorMESE[i]);
    }
    fclose(mese);

    //Ano de entrada 
    FILE *anoe;
    anoe = fopen("anoentrada.txt", "r");

    if (anoe == NULL) {
        printf("Erro a abrir ficheiro ano de entrada\n");
        exit(0);
    }

    for (i = 0; i < MAX; i++) {
        fscanf(anoe, "%d", &vetorANOE[i]);
    }
    fclose(anoe);

    //preço lavagem
    FILE *pl;
    pl = fopen("precolavagem.txt", "r");
    if (pl == NULL) {
        printf("Erro a abrir ficheiro Preços de lavagem\n");
        exit(0);
    }
    for (i = 0; i < MAX; i++) {
        fscanf(pl, "%d,", &vetorlavagem[i]);
    }
    fclose(pl);
    //lavagem
    FILE *p;
    p = fopen("Lavagem.txt", "r");
    if (p == NULL) {
        printf("Erro a abrir ficheiro avagem\n");
        exit(0);
    }
    for (i = 0; i < MAX; i++) {
        fscanf(p, "%d,", &vetorlavagem_1[i]);
    }
    fclose(p);
}// abre os ficheiros
