/* LeetCode 620 Not Boring Movies.sql */
/* Environment: Oracle */

/* Write your PL/SQL query statement below */
SELECT *
FROM cinema
WHERE mod(id, 2) = 1
    AND description <> 'boring'
ORDER BY rating DESC
;