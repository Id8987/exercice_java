class Noeud {
    int valeur;
    Noeud gauche;
    Noeud droite;

    public Noeud(int valeur) {
        this.valeur = valeur;
    }
}

public class ArbreBinaire {
    static Noeud racine = null;

    public static void feuille(Noeud A) {
        if (A != null) {
            if (A.gauche == null && A.droite == null) {
                System.out.println(A.valeur); // Affiche l'étiquette de la feuille
            }
            feuille(A.gauche); // Parcours récursif à gauche
            feuille(A.droite); // Parcours récursif à droite
        }
    }

    public static void degre(Noeud A) {
        if (A != null) {
            int degre = 0;
            if (A.gauche != null)
                degre++;
            if (A.droite != null)
                degre++;
            System.out.println("Noeud " + A.valeur + " : Degré " + degre);
            degre(A.gauche); // Parcours récursif à gauche
            degre(A.droite); // Parcours récursif à droite
        }
    }

    public static int profondeur(Noeud A, int x, int profondeurActuelle) {
        if (A != null) {
            if (A.valeur == x) {
                return profondeurActuelle;
            }
            int profondeurGauche = profondeur(A.gauche, x, profondeurActuelle + 1);
            int profondeurDroite = profondeur(A.droite, x, profondeurActuelle + 1);
            if (profondeurGauche != -1) {
                return profondeurGauche;
            } else {
                return profondeurDroite;
            }
        }
        return -1; // Nœud x non trouvé
    }

    public static int hauteur(Noeud A) {
        if (A == null) {
            return -1; // Arbre vide
        } else {
            int hauteurGauche = hauteur(A.gauche);
            int hauteurDroite = hauteur(A.droite);
            if (hauteurGauche > hauteurDroite) {
                return 1 + hauteurGauche;
            } else {
                return 1 + hauteurDroite;
            }
        }
    }

    public static int sommeNoeuds(Noeud A) {
        if (A == null) {
            return 0;
        } else {
            int sommeGauche = sommeNoeuds(A.gauche);
            int sommeDroite = sommeNoeuds(A.droite);
            return A.valeur + sommeGauche + sommeDroite;
        }
    }

    public static void main(String[] args) {
        // Exemple d'utilisation :
        Noeud A = new Noeud(2); // Créez un arbre binaire d'exemple (vous pouvez ajouter des nœuds)
        A.gauche = new Noeud(3);
        A.gauche.gauche = new Noeud(5);
        A.gauche.droite = new Noeud(7);
        A.droite = new Noeud(11);
        A.droite.gauche = new Noeud(13);
        A.droite.droite = new Noeud(17);

        // Affichez les étiquettes des feuilles
        System.out.println("Étiquettes des feuilles de l'arbre :");
        feuille(A);

        // Affichez les nœuds et leurs degrés
        System.out.println("Nœuds et leurs degrés :");
        degre(A);

        int x = 13; // Valeur du nœud x dont nous voulons trouver la profondeur
        int profondeur = profondeur(A, x, 0);

        if (profondeur != -1) {
            System.out.println("La profondeur du nœud " + x + " dans l'arbre est : " + profondeur);
        } else {
            System.out.println("Le nœud " + x + " n'a pas été trouvé dans l'arbre.");
        }

        System.out.println("La hauteur de l'arbre est : " + hauteur(A));

        System.out.println("La somme des nœuds de l'arbre est : " + sommeNoeuds(A));
    }
}
