# 💸 Finance — CS50 Final Project

## 📖 Overview
*Finance* is a Flask-based web application where users can simulate stock trading.  
It allows registering, logging in, “buying” and “selling” stocks, checking current prices via an API, and tracking portfolio history.  

This project demonstrates *web development, **database design, **user authentication, and **API integration* in Python/Flask.

---

## ✨ Features
- 🔐 *User Authentication* (Register, Login, Logout, Password Hashing with Werkzeug)
- 💹 *Quote Stocks*: search stock symbols in real time (API lookup)
- 🛒 *Buy/Sell Stocks*: manage virtual portfolio with account balance
- 📊 *Portfolio Overview*: current holdings, live prices, total value
- 📜 *Transaction History*: log of all buys and sells
- 💰 *Add Cash*: extra feature (if implemented) for depositing more balance
- 🖥 *Responsive UI* with Bootstrap

---

## 🗂 Project Structure

├── app.py          # Main Flask application ├── helpers.py      # Helper functions (apology, login_required, lookup, usd) ├── templates/      # Jinja2 HTML templates │   ├── layout.html │   ├── index.html │   ├── quote.html │   ├── buy.html │   ├── sell.html │   ├── history.html │   ├── login.html │   ├── register.html │   ├── apology.html │   └── ... ├── static/         # (optional) CSS/JS assets ├── finance.db      # SQLite3 database ├── requirements.txt └── README.md       # This file

---

## 🗄 Database Schema (SQLite3)
*Table: users*
- id (INTEGER, PK, autoincrement)  
- username (TEXT, UNIQUE, NOT NULL)  
- hash (TEXT, NOT NULL)  
- cash (REAL, DEFAULT 10000.00)  

*Table: transactions*
- id (INTEGER, PK)  
- user_id (INTEGER, FK → users.id)  
- symbol (TEXT, NOT NULL)  
- shares (INTEGER, NOT NULL, positive for buy, negative for sell)  
- price (REAL, NOT NULL, price per share at transaction)  
- timestamp (DATETIME, DEFAULT CURRENT_TIMESTAMP)  

---

## 🔑 Core Routes
| Route       | Method | Description |
|-------------|--------|-------------|
| /         | GET    | Portfolio overview (stocks owned, current price, value, cash, grand total) |
| /quote    | GET/POST | Lookup a stock price via API |
| /buy      | GET/POST | Buy shares (validate symbol, positive integer shares, sufficient cash) |
| /sell     | GET/POST | Sell shares (validate ownership, shares ≤ owned) |
| /history  | GET    | Transaction history |
| /register | GET/POST | Create new user |
| /login    | GET/POST | Log in existing user |
| /logout   | GET    | End session |

---

## 🚀 How to Run
1. *Install dependencies*
```bash
pip install -r requirements.txt

2. Set environment variable



export API_KEY=your_api_key_here

(API key from IEX Cloud or CS50 Finance)

3. Run the app



flask run

4. Open in browser:
👉 http://127.0.0.1:5000/




---

🧪 Testing

Register new user → check login + DB entry

Quote stocks (e.g., AAPL, TSLA) → verify prices appear

Buy shares → balance decreases, transaction logged

Sell shares → balance increases, transaction logged

History page shows correct logs (time + symbol + shares + price)

Edge cases:

Invalid symbols

Negative shares / zero shares

Insufficient balance

Selling more than owned




---

⚠ Common Pitfalls

Forgetting to round values with usd() (cents precision issues).

Not checking for invalid input (blank symbol, non-integer shares).

Cash not updating after buy/sell.

Portfolio not aggregating shares correctly (must SUM grouped by symbol).

API key not set → app crashes.



---

📦 Requirements

Python 3.10+

Flask

Flask-Session

Werkzeug

requests

SQLite3



---

📜 Example Screens

Index: Shows holdings, balance, grand total.

Quote: Lookup real-time stock price.

Buy: Purchase shares, error if insufficient cash.

Sell: Dropdown of owned stocks, choose shares to sell.

History: All transactions with timestamps.



---

✅ Checklist before submission

[ ] All routes implemented correctly

[ ] Templates extend layout.html

[ ] Cash updates correctly

[ ] Error handling with apology() everywhere needed

[ ] Passes check50 and submit50



---

👨‍💻 Author

Eyad Tamer
CS50 Finance Project
