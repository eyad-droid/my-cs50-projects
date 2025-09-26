💵 Cash — C

📖 Overview

Cash is a CS50 problem-set program written in C that calculates the minimum number of coins required to give a user change.
The program prompts the user for an amount of change (in dollars), converts it to cents, and uses a greedy algorithm with US coin denominations to return the fewest coins possible.


---

⚙ Features

Prompts for a non-negative amount of change (e.g., 0.41)

Converts dollars to cents safely (rounding to nearest cent)

Uses greedy algorithm with denominations: 25¢, 10¢, 5¢, 1¢

Outputs the minimum number of coins needed

Handles invalid inputs by reprompting (if using get_float)



---

📂 Project Structure

├── cash.c       # Main program
├── Makefile     # Compile rules (make cash)
└── README.md    # This file


---

🚀 Usage

1. Compile



make cash

2. Run



./cash

3. Example interaction



$ ./cash
Change owed: 0.41
4

(0.41 dollars → 41 cents → 1 quarter (25) + 1 dime (10) + 1 nickel (5) + 1 penny (1) = 4 coins)


---

🧠 Algorithm (brief)

1. Prompt user for a float amount d (dollars). Ensure d >= 0.


2. Convert to cents: cents = round(d * 100). Use round() to avoid floating-point errors.


3. Initialize coins = 0.


4. For each coin value in [25, 10, 5, 1]:

coins += cents / coin

cents = cents % coin



5. Print coins.



This greedy approach is optimal for standard U.S. coin denominations.


---

📊 Sample Runs

$ ./cash
Change owed: 0.01
1

$ ./cash
Change owed: 0.99
9

$ ./cash
Change owed: 0.00
0


---

⚠ Edge Cases & Tips

Always round after converting dollars to cents: int cents = (int) round(dollars * 100);

Avoid truncating floats directly (e.g., (int)(dollars * 100)) — that may cause off-by-one cent due to float precision.

Validate input: if using scanf or get_float, keep prompting while input is negative.

Test boundary values like 0.005, 0.001, and large amounts.



---

🛠 Requirements

C compiler (clang or gcc)

(Optional) CS50 library if you use get_float for input


Compile example without CS50:

gcc -o cash cash.c -lm

(if round() from <math.h> is used, link math library -lm.)


---

👨‍💻 Author

Eyad Tamer
