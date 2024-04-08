import java.util.Arrays;
import java.lang.Math;

class Main {
    // Classe pour représenter une matrice carrée
    static class MATCARREE {
        
        int taille;
        int n = (int) Math.sqrt(taille);
        
        double[] coefficients;
        double [] [] tab = new double[n][n] ;

        MATCARREE(int taille, double[] coefficients) {
            this.taille = taille;
            this.coefficients = coefficients;
        }
    }

    // Fonction pour vérifier si une matrice carrée est symétrique
    static boolean symetrique(MATCARREE m) {
        for (int i = 0; i < m.taille; i++) {
            for (int j = 0; j < m.taille; j++) {
                if (m.coefficients[i * m.taille + j] != m.coefficients[j * m.taille + i]) {
                    return false; // Non symétrique
                }
            }
        }
        return true; // Symétrique
    }

    // Fonction pour calculer le nombre de nombres réels nécessaires pour représenter une matrice symétrique
    static int nombreNombresReels(int n) {
        return (n * (n + 1)) / 2; // Un seul triangle de la matrice est nécessaire
    }

    // Fonction pour construire la représentation compacte d'une matrice symétrique
    static double[] symCompacte(MATCARREE m) {
        if (!symetrique(m)) {
            return null; // Matrice non symétrique
        }
        double[] compacte = new double[nombreNombresReels(m.taille)];
        int k = 0;
        for (int i = 0; i < m.taille; i++) {
            for (int j = 0; j <= i; j++) {
                compacte[k++] = m.coefficients[i * m.taille + j];
            }
        }
        return compacte;
    }

    // Fonction pour accéder au coefficient (i, j) dans la représentation compacte
    static double acces(double[] c, int i, int j, int n) {
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
    static void traiterCoef(double x) {
        System.out.printf("%.2f ", x); // Exemple de traitement : affichage du coefficient
    }

    // Fonction pour traiter une ligne de la matrice symétrique
    static void traiterLigne(double[] c, int n, int i) {
        for (int j = 0; j <= i; j++) {
            traiterCoef(acces(c, i, j, n)); // Traitement de chaque coefficient de la ligne
        }
        System.out.println();
    }

    // Fonction pour afficher la matrice symétrique
    static void afficher(double[] c, int n) {
        for (int i = 0; i < n; i++) {
            traiterLigne(c, n, i); // Affichage de chaque ligne
        }
    }

    public static void main(String[] args) {
        // Exemple d'utilisation
        MATCARREE m = new MATCARREE(3, new double[]{1.0, 2.0, 3.0, 2.0, 4.0, 5.0, 3.0, 5.0, 6.0});
        if (symetrique(m)) {
            System.out.println("La matrice est symétrique");
            double[] compacte = symCompacte(m);
            if (compacte != null) {
                System.out.println("Représentation compacte :");
                afficher(compacte, m.taille); // Affichage de la représentation compacte
            } else {
                System.out.println("Erreur lors de la construction de la représentation compacte");
            }
        } else {
            System.out.println("La matrice n'est pas symétrique");
        }
    }
}
