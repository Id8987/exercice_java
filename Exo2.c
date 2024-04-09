#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure du maillon
struct Maillon
{
    char value[100];
    struct Maillon *next;
    struct Maillon *prev;
};

// Variables globales pour ma liste chaînée bidirectionnelle
struct Maillon *premier = NULL;
struct Maillon *dernier = NULL;

// Fonction pour ajouter un maillon en tête de la liste
void ajouter_devant_simple(char *s)
{
    // Créez un nouveau maillon
    struct Maillon *new_maillon = (struct Maillon *)malloc(sizeof(struct Maillon));
    strcpy(new_maillon->value, s);
    new_maillon->next = NULL;
    new_maillon->prev = NULL;

    // Mettez à jour les pointeurs
    if (premier)
    {
        new_maillon->next = premier;
        premier->prev = new_maillon;
    }
    premier = new_maillon;

    // Si c'est le premier maillon, mettez à jour dernier également
    if (!dernier)
    {
        dernier = premier;
    }
}

// Fonction pour ajouter un maillon en tête de la liste
struct Maillon *ajouter_devant(struct Maillon *premier, struct Maillon *dernier, char *s)
{
    struct Maillon *new_maillon = (struct Maillon *)malloc(sizeof(struct Maillon));
    strcpy(new_maillon->value, s);
    new_maillon->next = NULL;
    new_maillon->prev = NULL;

    if (premier)
    {
        new_maillon->next = premier;
        premier->prev = new_maillon;
    }
    premier = new_maillon;

    if (!dernier)
    {
        dernier = premier;
    }

    return premier;
}

// Fonction pour supprimer un maillon de la liste
struct Maillon *supprimer(struct Maillon *premier, struct Maillon *dernier, char *s)
{
    struct Maillon *current = premier;
    while (current)
    {
        if (strcmp(current->value, s) == 0)
        {
            if (current->prev)
            {
                current->prev->next = current->next;
            }
            else
            {
                premier = current->next;
            }
            if (current->next)
            {
                current->next->prev = current->prev;
            }
            else
            {
                dernier = current->prev;
            }
            free(current);
            break;
        }
        current = current->next;
    }
    return premier;
}

// Fonction pour libérer la mémoire de tous les maillons
void liberer_memoire(struct Maillon *premier)
{
    struct Maillon *current = premier;
    while (current)
    {
        struct Maillon *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    // Exemple d'utilisation :
    premier = ajouter_devant(premier, dernier, "E");
    premier = ajouter_devant(premier, dernier, "D");
    premier = ajouter_devant(premier, dernier, "C");
    premier = ajouter_devant(premier, dernier, "B");
    premier = ajouter_devant(premier, dernier, "A");

    // Affichez la liste avant la suppression
    struct Maillon *current = premier;
    printf("Liste avant toute suppression\n");
    while (current)
    {
        printf("%s", current->value);
        current = current->next;
    }
    printf("\n");

    // Supprimez "B" de la liste
    premier = supprimer(premier, dernier, "B");

    // Affichez la liste après la suppression
    printf("Liste apres suppression de B\n");
    current = premier;
    while (current)
    {
        printf("%s", current->value);
        current = current->next;
    }
    printf("\n");

    liberer_memoire(premier);
    printf("Liberation de la memoire \n");
    return 0;
}
