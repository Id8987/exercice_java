#include <stdio.h>
#include <stdlib.h>

// Structure pour un nœud de l'arbre binaire
struct Noeud
{
    int valeur;
    struct Noeud *gauche;
    struct Noeud *droite;
};

// Alias pour simplifier l'utilisation
typedef struct Noeud ARB_BIN;

// Procédure pour afficher les étiquettes des feuilles de l'arbre
void FEUILLE(ARB_BIN *A)
{
    if (A)
    {
        if (!A->gauche && !A->droite)
        {
            printf("%d\n", A->valeur); // Affiche l'étiquette de la feuille
        }
        FEUILLE(A->gauche); // Parcours récursif à gauche
        FEUILLE(A->droite); // Parcours récursif à droite
    }
}

// Procédure pour afficher les nœuds et leurs degrés
void DEGRE(ARB_BIN *A)
{
    if (A)
    {
        int degre = 0;
        if (A->gauche)
            degre++;
        if (A->droite)
            degre++;
        printf("Noeud %d : Degré %d\n", A->valeur, degre);
        DEGRE(A->gauche); // Parcours récursif à gauche
        DEGRE(A->droite); // Parcours récursif à droite
    }
}

// Fonction pour trouver la profondeur d'un nœud x dans l'arbre
int PROFONDEUR(ARB_BIN *A, int x, int profondeur_actuelle)
{
    if (A)
    {
        if (A->valeur == x)
        {
            return profondeur_actuelle;
        }
        int profondeur_gauche = PROFONDEUR(A->gauche, x, profondeur_actuelle + 1);
        int profondeur_droite = PROFONDEUR(A->droite, x, profondeur_actuelle + 1);
        if (profondeur_gauche != -1)
        {
            return profondeur_gauche;
        }
        else
        {
            return profondeur_droite;
        }
    }
    return -1; // Nœud x non trouvé
}

// Fonction pour trouver la hauteur d'un arbre binaire A
int HAUTEUR(ARB_BIN *A)
{
    if (A == NULL)
    {
        return -1; // Arbre vide
    }
    else
    {
        int hauteur_gauche = HAUTEUR(A->gauche);
        int hauteur_droite = HAUTEUR(A->droite);
        if (hauteur_gauche > hauteur_droite)
        {
            return 1 + hauteur_gauche;
        }
        else
        {
            return 1 + hauteur_droite;
        }
    }
}

// Fonction pour trouver la somme des nœuds de l'arbre binaire A
int SOM_NOEUDS(ARB_BIN *A)
{
    if (A == NULL)
    {
        return 0;
    }
    else
    {
        int somme_gauche = SOM_NOEUDS(A->gauche);
        int somme_droite = SOM_NOEUDS(A->droite);
        return A->valeur + somme_gauche + somme_droite;
    }
}

int main()
{
    // Créez un arbre binaire
    ARB_BIN *A = malloc(sizeof(ARB_BIN));
    A->valeur = 1;
    A->gauche = malloc(sizeof(ARB_BIN));
    A->gauche->valeur = 2;
    A->gauche->gauche = NULL;
    A->gauche->droite = NULL;

    A->droite = malloc(sizeof(ARB_BIN));
    A->droite->valeur = 3;
    A->droite->gauche = malloc(sizeof(ARB_BIN));
    A->droite->gauche->valeur = 4;
    A->droite->gauche->gauche = NULL;
    A->droite->gauche->droite = NULL;

    A->droite->droite = malloc(sizeof(ARB_BIN));
    A->droite->droite->valeur = 5;
    A->droite->droite->gauche = NULL;
    A->droite->droite->droite = NULL;

    // Affichez les étiquettes des feuilles
    printf("Étiquettes des feuilles de l'arbre :\n");
    FEUILLE(A);

    // Affichez les nœuds et leurs degrés
    printf("Nœuds et leurs degrés :\n");
    DEGRE(A);

    int x = 4; // Valeur du nœud x dont nous voulons trouver la profondeur
    int profondeur = PROFONDEUR(A, x, 0);

    if (profondeur != -1)
    {
        printf("La profondeur du nœud %d dans l'arbre est : %d\n", x, profondeur);
    }
    else
    {
        printf("Le nœud %d n'a pas été trouvé dans l'arbre.\n", x);
    }

    printf("La hauteur de l'arbre est : %d\n", HAUTEUR(A));

    printf("La somme des nœuds de l'arbre est : %d\n", SOM_NOEUDS(A));

    return 0;
}
