# 💳 Credit — C

## 📖 Overview
This program checks the validity of credit card numbers using *Luhn’s Algorithm* and identifies the card type (AMEX, MASTERCARD, VISA).  
It’s one of CS50’s problem sets that focuses on loops, conditions, and algorithmic thinking in C.

---

## ⚙ Features
- Implements *Luhn’s Algorithm* to validate credit card numbers  
- Detects card type:  
  - *AMEX* (15 digits, starts with 34 or 37)  
  - *MASTERCARD* (16 digits, starts with 51–55)  
  - *VISA* (13 or 16 digits, starts with 4)  
- Prints "INVALID" if the number doesn’t match any valid type  

---

## 📂 Project Structure

├── credit.c    # Main program ├── Makefile    # Compile rules └── README.md   # Documentation

---

## 🚀 Usage
1. *Compile*
```bash
make credit

2. Run



./credit

3. Example



Number: 4003600000000014
VISA

Number: 1234567890
INVALID


---

🧠 Key Concepts

Loops: iterate over digits from right to left

Conditionals: check card prefixes and lengths

Modulo / Division: extract digits from numbers

Algorithm: apply Luhn’s checksum formula



---

🛠 Requirements

C compiler (clang or gcc)

CS50 library (get_long for input)



---

👨‍💻 Author

Eyad Tamer
