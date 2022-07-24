/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Login.h
 * Author: Utilizador
 *
 * Created on 5 de Janeiro de 2018, 18:28
 */

#ifndef LOGIN_H
#define LOGIN_H

#ifdef __cplusplus
extern "C" {
#endif

#define N_login 50 //numero de logins
    
typedef struct login {
    int n_utilizador;
    int passe;
    char tipo_veiculo;
    char matt[6];

} LOGIN;

LOGIN carro_registado[N_login];
    

void menu_login(void);
int inserir_n_utilizador();
int verifica_n_utilizador(LOGIN carro_logado[], int n_utili, int *p);
int verifica_existelogin(int n_utili, int *p);
void criar_login_novo(void);
void criar_vei_Login(void);
void inserir_vei_Login(int u);
void mostrar_login(LOGIN carro_logado[]);
void limpar_login(void);




#ifdef __cplusplus
}
#endif

#endif /* LOGIN_H */

