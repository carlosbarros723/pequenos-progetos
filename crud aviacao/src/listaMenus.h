#include <stdio.h>

int menuInicial(){



    int opcao = 0;

    printf("==============\n");
    printf("MENU PRINCIPAL\n");
    printf("==============\n");    
    printf("1. Gerenciamento de Voos\n");
    printf("2. Reservas\n");
    printf("3. Passageiros\n");
    printf("4. Sair\n");
    printf("==============\n");

    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

   
        switch (opcao) {
            case 1:
                printf("Opção escolhida: Gerenciamento de Voos\n");
                MenuGerenciamentoVoos();
                break;
            case 2:
                printf("Opção escolhida: Reservas\n");
                menuReservas();
                break;
            case 3:
                printf("Opção escolhida: Passageiros\n");
                menuPassageiros();
                break;
            case 4:
                printf("Encerrando o programa.\n");
                
                break;
            default:
                printf("Opção inválida. Escolha uma opção válida.\n");
                break;
        }
    


}


int MenuGerenciamentoVoos(){

    int opcao = 0;

    
        printf("========================\n");
        printf("GERENCIAMENTO DE VOOS\n");
        printf("========================\n");
        printf("1. Visualizar Voos\n");
        printf("2. Adicionar Novo Voo\n");
        printf("3. Atualizar Voo Existente\n");
        printf("4. Excluir Voo\n");
        printf("5. Voltar ao Menu Principal\n");
        printf("========================\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
            
                break;
            case 5:
                printf("Voltando ao Menu Principal.\n");
                break;

            default:
                printf("Opção inválida. Escolha uma opção válida.\n");
                break;
        }

}


int menuReservas() {
    int opcao = 0;

    
        printf("===================\n");
        printf("MENU DE RESERVAS\n");
        printf("===================\n");
        printf("1. Ver Reservas\n");
        printf("2. Criar Nova Reserva\n");
        printf("3. Atualizar Reserva\n");
        printf("4. Cancelar Reserva\n");
        printf("5. Voltar ao Menu Principal\n");
        printf("===================\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                printf("Voltando ao Menu Principal.\n");
                break;
            default:
                printf("Opção inválida. Escolha uma opção válida.\n");
                break;
        }
    

    
}


int menuPassageiros() {
    int opcao = 0;

    
        printf("=====================\n");
        printf("MENU DE PASSAGEIROS\n");
        printf("=====================\n");
        printf("1. Ver Passageiros\n");
        printf("2. Adicionar Novo Passageiro\n");
        printf("3. Editar Passageiro\n");
        printf("4. Remover Passageiro\n");
        printf("5. Voltar ao Menu Principal\n");
        printf("=====================\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                printf("Voltando ao Menu Principal.\n");
                break;
            default:
                printf("Opção inválida. Escolha uma opção válida.\n");
                break;
        }
    

    return 0;
}

