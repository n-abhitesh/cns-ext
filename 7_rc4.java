import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;
import java.security.Key;
import java.util.Base64;

public class App {
    
    // RC4 Encryption and Decryption
    public static String encryptRC4(String text, String secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("ARCFOUR");
        Key key = new SecretKeySpec(secretKey.getBytes(), "ARCFOUR");
        cipher.init(Cipher.ENCRYPT_MODE, key);

        byte[] encrypted = cipher.doFinal(text.getBytes());
        return Base64.getEncoder().encodeToString(encrypted);
    }

    public static String decryptRC4(String encryptedText, String secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("ARCFOUR");
        Key key = new SecretKeySpec(secretKey.getBytes(), "ARCFOUR");
        cipher.init(Cipher.DECRYPT_MODE, key);

        byte[] decoded = Base64.getDecoder().decode(encryptedText);
        byte[] decrypted = cipher.doFinal(decoded);
        return new String(decrypted);
    }



    public static void main(String[] args) {
        try {
            // RC4 Example
            String rc4Key = "myRC4Key12345"; // RC4 requires a lightweight key
            String plaintext = "Hello world";

            System.out.println("RC4 Encryption/Decryption:");
            String rc4Encrypted = encryptRC4(plaintext, rc4Key);
            System.out.println("Encrypted: " + rc4Encrypted);
            String rc4Decrypted = decryptRC4(rc4Encrypted, rc4Key);
            System.out.println("Decrypted: " + rc4Decrypted);


        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
