#include<stdio.h>

void inverse(int *tab, int taille){
    for(int i=0; i< taille/2; i++){
        int temp = tab[i];
        tab[i] = tab[taille-1-i];
        tab[taille-1-i] = temp;
    }
}

int main() {
    int tableau[] = {1, 2, 3, 4, 5};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    printf("Tableau avant inversion :\n");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    // Inverser le tableau
    inverse(tableau, taille);

    printf("Tableau après inversion :\n");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    return 0;
}