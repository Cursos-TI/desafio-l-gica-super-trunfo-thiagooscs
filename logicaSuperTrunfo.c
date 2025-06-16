#include <stdio.h> // 
#include <string.h> // 


typedef struct {
    char estado[3]; // Sigla do estado (ex: "SP", "RJ")
    char codigoCarta[10]; // Código único da carta (ex: "SP-001")
    char nomeCidade[50]; // Nome da cidade
    int populacao; // População da cidade
    float area; // Área da cidade em km²
    float pib; // Produto Interno Bruto da cidade em bilhões de Reais
    int pontosTuristicos; // Número de pontos turísticos
    float densidadePopulacional; // Densidade populacional (calculada)
    float pibPerCapita; // PIB per capita (calculado)
} Carta;

// Função para calcular a densidade populacional e o PIB per capita de uma carta.
// Recebe um ponteiro para a estrutura Carta para modificar seus valores diretamente.
void calcularAtributosCalculados(Carta *carta) {
    // Calcula a densidade populacional: População / Área
    // Verifica se a área é maior que zero para evitar divisão por zero.
    if (carta->area > 0) {
        carta->densidadePopulacional = (float)carta->populacao / carta->area;
    } else {
        carta->densidadePopulacional = 0.0; // Se a área for zero, a densidade é zero.
    }

    // Calcula o PIB per capita: PIB / População
    // Verifica se a população é maior que zero para evitar divisão por zero.
    if (carta->populacao > 0) {
        carta->pibPerCapita = carta->pib / (float)carta->populacao;
    } else {
        carta->pibPerCapita = 0.0; // Se a população for zero, o PIB per capita é zero.
    }
}

int main() {
    // --- Definição das duas cartas a serem comparadas ---
    // Os dados das cartas são pré-definidos no código, conforme o requisito do nível novato.

    // Carta 1: São Paulo (SP)
    Carta carta1;
    strcpy(carta1.estado, "SP"); // Copia "SP" para o campo estado
    strcpy(carta1.codigoCarta, "SP-001"); // Copia o código da carta
    strcpy(carta1.nomeCidade, "Sao Paulo"); // Copia o nome da cidade
    carta1.populacao = 12300000; // Define a população
    carta1.area = 1521.1; // Define a área em km²
    carta1.pib = 747.6; // Define o PIB em bilhões de Reais
    carta1.pontosTuristicos = 50; // Define o número de pontos turísticos
    calcularAtributosCalculados(&carta1); // Chama a função para calcular densidade e PIB per capita

    // Carta 2: Rio de Janeiro (RJ)
    Carta carta2;
    strcpy(carta2.estado, "RJ"); // Copia "RJ" para o campo estado
    strcpy(carta2.codigoCarta, "RJ-001"); // Copia o código da carta
    strcpy(carta2.nomeCidade, "Rio de Janeiro"); // Copia o nome da cidade
    carta2.populacao = 6780000; // Define a população
    carta2.area = 1200.0; // Define a área em km²
    carta2.pib = 370.0; // Define o PIB em bilhões de Reais
    carta2.pontosTuristicos = 45; // Define o número de pontos turísticos
    calcularAtributosCalculados(&carta2); // Chama a função para calcular densidade e PIB per capita

    // --- Escolha do atributo para comparação ---
    // Este valor pode ser alterado para comparar outros atributos.
    // 1: População (maior valor vence)
    // 2: Área (maior valor vence)
    // 3: PIB (maior valor vence)
    // 4: Densidade Populacional (menor valor vence)
    // 5: PIB per capita (maior valor vence)
    int atributoEscolhido = 1; // Atributo inicial para comparação: População

    printf("=======================================\n");
    printf("     Comparacao de Cartas Super Trunfo\n");
    printf("=======================================\n\n");

    // --- Exibição dos dados completos de cada carta ---
    printf("--- Carta 1: %s (%s) ---\n", carta1.nomeCidade, carta1.estado);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %.2f km2\n", carta1.area);
    printf("PIB: R$ %.2f bilhoes\n", carta1.pib);
    printf("Pontos Turisticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta1.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n\n", carta1.pibPerCapita);

    printf("--- Carta 2: %s (%s) ---\n", carta2.nomeCidade, carta2.estado);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %.2f km2\n", carta2.area);
    printf("PIB: R$ %.2f bilhoes\n", carta2.pib);
    printf("Pontos Turisticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta2.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n\n", carta2.pibPerCapita);

    printf("--- Resultado da Comparacao ---\n");

    // --- Lógica de comparação utilizando switch-case e if-else ---
    // O switch-case é usado para selecionar o atributo de comparação,
    // e os if-else são usados para determinar o vencedor com base nas regras.
    switch (atributoEscolhido) {
        case 1: // Comparação por População (maior valor vence)
            printf("Comparacao de cartas (Atributo: Populacao):\n");
            printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
            printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 2: // Comparação por Área (maior valor vence)
            printf("Comparacao de cartas (Atributo: Area):\n");
            printf("Carta 1 - %s (%s): %.2f km2\n", carta1.nomeCidade, carta1.estado, carta1.area);
            printf("Carta 2 - %s (%s): %.2f km2\n", carta2.nomeCidade, carta2.estado, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 3: // Comparação por PIB (maior valor vence)
            printf("Comparacao de cartas (Atributo: PIB):\n");
            printf("Carta 1 - %s (%s): R$ %.2f bilhoes\n", carta1.nomeCidade, carta1.estado, carta1.pib);
            printf("Carta 2 - %s (%s): R$ %.2f bilhoes\n", carta2.nomeCidade, carta2.estado, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 4: // Comparação por Densidade Populacional (menor valor vence)
            printf("Comparacao de cartas (Atributo: Densidade Populacional):\n");
            printf("Carta 1 - %s (%s): %.2f hab/km2\n", carta1.nomeCidade, carta1.estado, carta1.densidadePopulacional);
            printf("Carta 2 - %s (%s): %.2f hab/km2\n", carta2.nomeCidade, carta2.estado, carta2.densidadePopulacional);
            // Para densidade populacional, a carta com o MENOR valor vence
            if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 5: // Comparação por PIB per capita (maior valor vence)
            printf("Comparacao de cartas (Atributo: PIB per capita):\n");
            printf("Carta 1 - %s (%s): R$ %.2f\n", carta1.nomeCidade, carta1.estado, carta1.pibPerCapita);
            printf("Carta 2 - %s (%s): R$ %.2f\n", carta2.nomeCidade, carta2.estado, carta2.pibPerCapita);
            if (carta1.pibPerCapita > carta2.pibPerCapita) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        default: // Caso um atributo inválido seja escolhido
            printf("Atributo escolhido invalido. Por favor, escolha um numero entre 1 e 5.\n");
            break;
    }

    return 0; // Indica que o programa foi executado com sucesso
}
