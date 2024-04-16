#include <stdio.h>
#include <stdlib.h>
//Exo 4 en C
// Définition de la structure Monome
typedef struct Monome {
    int coefficient;
    int exposant;
    struct Monome *suivant;
} Monome;

// Définition de la structure Polynome
typedef struct Polynome {
    Monome *premierMonome;
} Polynome;

// Ajoute un monome à la fin du polynome
void ajouterUnMonome(Polynome *polynome, int coefficient, int exposant) {
    Monome *CeMonome = (Monome*)malloc(sizeof(Monome));
    CeMonome->coefficient = coefficient;
    CeMonome->exposant = exposant;
    CeMonome->suivant = NULL;

    if (polynome->premierMonome == NULL)
        polynome->premierMonome = CeMonome;
    else {
        Monome *monomeCourant = polynome->premierMonome;
        while (monomeCourant->suivant != NULL)
            monomeCourant = monomeCourant->suivant;
        monomeCourant->suivant = CeMonome;
    }
}

// Affiche le polynome de manière réaliste
void afficherCePolynome(Polynome *polynome) {
    Monome *monomeCourant = polynome->premierMonome;
    int premier = 1; // Pour gérer l'affichage du premier terme
    while (monomeCourant != NULL) {
        int coeff = monomeCourant->coefficient;
        int expo = monomeCourant->exposant;
        if (coeff != 0) { // Ignorer les termes avec coefficient nul
            if (!premier && coeff > 0) printf(" + "); // Afficher le signe "+" pour les termes positifs
            if (coeff < 0) printf("-");
            if (abs(coeff) != 1 || expo == 0) printf("%d", abs(coeff)); // Ne pas afficher le coefficient si c'est 1 (sauf pour x^0)
            if (expo > 0) {
                printf("x");
                if (expo != 1) printf("^%d", expo); // Afficher l'exposant si différent de 1
            }
            premier = 0;
        }
        monomeCourant = monomeCourant->suivant;
    }
    printf("\n");
}

// Calcul de la dérivée du polynome
Polynome* DERIVEE(Polynome *P) {
    Polynome *polynomeDerive = (Polynome*)malloc(sizeof(Polynome));
    polynomeDerive->premierMonome = NULL;
    Monome *monomeCourant = P->premierMonome;
    while (monomeCourant != NULL) {
        int coeff = monomeCourant->coefficient * monomeCourant->exposant;
        int expo = monomeCourant->exposant - 1;
        ajouterUnMonome(polynomeDerive, coeff, expo);
        monomeCourant = monomeCourant->suivant;
    }
    return polynomeDerive;
}

// Calcul de la k-ème dérivée du polynome
Polynome* DERIVEEKIEME(Polynome *P, int k) {
    Polynome *polynomeDerive = P;
    for (int i = 0; i < k; i++)
        polynomeDerive = DERIVEE(polynomeDerive);
    return polynomeDerive;
}

int main() {
    Polynome monPolynome;
    monPolynome.premierMonome = NULL;

    ajouterUnMonome(&monPolynome, 4, 5);
    ajouterUnMonome(&monPolynome, 6, 2);
    ajouterUnMonome(&monPolynome, 4, 4);
    afficherCePolynome(&monPolynome);

    Polynome *monPolynomeDerive = DERIVEE(&monPolynome);
    afficherCePolynome(monPolynomeDerive);

    Polynome *PolynomeDeriveek = DERIVEEKIEME(&monPolynome, 2);
    afficherCePolynome(PolynomeDeriveek);

    return 0;
}
