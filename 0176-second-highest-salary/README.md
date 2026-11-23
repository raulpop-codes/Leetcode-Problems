## Result

- Runtime: 343 ms, beats 31.35%

# 176. Second Highest Salary

Table: `Employee`

```
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
```

`id` is the primary key (column with unique values) for this table.
Each row of this table contains information about the salary of an
employee.

Write a solution to find the second highest **distinct** salary from the
`Employee` table. If there is no second highest salary, return `null`
(return `None` in Pandas).

The result format is in the following example.

**Example 1:**

```
Input:
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+

Output:
+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+
```

**Example 2:**

```
Input:
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
+----+--------+

Output:
+---------------------+
| SecondHighestSalary |
+---------------------+
| null                |
+---------------------+
```

## Approach

`DISTINCT` elimină duplicatele înainte de sortare, altfel doi angajați cu
cel mai mare salariu ar face ca „al doilea cel mai mare" să fie de fapt
tot primul. `ORDER BY salary DESC LIMIT 1 OFFSET 1` sare peste primul
rând (cel mai mare) și ia următorul. Interogarea e învelită într-un
subselect, ca atunci când nu există un al doilea salariu (tabel cu un
singur angajat), `LIMIT`/`OFFSET` să nu returneze niciun rând, iar
subselectul fără rânduri devine `null` în locul unui tabel gol —
exact comportamentul cerut de enunț.

## Complexity

- Time: O(n log n), din sortare
- Space: O(n) pentru valorile distincte
