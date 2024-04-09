import java.util.Scanner;

// Définition de la classe pour un nœud de la liste chaînée
class NoeudListe {
    int val;
    NoeudListe prochain;

    // Constructeur
    public NoeudListe(int val) {
        this.val = val;
        this.prochain = null;
    }
}

// Définition de la classe pour la liste chaînée
class LinkedList {
    NoeudListe tete;

    // Constructeur
    public LinkedList() {
        this.tete = null;
    }

    // Méthode pour ajouter un élément à la fin de la liste
    public void add(int val) {
        NoeudListe newNode = new NoeudListe(val);
        if (tete == null) {
            tete = newNode;
            return;
        }
        NoeudListe current = tete;
        while (current.prochain != null) {
            current = current.prochain;
        }
        current.prochain = newNode;
    }

    // Méthode pour afficher la liste
    public void display() {
        NoeudListe current = tete;
        while (current != null) {
            System.out.print(current.val + " ");
            current = current.prochain;
        }
        System.out.println();
    }

    // Méthode pour tester l'égalité de deux listes
    public boolean isEqual(LinkedList other) {
        NoeudListe current1 = this.tete;
        NoeudListe current2 = other.tete;

        while (current1 != null && current2 != null) {
            if (current1.val != current2.val) {
                return false;
            }
            current1 = current1.prochain;
            current2 = current2.prochain;
        }

        return current1 == null && current2 == null;
    }

    // Méthode pour concaténer deux listes en créant une troisième liste
    public LinkedList concatenate(LinkedList list2) {
        LinkedList result = new LinkedList();
        NoeudListe current = this.tete;
        
        while (current != null) {
            result.add(current.val);
            current = current.prochain;
        }

        current = list2.tete;
        while (current != null) {
            result.add(current.val);
            current = current.prochain;
        }

        return result;
    }

    // Méthode pour concaténer deux listes sans créer une troisième liste
    public void concatenateInPlace(LinkedList list2) {
        NoeudListe current = this.tete;
        while (current.prochain != null) {
            current = current.prochain;
        }
        current.prochain = list2.tete;
    }
}

public class Concat {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Création de la première liste avec 10 valeurs saisies au clavier
        System.out.println("Entrez 10 valeurs pour la première liste:");
        LinkedList list1 = createList(scanner);

        // Création de la deuxième liste avec 10 valeurs saisies au clavier
        System.out.println("Entrez 10 valeurs pour la deuxième liste:");
        LinkedList list2 = createList(scanner);

        // Affichage des deux listes
        System.out.println("Première liste:");
        list1.display();
        System.out.println("Deuxième liste:");
        list2.display();

        // Test d'égalité des deux listes
        if (list1.isEqual(list2)) {
            System.out.println("Les deux listes sont égales.");
        } else {
            System.out.println("Les deux listes ne sont pas égales.");
        }

        // Concaténation des deux listes dans une troisième liste
        LinkedList concatenatedList = list1.concatenate(list2);
        System.out.println("Liste concaténée avec une troisième liste:");
        concatenatedList.display();

        // Concaténation des deux listes sans créer une troisième liste
        list1.concatenateInPlace(list2);
        System.out.println("Liste concaténée sans créer une troisième liste:");
        list1.display();
    }

    // Méthode pour créer une liste avec 10 valeurs saisies au clavier
    public static LinkedList createList(Scanner scanner) {
        LinkedList list = new LinkedList();
        for (int i = 0; i < 10; i++) {
            System.out.print("Entrez la valeur " + (i + 1) + ": ");
            int val = scanner.nextInt();
            list.add(val);
        }
        return list;
    }
}
