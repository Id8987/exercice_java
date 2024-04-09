public class Polynome {
    Monome premierMonome;

    public Polynome() {
        this.premierMonome = null;
    }

    //cette méthode ajoute un monome à la fin de la chaine du  polynome
    //on cherche donc la fin du polynome qui est le monome avec le suivant 'null'
    public void ajouterUnMonome(int coefficients, int exposant) {
        Monome CeMonome = new Monome(coefficients, exposant);
        if (premierMonome == null)
            premierMonome = CeMonome;
        else {
            Monome monomeCourant = null;
            monomeCourant = premierMonome;
            while (monomeCourant.suivant != null) {
                monomeCourant = monomeCourant.suivant;
            }
            monomeCourant.suivant = CeMonome;
        }

    }


    public void afficherCePolynome() {
        Monome monomeCourant = premierMonome;
        StringBuilder sb = new StringBuilder();
        boolean premier = true;
        while (monomeCourant != null) {
            int coeff = monomeCourant.coefficients;
            int expo = monomeCourant.exposant;
            if (coeff != 0) {
                if (!premier) {
                    if (coeff > 0) {
                        sb.append(" + ");
                    } else {
                        sb.append(" - ");
                        coeff = -coeff;
                    }
                } else {
                    premier = false;
                    if (coeff < 0) {
                        sb.append("-");
                        coeff = -coeff;
                    }
                }
                if (coeff != 1 || expo == 0) {
                    sb.append(coeff);
                }
                if (expo > 0) {
                    sb.append("x");
                    if (expo != 1) {
                        sb.append("^").append(expo);
                    }
                }
            }
            monomeCourant = monomeCourant.suivant;
        }
        if (sb.isEmpty()) {
            sb.append("0");
        }
        System.out.println(sb);
    }
}



  //méthode dérivée P' d'un polynome
    /*public Polynome DERIVEE(Polynome P){
      Polynome polynomeDerive = new Polynome();
      Monome MonomeCourant = P.premierMonome;
      while (MonomeCourant.suivant != null){
          int coeff = MonomeCourant.coefficients * MonomeCourant.exposant;
          int expo = MonomeCourant.exposant - 1 ;
          polynomeDerive.ajouterUnMonome(coeff,expo);
          MonomeCourant = MonomeCourant.suivant;

      }
      return polynomeDerive;
    }*/

