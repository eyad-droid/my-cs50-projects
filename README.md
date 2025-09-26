# 🔡 Readability

## 📖 Overview  
Readability is a *CS50 problem set project* written in C that analyzes a block of text and outputs the approximate U.S. grade level needed to comprehend it.  
It computes the *Coleman–Liau index* based on counts of letters, words, and sentences.

---

## ⚙ Features  
- ✅ Counts letters, words, and sentences in input text  
- ✅ Computes the Coleman–Liau index:  
  - index = 0.0588 * L - 0.296 * S - 15.8  
    - where L = average letters per 100 words  
    - and S = average sentences per 100 words  
- ✅ Prints grade level (e.g., "Grade 8", "Before Grade 1", or "Grade 16+")

---

## 📂 Project Structure

├── readability.c   # Main program (counts and index calculation)
├── Makefile        # Compilation instructions
└── README.md       # This file

---

## 🚀 Usage  

1. *Compile the program*  
```bash
make readability

2. Run the program



./readability

3. Enter/paste the text when prompted (the program will read a line of text and output the grade).




---

🧮 Algorithm / Formula

1. Count total letters (A–Z, a–z).


2. Count total words (separated by spaces).


3. Count total sentences (punctuation: ., !, ?).


4. Compute:

L = (letters / words) * 100

S = (sentences / words) * 100

index = round(0.0588 * L - 0.296 * S - 15.8)



5. Output:

If index < 1 → Before Grade 1

If index >= 16 → Grade 16+

Else → Grade X





---

📊 Sample Interaction

$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3


---

🛠 Requirements

C compiler (clang or gcc)

CS50 Library (if you used it for get_string) — otherwise standard C I/O works



---

👨‍💻 Author

Eyad Tamer
