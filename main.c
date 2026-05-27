# include <stdio.h>

int temperatura, energia_porcent, opcao, comunicacao_status;

int main(){
    do {
        menu:
        printf("\n===========================================\n");
        printf("SISTEMA DE MONITORAMENTO DE MISSAO ESPACIAL");
        printf("\n===========================================\n");
        printf("(1) Inserir dados\n");
        printf("(2) Visualizar status\n");
        printf("(3) Executar analise\n");
        printf("(0) Encerrar sistema\n");
        printf("===========================================\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1 || opcao < 0 || opcao > 4) { 
        printf("\nOpcao invalida!\n");
        while (getchar() != '\n');
        goto menu;
        }
                        
        switch(opcao){
            case 1:
                printf("\n=== INSERIR DADOS ===\n");
                printf("Digite a temperatura (%cC): ", 248);
                while (scanf("%d", &temperatura) != 1 || temperatura < -273 || temperatura > 10000) {
                    printf("Temperatura deve estar entre -273%cC e 10000%cC!\n", 248, 248);
                    while (getchar() != '\n');
                    printf("Digite a temperatura (%cC): ", 248);
                }
                while (getchar() != '\n');

                printf("Digite a porcentagem de energia (%%): ");
                while (scanf("%d", &energia_porcent) != 1 || energia_porcent < 0 || energia_porcent > 100) {
                    printf("Porcentagem de energia deve estar entre 0%% e 100%%!\n");
                    while (getchar() != '\n');
                    printf("Digite a porcentagem de energia (%%): ");
                }
                while (getchar() != '\n');
                
                printf("Digite o status da comunicacao (1 - Ativa, 0 - Inativa): ");
                while (scanf("%d", &comunicacao_status) != 1 || (comunicacao_status != 0 && comunicacao_status != 1)) {
                    printf("Status de comunicacao deve ser 1 (Ativa) ou 0 (Inativa)!\n");
                    while (getchar() != '\n');
                    printf("Digite o status da comunicacao (1 - Ativa, 0 - Inativa): ");
                }
                while (getchar() != '\n');
                
                break;  
            case 2:
                printf("\n=== STATUS DA MISSAO ESPACIAL ===\n");
                printf("Temperatura: %d%cC\n", temperatura, 248);
                printf("Energia: %d%%\n", energia_porcent);
                printf("Comunicacao: ");
                if (comunicacao_status == 1) {
                    printf("Ativa\n");
                } else {
                    printf("Inativa\n");
                }
                
                break;
            case 3:
                printf("\n=== EXECUTAR ANALISE ===\n");
                // Lógica para executar análise
                break;
            case 0:
                printf("Encerrando sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}