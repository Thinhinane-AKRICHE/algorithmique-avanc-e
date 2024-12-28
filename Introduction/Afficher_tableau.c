#include <stdio.h>

void display(int *tab, int taille){
    for(int i=0; i<taille; i++){
        printf("%d ",tab[i]);
    }    
}
int main(){
    int tableau[] ={1,3,8,9,10};
    int taille = sizeof(tableau)/sizeof(tableau[0]);
    display(tableau, taille);
    return 0;
}