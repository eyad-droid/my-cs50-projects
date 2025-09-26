📝 Speller

📖 Overview

Speller is a CS50 problem set project that implements a spell checker.
It uses a hash table to store words from a dictionary and efficiently checks text files for misspellings.


---

⚙ Features

✅ Load words from a dictionary into memory

✅ Check if a word exists (case-insensitive)

✅ Report number of misspelled words

✅ Display performance statistics (load, check, size, unload)



---

📂 Project Structure

├── speller.c        # Main program logic  
├── dictionary.c     # Dictionary implementation (load, check, unload, size)  
├── dictionary.h     # Function prototypes  
├── Makefile         # Compilation instructions  
├── dictionaries/    # Sample dictionaries  
└── texts/           # Sample text files


---

🚀 Usage

1. Compile the program



make speller

2. Run with default dictionary



./speller texts/lalaland.txt

3. Run with custom dictionary



./speller dictionaries/large texts/lalaland.txt


---

📊 Sample Output

MISSPELLED WORDS

somthing  
wrng  
beleive  

WORDS MISSPELLED:     3  
WORDS IN DICTIONARY:  143091  
WORDS IN TEXT:        218  
TIME IN load:         0.05  
TIME IN check:        0.02  
TIME IN size:         0.00  
TIME IN unload:       0.01  
TIME IN TOTAL:        0.08


---

🛠 Requirements

C compiler (clang or gcc)

CS50 Library (provided by the course)



---

👨‍💻 Author

Eyad Tamer
