#include <stdio.h>
#include <stdlib.h>

#define NMAX 100 // Constante pour la taille maximale de la matrice carrée

// Définition du type MATCARREE représentant une matrice carrée
typedef struct {
    int taille;
    double *coefficients;
} MATCARREE;

// Fonction pour vérifier si une matrice carrée est symétrique
int symetrique(MATCARREE m) {
    int i, j;
    for (i = 0; i < m.taille; i++) {
        for (j = 0; j < m.taille; j++) {
            // Vérification de la symétrie par rapport à la diagonale principale
            if (m.coefficients[i * m.taille + j] != m.coefficients[j * m.taille + i]) {
                return 0; // Non symétrique
            }
        }
    }
    return 1; // Symétrique
}

// Fonction pour calculer le nombre de nombres réels nécessaires pour représenter une matrice symétrique
int nombreNombresReels(int n) {
    // Un seul triangle de la matrice est nécessaire, donc (n * (n + 1)) / 2 coefficients
    return (n * (n + 1)) / 2;
}

// Fonction pour construire la représentation compacte d'une matrice symétrique
double *symCompacte(MATCARREE m) {
    if (!symetrique(m)) {
        return NULL; // Matrice non symétrique
    }
    // Allocation dynamique pour la représentation compacte
    double *compacte = malloc(nombreNombresReels(m.taille) * sizeof(double));
    if (compacte == NULL) {
        printf("Allocation de mémoire échouée\n");
        exit(EXIT_FAILURE);
    }
    // Copie des coefficients symétriques dans la représentation compacte
    int i, j, k = 0;
    for (i = 0; i < m.taille; i++) {
        for (j = 0; j <= i; j++) {
            compacte[k++] = m.coefficients[i * m.taille + j];
        }
    }
    return compacte;
}

// Fonction pour accéder au coefficient (i, j) dans la représentation compacte
double acces(double *c, int i, int j, int n) {
    if (i < j) {
        // Si i < j, les indices sont échangés car on ne stocke que la partie inférieure ou égale de la matrice
        int temp = i;
        i = j;
        j = temp;
    }
    // Calcul de l'indice dans la représentation compacte
    return c[(i * (i + 1) / 2) + j];
}

// Fonction pour traiter un coefficient
void traiterCoef(double x) {
    printf("%.2f ", x); // Exemple de traitement : affichage du coefficient
}

// Fonction pour traiter une ligne de la matrice symétrique
void traiterLigne(double *c, int n, int i) {
    int j;
    for (j = 0; j <= i; j++) {
        traiterCoef(acces(c, i, j, n)); // Traitement de chaque coefficient de la ligne
    }
    printf("\n");
}

// Fonction pour afficher la matrice symétrique
void afficher(double *c, int n) {
    int i;
    for (i = 0; i < n; i++) {
        traiterLigne(c, n, i); // Affichage de chaque ligne
    }
}

int main() {
    // Exemple d'utilisation
    MATCARREE m = {3, (double[]){1.0, 2.0, 3.0, 2.0, 4.0, 5.0, 3.0, 5.0, 6.0}};
    if (symetrique(m)) {
        printf("La matrice est symétrique\n");
        double *compacte = symCompacte(m);
        if (compacte != NULL) {
            printf("Représentation compacte :\n");
            afficher(compacte, m.taille); // Affichage de la représentation compacte
            free(compacte); // Libération de la mémoire allouée dynamiquement
        } else {
            printf("Erreur lors de la construction de la représentation compacte\n");
        }
    } else {
        printf("La matrice n'est pas symétrique\n");
    }
    return 0;
}
