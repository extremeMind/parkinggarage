/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funções_g.h
 * Author: Utilizador
 *
 * Created on 5 de Janeiro de 2018, 19:52
 */

#ifndef FUNCOES_G_H
#define FUNCOES_G_H

#ifdef __cplusplus
extern "C" {
#endif
void teclacontinuar(void);
int compara(char matrizMAT[][6], char matricula[]);
void imprimetabela_user(void);
void pede_mat(void);
void verifica_existe(void);
char tipo_veic();
void criar_veiculo(void);
void inserir_veiculos(void);
int lavagem();
void sistemalavagem(void);
void saida_p(void);




#ifdef __cplusplus
}
#endif

#endif /* FUNCOES_G_H */

