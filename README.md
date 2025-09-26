🗳 Runoff

📖 Overview

Runoff is a CS50 problem set project that implements a ranked-choice voting system (instant-runoff voting).
Voters rank candidates in order of preference, and the program simulates rounds of voting until a winner is determined.


---

⚙ Features

✅ Accepts multiple candidates and voters

✅ Voters rank candidates by preference

✅ Simulates rounds of voting:

Tabulates votes for non-eliminated candidates

Eliminates candidates with the fewest votes

Continues until a candidate has majority support or a tie is declared


✅ Handles edge cases such as ties and majority wins



---

📂 Project Structure

├── runoff.c     # Main program logic  
└── Makefile     # Compilation instructions


---

🚀 Usage

1. Compile the program



make runoff

2. Run the election with candidates



./runoff Alice Bob Charlie

3. Enter number of voters and their ranked choices
The program will simulate the election and print the winner.




---

📊 Sample Output

Number of voters: 5

Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

...

Winner: Alice


---

🛠 Requirements

C compiler (clang or gcc)

CS50 Library (provided by the course)



---

👨‍💻 Author

Eyad Tamer
