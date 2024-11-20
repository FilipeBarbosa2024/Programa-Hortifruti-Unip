#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "menu.h"  // Inclui o cabeçalho do menu

int main() {
    MYSQL *conn;

    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, "localhost", "root", "3749_-+lmGK", "hortifruti", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    mainMenu(conn); // Chama o menu principal

    mysql_close(conn);
    return EXIT_SUCCESS;
}
