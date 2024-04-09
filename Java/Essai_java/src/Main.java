public class Main {
    public static void main(String[] args) {
    Polynome monPolynome = new Polynome();
    /*monPolynome.ajouterUnMonome(4,5);
    monPolynome.ajouterUnMonome(6,2);
    monPolynome.afficherCePolynome();
    monPolynome =DERIVEE(monPolynome);
    monPolynome.afficherCePolynome();
        monPolynome.ajouterUnMonome(2,1);
        monPolynome.ajouterUnMonome(-2,4);
        monPolynome.ajouterUnMonome(5,8);
        monPolynome.afficherCePolynome();
        Polynome derivee = new Polynome();
        derivee = DERIVEE(monPolynome);
        derivee.afficherCePolynome();*/
        monPolynome.ajouterUnMonome(-4,2);
        monPolynome.ajouterUnMonome(2,4);
        monPolynome.ajouterUnMonome(2,0);
        Polynome derivee = new Polynome();
        derivee = DERIVEE(monPolynome);
        monPolynome.afficherCePolynome();
        derivee.afficherCePolynome();




    }
    public static Polynome DERIVEE(Polynome P) {
        Polynome polynomeDerive = new Polynome();
        Monome monomeCourant = P.premierMonome;
        while (monomeCourant != null) {
            int coeff = monomeCourant.coefficients * monomeCourant.exposant;
            int expo = monomeCourant.exposant - 1;
            polynomeDerive.ajouterUnMonome(coeff, expo);
            monomeCourant = monomeCourant.suivant;
        }
        return polynomeDerive;
    }
    public static Polynome DERIVEEKIEME(Polynome P,int k){
        Polynome polynomeDerive = P;
        for (int i = 0; i < k; i++) {
            polynomeDerive = DERIVEE(polynomeDerive);
        }
        return  polynomeDerive;
    }
}