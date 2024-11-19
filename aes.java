public class AESKeyExpansion {
    
    // Predefined S-box values for specific hex values
    static final int[] sbox = new int[256];
    static {
        sbox[0x3A] = 0x80;
        sbox[0xF7] = 0x68;
        sbox[0xFA] = 0x2D;
        sbox[0xA0] = 0xE0;
    }

    // The second-round key as a 4x4 matrix
    static final int[][] secondRoundKey = {
        {0x56, 0xC7, 0x76, 0xA0},
        {0x08, 0x1A, 0x43, 0x3A},
        {0x20, 0xB1, 0x55, 0xF7},
        {0x07, 0x8F, 0x69, 0xFA}
    };

    // Round constant for the third round (0x04)
    static final int rcon = 0x04;

    public static void main(String[] args) {
        // Initialize the third round key array
        int[][] thirdRoundKey = new int[4][4];

        // Perform key expansion to generate the third-round key
        expandKey(secondRoundKey, thirdRoundKey);

        // Print the third-round key
        printKey(thirdRoundKey);
    }

    // Expands the key to generate the third-round key
    private static void expandKey(int[][] secondKey, int[][] thirdKey) {
        // Copy the second round key into the third round key
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                thirdKey[i][j] = secondKey[i][j];
            }
        }

        // Get the last column of the second round key
        int[] temp = { secondKey[0][3], secondKey[1][3], secondKey[2][3], secondKey[3][3] };

        // Perform the RotWord operation
        temp = rotWord(temp);

        // Perform the SubWord operation (substitute with S-box values)
        temp = subWord(temp);

        // XOR the first byte of the word with the round constant
        temp[0] ^= rcon;

        // First column of the third round key
        for (int i = 0; i < 4; i++) {
            thirdKey[i][0] ^= temp[i];
        }

        // Calculate the rest of the columns of the third round key
        for (int col = 1; col < 4; col++) {
            for (int row = 0; row < 4; row++) {
                thirdKey[row][col] ^= thirdKey[row][col - 1];
            }
        }
    }

    // Rotate the word (4 bytes) left by one byte
    private static int[] rotWord(int[] word) {
        int temp = word[0];
        word[0] = word[1];
        word[1] = word[2];
        word[2] = word[3];
        word[3] = temp;
        return word;
    }

    // Substitute each byte in the word using the S-box
    private static int[] subWord(int[] word) {
        for (int i = 0; i < 4; i++) {
            word[i] = sbox[word[i]]; // Use predefined S-box values
        }
        return word;
    }

    // Print the expanded key
    private static void printKey(int[][] key) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                System.out.printf("0x%02X ", key[i][j]);
            }
            System.out.println();
        }
    }
}