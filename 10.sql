-- names of all people who have directed a movie that received rating >= 9.0
SELECT DISTINCT p.name
FROM people p
JOIN directors d ON p.id = d.person_id
JOIN ratings r ON d.movie_id = r.movie_id
WHERE r.rating >= 9.0
ORDER BY p.name;