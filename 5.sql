-- titles and release years of all Harry Potter movies, chronological order
SELECT title, year
FROM movies
WHERE title LIKE 'Harry Potter%'
ORDER BY year;