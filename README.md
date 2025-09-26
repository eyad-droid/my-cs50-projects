# 🎬 Movies-SQL

## 📖 Overview
*Movies-SQL* is a relational database project that models a movie ecosystem: movies, people (actors/directors), genres, ratings, and user reviews.  
This project includes a normalized schema, sample data, and SQL queries (basic → advanced) to demonstrate common real-world operations such as searching, aggregation, recommendations, and analytics.

---

## ⚙ Features
- ✅ Normalized relational schema (movies, people, roles, genres, users, ratings)
- ✅ Sample CREATE TABLE scripts for PostgreSQL / SQLite
- ✅ Seed data examples and CSV import suggestions
- ✅ Common queries: search by title/actor/genre, top-rated movies, recent popular movies
- ✅ Advanced queries: window functions, recommendations, full-text search tips
- ✅ Indexing & optimization recommendations
- ✅ Test cases and expected outputs for verification

---

## 📂 Project Structure

├── sql/ │   ├── create_tables.sql      # Schema creation (Postgres / SQLite) │   ├── seed_data.sql          # Sample INSERTs │   ├── sample_queries.sql     # Basic + advanced queries │   └── test_queries.sql       # Queries used for testing ├── data/ │   ├── movies.csv │   ├── people.csv │   ├── movie_genres.csv │   └── ratings.csv └── README.md                  # This file

---

## 🧱 Schema (core tables)

