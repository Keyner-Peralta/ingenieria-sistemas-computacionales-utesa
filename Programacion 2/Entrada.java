import java.util.Scanner;

public class Entrada {
    public static void main(String[] args)
    {
        
        Scanner scanner = new Scanner(System.in);

        boolean continuar = true;
        while (continuar) {
            
            System.out.println("Ingresa tu nombre: ");
            String nombre = scanner.nextLine();
            System.out.println("Ingresa tu edad: ");
            int edad = scanner.nextInt();
            System.out.println("Tu nombre es: " + nombre + "\n" + "Tu edad es: " + edad);
            System.out.println("Desea continuar ejecutando el programa?");
           
            String respuesta = scanner.nextLine();
           
            if( respuesta.toLowerCase() == "no" )
            {
                continuar = false;
            }
        }
        scanner.close();
    }
}