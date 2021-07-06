import java.util.*;
import java.security.*;

public class HashingSHA256 {
    public static void main(String[] args) throws NoSuchAlgorithmException{
        Scanner s = new Scanner(System.in);
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        md.reset();
        md.update(s.nextLine().getBytes());
        for(byte i : md.digest()){
            System.out.print(String.format("%02x", i));
        }
        System.out.println();
    }
}