import java.util.Scanner;
import java.math.BigInteger;

public class BigIntegerI{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        BigInteger a = new BigInteger(s.nextLine());
        BigInteger b = new BigInteger(s.nextLine());
        System.out.println("Hello a = " + a);
        System.out.println("Hello b = " + b);
        System.out.println("Hello a + b = " + a.add(b));
        System.out.println("Hello a * b = " + a.multiply(b));

    }
}