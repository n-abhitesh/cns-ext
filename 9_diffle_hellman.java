import java.math.BigInteger;
import java.security.SecureRandom;

public class DiffieHellman {

    // Generate a large prime number and a primitive root modulo prime
    public static BigInteger generatePrime(int bitLength) {
        SecureRandom rand = new SecureRandom();
        BigInteger prime = BigInteger.probablePrime(bitLength, rand);
        return prime;
    }

    // Generate public and private keys
    public static BigInteger[] generateKeys(BigInteger prime, BigInteger generator) {
        SecureRandom rand = new SecureRandom();
        BigInteger privateKey = new BigInteger(prime.bitLength(), rand);
        BigInteger publicKey = generator.modPow(privateKey, prime);
        return new BigInteger[]{privateKey, publicKey};
    }

    // Compute shared secret
    public static BigInteger computeSharedSecret(BigInteger otherPublicKey, BigInteger privateKey, BigInteger prime) {
        return otherPublicKey.modPow(privateKey, prime);
    }

    public static void main(String[] args) {
        // Step 1: Generate a large prime number and a primitive root
        int bitLength = 512; // 512-bit prime
        BigInteger prime = generatePrime(bitLength);
        BigInteger generator = BigInteger.valueOf(2); // Commonly used generator

        System.out.println("Prime: " + prime);
        System.out.println("Generator: " + generator);

        // Step 2: Generate public and private keys for Alice
        BigInteger[] aliceKeys = generateKeys(prime, generator);
        BigInteger alicePrivateKey = aliceKeys[0];
        BigInteger alicePublicKey = aliceKeys[1];

        // Step 3: Generate public and private keys for Bob
        BigInteger[] bobKeys = generateKeys(prime, generator);
        BigInteger bobPrivateKey = bobKeys[0];
        BigInteger bobPublicKey = bobKeys[1];

        System.out.println("\nAlice's Public Key: " + alicePublicKey);
        System.out.println("Bob's Public Key: " + bobPublicKey);

        // Step 4: Compute shared secret
        BigInteger aliceSharedSecret = computeSharedSecret(bobPublicKey, alicePrivateKey, prime);
        BigInteger bobSharedSecret = computeSharedSecret(alicePublicKey, bobPrivateKey, prime);

        System.out.println("\nAlice's Shared Secret: " + aliceSharedSecret);
        System.out.println("Bob's Shared Secret: " + bobSharedSecret);

        // Step 5: Verify that both shared secrets match
        if (aliceSharedSecret.equals(bobSharedSecret)) {
            System.out.println("\nThe shared secrets match! Key exchange successful.");
        } else {
            System.out.println("\nThe shared secrets do not match! Key exchange failed.");
        }
    }
}
