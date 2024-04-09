
public class MaillonListe {
    static Maillon premier = null;
    static Maillon dernier = null;

    public static void ajouterDevant(String s) {
        Maillon newMaillon = new Maillon(s);
        newMaillon.next = premier;
        if (premier != null) {
            premier.prev = newMaillon;
        }
        premier = newMaillon;
        if (dernier == null) {
            dernier = premier;
        }
    }

    public static Maillon ajouterDevant(Maillon premier, Maillon dernier, String s) {
        Maillon newMaillon = new Maillon(s);
        newMaillon.next = premier;
        if (premier != null) {
            premier.prev = newMaillon;
        }
        premier = newMaillon;
        if (dernier == null) {
            dernier = premier;
        }
        return premier;
    }

    public static Maillon supprimer(Maillon premier, Maillon dernier, String s) {
        Maillon current = premier;
        while (current != null) {
            if (current.value.equals(s)) {
                if (current.prev != null) {
                    current.prev.next = current.next;
                } else {
                    premier = current.next;
                }
                if (current.next != null) {
                    current.next.prev = current.prev;
                } else {
                    dernier = current.prev;
                }
                break;
            }
            current = current.next;
        }
        return premier;
    }

    public static void libererMemoire(Maillon premier) {
        Maillon current = premier;
        while (current != null) {
            Maillon temp = current;
            current = current.next;
            temp.next = null;
            temp.prev = null;
        }
    }

    public static void main(String[] args) {
        // Exemple d'utilisation :
        premier = ajouterDevant(premier, dernier, "E");
        premier = ajouterDevant(premier, dernier, "D");
        premier = ajouterDevant(premier, dernier, "C");
        premier = ajouterDevant(premier, dernier, "B");
        premier = ajouterDevant(premier, dernier, "A");

        // Affichez la liste avant la suppression
        Maillon current = premier;
        System.out.println("Liste avant toute suppression");
        while (current != null) {
            System.out.print(current.value);
            current = current.next;
        }
        System.out.println();

        // Supprimez "B" de la liste
        premier = supprimer(premier, dernier, "B");

        // Affichez la liste après la suppression
        System.out.println("Liste apres suppression de B");
        current = premier;
        while (current != null) {
            System.out.print(current.value);
            current = current.next;
        }
        System.out.println();

        libererMemoire(premier);
        System.out.println("Liberation de la memoire");
    }
}
