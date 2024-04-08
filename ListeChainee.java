public class ListeChainee {
    // Classe interne représentant un maillon de la liste chaînée
    class Maillon {
        String mot;     // Le mot contenu dans le maillon
        Maillon suiv;   // Référence vers le maillon suivant dans la liste

        // Constructeur du maillon
        public Maillon(String mot) {
            this.mot = mot;     // Initialise le mot
            this.suiv = null;   // Initialise la référence suivante à null
        }
    }

    Maillon tete;   // Référence vers le premier maillon de la liste

    // Constructeur de la liste chaînée
    public ListeChainee() {
        this.tete = null;   // Initialise la tête de la liste à null (liste vide)
    }

    // Méthode pour ajouter un nouveau maillon au début de la liste
    public void ajouteDebut(String mot) {
        Maillon nouveauMaillon = new Maillon(mot); // Crée un nouveau maillon avec le mot spécifié
        if (tete == null) {
            tete = nouveauMaillon;  // Si la liste est vide, le nouveau maillon devient la tête de la liste
        } else {
            nouveauMaillon.suiv = tete;    // Relie le nouveau maillon à la tête actuelle de la liste
            tete = nouveauMaillon;  // Met à jour la tête de la liste pour pointer vers le nouveau maillon
        }
    }

    // Méthode pour ajouter un nouveau maillon à la fin de la liste
    public void ajouteFin(String mot) {
        Maillon nouveauMaillon = new Maillon(mot); // Crée un nouveau maillon avec le mot spécifié
        if (tete == null) {
            tete = nouveauMaillon;  // Si la liste est vide, le nouveau maillon devient la tête de la liste
        } else {
            Maillon temp = tete;
            while (temp.suiv != null) {
                temp = temp.suiv;   // Parcourt la liste jusqu'à atteindre le dernier maillon
            }
            temp.suiv = nouveauMaillon; // Relie le dernier maillon au nouveau maillon
        }
    }

    // Méthode pour supprimer un maillon contenant un mot spécifié de la liste
    public void supprimer(String mot) {
        if (tete != null && tete.mot.equals(mot)) {
            tete = tete.suiv;   // Si le mot est dans le premier maillon, met à jour la tête de la liste
            return;
        }
        Maillon courant = tete;
        Maillon precedent = null;
        while (courant != null && !courant.mot.equals(mot)) {
            precedent = courant;
            courant = courant.suiv; // Parcourt la liste jusqu'à trouver le maillon contenant le mot
        }
        if (courant == null) {
            System.out.println("Mot non trouvé dans la liste.");
            return;
        }
        precedent.suiv = courant.suiv; // Relie le maillon précédent au maillon suivant pour supprimer le maillon courant
    }

    // Méthode pour afficher les n premiers mots de la liste
    public void premiers(int n) {
        Maillon temp = tete;
        while (temp != null && n > 0) {
            System.out.print(temp.mot + " "); // Affiche le mot du maillon courant
            temp = temp.suiv;   // Passe au maillon suivant
            n--;
        }
        System.out.println();
    }

    // Méthode pour supprimer les doublons de la liste
    public void purifie() {
        if (tete == null)
            return;

        Maillon courant = tete;
        while (courant != null) {
            Maillon compare = courant;
            while (compare.suiv != null) {
                if (courant.mot.equals(compare.suiv.mot)) {
                    compare.suiv = compare.suiv.suiv; // Supprime le maillon suivant s'il contient le même mot
                } else {
                    compare = compare.suiv; // Passe au maillon suivant
                }
            }
            courant = courant.suiv; // Passe au maillon suivant dans la liste
        }
    }

    // Méthode principale exécutant un exemple d'utilisation de la classe ListeChainee
    public static void main(String[] args) {
        ListeChainee liste = new ListeChainee();
        liste.ajouteFin("Bonjour");
        liste.ajouteFin("Bonjour");
        liste.ajouteFin("Monde");
        liste.ajouteFin("Bonjour");
        liste.ajouteFin("Monde");
        liste.ajouteFin("Bonjour");
        liste.ajouteFin("Monde");
        liste.ajouteFin("Bonjour");

        System.out.println("Liste initiale:");
        Maillon temp = liste.tete;
        while (temp != null) {
            System.out.print(temp.mot + " ");
            temp = temp.suiv;
        }
        System.out.println();

        System.out.println("Liste des n premiers termes:\n");
        liste.premiers(5);

        liste.purifie(); // Supprime les doublons de la liste

        System.out.println("Liste après purification:");
        temp = liste.tete;
        while (temp != null) {
            System.out.print(temp.mot + " ");
            temp = temp.suiv;
        }
        System.out.println();
    }
}
