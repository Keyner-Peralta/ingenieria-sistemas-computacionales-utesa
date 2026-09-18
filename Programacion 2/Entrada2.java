import java.util.Scanner;

public class Entrada2 {
    public static void main()
    {
        var scan = new Scanner(System.in);
        System.out.print("Dime el numero que deseas encontrar dentro de los aleatorios 0 - 100:");
        int miNumero = scan.nextInt();

        int sum;

        for(;;)
        {
            sum = (int)(Math.random() * 101);
            if(sum == miNumero)
            {
                System.out.println("ENCONTRADO:\t" + sum);
                break;
            }

            System.out.println(sum);
        }

        scan.close();
    }
}
