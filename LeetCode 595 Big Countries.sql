/* LeetCode 595 Big Countries.sql */
/* Environment: Oracle */

/* Write your PL/SQL query statement below */
SELECT name, population, area
FROM World
WHERE population > 25000000
    OR area > 3000000
;