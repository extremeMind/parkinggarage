/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Variaveis.h
 * Author: Utilizador
 *
 * Created on 5 de Janeiro de 2018, 18:24
 */

#ifndef VARIAVEIS_H
#define VARIAVEIS_H

#ifdef __cplusplus
extern "C" {
#endif
#define MAX 100//Capacidade maxima do parque

 

#ifdef WIN32 //system("clear");//macro
#define clear() system("cls")
#else
#define clear() system("clear")
#endif

//variaveis globais
int vetorDIAE[MAX];
int vetorMESE[MAX];
int vetorANOE[MAX];
int vetorLugares[MAX];
char vetorOD[MAX];
int vetorHoraE[MAX];
int vetorMinE[MAX];
char vetorTIPO[MAX];
char matrizMAT[MAX][6];
int vetorlavagem[MAX];
char vetorlavagem_1[MAX];

int lugareslivres;
int ocupado;

char matricula[6];
int L;

//horas e dias (entrada e saida)
char horas[MAX], minutos[MAX];
char dias[MAX], mes[MAX], ano[MAX];




#ifdef __cplusplus
}
#endif

#endif /* VARIAVEIS_H */

