import java.util.Scanner;

public class HillCipher {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the key: ");
        String key = sc.nextLine();

        System.out.print("Enter the plaintext: ");
        String plaintext = sc.nextLine();

        // Pad the plaintext to be a multiple of the key length
        while (plaintext.length() % key.length() != 0) {
            plaintext += 'x';
        }

        // Convert the key to a matrix
        int[][] keyMatrix = new int[key.length()][key.length()];
        for (int i = 0; i < key.length(); i++) {
            for (int j = 0; j < key.length(); j++) {
                keyMatrix[i][j] = key.charAt(i) - 'a';
            }
        }

        // Encrypt the plaintext using the key
        StringBuilder ciphertext = new StringBuilder();
        for (int i = 0; i < plaintext.length(); i += key.length()) {
            int[] plaintextVector = new int[key.length()];
            for (int j = 0; j < key.length(); j++) {
                plaintextVector[j] = plaintext.charAt(i + j) - 'a';
            }
            int[] ciphertextVector = multiplyMatrixVector(keyMatrix, plaintextVector);
            for (int j = 0; j < key.length(); j++) {
                ciphertext.append((char) (ciphertextVector[j] + 'a'));
            }
        }

        // Print the ciphertext
        System.out.println("Ciphertext: " + ciphertext.toString());
    }

    private static int[] multiplyMatrixVector(int[][] matrix, int[] vector) {
        int[] result = new int[matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < vector.length; j++) {
                result[i] += matrix[i][j] * vector[j];
            }
            result[i] %= 26;
        }
        return result;
    }

}