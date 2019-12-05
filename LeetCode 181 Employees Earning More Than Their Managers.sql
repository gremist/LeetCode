/* LeetCode 181 Employees Earning More Than Their Managers.sql */
/* Environment: Oracle */

/* Write your PL/SQL query statement below */
SELECT e1.Name AS Employee
FROM Employee e1
    INNER JOIN Employee e2 ON e1.ManagerId = e2.Id 
WHERE e1.Salary > e2.Salary
;