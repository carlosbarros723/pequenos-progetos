#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/estruturas.h"
#include "../bibliotecaSqlite3/sqlite3.c"
#include "gerenciadorBanco.c"
#include "listaMenus.h"

static int callback(void *data, int argc, char **argv, char **azColName);

int main() {
    sqlite3 *db;
    char *errMsg = 0;
    
    sqlite3 *novoBanco = criaBanco();
  
    int id;
    char nomeCliente[50];
    int parar = 0;

    const char *createTableSQL = "CREATE TABLE IF NOT EXISTS CLIENTES("
                                 "ID INT PRIMARY KEY NOT NULL,"
                                 "NAME TEXT NOT NULL,"
                                 "DATA TEXT,"
                                 "GENERO TEXT,"
                                 "TELEFONE INT );";
    
    novaTabela(novoBanco, createTableSQL);

    printf("============================================\n");
    printf("BEM-VINDO AO SISTEMA DA EMPRESA AÉREA\n");
    printf("============================================\n\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║                                        ║\n");
    printf("║     Seja bem-vindo ao Sistema da       ║\n");
    printf("║       Empresa Aérea! Aqui você         ║\n");
    printf("║    poderá gerenciar voos, reservas,    ║\n");
    printf("║    passageiros e muito mais de forma   ║\n");
    printf("║          eficiente e organizada.       ║\n");
    printf("║                                        ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
    printf("============================================\n");

    while (1) {
        printf("ID do cliente: ");
        scanf("%d", &id);
        fflush(stdin);

        printf("Nome do cliente: ");
        fgets(nomeCliente, sizeof(nomeCliente), stdin);
        nomeCliente[strlen(nomeCliente) - 1] = '\0';

        DadosCliente clienteArray[] = {
            {"CLIENTES", id, nomeCliente, "31/02/1998", "Feminino", 99999999},
        };

        size_t numClientes = sizeof(clienteArray) / sizeof(DadosCliente);
        gravarDados(novoBanco, clienteArray, numClientes);

        printf("DESEJA PARAR (1 para sim, 0 para não): ");
        scanf("%d", &parar);

        if (parar != 0) {
            break;
        }
    }

    char buscarNome[50];
    printf("Digite o nome do cliente que deseja buscar: ");
    scanf("%s", buscarNome);

    char selectClienteSQL[100];
    snprintf(selectClienteSQL, sizeof(selectClienteSQL), "SELECT * FROM CLIENTES WHERE NAME = '%s';", buscarNome);

    int resultado = sqlite3_exec(novoBanco, selectClienteSQL, callback, 0, &errMsg);
    if (resultado != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    sqlite3_close(novoBanco);

    return 0;
}

static int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");


   
    return 0;
}
