import java.util.Arrays;
import java.util.Scanner;

public class AdvancedColumnarTransposition {

    // Method to perform encryption using Advanced Columnar Transposition
    public static String encrypt(String text, String key) {
        int length = text.length();
        int rows = (int) Math.ceil((double) length / key.length());
        char[][] grid = new char[rows][key.length()];

        // Fill the grid with characters from the text
        int index = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < key.length(); j++) {
                if (index < length) {
                    grid[i][j] = text.charAt(index++);
                } else {
                    grid[i][j] = 'X'; // Padding character if needed
                }
            }
        }

        // Create a mapping of columns based on the key
        Integer[] order = new Integer[key.length()];
        for (int i = 0; i < key.length(); i++) {
            order[i] = i;
        }

        // Sort the columns based on the alphabetical order of the key
        Arrays.sort(order, (i, j) -> Character.compare(key.charAt(i), key.charAt(j)));

        // Read the columns in the new order to form the encrypted text
        StringBuilder encryptedText = new StringBuilder();
        for (int col : order) {
            for (int row = 0; row < rows; row++) {
                encryptedText.append(grid[row][col]);
            }
        }
        return encryptedText.toString();
    }

    // Method to perform decryption using Advanced Columnar Transposition
    public static String decrypt(String text, String key) {
        int length = text.length();
        int rows = (int) Math.ceil((double) length / key.length());
        char[][] grid = new char[rows][key.length()];

        // Create a mapping of columns based on the key
        Integer[] order = new Integer[key.length()];
        for (int i = 0; i < key.length(); i++) {
            order[i] = i;
        }

        // Sort the columns based on the alphabetical order of the key
        Arrays.sort(order, (i, j) -> Character.compare(key.charAt(i), key.charAt(j)));

        // Fill the grid with the text in the correct order of columns
        int index = 0;
        for (int col : order) {
            for (int row = 0; row < rows; row++) {
                if (index < length) {
                    grid[row][col] = text.charAt(index++);
                }
            }
        }

        // Read the grid row by row to form the decrypted text
        StringBuilder decryptedText = new StringBuilder();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < key.length(); j++) {
                decryptedText.append(grid[i][j]);
            }
        }

        return decryptedText.toString().replaceAll("X+$", ""); // Remove padding
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input the plaintext
        System.out.print("Enter plaintext: ");
        String text = sc.nextLine().replaceAll(" ", "");  // Remove spaces for encryption

        // Input the key (a string, not just a number)
        System.out.print("Enter key (string): ");
        String key = sc.nextLine();

        // Encryption
        String encryptedText = encrypt(text, key);
        System.out.println("Encrypted Text: " + encryptedText);

        // Decryption
        String decryptedText = decrypt(encryptedText, key);
        System.out.println("Decrypted Text: " + decryptedText);
    }
}