```sql
-- movies
movies (
  id SERIAL PRIMARY KEY,
  title TEXT NOT NULL,
  year INT,
  runtime_minutes INT,
  description TEXT,
  language VARCHAR(50),
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- people (actors, directors, writers)
people (
  id SERIAL PRIMARY KEY,
  name TEXT NOT NULL,
  birth_year INT,
  country VARCHAR(100)
);

-- movie_genres (many-to-many)
genres (
  id SERIAL PRIMARY KEY,
  name VARCHAR(50) UNIQUE
);

movie_genres (
  movie_id INT REFERENCES movies(id) ON DELETE CASCADE,
  genre_id INT REFERENCES genres(id) ON DELETE CASCADE,
  PRIMARY KEY (movie_id, genre_id)
);

-- roles (cast + crew)
roles (
  id SERIAL PRIMARY KEY,
  movie_id INT REFERENCES movies(id) ON DELETE CASCADE,
  person_id INT REFERENCES people(id) ON DELETE CASCADE,
  role_type VARCHAR(20), -- 'actor', 'director', 'writer'
  character_name TEXT     -- nullable (for actors)
);

-- users and ratings
users (
  id SERIAL PRIMARY KEY,
  username VARCHAR(50) UNIQUE NOT NULL,
  email VARCHAR(255) UNIQUE,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

ratings (
  id SERIAL PRIMARY KEY,
  user_id INT REFERENCES users(id) ON DELETE CASCADE,
  movie_id INT REFERENCES movies(id) ON DELETE CASCADE,
  rating SMALLINT CHECK (rating >= 1 AND rating <= 10),
  review TEXT,
  rated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  UNIQUE(user_id, movie_id)
);


---

🧭 ER Diagram (ASCII)

people 1---* roles ---1 movies *--- movie_genres *---1 genres
users 1---* ratings *---1 movies


---

🚀 Quick Start (PostgreSQL)

1. Create DB and user (example):



createdb movies_db
psql movies_db

2. Run schema:



\i sql/create_tables.sql

3. Seed sample data:



\i sql/seed_data.sql

4. Run sample queries:



\i sql/sample_queries.sql

(If using SQLite, adapt SERIAL → INTEGER PRIMARY KEY AUTOINCREMENT, and adjust timestamp defaults.)


---

🔍 Useful Sample Queries

Basic: Top 10 highest-rated movies (by average rating)

SELECT m.id, m.title, m.year, ROUND(AVG(r.rating)::numeric,2) AS avg_rating, COUNT(r.*) AS votes
FROM movies m
JOIN ratings r ON r.movie_id = m.id
GROUP BY m.id
HAVING COUNT(r.*) >= 5
ORDER BY avg_rating DESC, votes DESC
LIMIT 10;

Search by actor name

SELECT DISTINCT m.id, m.title, m.year
FROM movies m
JOIN roles ro ON ro.movie_id = m.id AND ro.role_type = 'actor'
JOIN people p ON p.id = ro.person_id
WHERE p.name ILIKE '%tom hanks%';

Movies and their genres (comma-separated)

SELECT m.id, m.title, STRING_AGG(g.name, ', ' ORDER BY g.name) AS genres
FROM movies m
JOIN movie_genres mg ON mg.movie_id = m.id
JOIN genres g ON g.id = mg.genre_id
GROUP BY m.id;

Recent popular movies (last year most rated)

SELECT m.id, m.title, COUNT(r.*) AS ratings_count
FROM movies m
JOIN ratings r ON r.movie_id = m.id
WHERE r.rated_at >= NOW() - INTERVAL '1 year'
GROUP BY m.id
ORDER BY ratings_count DESC
LIMIT 10;

Advanced: Recommend movies based on user’s top genres

WITH user_top_genres AS (
  SELECT g.id AS genre_id, g.name, COUNT(*) AS cnt
  FROM ratings r
  JOIN movies m ON m.id = r.movie_id
  JOIN movie_genres mg ON mg.movie_id = m.id
  JOIN genres g ON g.id = mg.genre_id
  WHERE r.user_id = $USER_ID AND r.rating >= 8
  GROUP BY g.id
  ORDER BY cnt DESC
  LIMIT 3
)
SELECT DISTINCT m.id, m.title, ROUND(AVG(r.rating)::numeric,2) as avg_rating
FROM movies m
JOIN movie_genres mg ON mg.movie_id = m.id
JOIN user_top_genres utg ON utg.genre_id = mg.genre_id
LEFT JOIN ratings r ON r.movie_id = m.id
WHERE m.id NOT IN (
  SELECT movie_id FROM ratings WHERE user_id = $USER_ID
)
GROUP BY m.id
ORDER BY avg_rating DESC
LIMIT 10;


---

⚙ Indexing & Performance Tips

Add indexes on:

movies(title) for searches (or use full-text search)

people(name) for actor/director lookup

ratings(movie_id) and ratings(user_id) for aggregation

movie_genres(movie_id) and movie_genres(genre_id) for joins


Use EXPLAIN ANALYZE to check slow queries.

For text search, consider PostgreSQL full-text search (tsvector) or PG Trigram extension for fuzzy matches.

Maintain COUNT caches for very large datasets (materialized views) if needed.



---

✅ Edge Cases & Validation

Enforce UNIQUE(user_id, movie_id) in ratings so a user can't rate same movie twice.

Validate rating range using CHECK.

Use transactions when performing multi-step inserts (e.g., insert movie + genres + roles).

Handle NULL character_name for non-actor roles.



---

🧪 Testing (sample checks)

1. Run sample queries in sql/test_queries.sql.


2. Check that:

Top-rated list returns expected movie titles from seed.

A user cannot insert two ratings for same movie (expect constraint error).

Search by partial actor name returns expected movies.




Example test query:

-- Expect: 'Forrest Gump' appears when searching 'tom hanks'
SELECT m.title
FROM movies m
JOIN roles ro ON ro.movie_id = m.id
JOIN people p ON p.id = ro.person_id
WHERE p.name ILIKE '%tom hanks%';


---

🧾 Sample Seed (example)

INSERT INTO movies (title, year, runtime_minutes, description) VALUES
('The Example', 1994, 142, 'An example movie for tests.');

INSERT INTO people (name, birth_year) VALUES ('Tom Hanks', 1956), ('Jane Doe', 1980);

INSERT INTO genres (name) VALUES ('Drama'), ('Comedy');

-- Link movie & genre
INSERT INTO movie_genres (movie_id, genre_id) VALUES (1, 1);

-- Roles
INSERT INTO roles (movie_id, person_id, role_type, character_name) VALUES (1, 1, 'actor', 'Forrest G.');

-- Users + ratings
INSERT INTO users (username, email) VALUES ('eyadt', 'eyad@example.com');
INSERT INTO ratings (user_id, movie_id, rating, review) VALUES (1, 1, 9, 'Amazing!');


---

🔐 Security & Best Practices

Sanitize user input in any app layer (avoid SQL injection).

Use prepared statements / parameterized queries from application code.

Limit privileges: app user should not be a DB superuser.

Back up your DB regularly and test restores.



---

🛠 Requirements

PostgreSQL 12+ (recommended) or SQLite (for small demos)

psql or sqlite3 CLI for local testing

Optional: pg_trgm extension for fuzzy search



---

👨‍💻 Author

Eyad Tamer
