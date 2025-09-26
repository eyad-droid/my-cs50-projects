# 🔐 Caesar Cipher — C

## 📖 Overview
This program encrypts text using the *Caesar cipher*, one of the simplest classical encryption techniques.  
It shifts each alphabetical character in the plaintext by a key value (an integer), wrapping around the alphabet if necessary.

This is part of the CS50 problem sets to practice working with strings, command-line arguments, and ASCII manipulation in C.

---

## ⚙ Features
- Accepts a *command-line argument* (the key, as a non-negative integer)  
- Prompts the user for plaintext  
- Shifts each alphabetical character by the key value  
- Preserves case (uppercase and lowercase)  
- Leaves non-alphabetical characters unchanged  
- Outputs the resulting ciphertext  

---

## 📂 Project Structure

├── caesar.c      # Main program ├── Makefile      # Compile rules └── README.md     # Documentation

---

## 🚀 Usage

1. *Compile*
```bash
make caesar

2. Run



./caesar KEY

Where KEY is a non-negative integer.

3. Example



$ ./caesar 13
plaintext:  Hello, World!
ciphertext: Uryyb, Jbeyq!


---

🧠 How It Works

1. Takes the command-line argument KEY and ensures it is numeric.


2. Prompts the user for a string (plaintext).


3. For each character:

If it’s alphabetical → shift by KEY % 26 positions.

If uppercase → wrap around within A–Z.

If lowercase → wrap around within a–z.

Otherwise → leave unchanged.



4. Prints the resulting ciphertext.




---

⚠ Example Runs

$ ./caesar 1
plaintext:  abcXYZ
ciphertext: bcdYZA

$ ./caesar 0
plaintext:  hello
ciphertext: hello

$ ./caesar 27
plaintext:  CS50
ciphertext: DT50


---

🛠 Requirements

C compiler (clang or gcc)

CS50 library (for get_string)


Compile example:

gcc -o caesar caesar.c -lcs50


---

👨‍💻 Author

Eyad Tamer
