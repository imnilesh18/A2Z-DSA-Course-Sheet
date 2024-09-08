1934. Confirmation Rate

Table: Signups
+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| user_id        | int      |
| time_stamp     | datetime |
+----------------+----------+
user_id is the column of unique values for this table.
Each row contains information about the signup time for the user with ID user_id.

Table: Confirmations
+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| user_id        | int      |
| time_stamp     | datetime |
| action         | ENUM     |
+----------------+----------+
(user_id, time_stamp) is the primary key (combination of columns with unique values) for this table.
user_id is a foreign key (reference column) to the Signups table.
action is an ENUM (category) of the type ('confirmed', 'timeout')
Each row of this table indicates that the user with ID user_id requested a confirmation message at time_stamp and that confirmation message was either confirmed ('confirmed') or expired without confirming ('timeout').
 
The confirmation rate of a user is the number of 'confirmed' messages divided by the total number of requested confirmation messages. The confirmation rate of a user that did not request any confirmation messages is 0. Round the confirmation rate to two decimal places.
Write a solution to find the confirmation rate of each user.
Return the result table in any order.
The result format is in the following example.

Example 1:
Input: 
Signups table:
+---------+---------------------+
| user_id | time_stamp          |
+---------+---------------------+
| 3       | 2020-03-21 10:16:13 |
| 7       | 2020-01-04 13:57:59 |
| 2       | 2020-07-29 23:09:44 |
| 6       | 2020-12-09 10:39:37 |
+---------+---------------------+
Confirmations table:
+---------+---------------------+-----------+
| user_id | time_stamp          | action    |
+---------+---------------------+-----------+
| 3       | 2021-01-06 03:30:46 | timeout   |
| 3       | 2021-07-14 14:00:00 | timeout   |
| 7       | 2021-06-12 11:57:29 | confirmed |
| 7       | 2021-06-13 12:58:28 | confirmed |
| 7       | 2021-06-14 13:59:27 | confirmed |
| 2       | 2021-01-22 00:00:00 | confirmed |
| 2       | 2021-02-28 23:59:59 | timeout   |
+---------+---------------------+-----------+
Output: 
+---------+-------------------+
| user_id | confirmation_rate |
+---------+-------------------+
| 6       | 0.00              |
| 3       | 0.00              |
| 7       | 1.00              |
| 2       | 0.50              |
+---------+-------------------+
Explanation: 
User 6 did not request any confirmation messages. The confirmation rate is 0.
User 3 made 2 requests and both timed out. The confirmation rate is 0.
User 7 made 3 requests and all were confirmed. The confirmation rate is 1.
User 2 made 2 requests where one was confirmed and the other timed out. The confirmation rate is 1 / 2 = 0.5.

Solution:

SELECT s.user_id, 
    -- ROUND(AVG(IF(c.action = 'confirmed', 1, 0)), 2) AS confirmation_rate
    IFNULL(ROUND(SUM(c.action = 'confirmed') / COUNT(*), 2), 0.00) AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c
ON s.user_id = c.user_id
GROUP BY s.user_id;

Explanation:
SELECT s.user_id:
We are selecting the user_id from the Signups table (s).

ROUND(AVG(IF(c.action = 'confirmed', 1, 0)), 2) AS confirmation_rate:
We calculate the confirmation rate using AVG:
IF(c.action = 'confirmed', 1, 0) returns 1 if the action is 'confirmed' and 0 otherwise.
Averages these values to get the confirmation rate for each user.
ROUND is used to round the result to 2 decimal places.

Alternatively
IFNULL(ROUND(SUM(c.action = 'confirmed') / COUNT(*), 2), 0.00) AS confirmation_rate:
We calculate the confirmation rate by dividing the count of 'confirmed' actions by the total number of actions.
SUM(c.action = 'confirmed') counts the number of 'confirmed' actions.
COUNT(*) counts all actions (both confirmed and timeout).
ROUND is used to round the result to 2 decimal places.
IFNULL handles cases where no actions are found, setting the confirmation rate to 0.00.

FROM Signups s:
We are selecting from the Signups table and giving it the alias s.

LEFT JOIN Confirmations c:
We perform a LEFT JOIN between the Signups table (s) and the Confirmations table (c).
This ensures all users from Signups are included, even if they have no corresponding entries in Confirmations.

ON s.user_id = c.user_id:
The join condition ensures we match rows based on user_id in both tables.

GROUP BY s.user_id:
We group the results by user_id to aggregate the confirmation rate for each user.

Example Using Input Data:
Signups Table:
+---------+---------------------+
| user_id | time_stamp          |
+---------+---------------------+
| 3       | 2020-03-21 10:16:13 |
| 7       | 2020-01-04 13:57:59 |
| 2       | 2020-07-29 23:09:44 |
| 6       | 2020-12-09 10:39:37 |
+---------+---------------------+

Confirmations Table:
+---------+---------------------+-----------+
| user_id | time_stamp          | action    |
+---------+---------------------+-----------+
| 3       | 2021-01-06 03:30:46 | timeout   |
| 3       | 2021-07-14 14:00:00 | timeout   |
| 7       | 2021-06-12 11:57:29 | confirmed |
| 7       | 2021-06-13 12:58:28 | confirmed |
| 7       | 2021-06-14 13:59:27 | confirmed |
| 2       | 2021-01-22 00:00:00 | confirmed |
| 2       | 2021-02-28 23:59:59 | timeout   |
+---------+---------------------+-----------+

Join Operation:
User 6 did not request any confirmation messages, so their confirmation rate is 0.
User 3 made 2 requests, both timed out, so their confirmation rate is 0.
User 7 made 3 requests, all confirmed, so their confirmation rate is 1.
User 2 made 2 requests, one confirmed and one timed out, so their confirmation rate is 0.5.

Output:
+---------+-------------------+
| user_id | confirmation_rate |
+---------+-------------------+
| 6       | 0.00              |
| 3       | 0.00              |
| 7       | 1.00              |
| 2       | 0.50              |
+---------+-------------------+