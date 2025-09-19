#include <stdio.h>
#include <string.h>

// Definição da estrutura Carta
typedef struct {
    char estado[2];
    char codigoCarta[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int numPontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para preencher os dados de uma carta
void preencherCarta(Carta *c) {
    printf("--- Cadastro da Carta ---\n");
    printf("Digite o estado (ex: SP): ");
    scanf("%s", c->estado);
    printf("Digite o codigo da carta (ex: A101): ");
    scanf("%s", c->codigoCarta);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", c->nomeCidade);
    printf("Digite a populacao (int): ");
    scanf("%d", &c->populacao);
    printf("Digite a area (km^2, float): ");
    scanf("%f", &c->area);
    printf("Digite o PIB (em bilhoes, float): ");
    scanf("%f", &c->pib);
    printf("Digite o numero de pontos turisticos (int): ");
    scanf("%d", &c->numPontosTuristicos);

    if (c->area > 0) {
        c->densidadePopulacional = (float)c->populacao / c->area;
    } else {
        c->densidadePopulacional = 0;
    }
    if (c->populacao > 0) {
        c->pibPerCapita = c->pib / c->populacao;
    } else {
        c->pibPerCapita = 0;
    }
}

// Função para comparar as duas cartas
void compararCartas(Carta carta1, Carta carta2) {
    char atributo[50];
    float valor1, valor2;
    int venceu1 = 0;
    int venceu2 = 0;

    strcpy(atributo, "Densidade Populacional");
    valor1 = carta1.densidadePopulacional;
    valor2 = carta2.densidadePopulacional;

    if (valor1 < valor2) {
        venceu1 = 1;
    } else if (valor2 < valor1) {
        venceu2 = 1;
    }

    printf("\n--- Resultado da Comparacao ---\n");
    printf("Comparacao de cartas (Atributo: %s):\n", atributo);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, valor2);

    if (venceu1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (venceu2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    Carta carta1, carta2;

    preencherCarta(&carta1);
    preencherCarta(&carta2);

    compararCartas(carta1, carta2);

    return 0;
}
