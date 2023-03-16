#include <iostream>
#include <string>
#include <vector>

using namespace std;

void encrypt(string plaintext, string key) {
    // Pad the plaintext to be a multiple of the key length
    while (plaintext.length() % key.length() != 0) {
        plaintext += 'x';
    }

    // Convert the key to a matrix
    int keyLength = key.length();
    vector<vector<int>> keyMatrix(keyLength, vector<int>(keyLength));
    for (int i = 0; i < keyLength; i++) {
        for (int j = 0; j < keyLength; j++) {
            keyMatrix[i][j] = key[i] - 'a';
        }
    }

    // Encrypt the plaintext using the key
    int plaintextLength = plaintext.length();
    string ciphertext;
    for (int i = 0; i < plaintextLength; i += keyLength) {
        vector<int> plaintextVector(keyLength);
        for (int j = 0; j < keyLength; j++) {
            plaintextVector[j] = plaintext[i + j] - 'a';
        }
        vector<int> ciphertextVector = multiplyMatrixVector(keyMatrix, plaintextVector);
        for (int j = 0; j < keyLength; j++) {
            ciphertext += (char) (ciphertextVector[j] + 'a');
        }
    }

    // Print the ciphertext
    cout << "Ciphertext: " << ciphertext << endl;
}

vector<int> multiplyMatrixVector(vector<vector<int>>& matrix, vector<int>& vector) {
    int matrixSize = matrix.size();
    vector<int> result(matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
        result[i] %= 26;
    }
    return result;
}

int main() {
    string key, plaintext;
    cout << "Enter the key: ";
    cin >> key;
    cout << "Enter the plaintext: ";
    cin >> plaintext;
    encrypt(plaintext, key);
    return 0;
}