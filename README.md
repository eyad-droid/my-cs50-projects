# Finance Problem Set – CS50 Web Programming

## 📌 Course Overview
This repository contains all the necessary materials and solutions for the *Finance Problem Set* from Harvard's *CS50 Web Programming Course*.  
The project simulates a real-world stock trading platform and reinforces key concepts in web development, database management, and user authentication, while also aligning with core finance concepts like valuation and portfolio management.

---

## 📂 Course Structure & Project Files
The repository is organized to cover both learning and practical implementation:

- *problems/* – PDF or Markdown documents with the problem statements.
- *solutions/* – Jupyter notebooks or Python scripts with detailed, commented solutions.
- *data/* – Required data files (e.g., .csv, .xlsx) used in the solutions.
- *project/* – Full CS50 Finance web application:
  - app.py – Main Flask application.
  - helpers.py – Helper functions (API requests, formatting, etc.).
  - finance.db – SQLite database.
  - templates/ – HTML templates for dynamic pages.
  - static/ – CSS and JavaScript files.
  - requirements.txt – Python dependencies.

---

## 🚀 Project Features
- *User Authentication:* Secure registration, login, and logout; password hashing implemented.
- *Stock Quotes:* Search for real-time stock prices using an external API.
- *Buy & Sell Stocks:* Execute trades with balance validation; updates portfolio dynamically.
- *Portfolio Management:* Displays all owned stocks, their quantity, current value, and total portfolio worth.
- *Transaction History:* Complete record of all trades with timestamps.
- *Cash Balance:* Users start with a virtual balance, updated automatically after transactions.

---

## 🛠 Technologies Used
- *Backend:* Python, Flask
- *Database:* SQLite
- *Frontend:* HTML, CSS, Bootstrap, Jinja2 templates
- *External API:* IEX API for stock prices
- *Tools:* VS Code, GitHub for version control

---

## 📖 Topics Covered
This problem set reinforces essential finance concepts, including:

- *Time Value of Money (TVM):* Present value, future value, annuities, perpetuities.
- *Capital Budgeting:* NPV, IRR, Payback Period.
- *Risk and Return:* Portfolio theory, CAPM, risk-adjusted returns.
- *Cost of Capital:* WACC, cost of equity, cost of debt.
- *Valuation:* DCF analysis, relative valuation.
- *Derivatives:* Introduction to options and futures.

---

## 📖 How the Application Works
1. Users *register* and *log in*.
2. Each user has a *starting virtual balance*.
3. Use the *Quote* feature to check stock prices.
4. *Buy and sell stocks*, updating portfolio and balance dynamically.
5. *Portfolio* page shows owned stocks, quantities, current prices, and total value.
6. *History* page records all transactions with timestamps.

---

## 🎯 Learning Outcomes
- Building a *full-stack web application* with Flask.
- Managing *relational databases* using SQLite.
- Integrating *external APIs* into web applications.
- Implementing *user authentication* and session management.
- Creating *dynamic and interactive web pages* using Jinja2 templates.
- Applying best practices in *code organization, modularity, and documentation*.

---

## 🙌 Acknowledgements
- Harvard CS50 Web Programming Course for guidance and starter code.
- The CS50 team for educational resources and support.
- Inspired by real-world stock trading platforms and finance principles.
