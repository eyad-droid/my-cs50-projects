Speller
📖 Description
This project is part of the CS50 Problem Sets, implementing a dictionary’s functionality for a spell-checker program.
It loads words from a dictionary into a hash table, checks words in a text for correctness, and reports misspelled words, along with performance statistics.
⚙ Features
• Loads dictionary words into memory using a hash table.
• Checks if a word exists in the dictionary (case-insensitive).
• Reports the number of misspelled words.
• Provides statistics about time spent in different operations: 
• Loading dictionary
• Checking words
• Determining dictionary size
• Unloading dictionary
📂 File Structure
• speller.c → Main program logic.
• dictionary.c → Implements dictionary functions (load, check, unload, size).
• dictionary.h → Header file with function prototypes.
• Makefile → Compilation instructions.
• dictionaries/ → Contains sample dictionary files.
• texts/ → Contains sample texts to test the program.
🚀 How to Run
• Compile the program: make speller 
• Run the spell checker with a text: ./speller texts/lalaland.txt Or specify a custom dictionary: ./speller dictionaries/large texts/lalaland.txt 
🛠 Requirements
• C compiler (e.g., clang or gcc)
• CS50 Library (provided in the course)
📊 Example Output
MISSPELLED WORDS somthing wrng beleive WORDS MISSPELLED: 3 WORDS IN DICTIONARY: 143091 WORDS IN TEXT: 218 TIME IN load: 0.05 TIME IN check: 0.02 TIME IN size: 0.00 TIME IN unload: 0.01 TIME IN TOTAL: 0.08 
👨‍💻 Author
• Eyad Tamer
