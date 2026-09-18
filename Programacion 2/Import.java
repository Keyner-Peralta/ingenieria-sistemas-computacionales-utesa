import java.util.Scanner;

public class Import{
    public static void main()
    {
        Scanner sc = new Scanner(System.in);

        System.out.println("¿Cuál es tu edad?");
        System.out.print("Tu respuesta: ");
        int edad = sc.nextInt();

        if(edad >= 18)
        {
            System.out.println("Eres un adulto");
        }else{
            System.out.println("Eres un menor de edad");
        }
        
    }
}
