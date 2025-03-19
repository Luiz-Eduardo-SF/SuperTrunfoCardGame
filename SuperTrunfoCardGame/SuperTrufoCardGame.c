#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta com dados sobre uma cidade
typedef struct {
    char estado[3];  // Armazena a sigla do estado (ex: SP, RJ, MG)
    char cidade[51]; // Nome da cidade
    char codigo[11]; // Código identificador da carta
    int populacao;   // População da cidade
    int pontostu;    // Número de pontos turísticos
    float area;      // Área da cidade em km²
    float PIB;       // Produto Interno Bruto da cidade
    float PIBperCap; // PIB per capita
    float pessoaKm;  // Densidade populacional (habitantes por km²)
    float superPoder; // Indicador fictício baseado nos outros atributos
} Carta;

// Função para limpar o buffer do teclado após entrada de dados
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função que exibe o menu de opções
int menuOP() {
    printf("\n\n\n================================================================================\n");
    printf("Selecione uma opção:\n");
    printf("1 - Cadastrar uma nova carta\n");
    printf("2 - Como Funciona\n");
    printf("3 - Sair\n");
    printf("================================================================================\n");

    printf("Opção: ");
    int opcao;
    scanf("%d", &opcao);
    limparBuffer(); // Limpa o buffer após o scanf

    printf("================================================================================\n\n");

    return opcao;
}

