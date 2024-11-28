import org.opencv.core.*;
import org.opencv.imgcodecs.Imgcodecs;
import org.opencv.core.CvType;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;
import java.nio.file.Files;
import java.nio.file.Paths;

public class ImageEncryptDecrypt {

    public static void main(String[] args) {
        System.loadLibrary(Core.NATIVE_LIBRARY_NAME);

        try {
            // Load the image using OpenCV
            Mat image = Imgcodecs.imread("input_image.jpg");
            byte[] imageBytes = matToBytes(image);

            // Generate AES secret key
            SecretKey secretKey = generateAESKey();

            // Encrypt the image bytes
            byte[] encryptedImage = encryptImage(imageBytes, secretKey);
            Files.write(Paths.get("encrypted_image.dat"), encryptedImage);

            // Decrypt the image bytes
            byte[] decryptedImage = decryptImage(encryptedImage, secretKey);

            // Convert decrypted bytes back to image
            Mat decryptedMat = bytesToMat(decryptedImage);
            Imgcodecs.imwrite("decrypted_image.jpg", decryptedMat);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Convert OpenCV Mat to byte array
    public static byte[] matToBytes(Mat mat) {
        int size = (int) (mat.total() * mat.elemSize());
        byte[] data = new byte[size];
        mat.get(0, 0, data);
        return data;
    }

    // Convert byte array to OpenCV Mat
    public static Mat bytesToMat(byte[] data) {
        Mat mat = new Mat(1, data.length, CvType.CV_8U);
        mat.put(0, 0, data);
        return mat;
    }

    // Generate AES secret key
    public static SecretKey generateAESKey() throws Exception {
        KeyGenerator keyGenerator = KeyGenerator.getInstance("AES");
        keyGenerator.init(128);  // AES-128
        return keyGenerator.generateKey();
    }

    // Encrypt image bytes using AES
    public static byte[] encryptImage(byte[] imageBytes, SecretKey secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);
        return cipher.doFinal(imageBytes);
    }

    // Decrypt image bytes using AES
    public static byte[] decryptImage(byte[] encryptedImage, SecretKey secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        return cipher.doFinal(encryptedImage);
    }
}
