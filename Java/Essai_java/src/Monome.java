public class Monome {
    int coefficients ;
    int exposant ;
    Monome suivant;

    public Monome(int coefficients,int exposant){
        this.coefficients = coefficients;
        this.exposant = exposant ;
        this.suivant = null;
    }
}
