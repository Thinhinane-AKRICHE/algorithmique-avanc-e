#include<stdio.h>

void erase(int *tab, int taille, int position){
    for(int i = position; i < taille - 1; i++){
        tab[i] = tab[i + 1]; // Décale les éléments vers la gauche
    }
}

int main(){

    int tableau[] = {1, 2, 5, 9, 10};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    int position = 2; // Position à supprimer (index 2)

    printf("Tableau avant suppression : \n");
    for(int i = 0; i < taille; i++){
        printf("%d ", tableau[i]); 
    }
    printf("\n");

    erase(tableau, taille, position);

    printf("Tableau apres suppression de l'element a la position 2 : \n");
    for(int i = 0; i < taille - 1; i++){ 
        printf("%d ", tableau[i]);
    }
    printf("\n");
    
    return 0;
}
