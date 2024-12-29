#include<stdio.h>

void insert(int *tab, int taille, int position, int element){
    for(int i=taille-1; i>=position; i--){
        tab[i+1] = tab[i];
    }
    tab[position] = element;
}

int main(){
    int tableau[] = {1, 2, 5, 9, 10};
    int taille = sizeof(tableau)/sizeof(tableau[0]);
    int position = 2;
    int element = 42;
    insert(tableau, taille, position, element);
    taille++;
    printf("le tableau apres l'insertion de l'element: ");
    printf("\n");
    for(int i=0; i<taille; i++){
        printf("%d ", tableau[i]);
    }

}