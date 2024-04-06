#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 1. Déclaration du type Maillon
// indice est un champ de type int qui stocke l'indice de la composante dans le vecteur d'origine.
//valeur est un champ de type float qui stocke la valeur de la composante.
//suivant est un champ de type struct maillon * qui stocke un pointeur vers le maillon suivant de la liste.
typedef struct maillon {
    int indice;
    float valeur;
    struct maillon *suivant;
} MAILLON;
// Déclaration du type PTR
typedef MAILLON *PTR;

//2.  Ecrire une fonction nouveau_maillon permettant de créer un nouveau maillon avec des
//valeurs initiales fournies en arguments.
//Cette fonction crée un nouveau maillon et l'initialise avec les valeurs indice et valeur fournies en arguments.
//La fonction retourne un pointeur vers le nouveau maillon.
MAILLON *nouveau_maillon(int indice, float valeur) {
    MAILLON *nouveau = malloc(sizeof(MAILLON));
    nouveau->indice = indice;
    nouveau->valeur = valeur;
    nouveau->suivant = NULL;
    return nouveau;
}

//3. Ecrire une fonction PTR vecteur_creux (float t[ ], int n) qui prend un tableau t ayant n
//éléments et construit sa représentation sous forme de vecteur creux.
//Cette fonction parcourt le tableau t et pour chaque élément non nul, elle crée un nouveau maillon et l'ajoute à la liste.
//La fonction retourne un pointeur vers le premier maillon de la liste (tête de la liste).
PTR vecteur_creux(float t[], int n) {
    PTR tete = NULL;
    PTR p = NULL;
    for (int i = 0; i < n; i++) {
        if (t[i] != 0.0) {
            if (tete == NULL) {
                tete = nouveau_maillon(i, t[i]);
                p = tete;
            } else {
                p->suivant = nouveau_maillon(i, t[i]);
                p = p->suivant;
            }
        }
    }
    return tete;
}

PTR somme(PTR a, PTR b)
{
    PTR tete = NULL;
    PTR p = a;
    PTR q = b;
    PTR dernier = NULL; // Pointeur vers le dernier maillon ajouté

    while (p && q)
    {
        if (p->indice == q->indice)
        {
            // Addition des valeurs
            float valeur = p->valeur + q->valeur;
            PTR nouveau = nouveau_maillon(p->indice, valeur);
            if (!tete)
            {
                tete = nouveau;
                dernier = tete;
            }
            else
            {
                dernier->suivant = nouveau;
                dernier = dernier->suivant;
            }
            p = p->suivant;
            q = q->suivant;
        }
        else if (p->indice < q->indice)
        {
            PTR nouveau = nouveau_maillon(p->indice, p->valeur);
            if (!tete)
            {
                tete = nouveau;
                dernier = tete;
            }
            else
            {
                dernier->suivant = nouveau;
                dernier = dernier->suivant;
            }
            p = p->suivant;
        }
        else
        {
            PTR nouveau = nouveau_maillon(q->indice, q->valeur);
            if (!tete)
            {
                tete = nouveau;
                dernier = tete;
            }
            else
            {
                dernier->suivant = nouveau;
                dernier = dernier->suivant;
            }
            q = q->suivant;
        }
    }

    // Ajouter les éléments restants de a et b
    while (p)
    {
        PTR nouveau = nouveau_maillon(p->indice, p->valeur);
        if (!tete)
        {
            tete = nouveau;
            dernier = tete;
        }
        else
        {
            dernier->suivant = nouveau;
            dernier = dernier->suivant;
        }
        p = p->suivant;
    }
    while (q)
    {
        PTR nouveau = nouveau_maillon(q->indice, q->valeur);
        if (!tete)
        {
            tete = nouveau;
            dernier = tete;
        }
        else
        {
            dernier->suivant = nouveau;
            dernier = dernier->suivant;
        }
        q = q->suivant;
    }

    return tete;
}
// Fonction principale
int main() {
    // Test de la fonction nouveau_maillon
    MAILLON *m = nouveau_maillon(5, 3.14);
    printf("Nouveau maillon cree :\n");
    printf(" %d %.2f\n", m->indice, m->valeur);
    free(m);

    // Test de la fonction vecteur_creux
    float t[] = {0, 2, 0, 5, 0, 7, 0, 3, 0, 0};
    int n = sizeof(t) / sizeof(t[0]);
    PTR tete = vecteur_creux(t, n);
    if (tete == NULL) {
        printf("Erreur de création du vecteur creux\n");
        return 1;
    } else {
        printf("Vecteur creux cree :\n");
        PTR p = tete;
        while (p != NULL) {
            printf("  %d %.2f", p->indice, p->valeur,"\t");

            p = p->suivant;
        }
        printf("\n");
    }


    // Créer deux tableaux creux
    PTR a = nouveau_maillon(1, 2.5);
    a->suivant = nouveau_maillon(3, 1.0);
    a->suivant->suivant = nouveau_maillon(4, 3.0);

    PTR b = nouveau_maillon(2, 1.5);
    b->suivant = nouveau_maillon(3, 2.0);
    b->suivant->suivant = nouveau_maillon(5, 4.0);

    // Calculer la somme
    PTR resultat = somme(a, b);
    printf("La somme des vecteurs creux :\n");
    // Afficher le résultat
    while (resultat)
    {

        printf("%d %.2f", resultat->indice, resultat->valeur,"\t");
        printf("  ");
        resultat = resultat->suivant;
    }
    printf("\n");


    // Libérer la mémoire
    while (tete != NULL) {
        PTR suivant = tete->suivant;
        free(tete);
        tete = suivant;
    }

    while (a != NULL) {
        PTR suivant = a->suivant;
        free(a);
        a = suivant;
    }

    while (b != NULL) {
        PTR suivant = b->suivant;
        free(b);
        b = suivant;
    }



    return 0;
}
