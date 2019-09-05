/* LeetCode 176 Second Highest Salary.sql */
/* Environment: Oracle */

/* Write your PL/SQL query statement below */
SELECT MAX(Salary) AS SecondHighestSalary
FROM Employee
WHERE Salary < (
    SELECT MAX(Salary)
    FROM Employee
)