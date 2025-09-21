-- names of all people who starred in a movie in which Kevin Bacon (born 1958) also starred,
-- excluding Kevin Bacon himself
WITH kb AS (
  SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958
)
SELECT DISTINCT p.name
FROM people p
JOIN stars s ON p.id = s.person_id
WHERE s.movie_id IN (
  SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM kb)
)
  AND p.id != (SELECT id FROM kb)
ORDER BY p.name;