public class conversion {
    public static void main()
    {
        System.out.println("Conversión de tipos dentro de java");
        byte BYTE = 4;
        short SHORT = BYTE;
        int INT = SHORT;
        System.out.println(INT);
        byte conver  = (byte) INT;
        System.out.println(conver);
    }
}
