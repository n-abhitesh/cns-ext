import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.security.SecureRandom;
import java.util.Base64;

public class App {

    // Encrypts a plaintext message using the Rijndael (AES) algorithm
    public static String encrypt(String plainText, SecretKey secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encryptedBytes = cipher.doFinal(plainText.getBytes());
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }

    // Decrypts a ciphertext back into plaintext
    public static String decrypt(String cipherText, SecretKey secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] decryptedBytes = cipher.doFinal(Base64.getDecoder().decode(cipherText));
        return new String(decryptedBytes);
    }

    // Generates a secret key with a specified key size (128, 192, or 256 bits)
    public static SecretKey generateSecretKey(int keySize) throws Exception {
        KeyGenerator keyGen = KeyGenerator.getInstance("AES");
        keyGen.init(keySize, new SecureRandom());
        return keyGen.generateKey();
    }

    public static void main(String[] args) {
        try {
            // Define the key size (128, 192, or 256 bits)
            int keySize = 256;

            // Generate a secret key
            SecretKey secretKey = generateSecretKey(keySize);

            // Example plaintext
            String plainText = "This is a test message for Rijndael encryption.";

            // Encrypt the plaintext
            String encryptedText = encrypt(plainText, secretKey);
            System.out.println("Encrypted Text: " + encryptedText);

            // Decrypt the ciphertext
            String decryptedText = decrypt(encryptedText, secretKey);
            System.out.println("Decrypted Text: " + decryptedText);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
