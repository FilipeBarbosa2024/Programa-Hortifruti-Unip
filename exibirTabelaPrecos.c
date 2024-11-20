#include <stdio.h>
#include <mysql/mysql.h>
#include "exibirTabelaPrecos.h"

// Função para exibir a tabela de preços
void tab(MYSQL *conn) {
    MYSQL_RES *res;
    MYSQL_ROW row;

    if (mysql_query(conn, "SELECT nome, preco FROM produtos")) {
        fprintf(stderr, "Erro na consulta: %s\n", mysql_error(conn));
        return;
    }

    res = mysql_store_result(conn);
    if (res == NULL) {
        fprintf(stderr, "Erro ao obter resultado: %s\n", mysql_error(conn));
        return;
    }

    printf("Tabela de Preços:\n");
    printf("Produto\t\tPreço\n");
    printf("-----------------------\n");

    while ((row = mysql_fetch_row(res))) {
        printf("%s\t\t%s\n", row[0], row[1]); // Exibindo nome e preço
    }

    mysql_free_result(res);
}
