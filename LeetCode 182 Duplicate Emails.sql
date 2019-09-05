/* LeetCode 182 Duplicate Emails.sql */
/* Environment: Oracle */

/* Write your PL/SQL query statement below */
SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1
;