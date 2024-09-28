#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    const int MAX = 100; 
    char titre[MAX][50], auteur[MAX][50]; 
    float prix[MAX]; 
    int quantite[MAX]; 
    int total = 0; 
    int choice; 
    char search[50]; 
    int stock = 0;

    do { 
        printf("\n***** MENU *****\n");
        printf("1. Ajouter un livre au stock.\n");
        printf("2. Afficher tous les livres disponibles.\n");
        printf("3. Rechercher un livre par son titre.\n");
        printf("4. Mettre a jour la quantite d'un livre.\n");
        printf("5. Supprimer un livre du stock.\n");
        printf("6. Afficher le nombre total de livres en stock.\n");
        printf("7. Quitter.\n");
        printf("Entrer un nombre: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nEntree invalide.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch (choice) {
            case 1: 
                if (total < MAX) {
                    printf("\nTitre de livre: ");
                    fgets(titre[total], 50, stdin);
                    titre[total][strcspn(titre[total], "\n")] = '\0';
                    
                    printf("\nAuteur de livre: ");
                    fgets(auteur[total], 50, stdin);
                    auteur[total][strcspn(auteur[total], "\n")] = '\0';

                    printf("\nPrix de livre: ");
                    scanf("%f", &prix[total]);
                    printf("\nQuantite de livre: ");
                    scanf("%d", &quantite[total]);

                    printf("\nCette operation est un succes. \n");
                    total++;
                } else {
                    printf("Stock maximum atteint.\n");
                }
                break;

            case 2: 
                if (total == 0) {
                    printf("Il n'y a pas de stock.\n");
                } else {
                    for (int i = 0; i < total; i++) {
                        printf("\n%d. Titre: %s, Auteur: %s || Prix: %.2f DH, Quantite: %d", i + 1, titre[i], auteur[i], prix[i], quantite[i]);
                    }
                }
                break;

            case 3: 
                printf("\nEntrez le titre du livre a rechercher: ");
                fgets(search, 50, stdin);
                search[strcspn(search, "\n")] = '\0';
                int trouve = 0;

                for (int i = 0; i < total; i++) {
                    if (strcmp(titre[i], search) == 0) {
                        printf("\nLe livre existe: Titre: %s, Auteur: %s || Prix: %.2f, Quantite: %d\n", titre[i], auteur[i], prix[i], quantite[i]);
                        trouve = 1;
                        break;
                    }
                }
                if (!trouve) {
                    printf("\nLe livre n'existe pas.\n");
                }
                break;

            case 4: 
                printf("Entrez le titre du livre a mettre a jour: ");
                fgets(search, 50, stdin);
                search[strcspn(search, "\n")] = '\0';
                trouve = 0;

                for (int i = 0; i < total; i++) {
                    if (strcmp(titre[i], search) == 0) {
                        printf("Entrez la nouvelle quantite: ");
                        scanf("%d", &quantite[i]);
                        printf("Quantite mise a jour.\n");
                        trouve = 1;
                        break;
                    }
                }
                if (!trouve) {
                    printf("\nLe livre n'existe pas.\n");
                }
                break;

            case 5: 
                printf("Entrez le titre du livre a supprimer: ");
                fgets(search, sizeof(search), stdin);
                search[strcspn(search, "\n")] = '\0';
                trouve = 0;

                for (int i = 0; i < total; i++) {
                    if (strcmp(titre[i], search) == 0) {
                        for (int j = i; j < total - 1; j++) {
                            strcpy(titre[j], titre[j + 1]);
                            strcpy(auteur[j], auteur[j + 1]);
                            prix[j] = prix[j + 1];
                            quantite[j] = quantite[j + 1];
                        }
                        total--;
                        printf("Livre supprime.\n");
                        trouve = 1;
                        break;
                    }
                }
                if (!trouve) {
                    printf("Le livre n'existe pas.\n");
                }
                break;

            case 6: 
                stock = 0;
                for (int i = 0; i < total; i++) {
                    stock += quantite[i];
                }
                printf("Nombre total de livres en stock: %d\n", stock);
                break;

            default:
                break;
        }
    } while (choice != 7);

    printf("\nPasse une bonne journee!");
    return 0;
}