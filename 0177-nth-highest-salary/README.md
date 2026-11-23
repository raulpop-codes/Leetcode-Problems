## Result

- Runtime: 497 ms, beats 56.66%

# 177. Nth Highest Salary

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

Write a solution to find the `nth` highest **distinct** salary from the
`Employee` table. If there are less than `n` distinct salaries, return
`null`.

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
n = 2

Output:
+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+
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
n = 2

Output:
+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| null                   |
+------------------------+
```

## Approach

Generalizarea directă a problemei 176: acolo `OFFSET` era fixat la 1,
aici devine parametrizat prin `N - 1` (al `n`-lea cel mai mare salariu
e la offset `n-1` într-o listă sortată descrescător, sărind peste
primele `n-1`). Verificarea `N < 1` tratează explicit cazul în care
funcția e apelată cu un parametru invalid, înainte să ajungă la
interogare. `DISTINCT` rămâne obligatoriu, din același motiv ca la 176
— fără el, salariile duplicate ar deplasa poziția celui de-al `n`-lea
salariu *distinct*. Dacă `n` depășește numărul de salarii distincte,
`LIMIT 1 OFFSET N` nu găsește niciun rând, iar funcția întoarce `null`
automat.

## Complexity

- Time: O(k log k), unde k e numărul de salarii distincte
- Space: O(k) pentru valorile distincte
