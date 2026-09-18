public class Arrays{
    public static void main()
    {
        //Arreglos en java
        String[] Grupo1 = {"Keyner", "Ana", "Pamela"};

        System.out.println("\tEstudiantes del Grupo 1");
        

        for(int i = 0; i < Grupo1.length; i++)
        {
            System.out.println((i+1) + ". estudiante: " + Grupo1[i]);
        }

        var marcas = new String[4];
        marcas[0] = "Volvo";
        marcas[1] = "Toyota";
        marcas[2] = "Nissan";
        marcas[3] = "Audi";

        for(var coche : marcas)
        {
            System.out.println("Marcas de carro: " + coche);
        }

        System.out.print("Calcular la suma del arreglo: {12,3,4,5} = ");
        int[] num = {12,3,4,5};

        int sum = 0;

        for (int number : num) {
            sum += number;
        }
        System.out.print(sum);

        System.out.println("Numeros pares e impares:");

        for(int i = 1; i <= 20; i++)
        System.out.println(  i + (( i % 2 == 0 ) ? " = par" : " = impar"));

        System.out.println("Arreglos multidimensionales:");
        String[][] Grupos = 
        {
            //Grupo 1
            {"Keyner", "Ana", "Juan"},
            //Grupo 2
            {"Pedro", "Angel", "Miriam"},
            //Grupo 3
            {"Marcos", "Alex", "Alexa"}
        };

        for(int filas = 0; filas < Grupos.length; filas++)
        {
            System.out.println("\tEstudiantes del Grupo " + (filas+1));
            for(int estudiante = 0; estudiante < Grupos[filas].length; estudiante++)
            {
                System.out.println((estudiante+1)+". "+Grupos[filas][estudiante]);
            }
        }
    }
}