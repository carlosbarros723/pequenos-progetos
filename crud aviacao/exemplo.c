// // Defina uma estrutura para armazenar informações sobre a tabela e os dados
// typedef struct {
//     const char *tableName;
//     int id;
//     const char *name;
//     int age;
//     const char *address;
//     double salary;
// } DadosInsercao;

// // Crie um array com informações de inserção para diferentes tabelas
// DadosInsercao dadosArray[] = {
//     {"COMPANY", 1, "John Doe", 25, "123 Main St", 50000.0},
//     {"OUTRA_TABELA", 2, "Alice", 30, "456 Elm St", 60000.0},
//     // Adicione mais entradas conforme necessário
// };

// const char *insertDataSQL = "INSERT INTO %s (ID, NAME, AGE, ADDRESS, SALARY) "
//                             "VALUES (?, ?, ?, ?, ?);";

// sqlite3_stmt *stmt;

// for (int i = 0; i < sizeof(dadosArray) / sizeof(DadosInsercao); i++) {
//     DadosInsercao dados = dadosArray[i];

//     char queryBuffer[512];
//     snprintf(queryBuffer, sizeof(queryBuffer), insertDataSQL, dados.tableName);

//     int resultado = sqlite3_prepare_v2(acessoBanco, queryBuffer, -1, &stmt, NULL);

//     if (resultado != SQLITE_OK) {
//         fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(acessoBanco));
//         return;
//     }

//     // Bind values to placeholders
//     sqlite3_bind_int(stmt, 1, dados.id);
//     sqlite3_bind_text(stmt, 2, dados.name, -1, SQLITE_STATIC);
//     sqlite3_bind_int(stmt, 3, dados.age);
//     sqlite3_bind_text(stmt, 4, dados.address, -1, SQLITE_STATIC);
//     sqlite3_bind_double(stmt, 5, dados.salary);

//     resultado = sqlite3_step(stmt);

//     if (resultado != SQLITE_DONE) {
//         fprintf(stderr, "Execution error: %s\n", sqlite3_errmsg(acessoBanco));
//     }

//     sqlite3_finalize(stmt);
// }
