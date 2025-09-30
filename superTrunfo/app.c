#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h> // necessário para strcpy

// Agrupando todos os atributos
typedef struct {
    char nome[20];
    int ataque;
    int defesa;
    int recuo;
} Carta;

// Função para criar carta
Carta criarcarta(int opcao) {
    Carta c;

    switch(opcao) {
        case 1:
            strcpy(c.nome, "Brasil");
            break;
        case 2:
            strcpy(c.nome, "Estados Unidos");
            break;
        case 3:
            strcpy(c.nome, "Argentina");
            break;
        case 4:
            strcpy(c.nome, "Alemanha");
            break;
        case 5:
            strcpy(c.nome, "Inglaterra");
            break;
        default:
            strcpy(c.nome, "Nao escolhido");
            break;
    }

    // Gerar valores aleatórios para atributos
    c.ataque = (rand() % 100) + 1;
    c.defesa = (rand() % 100) + 1;
    c.recuo = (rand() % 100) + 1;

    return c;
}

// Função para mostrar a carta
void mostrarCarta(Carta c) {
    printf("\n=== Carta Escolhida: %s ===\n", c.nome);
    printf("Ataque: %d\n", c.ataque);
    printf("Defesa: %d\n", c.defesa);
    printf("Recuo : %d\n", c.recuo);
    printf("===========================\n");
}

int main() {
    srand(time(NULL)); // inicializa números aleatórios

    int opcao1, opcao2;

    printf("========== MENU ==========\n");
    printf("ESCOLHA SUA CARTA\n");
    printf("1- BRASIL\n");
    printf("2- ESTADOS UNIDOS\n");
    printf("3- ARGENTINA\n");
    printf("4- ALEMANHA\n");
    printf("5- INGLATERRA\n");

    printf("\nJogador 1, escolha sua carta: ");
    scanf("%d", &opcao1);
    printf("Jogador 2, escolha sua carta: ");
    scanf("%d", &opcao2);

    Carta jogador1 = criarcarta(opcao1);
    Carta jogador2 = criarcarta(opcao2);

    mostrarCarta(jogador1);
    mostrarCarta(jogador2);

    int total1 = jogador1.ataque + jogador1.defesa + jogador1.recuo;
    int total2 = jogador2.ataque + jogador2.defesa + jogador2.recuo;

    printf("\nResultado da Partida:\n");
    if (total1 > total2) {
        printf("Jogador 1 venceu!\n");
    } else if (total2 > total1) {
        printf("Jogador 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;    
}