// ===========================================================================
// PRÁTICA: JOGO WAR
// ===========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcspn()

#define MAX_TERRITORIOS 5
#define TAM_STRING 100

// --- Estrutura ---
struct Territorio {
    char nome[TAM_STRING];
    char corExercito[TAM_STRING];
    int numeroTropas;
};

// --- Função para limpar buffer ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Territorio territorios[MAX_TERRITORIOS];
    int totalTerritorios = 0;
    int opcao;

    do {
        printf("============================================\n");
        printf("  JOGO WAR - MAPA DO MUNDO - GUINOBLAT\n");
        printf("============================================\n");
        printf("1 - Cadastrar Territorio 1\n");
        printf("2 - Cadastrar Territorio 2\n");
        printf("3 - Cadastrar Territorio 3\n");
        printf("4 - Cadastrar Territorio 4\n");
        printf("5 - Cadastrar Territorio 5\n");
        printf("6 - Listar todos os territorios\n");
        printf("0 - Sair\n");
        printf("-----------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5: {
                int index = opcao - 1; // posição do array
                printf("\n--- Cadastrando Territorio %d ---\n", opcao);

                printf("Nome do Territorio: ");
                fgets(territorios[index].nome, TAM_STRING, stdin);

                printf("Cor do Exercito (ex: Azul, Verde): ");
                fgets(territorios[index].corExercito, TAM_STRING, stdin);

                territorios[index].nome[strcspn(territorios[index].nome, "\n")] = '\0';
                territorios[index].corExercito[strcspn(territorios[index].corExercito, "\n")] = '\0';

                printf("Numero de Tropas: ");
                scanf("%d", &territorios[index].numeroTropas);
                limparBufferEntrada();

                if (index >= totalTerritorios) {
                    totalTerritorios = index + 1; // Atualiza qtde total cadastrada
                }

                printf("\nTerritorio %d cadastrado com sucesso!\n", opcao);
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
            }

            case 6: // LISTAR
                printf("\n--- Lista de Territorios Cadastrados ---\n");
                if (totalTerritorios == 0) {
                    printf("Nenhum territorio cadastrado ainda.\n");
                } else {
                    for (int i = 0; i < totalTerritorios; i++) {
                        printf("-----------------------------------\n");
                        printf("TERRITORIO %d\n", i + 1);
                        printf("Nome: %s\n", territorios[i].nome);
                        printf("Cor do Exercito: %s\n", territorios[i].corExercito);
                        printf("Numero de Tropas: %d\n", territorios[i].numeroTropas);
                    }
                    printf("-----------------------------------\n");
                }
                printf("\nPressione Enter para continuar...");
                getchar();
                break;

            case 0:
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
        }
    } while (opcao != 0);

    return 0;
}