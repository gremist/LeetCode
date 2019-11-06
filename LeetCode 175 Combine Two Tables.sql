/* LeetCode 175 Combine Two Tables.sql */
/* Environment: Oracle */

/* Write your PL/SQL query statement below */
SELECT FirstName, LastName, City, State
FROM Person
	LEFT JOIN Address ON Person.PersonID = Address.PersonID
;