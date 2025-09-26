# 💳 Credit — Python

A simple credit-card validator implemented in Python.  
The program validates card numbers using *Luhn’s algorithm* and identifies common card types (AMEX, MASTERCARD, VISA) or returns INVALID.

---

## 🔍 Overview
This project reads a credit-card number (as a string), verifies its checksum with Luhn’s algorithm, and determines the card network based on length and prefix rules.  
It is small, dependency-free, and great as a learning exercise for strings, algorithms, and basic testing.

---

## ✅ Features
- Validates credit-card numbers with *Luhn’s algorithm*.
- Detects card issuer types:
  - *AMEX* — 15 digits, starts with 34 or 37.
  - *MASTERCARD* — 16 digits, starts with 51–55 or ranges 2221–2720.
  - *VISA* — 13, 16, or 19 digits, starts with 4.
- Ignores spaces and hyphens in input.
- Returns INVALID for any non-digit input, failed checksum, or unknown pattern.
- Lightweight single-file implementation (no external libraries).

---

## 📁 Repository structure

├── credit.py        # Main script (validator + CLI) ├── tests/ │   └── test_credit.py  # Optional pytest tests ├── README.md └── LICENSE

---

## 🚀 Usage

1. Copy credit.py into your project folder.

2. Run from the command line:
```bash
python3 credit.py

3. Enter the card number when prompted:



Number: 4003600000000014
VISA


---

🧠 Implementation notes

Luhn’s algorithm: process digits from right to left. Double every second digit; if doubling gives a value > 9, subtract 9 (equivalent to summing digits). The number is valid if the total sum modulo 10 equals 0.

Normalization: input accepts digits, spaces, and hyphens; all non-digit characters are removed before validation.

Type detection occurs after successful Luhn validation to avoid misclassifying invalid numbers that match a prefix pattern.



---

📌 Example credit.py (reference)

> This is a minimal working example — use yours or adapt as needed.



# credit.py
def luhn_valid(card_number: str) -> bool:
    total = 0
    s = ''.join(ch for ch in card_number if ch.isdigit())[::-1]
    if not s:
        return False
    for i, ch in enumerate(s):
        d = int(ch)
        if i % 2 == 1:
            d = d * 2
            if d > 9:
                d -= 9
        total += d
    return total % 10 == 0

def card_type(card_number: str) -> str:
    s = ''.join(ch for ch in card_number if ch.isdigit())
    if not s or not luhn_valid(s):
        return "INVALID"
    length = len(s)
    if length == 15 and (s.startswith("34") or s.startswith("37")):
        return "AMEX"
    if length == 16:
        first_two = int(s[:2])
        first_four = int(s[:4])
        if 51 <= first_two <= 55 or 2221 <= first_four <= 2720:
            return "MASTERCARD"
    if length in (13, 16, 19) and s.startswith("4"):
        return "VISA"
    return "INVALID"

if _name_ == "_main_":
    try:
        card = input("Number: ").strip()
    except EOFError:
        exit()
    print(card_type(card))


---

🧪 Tests (suggested)

Create tests/test_credit.py and run with pytest. Example tests:

from credit import card_type

def test_visa():
    assert card_type("4003600000000014") == "VISA"

def test_amex():
    assert card_type("378282246310005") == "AMEX"

def test_mastercard():
    assert card_type("5105105105105100") == "MASTERCARD"

def test_invalid():
    assert card_type("1234567890") == "INVALID"

def test_spaces_and_hyphens():
    assert card_type("  4 003-6000-0000-014 ") == "VISA"

Run:

pip install pytest          # if not installed
pytest -q


---

⚠ Edge cases & validation tips

Reject empty input or strings with no digits.

Handle extremely long numeric strings cautiously (but Python supports big integers as strings).

Keep detection rules up-to-date if you need broader card network coverage (e.g., Discover, JCB).

Use unit tests to lock behavior and avoid regressions.



---

📦 Dependencies

Pure Python 3 — no external packages required.



---

📝 License

Choose a license (e.g., MIT) and include a LICENSE file if you plan to publish.


---

👨‍💻 Author

Eyad Tamer
