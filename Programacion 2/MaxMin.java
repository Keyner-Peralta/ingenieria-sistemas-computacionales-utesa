public class MaxMin {
    public static void main()
    {
        int[] numbers = {45, 12, 98, 33, 27};

        int max = numbers[0];
        int min = numbers[0];

        for(int num : numbers)
        {
            if(num > max)
            {
                max = num;
                continue;
            }
            else if (num < min) {
                min = num;
            }
        }
        System.out.println("El numero mas grande: " + max);
        System.out.println("El numero mas pequeño: " + min);
    }
}
