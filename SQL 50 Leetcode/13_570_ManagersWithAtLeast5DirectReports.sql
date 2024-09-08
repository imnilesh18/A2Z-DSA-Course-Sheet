570. Managers with at Least 5 Direct Reports

Table: Employee
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the name of an employee, their department, and the id of their manager.
If managerId is null, then the employee does not have a manager.
No employee will be the manager of themself.
Write a solution to find managers with at least five direct reports.
Return the result table in any order.
The result format is in the following example.

Example 1:
Input: 
Employee table:
+-----+-------+------------+-----------+
| id  | name  | department | managerId |
+-----+-------+------------+-----------+
| 101 | John  | A          | null      |
| 102 | Dan   | A          | 101       |
| 103 | James | A          | 101       |
| 104 | Amy   | A          | 101       |
| 105 | Anne  | A          | 101       |
| 106 | Ron   | B          | 101       |
+-----+-------+------------+-----------+
Output: 
+------+
| name |
+------+
| John |
+------+

Solution:

SELECT e1.name
FROM employee e1
INNER JOIN employee e2
ON e1.id = e2.managerId
GROUP BY e2.managerId
HAVING COUNT(e2.managerid) >= 5

Explanation:
SELECT e1.name:
We are selecting the name of the manager from the Employee table (e1).

FROM employee e1:
We are selecting from the Employee table and giving it the alias e1.

INNER JOIN employee e2:
We perform an INNER JOIN between the Employee table (e1) and itself (e2).
This means we are joining the Employee table with itself to match employees with their managers.

ON e1.id = e2.managerId:
The join condition is based on matching the manager's ID (e1.id) with the employee's managerId (e2.managerId).
This ensures that we only consider rows where e2 is managed by e1.

GROUP BY e2.managerId:
We group the results by the manager ID (e2.managerId) to aggregate the count of direct reports for each manager.

HAVING count(e2.managerId) >= 5:
We filter the grouped results to include only managers who have at least 5 direct reports.

Example Using Input Data:
Employee Table:
+-----+-------+------------+-----------+
| id  | name  | department | managerId |
+-----+-------+------------+-----------+
| 101 | John  | A          | null      |
| 102 | Dan   | A          | 101       |
| 103 | James | A          | 101       |
| 104 | Amy   | A          | 101       |
| 105 | Anne  | A          | 101       |
| 106 | Ron   | B          | 101       |
+-----+-------+------------+-----------+

Join Operation:
John (id = 101) manages Dan, James, Amy, Anne, and Ron.
Since John has at least 5 direct reports, he is included in the result.

Output:
+------+
| name |
+------+
| John |
+------+