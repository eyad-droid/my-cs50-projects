# 🧬 Inheritance — C

## 📖 Overview
This program (from CS50’s Problem Set) simulates the inheritance of blood types across generations.  
It uses recursion and structs in C to model family trees, where each person inherits one allele from each parent.  

---

## ⚙ Features
- Creates a family tree of a given number of generations  
- Randomly assigns alleles to the base generation (ancestors)  
- Inherits alleles recursively down to the youngest generation  
- Prints the full family tree with alleles assigned to each person  

---

## 📂 Project Structure

├── inheritance.c   # Main program ├── Makefile        # Compile rules └── README.md       # This file

---

## 🚀 Usage

1. *Compile*
```bash
make inheritance

2. Run



./inheritance

3. Example Output



Child (Generation 0): blood type AB
    Parent (Generation 1): blood type AO
        Grandparent (Generation 2): blood type AA
        Grandparent (Generation 2): blood type BO
    Parent (Generation 1): blood type BO
        Grandparent (Generation 2): blood type BB
        Grandparent (Generation 2): blood type OO


---

🧠 Key Concepts

Structs: used to represent each person and their alleles

Pointers: to link parents and children in the family tree

Recursion: generates the family tree and assigns alleles

Randomization: base alleles (for oldest generation) are randomly chosen from {A, B, O}



---

🧪 Notes

Default generations = 3 (but can be adjusted in code)

Always free allocated memory (use free() on family tree) to avoid leaks

Each run may produce different results due to randomness



---

🛠 Requirements

C compiler (clang or gcc)

CS50 library not required for this one



---

👨‍💻 Author

Eyad Tamer
