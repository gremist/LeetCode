/* LeetCode 197 Rising Temperature.sql */
/* Environment: Oracle */

/* Write your PL/SQL query statement below */
SELECT t.Id
FROM Weather t
	INNER JOIN Weather y ON t.RecordDate = y.RecordDate + 1 
WHERE t.Temperature > y.Temperature
;