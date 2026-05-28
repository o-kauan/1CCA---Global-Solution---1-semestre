# include <stdio.h>

int energia_porcent, opcao, comunicacao_status, status_op;
float temperatura;

int filtrar_decimais_e_letras(int*resposta){
    if (scanf("%d", resposta) != 1) {
        while (getchar() != '\n'); 
        return 0; 
    }
    if (getchar() != '\n') {
        while (getchar() != '\n');
        return 0; 
    }
    return 1; 
}

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
        if (filtrar_decimais_e_letras(&opcao) != 1 || opcao < 0 || opcao > 3) { 
        printf("\nOpcao invalida!\n");
        goto menu;
        }
                                
        switch(opcao){
            case 1:
                printf("\n=== INSERIR DADOS ===\n");
                
                // Validação da Temperatura
                printf("Digite a temperatura (%cC): ", 248);
                while (scanf("%f", &temperatura) != 1 || temperatura < -273 || temperatura > 10000) {
                    while (getchar() != '\n');
                    printf("==============================================\n");
                    printf("Temperatura deve estar entre -273%cC e 10000%cC!", 248, 248);
                    printf("\n==============================================\n");
                    printf("Digite a temperatura (%cC): ", 248);
                }
                while (getchar() != '\n');

                // Validação da Energia
                printf("Digite a porcentagem de energia (%%): ");
                while (filtrar_decimais_e_letras(&energia_porcent) != 1 || energia_porcent < 0 || energia_porcent > 100) {
                    printf("==================================================\n");
                    printf("Porcentagem de energia deve estar entre 0%% e 100%%!");
                    printf("\n==================================================\n");
                    printf("Digite a porcentagem de energia (%%): ");
                }
                
                // Validação do Status de Comunicação
                printf("Digite o status da comunicacao (1) - Ativa ou (0) - Inativa: ");
                while (filtrar_decimais_e_letras(&comunicacao_status) != 1 || (comunicacao_status != 0 && comunicacao_status != 1)) {
                    printf("========================================================\n");
                    printf("Status de comunicacao deve ser 1 (Ativa) ou 0 (Inativa)!");
                    printf("\n========================================================\n");
                    printf("Digite o status da comunicacao (1) - Ativa ou (0) - Inativa: ");
                }
                break;  
            case 2:
                printf("\n=== STATUS DA MISSAO ===\n");
                
                printf("Temperatura: %.2f%cC\n", temperatura, 248);
                
                printf("Energia: %d%%\n", energia_porcent);
                
                printf("Comunicacao: ");
                if (comunicacao_status == 1) {
                    printf("Ativa\n");
                } else {
                    printf("Inativa\n");
                }
                
                break;
            case 3:
                printf("\n=== ANALISE DA SITUACAO ===\n");
                status_op = 1;
                // Situação da Temperatura
                printf("Temperatura: %.2f%cC", temperatura, 248);
                if (temperatura > 80) {
                    printf(" - Superaquecimento!\n");
                    status_op = 0;
                } else if (temperatura < -20) {
                    printf(" - Resfriamento extremo!\n");
                    status_op = 0;
                } else {
                    printf(" - OK\n");
                }

                // Situação da Energia
                printf("Energia: %d%%", energia_porcent);
                if (energia_porcent < 20) {
                    printf(" - Economia de energia\n");
                    status_op = 0;
                } else {
                    printf(" - OK\n");
                }

                // Situação da Comunicação
                printf("Comunicacao: ");
                if (comunicacao_status == 1) {
                    printf("Ativa - OK\n");
                } else {
                    printf("Inativa - Falha de comunicacao!\n");
                    status_op = 0;
                }
                printf("= Status Geral da Missao: ");
                if (status_op == 1) {
                    printf("NORMAL =\n");
                } else {
                    printf("CRITICO =\n");
                }
                break;

            case 0:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}