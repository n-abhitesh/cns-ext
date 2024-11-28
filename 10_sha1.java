import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class App {
    public static void main(String[] args) {
        try {
            // Input text to hash
            String input = "Hello, world!";
            
            // Create MessageDigest instance for SHA-1
            MessageDigest digest = MessageDigest.getInstance("SHA-1");
            
            // Perform the hashing
            byte[] hashBytes = digest.digest(input.getBytes());
            
            // Convert byte array to hexadecimal format
            StringBuilder hexString = new StringBuilder();
            for (byte b : hashBytes) {
                hexString.append(String.format("%02x", b));
            }
            
            // Output the message digest
            System.out.println("SHA-1 Message Digest: " + hexString.toString());
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}
