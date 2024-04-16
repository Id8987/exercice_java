#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure maillon
typedef struct maillon {
    char *mot;
    struct maillon *suiv;
} MAILLON, *PTR;

// Fonction pour ajouter un nouveau maillon au début de la liste
PTR ajoute_debut(char *mot, PTR L) {
    // Allocation de mémoire pour le nouveau maillon
    PTR nouveau_maillon = (PTR)malloc(sizeof(MAILLON));
    // Vérification si l'allocation de mémoire a réussi
    if (nouveau_maillon == NULL) {
        printf("Allocation de mémoire échouée\n");
        exit(EXIT_FAILURE);
    }
    // Copie du mot dans le nouveau maillon
    nouveau_maillon->mot = strdup(mot);
    // Le maillon suivant pointe vers l'ancienne tête de liste
    nouveau_maillon->suiv = L;
    // Retourne le nouveau maillon qui devient la nouvelle tête de liste
    return nouveau_maillon;
}

// Fonction pour ajouter un nouveau maillon à la fin de la liste
PTR ajoute_fin(char *mot, PTR L) {
    // Allocation de mémoire pour le nouveau maillon
    PTR nouveau_maillon = (PTR)malloc(sizeof(MAILLON));
    // Vérification si l'allocation de mémoire a réussi
    if (nouveau_maillon == NULL) {
        printf("Allocation de mémoire échouée\n");
        exit(EXIT_FAILURE);
    }
    // Copie du mot dans le nouveau maillon
    nouveau_maillon->mot = strdup(mot);
    // Le maillon suivant du nouveau maillon est NULL car il est ajouté à la fin
    nouveau_maillon->suiv = NULL;
    
    // Si la liste est vide, le nouveau maillon devient la seule élément de la liste
    if (L == NULL) {
        return nouveau_maillon;
    }
    
    // Sinon, on parcourt la liste jusqu'à la fin pour ajouter le nouveau maillon
    PTR temp = L;
    while (temp->suiv != NULL) {
        temp = temp->suiv;
    }
    temp->suiv = nouveau_maillon;
    
    // Retourne la tête de liste inchangée
    return L;
}

// Fonction pour supprimer un maillon contenant un mot spécifique de la liste
PTR supprimer(char *mot, PTR L) {
    PTR courant = L;
    PTR precedent = NULL;

    // Parcours de la liste jusqu'à trouver le mot spécifié
    while (courant != NULL) {
        // Si le mot est trouvé dans le premier maillon de la liste
        if (strcmp(courant->mot, mot) == 0) {
            // Si le maillon est la tête de liste, mise à jour de la tête
            if (precedent == NULL) {
                PTR temp = courant->suiv;
                free(courant->mot);
                free(courant);
                return temp;
            } else { // Sinon, ajustement des pointeurs pour supprimer le maillon
                precedent->suiv = courant->suiv;
                free(courant->mot);
                free(courant);
                return L;
            }
        }
        // Passage au maillon suivant dans la liste
        precedent = courant;
        courant = courant->suiv;
    }
    // Si le mot n'est pas trouvé, retourne la liste inchangée
    return L;
}

// Fonction pour afficher les n premiers maillons de la liste
void premiers(PTR liste, int n) {
    PTR temp = liste;
    while (temp != NULL && n > 0) {
        printf("%s ", temp->mot);
        temp = temp->suiv;
        n--;
    }
    printf("\n");
}

// Fonction pour supprimer les doublons de la liste
void purifie(MAILLON *liste) {
    // Vérification si la liste est vide
    if (liste == NULL)
        return;

    MAILLON *courant = liste;
    // Parcours de la liste
    while (courant != NULL) {
        MAILLON *compare = courant;
        // Comparaison avec les maillons suivants
        while (compare->suiv != NULL) {
            // Si deux maillons contiennent le même mot, supprime le maillon suivant
            if (strcmp(courant->mot, compare->suiv->mot) == 0) {
                MAILLON *temp = compare->suiv;
                compare->suiv = compare->suiv->suiv;
                free(temp->mot);
                free(temp);
            } else {
                compare = compare->suiv;
            }
        }
        courant = courant->suiv;
    }
}

// Exemple d'utilisation
int main() {
    // Création de la liste et ajout de mots
    PTR liste = NULL;
    liste = ajoute_fin("Bonjour", liste);
    liste = ajoute_fin("Bonjour", liste);
    liste = ajoute_fin("Monde", liste);
    liste = ajoute_fin("Bonjour", liste);
    
    // Affichage de la liste initiale
    printf("Liste initiale:\n");
    PTR temp = liste;
    while (temp != NULL) {
        printf("%s ", temp->mot);
        temp = temp->suiv;
    }
    printf("\n");
    
    // Purification de la liste
    purifie(liste);
    
    // Affichage de la liste après purification
    printf("Liste après purification:\n");
    temp = liste;
    while (temp != NULL) {
        printf("%s ", temp->mot);
        temp = temp->suiv;
    }
    printf("\n");
    
    return 0;
}
