-- birth year of Emma Stone (assumes 'birth' column stores the year)
SELECT birth
FROM people
WHERE name = 'Emma Stone'
LIMIT 1;