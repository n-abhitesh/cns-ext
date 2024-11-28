import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;

public class App {
    public static void main(String[] args) throws Exception {
        String data = "SensitiveData";
        System.out.println("Original Data: " + data);

        // Generate a Blowfish key
        SecretKey secretKey = generateKey();

        // Encrypt the data
        String encryptedData = encrypt(data, secretKey);
        System.out.println("Encrypted Data: " + encryptedData);

        // Decrypt the data
        String decryptedData = decrypt(encryptedData, secretKey);
        System.out.println("Decrypted Data: " + decryptedData);
    }

    // Method to generate a secret key
    public static SecretKey generateKey() throws Exception {
        KeyGenerator keyGenerator = KeyGenerator.getInstance("Blowfish");
        keyGenerator.init(128); // Key size (128 bits)
        return keyGenerator.generateKey();
    }

    // Method to encrypt data
    public static String encrypt(String data, SecretKey secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("Blowfish");
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encryptedBytes = cipher.doFinal(data.getBytes());
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }

    // Method to decrypt data
    public static String decrypt(String encryptedData, SecretKey secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("Blowfish");
        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] decodedBytes = Base64.getDecoder().decode(encryptedData);
        byte[] decryptedBytes = cipher.doFinal(decodedBytes);
        return new String(decryptedBytes);
    }
}
