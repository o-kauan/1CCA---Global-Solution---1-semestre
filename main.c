# include <stdio.h>

int energia_porcent, opcao, comunicacao_status, status_op [7] = {0, 0, 0, 0, 0, 0, 0};
float temperatura, geracao_solar_kW, capacidade_bateria_kWh = 1000.0, energia_disponivel_kWh, consumo_energia_kWh, saldo_energia_kWh;

// Evita entradas inválidas, como letras ou decimais
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
                
                // Validação do Status de Comunicação
                printf("Digite o status da comunicacao (1) - Ativa ou (0) - Inativa: ");
                while (filtrar_decimais_e_letras(&comunicacao_status) != 1 || (comunicacao_status != 0 && comunicacao_status != 1)) {
                    printf("========================================================\n");
                    printf("Status de comunicacao deve ser 1 (Ativa) ou 0 (Inativa)!");
                    printf("\n========================================================\n");
                    printf("Digite o status da comunicacao (1) - Ativa ou (0) - Inativa: ");
                }

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

                // Validação da porcentagem de Energia
                printf("Digite a porcentagem de energia (%%): ");
                while (filtrar_decimais_e_letras(&energia_porcent) != 1 || energia_porcent < 0 || energia_porcent > 100) {
                    printf("==================================================\n");
                    printf("Porcentagem de energia deve estar entre 0%% e 100%%!");
                    printf("\n==================================================\n");
                    printf("Digite a porcentagem de energia (%%): ");
                }
                
                // Validação do consumo de energia
                printf("Digite o consumo de energia (kWh): ");
                while (scanf("%f", &consumo_energia_kWh) != 1 || consumo_energia_kWh < 0 || consumo_energia_kWh > 10000) {
                    while (getchar() != '\n');
                    printf("======================================================\n");
                    printf("Consumo de energia deve estar entre 0 kWh e 10000 kWh!");
                    printf("\n======================================================\n");
                    printf("Digite o consumo de energia (kWh): ");
                }
                while (getchar() != '\n');

                // Validação da geração de energia solar
                printf("Digite a geracao de energia solar (kW): ");
                while (scanf("%f", &geracao_solar_kW) != 1 || geracao_solar_kW < 0 || geracao_solar_kW > 10000) {
                    while (getchar() != '\n');
                    printf("==========================================================\n");
                    printf("Geracao de energia solar deve estar entre 0 kW e 10000 kW!");
                    printf("\n==========================================================\n");
                    printf("Digite a geracao de energia solar (kW): ");
                }
                while (getchar() != '\n');         
                
                // Definição da energia disponível 
                energia_disponivel_kWh = capacidade_bateria_kWh * (energia_porcent / 100.0f);
                
                // Definição do saldo de energia
                saldo_energia_kWh = geracao_solar_kW - consumo_energia_kWh;

                printf("\nDados inseridos com sucesso!\n");

                break;  
            case 2:
                printf("\n=== STATUS DA MISSAO ===\n");
                
                printf("Comunicacao: ");
                if (comunicacao_status == 1) {
                    printf("Ativa\n");
                } else {
                    printf("Inativa\n");
                }
                printf("Temperatura: %.2f%cC\n", temperatura, 248);
                
                printf("Capacidade maxima da bateria: %.0f kWh\n", capacidade_bateria_kWh);
                
                printf("Energia disponivel: %d%%", energia_porcent);
                printf(" (%.2f kWh)\n", energia_disponivel_kWh);
                
                printf("Consumo de energia: %.2f kWh\n", consumo_energia_kWh);

                printf("Geracao de energia solar: %.2f kW\n", geracao_solar_kW);

                if (saldo_energia_kWh < 0) {
                    printf("Perdendo energia:");
                    printf(" (%.2f kWh)\n", saldo_energia_kWh);
                } else if (saldo_energia_kWh > 0) {
                    printf("Recarregando energia:");
                    printf(" (%.2f kWh)\n", saldo_energia_kWh);
                } else {
                    printf("Energia estavel");
                }
                

                break;
            case 3:
                printf("\n=== ANALISE DA SITUACAO ===\n");
                
                // Situação da Comunicação
                printf("Comunicacao: ");
                if (comunicacao_status == 1) {
                    printf("Ativa - OK\n");
                } else {
                    printf("Inativa - Falha de comunicacao!\n");
                    status_op[0] = 1;
                }
                // Situação da Temperatura
                printf("Temperatura: %.2f%cC", temperatura, 248);
                if (temperatura > 80) {
                    printf(" - Superaquecimento!\n");
                    status_op[1] = 1;
                } else if (temperatura < -20) {
                    printf(" - Resfriamento extremo!\n");
                    status_op[2] = 1;
                } else {
                    printf(" - OK\n");
                }

                // Situação da Energia
                printf("Energia: %d%%", energia_porcent);
                if (energia_porcent < 20) {
                    printf(" - Economia de energia\n");
                    status_op[3] = 1;
                } else {
                    printf(" - OK\n");
                }

                // Saldo Energético
                if (saldo_energia_kWh < 0) {
                    printf("Saldo de energia: %.2f kWh (Perda de energia)\n", saldo_energia_kWh);
                    status_op[4] = 1;
                } else if (saldo_energia_kWh > 0) {
                    printf("Saldo de energia: %.2f kWh (Recarregando energia)\n", saldo_energia_kWh);
                    status_op[5] = 1;
                } else {
                    printf("Saldo de energia: %.2f kWh (Energia estavel)\n", saldo_energia_kWh);
                    status_op[6] = 1;
                }

// status_op:
// [0] = comunicacao, [1] = superaquecimento, [2] = resfriamento extremo, [3] = baixa energia, 
// [4] = perda de energia, [5] = recarga de energia, [6] = energia estavel

                printf("= Status Geral da Missao: ");
                if (status_op[0] == 1 || status_op[1] == 1 || status_op[2] == 1 || status_op[3] == 1 || status_op[4] == 1 || status_op[5] == 1 || status_op[6] == 1) {
                    printf("CRITICO =\n");
                } else {
                    printf("NORMAL =\n");
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