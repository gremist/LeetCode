/* LeetCode 596 Classes More Than 5 Students.sql */
/* Environment: Oracle */

/* Write your PL/SQL query statement below */
SELECT class
FROM courses
GROUP BY class
HAVING COUNT(DISTINCT student) >= 5
;