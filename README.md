# 🧬 DNA — Python

## 📖 Overview
This program identifies individuals by analyzing their DNA sequences.  
It compares a given DNA sequence against a database of individuals and their Short Tandem Repeats (*STRs*) counts, then reports whose DNA (if any) matches.

This is part of the CS50 problem set for *Bioinformatics basics with Python*.

---

## ⚙ Features
- Reads a *CSV database* containing names and STR counts  
- Reads a *DNA sequence file* (text format)  
- Computes the *longest run* of each STR in the DNA sequence  
- Compares the computed STR profile against the database  
- Outputs the matching person’s name or "No match"

---

## 📂 Project Structure

├── dna.py         # Main program ├── databases/     # Example CSV files (small.csv, large.csv) ├── sequences/     # DNA sequence text files └── README.md      # Documentation

---

## 🚀 Usage

1. *Run the program with arguments:*
```bash
python dna.py databases/small.csv sequences/1.txt

2. Example



$ python dna.py databases/small.csv sequences/1.txt
Bob

If no profile matches:

No match


---

🧠 How It Works

1. Input handling: program expects two arguments → a CSV file and a DNA sequence file.


2. Database parsing: reads CSV into memory, storing names and STR counts.


3. Sequence analysis: for each STR in the database, finds the longest consecutive run inside the DNA sequence.


4. Matching: compares the resulting counts with each individual in the database.

If all STR counts match → print the person’s name

Otherwise → print "No match"





---

🧪 Example Data

Database (small.csv):

name,AGAT,AATG,TATC
Alice,2,8,3
Bob,4,1,5
Charlie,3,2,5

Sequence (1.txt):

AGATAGATAGATAATGTATCTATCTATC

Output:

Bob


---

⚠ Edge Cases

If file arguments are missing → program should exit with an error.

If multiple people partially match → no match should be printed.

Handle both small and large CSV databases.

Efficient string search is required since sequences can be very long.



---

🛠 Requirements

Python 3.x

CSV and file I/O modules (built-in)


Run with:

python dna.py database.csv sequence.txt


---

👨‍💻 Author

Eyad Tamer