// Função que faz a coleta dos dados das cartas
void coletarDadosCarta(Carta *carta) { // Coloco a carta na função como um ponteiro para usar ->
    printf("================================================================================\n");

    printf("Digite o estado da carta (2 letras): ");
    fgets(carta->estado, sizeof(carta->estado), stdin);
    carta->estado[strcspn(carta->estado, "\n")] = '\0'; // Remove o '\n' do final
    limparBuffer();

    printf("================================================================================\n");

    printf("Digite a cidade da carta (até 50 letras): ");
    fgets(carta->cidade, sizeof(carta->cidade), stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = '\0'; // Remove o '\n' do final

    printf("================================================================================\n");

    printf("Digite o código da carta (11 letras): ");
    fgets(carta->codigo, sizeof(carta->codigo), stdin);
    carta->codigo[strcspn(carta->codigo, "\n")] = '\0'; // Remove o '\n' do final

    printf("================================================================================\n");

    printf("Digite a população da carta: ");
    scanf("%d", &carta->populacao);
    limparBuffer(); // Limpa o buffer após o scanf

    printf("================================================================================\n");

    printf("Digite o número de pontos turísticos da carta: ");
    scanf("%d", &carta->pontostu);
    limparBuffer(); // Limpa o buffer após o scanf

    printf("================================================================================\n");

    printf("Digite a área da carta: ");
    scanf("%f", &carta->area);
    limparBuffer(); // Limpa o buffer após o scanf

    printf("================================================================================\n");

    printf("Digite o PIB da carta: ");
    scanf("%f", &carta->PIB);
    limparBuffer(); // Limpa o buffer após o scanf

    printf("================================================================================\n");
}

// Função que calcula os indicadores
void calcularIndicadores(Carta *carta) {
    carta->PIBperCap = carta->PIB / carta->populacao; // Calcula o PIB per Capita
    carta->pessoaKm = carta->populacao / carta->area; // Calcula a densidade populacional
    carta->superPoder = carta->PIB + carta->PIBperCap + carta->pessoaKm + carta->populacao + carta->pontostu; // Calcula o Super Poder
}

// Função que compara as cartas e exibe os resultados
void compararCartas(Carta carta1, Carta carta2) {
    
    // Exibe os resultados
    printf("\nResultados:");
    printf("\n================================================================================");
    printf("\nEstado: %s (carta 1) vs %s (carta 2)", carta1.estado, carta2.estado);
    printf("\n================================================================================");
    printf("\nCidade: %s (carta 1) vs %s (carta 2)", carta1.cidade, carta2.cidade);
    printf("\n================================================================================");
    printf("\nCódigo: %s (carta 1) vs %s (carta 2)", carta1.codigo, carta2.codigo);
    printf("\n================================================================================");

    // Comparações dos atributos

    // População

    if (carta1.populacao > carta2.populacao) {
        printf("\nPopulação: %d (carta 1) vs %d (carta 2) || Carta 1 Venceu", carta1.populacao, carta2.populacao);
    } else if (carta1.populacao < carta2.populacao) {
        printf("\nPopulação: %d (carta 1) vs %d (carta 2) || Carta 2 Venceu", carta1.populacao, carta2.populacao);
    } else {
        printf("\nPopulação: %d (carta 1) vs %d (carta 2) || Empate!!!", carta1.populacao, carta2.populacao);
    }

    printf("\n================================================================================");

    // Pontos turísticos

    if (carta1.pontostu > carta2.pontostu) {
        printf("\nPontos turísticos: %d (carta 1) vs %d (carta 2) || Carta 1 Venceu", carta1.pontostu, carta2.pontostu);
    } else if (carta1.pontostu < carta2.pontostu) {
        printf("\nPontos turísticos: %d (carta 1) vs %d (carta 2) || Carta 2 Venceu", carta1.pontostu, carta2.pontostu);
    } else {
        printf("\nPontos turísticos: %d (carta 1) vs %d (carta 2) || Empate!!!", carta1.pontostu, carta2.pontostu);
    }

    printf("\n================================================================================");

    // Area

    if (carta1.area > carta2.area) {
        printf("\nÁrea: %.2f (carta 1) vs %.2f (carta 2) || Carta 1 Venceu", carta1.area, carta2.area);
    } else if (carta1.area < carta2.area) {
        printf("\nÁrea: %.2f (carta 1) vs %.2f (carta 2) || Carta 2 Venceu", carta1.area, carta2.area);
    } else {
        printf("\nÁrea: %.2f (carta 1) vs %.2f (carta 2) || Empate!!!", carta1.area, carta2.area);
    }

    printf("\n================================================================================");

    // PIB

    if (carta1.PIB > carta2.PIB) {
        printf("\nPIB: %.2f (carta 1) vs %.2f (carta 2) || Carta 1 Venceu", carta1.PIB, carta2.PIB);
    } else if (carta1.PIB < carta2.PIB) {
        printf("\nPIB: %.2f (carta 1) vs %.2f (carta 2) || Carta 2 Venceu", carta1.PIB, carta2.PIB);
    } else {
        printf("\nPIB: %.2f (carta 1) vs %.2f (carta 2) || Empate!!!", carta1.PIB, carta2.PIB);
    }

    printf("\n================================================================================");

    // PIB per Capita

    if (carta1.PIBperCap > carta2.PIBperCap) {
        printf("\nPIB per capita: %.2f (carta 1) vs %.2f (carta 2) || Carta 1 Venceu", carta1.PIBperCap, carta2.PIBperCap);
    } else if (carta1.PIBperCap < carta2.PIBperCap) {
        printf("\nPIB per capita: %.2f (carta 1) vs %.2f (carta 2) || Carta 2 Venceu", carta1.PIBperCap, carta2.PIBperCap);
    } else {
        printf("\nPIB per capita: %.2f (carta 1) vs %.2f (carta 2) || Empate!!!", carta1.PIBperCap, carta2.PIBperCap);
    }

    printf("\n================================================================================");

    // Pessoa por km

    if (carta1.pessoaKm < carta2.pessoaKm) {
        printf("\nPessoa por km²: %.2f (carta 1) vs %.2f (carta 2) || Carta 1 Venceu", carta1.pessoaKm, carta2.pessoaKm);
    } else if (carta1.pessoaKm > carta2.pessoaKm) {
        printf("\nPessoa por km²: %.2f (carta 1) vs %.2f (carta 2) || Carta 2 Venceu", carta1.pessoaKm, carta2.pessoaKm);
    } else {
        printf("\nPessoa por km²: %.2f (carta 1) vs %.2f (carta 2) || Empate!!!", carta1.pessoaKm, carta2.pessoaKm);
    }

    printf("\n================================================================================");

    // "Super Poder"

    if (carta1.superPoder > carta2.superPoder) {
        printf("\nSuper Poder: %.2f (carta 1) vs %.2f (carta 2) || Carta 1 Venceu", carta1.superPoder, carta2.superPoder);
    } else if (carta1.superPoder < carta2.superPoder) {
        printf("\nSuper Poder: %.2f (carta 1) vs %.2f (carta 2) || Carta 2 Venceu", carta1.superPoder, carta2.superPoder);
    } else {
        printf("\nSuper Poder: %.2f (carta 1) vs %.2f (carta 2) || Empate!!!", carta1.superPoder, carta2.superPoder);
    }

    printf("\n================================================================================");
}

// Função que gerencia o jogo
void jogo() {
    Carta carta1, carta2;

    // Coleta os dados da primeira carta
    printf("================================================================================\n");
    printf("Digite os dados da carta 1\n");
    coletarDadosCarta(&carta1);
    calcularIndicadores(&carta1);

    // Coleta os dados da segunda carta
    printf("================================================================================\n");
    printf("\nDigite os dados da carta 2\n");
    coletarDadosCarta(&carta2);
    calcularIndicadores(&carta2);

    // Compara as duas cartas
    compararCartas(carta1, carta2);
}

// Função principal
int main() {
    int opcao = menuOP();
    switch (opcao) {
        case 1:
            printf("Iniciando o jogo....\n");
            jogo();
            break;
        case 2:
            printf("Como Funciona\n");
            printf("========================================================================================================\n");
            printf(">>>> Quando o jogo começar o sistema vai pedir sobre informações para armazenar em duas cartas por vez\n");
            printf(">>>> Depois de receber os dados, todos os mesmo vão ser comparados entre as duas cartas\n");
            printf(">>>> A Carta que for superior a outra em valores vence!! e caso seja a mesma, resulta em um empate.\n");
            printf("=========================================================================================================\n\n");
            main();
            break;
        case 3:
            printf("Saindo....\n");
            return 0;
        default:
            printf("Opção inválida || Escolha novamente\n\n");
            main();
            break;
    }
    return 0;
}