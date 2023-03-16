import numpy as np

def encrypt(plain_text, key):
    # Pad plain_text to be a multiple of the key length
    while len(plain_text) % len(key) != 0:
        plain_text += 'x'

    # Convert plain_text and key to matrices
    plain_text_matrix = np.array([ord(c) - ord('a') for c in plain_text]).reshape(-1, len(key))
    key_matrix = np.array([ord(c) - ord('a') for c in key]).reshape(len(key), -1)

    # Encrypt plain_text using the key
    encrypted_matrix = np.dot(plain_text_matrix, key_matrix) % 26

    # Convert encrypted_matrix back to a string
    encrypted_text = ''.join([chr(c + ord('a')) for c in encrypted_matrix.flatten()])

    return encrypted_text

# Get key and plaintext inputs from user
key = input("Enter the key: ")
plain_text = input("Enter the plaintext: ")

# Encrypt the plaintext using the key
cipher_text = encrypt(plain_text, key)

# Print the cipher text
print("Cipher text:", cipher_text)