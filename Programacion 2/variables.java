public class variables {
    public static void main(String[] args){
        //entero
        int edad = 18;
        System.out.println("Mi edad es: " + edad);
        //flotante
        float metros = 1.2356f;
        System.out.println("Metros recorridos: " + metros);
        //Decimal
        double money = 12.949505;
        System.out.println("Mi dinero es " + money);

        //Texto
        String persona1 = "Keyner";
        char primeraLetra = 'K';

        System.out.println("Mi nombre es: " + persona1 + "\nY Mi primera letra es " + primeraLetra);

        String palabra1 = "Vida", palabra2 = "dinero";
        System.out.println("La " + palabra1 + " es " + palabra2 );
        System.out.println("Concatenacion ".concat("desde un literal"));

        final double PI = 3.1416;
        System.out.println(PI);
    }
}