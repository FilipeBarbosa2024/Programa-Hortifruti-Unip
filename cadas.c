#include <stdio.h>
#include <stdlib.h>
#include "cadas.h"

// Função para cadastrar um produto
void cadastrarProduto(MYSQL *conn) {
    char nome[100];
    int quantidade;

    printf("Digite o nome do produto: ");
    scanf("%s", nome);
    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);

    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO produtos (nome, quantidade) VALUES ('%s', %d)", nome, quantidade);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Erro ao cadastrar produto: %s\n", mysql_error(conn));
    } else {
        printf("Produto cadastrado com sucesso!\n");
    }
}
