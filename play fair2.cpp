#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void prepareKeyMatrix(char key[], char keyMatrix[SIZE][SIZE]) {
    int row, col, k = 0;
    int isPresent[26] = {0};

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (k < strlen(key)) {
                if (!isPresent[toupper(key[k]) - 'A']) {
                    keyMatrix[row][col] = toupper(key[k]);
                    isPresent[key[k] - 'A'] = 1;
                    k++;
                } else {
                    col--;
                }
            } else {
                for (int l = 0; l < 26; l++) {
                    if (!isPresent[l]) {
                        keyMatrix[row][col] = l + 'A';
                        isPresent[l] = 1;
                        break;
                    }
                }
            }
        }
    }
}

void findPosition(char keyMatrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J') 
        ch = 'I';

    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (keyMatrix[*row][*col] == ch) {
                return;
            }
        }
    }
}

void playfairEncrypt(char keyMatrix[SIZE][SIZE], char message[], char encryptedMessage[]) {
    int i, row1, col1, row2, col2;

    for (i = 0; i < strlen(message); i += 2) {
        findPosition(keyMatrix, message[i], &row1, &col1);
        findPosition(keyMatrix, message[i + 1], &row2, &col2);

        if (row1 == row2) {
            encryptedMessage[i] = keyMatrix[row1][(col1 + 1) % SIZE];
            encryptedMessage[i + 1] = keyMatrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            encryptedMessage[i] = keyMatrix[(row1 + 1) % SIZE][col1];
            encryptedMessage[i + 1] = keyMatrix[(row2 + 1) % SIZE][col2];
        } else {
            encryptedMessage[i] = keyMatrix[row1][col2];
            encryptedMessage[i + 1] = keyMatrix[row2][col1];
        }
    }
    encryptedMessage[i] = '\0';
}

void playfairDecrypt(char keyMatrix[SIZE][SIZE], char encryptedMessage[], char decryptedMessage[]) {
    int i, row1, col1, row2, col2;

    for (i = 0; i < strlen(encryptedMessage); i += 2) {
        findPosition(keyMatrix, encryptedMessage[i], &row1, &col1);
        findPosition(keyMatrix, encryptedMessage[i + 1], &row2, &col2);

        if (row1 == row2) {
            decryptedMessage[i] = keyMatrix[row1][(col1 + SIZE - 1) % SIZE];
            decryptedMessage[i + 1] = keyMatrix[row2][(col2 + SIZE - 1) % SIZE];
        } else if (col1 == col2) {
            decryptedMessage[i] = keyMatrix[(row1 + SIZE - 1) % SIZE][col1];
            decryptedMessage[i + 1] = keyMatrix[(row2 + SIZE - 1) % SIZE][col2];
        } else {
            decryptedMessage[i] = keyMatrix[row1][col2];
            decryptedMessage[i + 1] = keyMatrix[row2][col1];
        }
    }
    decryptedMessage[i] = '\0';
}

int main() {
    char key[26], message[100], encryptedMessage[100], decryptedMessage[100];
    char keyMatrix[SIZE][SIZE];

    printf("Enter the key (uppercase, no repeated letters, treat 'J' as 'I'): ");
    scanf("%s", key);

    printf("Enter the message to encrypt (uppercase, no spaces): ");
    scanf("%s", message);

    prepareKeyMatrix(key, keyMatrix);
    playfairEncrypt(keyMatrix, message, encryptedMessage);
    playfairDecrypt(keyMatrix, encryptedMessage, decryptedMessage);

    printf("Encrypted message: %s\n", encryptedMessage);
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}
