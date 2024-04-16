// 1. Déclaration du type Maillon
// indice est un champ de type int qui stocke l'indice de la composante dans le vecteur d'origine.
//valeur est un champ de type float qui stocke la valeur de la composante.
//suivant est un champ de type Maillon qui stocke un pointeur vers le maillon suivant de la liste.
public class Maillon {
    private int indice;
    private float valeur;
    private Maillon suivant;

    public Maillon(int indice, float valeur) {
        this.indice = indice;
        this.valeur = valeur;
        this.suivant = null;
    }

    //2. Ecrire une fonction nouveau_maillon permettant de créer un nouveau maillon avec des
    //valeurs initiales fournies en arguments.
    //Cette fonction crée un nouveau maillon et l'initialise avec les valeurs indice et valeur fournies en arguments.
    //La fonction retourne un pointeur vers le nouveau maillon.
    public static Maillon nouveauMaillon(int indice, float valeur) {
        Maillon nouveau = new Maillon(indice, valeur);
        return nouveau;
    }

    //3. Ecrire une fonction PTR vecteur_creux (float t[ ], int n) qui prend un tableau t ayant n
    //éléments et construit sa représentation sous forme de vecteur creux.
    //Cette fonction parcourt le tableau t et pour chaque élément non nul, elle crée un nouveau maillon et l'ajoute à la liste.
    //La fonction retourne un pointeur vers le premier maillon de la liste (tête de la liste).
    public static Maillon vecteurCreux(float[] t, int n) {
        Maillon tete = null;
        Maillon p = null;
        for (int i = 0; i < n; i++) {
            if (t[i] != 0.0) {
                if (tete == null) {
                    tete = nouveauMaillon(i, t[i]);
                    p = tete;
                } else {
                    p.suivant = nouveauMaillon(i, t[i]);
                    p = p.suivant;
                }
            }
        }
        return tete;
    }


  //4. Ecrire une fonction PTR somme (PTR a, PTR b) qui reçoit deux vecteurs creux a et b et
  //retourne le vecteur creux qui représente leur somme 
    public static Maillon somme(Maillon a, Maillon b) {
        Maillon tete = null;
        Maillon p = a;
        Maillon q = b;
        Maillon dernier = null; // Pointeur vers le dernier maillon ajouté

        while (p != null && q != null) {
            if (p.indice == q.indice) {
                // Addition des valeurs
                float valeur = p.valeur + q.valeur;
                Maillon nouveau = nouveauMaillon(p.indice, valeur);
                if (tete == null) {
                    tete = nouveau;
                    dernier = tete;
                } else {
                    dernier.suivant = nouveau;
                    dernier = dernier.suivant;
                }
                p = p.suivant;
                q = q.suivant;
            } else if (p.indice < q.indice) {
                Maillon nouveau = nouveauMaillon(p.indice, p.valeur);
                if (tete == null) {
                    tete = nouveau;
                    dernier = tete;
                } else {
                    dernier.suivant = nouveau;
                    dernier = dernier.suivant;
                }
                p = p.suivant;
            } else {
                Maillon nouveau = nouveauMaillon(q.indice, q.valeur);
                if (tete == null) {
                    tete = nouveau;
                    dernier = tete;
                } else {
                    dernier.suivant = nouveau;
                    dernier = dernier.suivant;
                }
                q = q.suivant;
            }
        }

        // Ajouter les éléments restants de a et b
        while (p != null) {
            Maillon nouveau = nouveauMaillon(p.indice, p.valeur);
            if (tete == null) {
                tete = nouveau;
                dernier = tete;
            } else {
                dernier.suivant = nouveau;
                dernier = dernier.suivant;
            }
            p = p.suivant;
        }
        while (q != null) {
            Maillon nouveau = nouveauMaillon(q.indice, q.valeur);
            if (tete == null) {
                tete = nouveau;
                dernier = tete;
            } else {
                dernier.suivant = nouveau;
                dernier = dernier.suivant;
            }
            q = q.suivant;
        }

        return tete;
    }

    public static void main(String[] args) {
        // Test de la fonction nouveau_maillon
        Maillon m = nouveauMaillon(5, 3.14F);
        System.out.println("Nouveau maillon cree :");
        System.out.println(" " + m.getIndice() + " " + m.getValeur());

        // Test de la fonction vecteur_creux
        float[] t = {0, 2, 0, 5, 0, 7, 0, 3, 0, 0};
        int n = t.length;
        Maillon tete = vecteurCreux(t, n);
        if (tete == null) {
            System.out.println("Erreur de création du vecteur creux");
            return;
        } else {
            System.out.println("Vecteur creux cree :");
            Maillon p = tete;
            while (p != null) {
                System.out.print(" " + p.getIndice() + " " + p.getValeur() + "   ");
                p = p.suivant;
            }
            System.out.println();
        }

        //Test de la fonction somme vecteurs creux
        // Créer deux tableaux creux
        Maillon a = nouveauMaillon(1, 2.5F);
        a.suivant = nouveauMaillon(3, 1.0F);
        a.suivant.suivant = nouveauMaillon(4, 3.0F);

        Maillon b = nouveauMaillon(2, 1.5F);
        b.suivant = nouveauMaillon(3, 2.0F);
        b.suivant.suivant = nouveauMaillon(5, 4.0F);

        // Calculer la somme
        Maillon resultat = somme(a, b);
        System.out.println("La somme des vecteurs creux :");
        // Afficher le résultat
        while (resultat != null) {
            System.out.print(resultat.getIndice() + " " + resultat.getValeur() + "   ");
            resultat = resultat.suivant;
        }

    }

    public int getIndice() {
        return indice;
    }

    public void setIndice(int indice) {
        this.indice = indice;
    }

    public float getValeur() {
        return valeur;
    }

    public void setValeur(float valeur) {
        this.valeur = valeur;
    }

    public Maillon getSuivant() {
        return suivant;
    }

    public void setSuivant(Maillon suivant) {
        this.suivant = suivant;
    }

}

