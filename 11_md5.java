import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class App {
    public static void main(String[] args) {
        try {
            // Input text
            String inputText = "Hello, World!";
            
            // Create MessageDigest instance for MD5
            MessageDigest md = MessageDigest.getInstance("MD5");
            
            // Update the MessageDigest with the input bytes
            md.update(inputText.getBytes());
            
            // Calculate the digest (MD5 hash)
            byte[] digest = md.digest();
            
            // Convert the byte array to a hexadecimal string
            StringBuilder hexString = new StringBuilder();
            for (byte b : digest) {
                // Convert each byte to a two-digit hex value
                hexString.append(String.format("%02x", b));
            }
            
            // Output the MD5 hash
            System.out.println("MD5 Hash: " + hexString.toString());
        } catch (NoSuchAlgorithmException e) {
            System.err.println("MD5 algorithm not available.");
        }
    }
}
