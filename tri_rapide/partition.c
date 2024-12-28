#include <stdio.h>
#include <stdlib.h>

// Définition de la structure Array
typedef struct {
    int *data;
    int size;
} Array;

// Fonction pour échanger deux éléments dans le tableau
void swap(Array *tab, int i, int j) {
    int temp = tab->data[i];
    tab->data[i] = tab->data[j];
    tab->data[j] = temp;
}

// Fonction de partition pour le tri
int partition(Array *tab, int pivot) {
    int pivotValue = tab->data[pivot]; // Valeur du pivot
    int j = 0; // Indice pour suivre la position d'insertion
    
    swap(tab, pivot, tab->size - 1);

    for (int i = 0; i < tab->size - 1; i++) {
        if (tab->data[i] <= pivotValue) {
            swap(tab, i, j);
            j++;
        }
    }

    swap(tab, j, tab->size - 1);

    return j; 
}

// Fonction pour choisir un pivot (simplement le premier élément ici)
int pivotChoice(Array *tab) {
    return 0; // Exemple : retourne le premier élément comme pivot
}

// Fonction pour créer un sous-tableau
Array subArray(Array *tab, int start, int end) {
    Array sub;
    sub.size = end - start;
    sub.data = (int *)malloc(sub.size * sizeof(int));
    for (int i = 0; i < sub.size; i++) {
        sub.data[i] = tab->data[start + i];
    }
    return sub;
}

// Fonction pour libérer la mémoire d'un tableau
void freeArray(Array *tab) {
    free(tab->data);
    tab->data = NULL;
    tab->size = 0;
}

// Fonction de tri rapide (QuickSort)
void quickSort(Array *tab) {
    if (tab->size <= 1) return; // Rien à trier si taille <= 1

    int p = pivotChoice(tab);
    p = partition(tab, p);

    if (p >= 1) {
        Array left = subArray(tab, 0, p);
        quickSort(&left);
        for (int i = 0; i < left.size; i++) {
            tab->data[i] = left.data[i];
        }
        freeArray(&left);
    }

    if (p < tab->size - 1) {
        Array right = subArray(tab, p + 1, tab->size);
        quickSort(&right);
        for (int i = 0; i < right.size; i++) {
            tab->data[p + 1 + i] = right.data[i];
        }
        freeArray(&right);
    }
}

// Fonction pour afficher le tableau
void printArray(Array *tab) {
    for (int i = 0; i < tab->size; i++) {
        printf("%d ", tab->data[i]);
    }
    printf("\n");
}

int main() {
    // Exemple d'utilisation
    int data[] = {10, 7, 8, 9, 1, 5};
    Array tab = {data, 6};

    printf("Tableau original : ");
    printArray(&tab);

    quickSort(&tab);

    printf("Tableau trié : ");
    printArray(&tab);

    return 0;
}
