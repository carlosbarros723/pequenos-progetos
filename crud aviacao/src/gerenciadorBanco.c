

char *errMsg = 0; // mensagem de erro



sqlite3 *criaBanco() { //cria um novo banco de dados, irei remover na versão final
    
    sqlite3 *db; //ponteiro para o banco de dados
    
    int iniciaBanco = sqlite3_open("dados", &db); 

    //tratativa de erros
    if (iniciaBanco != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return NULL;
    } else {
        fprintf(stderr, "Opened database successfully\n");
        return db;
    }
}


void novaTabela(sqlite3 *acessoBanco, const char *nomeTabela) {
    
    int resultado = sqlite3_exec(acessoBanco, nomeTabela, 0, 0, &errMsg);

if (resultado != SQLITE_OK) {
        fprintf(stderr, "Table creation error: %s\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(acessoBanco);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
}

// void gravarDados(sqlite3 *acessobanco, const char *novosDados) {
   
//     int resultado = sqlite3_exec(acessobanco, novosDados, 0, 0, &errMsg);
   
//     if (resultado != SQLITE_OK) {
//         fprintf(stderr, "Data insertion error: %s\n", errMsg);
//         sqlite3_free(errMsg);
//     } else {
//         fprintf(stdout, "Data inserted successfully\n");
//     }
// }

// função gravar dados
// no primeiro argumento recebe o acesso ao banco de dados;
// no segundo recebe a struct com os dados;
// no terceiro recebe o tamnho da struct;
// essa e uma unção generica para lidar com estruturas de 
// dados de tamhanhos diferentes, sem que seja necesario criar 
// uma função para cada dado que eu resolva armazenar.  

void gravarDados(sqlite3 *acessoBanco, void *dadosArray, size_t numDados) {
    const char *insertDataSQL = "INSERT INTO CLIENTES (ID, NAME, DATA, GENERO, TELEFONE) "
                                "VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt *stmt;


    // Determinar o tamanho da struct que será armazenada em cada elemento do array
    size_t tamanhoDados = sizeof(DadosCliente);

    for (size_t i = 0; i < numDados; i++) {
        // Calculando o endereço do elemento da struct dentro do array
        DadosCliente *dados = (DadosCliente *)((char *)dadosArray + i * tamanhoDados);

        // Criar a query usando o nome da tabela
        char queryBuffer[512];
        snprintf(queryBuffer, sizeof(queryBuffer), insertDataSQL, dados->tableName);

        int resultado = sqlite3_prepare_v2(acessoBanco, queryBuffer, -1, &stmt, NULL);

        if (resultado != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(acessoBanco));
            return;
        }

        // Bind dos valores aos placeholders
        sqlite3_bind_int(stmt, 1, dados->id);
        sqlite3_bind_text(stmt, 2, dados->name, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, dados->data, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, dados->genero, -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 5, dados->telefone);

        resultado = sqlite3_step(stmt);

        if (resultado != SQLITE_DONE) {
            fprintf(stderr, "Execution error: %s\n", sqlite3_errmsg(acessoBanco));
        }

        sqlite3_finalize(stmt);
    }
}

