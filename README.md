# 🗳 Plurality

## 📖 Overview  
Plurality is a *CS50 problem set project* written in C that simulates a simple plurality voting system.  
Each voter votes for a single candidate; the candidate(s) with the most votes win.

---

## ⚙ Features  
- ✅ Accepts a list of candidates via command-line arguments  
- ✅ Accepts votes from voters (by candidate name)  
- ✅ Tallies votes and handles invalid votes gracefully  
- ✅ Prints winner(s) (handles ties by printing all winners)

---

## 📂 Project Structure

├── plurality.c   # Main program (vote counting logic)
├── Makefile      # Compilation instructions
└── README.md     # This file

---

## 🚀 Usage  

1. *Compile the program*  
```bash
make plurality

2. Run with candidates



./plurality Alice Bob Charlie

3. Follow prompts



Enter number of voters.

For each voter, type the name of the candidate they vote for.

The program will tally and print the winner(s).



---

🧠 Algorithm / Behavior

1. Initialize each candidate's vote count to 0.


2. For each voter:

Read the vote (string).

If the name matches a candidate, increment that candidate's vote count.

Otherwise, print/handle Invalid vote. and ignore it.



3. After all votes, determine the highest vote count.


4. Print every candidate whose vote count equals the highest (one or more — ties allowed).




---

📊 Sample Interaction

$ ./plurality Alice Bob Charlie
Number of voters: 5
Vote: Alice
Vote: Bob
Vote: Charlie
Vote: Alice
Vote: Bob

Alice
Bob

(Here Alice and Bob tied with the highest votes — both printed.)


---

🛠 Requirements

C compiler (clang or gcc)

CS50 Library (optional — if you used get_string or get_int)



---

👨‍💻 Author

Eyad Tamer
