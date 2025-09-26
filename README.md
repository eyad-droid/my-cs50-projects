# 🧠 Trivia — Web App

## 📖 Overview
*Trivia* is a lightweight quiz web application that serves multiple-choice questions to users, tracks scores, and supports timed quizzes, categories, and leaderboards.  
Designed as a small learning project or portfolio piece demonstrating frontend & backend integration, authentication, and simple game logic.

---

## ✨ Features
- User-friendly quiz interface with multiple-choice questions  
- Support for multiple categories and difficulty levels  
- Timed quizzes (optional per question or per quiz)  
- Score tracking and per-session results  
- Leaderboard to show top scores (global or per-category)  
- Admin or contributor interface to add/edit/delete questions (optional)  
- RESTful API endpoints for questions and submissions (optional)  
- Responsive UI (works on mobile & desktop)

---

## 🧭 Tech Stack (example)
- *Frontend:* HTML/CSS/JavaScript (Vanilla or React/Vue)  
- *Backend:* Python (Flask/FastAPI) or Node.js (Express)  
- *Database:* SQLite (dev) / PostgreSQL (prod)  
- *Auth:* Sessions or JWT (for API)  
- *Optional:* Docker for containerization

---

## 📂 Project Structure (example)

├── backend/ │   ├── app.py (or server.js) │   ├── models.py │   ├── routes/ │   └── migrations/ ├── frontend/ │   ├── index.html │   ├── assets/ │   └── src/ ├── data/ │   └── questions.csv (or JSON) ├── requirements.txt (or package.json) └── README.md

---

## 🗄 Data Model (simplified)
*Table: questions*
- id (PK)  
- category (TEXT)  
- difficulty (TEXT)  
- question (TEXT)  
- choice_a (TEXT)  
- choice_b (TEXT)  
- choice_c (TEXT)  
- choice_d (TEXT)  
- answer (CHAR) — e.g., 'A','B','C','D'  
- created_at (TIMESTAMP)

*Table: users*
- id, username, hash, created_at, etc.

*Table: results*
- id, user_id (nullable), score, total_questions, category, duration, created_at

---

## 🚀 Quick Start (example with Flask)

1. Clone repository:
```bash
git clone https://github.com/youruser/trivia.git
cd trivia

2. (Backend) Create venv & install:



python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt

3. Set environment variables (example):



export FLASK_APP=app
export FLASK_ENV=development
export DATABASE_URL=sqlite:///trivia.db

4. Initialize DB and seed questions:



flask db upgrade
python seed_questions.py  # optional script to import sample questions

5. Run backend:



flask run

6. Open frontend (if static) or run frontend dev server and point it to backend API.




---

🧩 API Endpoints (example)

Route	Method	Description

/api/categories	GET	List available categories
/api/questions?category=&difficulty=&n=	GET	Get n random questions matching filters
/api/submit	POST	Submit answers and get score ({answers: [...], user_id?, time_spent})
/api/leaderboard	GET	Top scores (global or by category)
/auth/register	POST	Register user
/auth/login	POST	Login user


Request/response examples should be documented in a separate API.md if the API is large.


---

🎮 Gameplay Flow (frontend)

1. User picks category & difficulty (or random).


2. Fetch n questions from backend.


3. Start timer (if timed).


4. User answers questions (instant feedback optional).


5. Submit answers → backend grades and returns score and breakdown.


6. Optionally record result in leaderboard and show review screen.




---

🧪 Testing

Unit tests for:

Question loading/parsing

Scoring logic and edge cases

Timer behavior (if implemented)

Auth workflows (register/login)


Integration tests:

Full quiz flow: request questions → submit answers → check saved result


Suggested tools: pytest (Python), jest (Node/React), or Cypress for E2E.



---

🔐 Security & Validation

Sanitize user input (especially question content and CSV/JSON imports).

Rate-limit API endpoints to prevent scraping or abuse.

For public leaderboards, avoid storing PII — store only usernames or display names.

Use hashed passwords (bcrypt or werkzeug.security).



---

💾 Seeding Questions

Provide a questions.csv or questions.json as sample dataset.

Example CSV columns:


category,difficulty,question,choice_a,choice_b,choice_c,choice_d,answer
General,Easy,"What is the capital of France?","Paris","London","Berlin","Rome","A"

Include a seed_questions.py script to import that file into the DB.



---

📦 Deployment

Use Docker for reproducible deploys (provide Dockerfile and docker-compose.yml).

Use managed DB (Postgres) for production.

Host backend on Render/Heroku/Vercel (serverless backend alternatives) and frontend on Netlify/GitHub Pages (if static SPA).

Configure env vars and secrets (do NOT commit API keys).



---

✅ Checklist before publishing

[ ] Seed data included and documented

[ ] API documented (endpoints & sample payloads)

[ ] Tests passing & CI configured (GitHub Actions)

[ ] Leaderboard privacy considerations handled

[ ] Responsive UI and mobile UX tested



---

👨‍💻 Author

Eyad Tamer
