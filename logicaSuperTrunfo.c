#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[3];            // UF do estado (ex: "SP")
    char codigo_carta[10];     // Código único da carta (ex: "SP001")
    char nome_cidade[50];      // Nome da cidade (ex: "São Paulo")
    int populacao;             // População da cidade
    float area;                // Área da cidade em km²
    float pib;                 // PIB da cidade em bilhões de reais
    int pontos_turisticos;     // Número de pontos turísticos
    float densidade_populacional; // Calculado: População / Área
    float pib_per_capita;      // Calculado: PIB / População
} CartaSuperTrunfo;

// Função para exibir os dados de uma carta
void exibirCarta(CartaSuperTrunfo carta) {
    printf("\n--- Dados da Carta: %s (%s) ---\n", carta.nome_cidade, carta.estado);
    printf("Código da Carta: %s\n", carta.codigo_carta);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per Capita: R$ %.2f\n", carta.pib_per_capita);
}

int main() {
    // Declaração de duas cartas pré-definidas
    CartaSuperTrunfo carta1;
    CartaSuperTrunfo carta2;

    // --- Cadastro da Carta 1 (São Paulo) ---
    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo_carta, "SP001");
    strcpy(carta1.nome_cidade, "Sao Paulo");
    carta1.populacao = 12396372; // População de São Paulo em 2023 (IBGE)
    carta1.area = 1521.11;     // Área de São Paulo em km² (IBGE)
    carta1.pib = 763.80;       // PIB de São Paulo em bilhões de reais (aproximado)
    carta1.pontos_turisticos = 50;

    // Calcula Densidade Populacional e PIB per capita para Carta 1
    carta1.densidade_populacional = (float)carta1.populacao / carta1.area;
    carta1.pib_per_capita = (carta1.pib * 1000000000) / carta1.populacao; // Convertendo PIB para reais para cálculo per capita
