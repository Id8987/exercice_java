#include <stdio.h>
#include <stdlib.h>

// Définition de la structure pour les nœuds de la liste
typedef struct Noeud {
    int donnee; // Donnée stockée dans le nœud
    struct Noeud* suivant; // Pointeur vers le nœud suivant
} Noeud;

// Fonction pour créer un nouveau nœud
Noeud* creerNoeud(int donnee) {
    Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud)); // Allouer de la mémoire pour le nouveau nœud
    if(nouveauNoeud == NULL) { // Vérifier si l'allocation de mémoire a réussi
        printf("Erreur d'allocation de mémoire.\n");
        return NULL;
    }
    nouveauNoeud->donnee = donnee; // Assigner la donnée au nœud
    nouveauNoeud->suivant = NULL; // Initialiser le pointeur vers le prochain nœud à NULL
    return nouveauNoeud; // Retourner le nouveau nœud
}

// Fonction pour créer une liste à partir de valeurs saisies au clavier
Noeud* creerListe() {
    Noeud* tete = NULL; // Initialiser la tête de la liste à NULL
    Noeud* temp = NULL; // Initialiser un pointeur temporaire à NULL
    int i;
    for(i = 0; i < 10; i++) { // Boucle pour saisir 10 valeurs
        int val;
        printf("Entrez la valeur %d : ", i+1); // Demander à l'utilisateur d'entrer une valeur
        scanf("%d", &val); // Lire la valeur entrée par l'utilisateur
        Noeud* noeud = creerNoeud(val); // Créer un nouveau nœud avec la valeur
        if(tete == NULL) { // Si la liste est vide
            tete = noeud; // Faire du nouveau nœud la tête de la liste
        } else { // Si la liste n'est pas vide
            temp->suivant = noeud; // Ajouter le nouveau nœud à la fin de la liste
        }
        temp = noeud; // Mettre à jour le pointeur temporaire pour pointer vers le dernier nœud
    }
    return tete; // Retourner la tête de la liste
}

// Fonction pour tester l'égalité de deux listes
int estEgal(Noeud* liste1, Noeud* liste2) {
    while(liste1 != NULL && liste2 != NULL) { // Tant que les deux listes ont des nœuds
        if(liste1->donnee != liste2->donnee) { // Si les données des nœuds actuels ne sont pas égales
            return 0; // Retourner 0 (faux)
        }
        liste1 = liste1->suivant; // Passer au nœud suivant dans la première liste
        liste2 = liste2->suivant; // Passer au nœud suivant dans la deuxième liste
    }
    if(liste1 == NULL && liste2 == NULL) { // Si les deux listes sont terminées
        return 1; // Retourner 1 (vrai)
    }
    return 0; // Sinon, retourner 0 (faux)
}

// Fonction pour concaténer deux listes
Noeud* concatener(Noeud* liste1, Noeud* liste2) {
    if(liste1 == NULL) { // Si la première liste est vide
        return liste2; // Retourner la deuxième liste
    }
    Noeud* temp = liste1; // Initialiser un pointeur temporaire pour parcourir la première liste
    while(temp->suivant != NULL) { // Tant qu'il y a des nœuds dans la première liste
        temp = temp->suivant; // Passer au nœud suivant
    }
    temp->suivant = liste2; // Ajouter la deuxième liste à la fin de la première liste
    return liste1; // Retourner la première liste (qui contient maintenant les nœuds de la deuxième liste)
}

// Fonction principale pour tester les fonctions de liste
int main() {
    // Créer deux listes
    printf("Création de la première liste :\n");
    Noeud* liste1 = creerListe();

    printf("\nCréation de la deuxième liste :\n");
    Noeud* liste2 = creerListe();

    // Tester l'égalité des deux listes
    if(estEgal(liste1, liste2)) {
        printf("\nLes deux listes sont égales.\n");
    } else {
        printf("\nLes deux listes ne sont pas égales.\n");
    }

    // Concaténer les deux listes
    Noeud* concat = concatener(liste1, liste2);

    // Afficher la liste concaténée
    printf("\nListe concaténée :\n");
    Noeud* temp = concat;
    while(temp != NULL) {
        printf("%d -> ", temp->donnee);
        temp = temp->suivant;
    }
    printf("NULL\n");

    return 0;
}
