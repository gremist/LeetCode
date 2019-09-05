/* LeetCode 627 Swap Salary.sql */
/* Environment: Oracle */

/* Write your PL/SQL query statement below */
UPDATE salary
SET sex = CASE sex
    WHEN 'f' THEN 'm'
    ELSE 'f'
END
;