#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "menu.h"
#include "cadas.h"
#include "endp.h"
#include "exibirTabelaPrecos.h"

void consultarArmazem(MYSQL *conn) {
    MYSQL_RES *res;
    MYSQL_ROW row;

    if (mysql_query(conn, "SELECT nome, quantidade FROM produtos")) {
        fprintf(stderr, "Erro na consulta: %s\n", mysql_error(conn));
        return;
    }

    res = mysql_store_result(conn);
    if (res == NULL) {
        fprintf(stderr, "Erro ao obter resultado: %s\n", mysql_error(conn));
        return;
    }

    while ((row = mysql_fetch_row(res))) {
        printf("Produto: %s | Quantidade: %s\n", row[0], row[1]);
    }
    mysql_free_result(res);
}

void mainMenu(MYSQL *conn) {
    int valor;
    int resultado;

    printf("====================||====================\n");
    printf("======|BEM-VINDO A HORTIFRUTI DO ZÉ|======\n");
    printf("====================||====================\n");

    do {
        printf("Escolha a ação realizada no programa.\n");
        printf("1- Consultar o armazém.\n");
        printf("2- Cadastramento de produto.\n");
        printf("3- Tabela de preços.\n");
        printf("4- Sair do programa.\n");
        printf("Escolha uma das opções: ");
        
        resultado = scanf("%d", &valor);
        printf("\n\n");

        if (resultado != 1) {
            printf("Entrada inválida! Por favor, insira um número.\n");
            while (getchar() != '\n'); // Limpar entrada
            valor = 0; // Reset valor
        } else {
            switch(valor) {
                case 1:
                    consultarArmazem(conn);
                    break;
                case 2:
                    cadastrarProduto(conn);
                    break;
                case 3:
                    tab(conn); // Chamada para a função "tab"
                    break;
                case 4:
                    mainFinal();
                    break;
                default:
                    printf("Opção incorreta, tente novamente.\n");
            }
        }
    } while (valor != 4);
}
