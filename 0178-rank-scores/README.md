## Result

- Runtime: 565 ms, beats 10.17%

# 178. Rank Scores

Table: `Scores`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| score       | decimal |
+-------------+---------+
```

`id` is the primary key (column with unique values) for this table.
Each row of this table contains the score of a game. Score is a
floating point value with two decimal places.

Write a solution to find the rank of the scores. The ranking should be
calculated according to the following rules:

- The scores should be ranked from the highest to the lowest.
- If there is a tie between two scores, both should have the same
  ranking.
- After a tie, the next ranking number should be the next consecutive
  integer value. In other words, there should be no holes between
  ranks.

Return the result table ordered by `score` in descending order.

The result format is in the following example.

**Example 1:**

```
Input:
Scores table:
+----+-------+
| id | score |
+----+-------+
| 1  | 3.50  |
| 2  | 3.65  |
| 3  | 4.00  |
| 4  | 3.85  |
| 5  | 4.00  |
| 6  | 3.65  |
+----+-------+

Output:
+-------+------+
| score | rank |
+-------+------+
| 4.00  | 1    |
| 4.00  | 1    |
| 3.85  | 2    |
| 3.65  | 3    |
| 3.65  | 3    |
| 3.50  | 4    |
+-------+------+
```

## Approach

`rank`-ul fiecărui scor e definit ca „numărul de scoruri distincte mai
mari sau egale cu el". De-asta `JOIN`-ul e făcut pe `s1.score <=
s2.score`, nu pe egalitate: pentru fiecare rând `s1`, numără toate
scorurile `s2` care îl egalează sau îl depășesc. `COUNT(DISTINCT
s2.score)` e esențial — fără `DISTINCT`, două scoruri egale la rândul
`s2` ar umfla artificial rangul, tocmai contrariul regulii „fără
goluri între ranguri".

`GROUP BY s1.id, s1.score` grupează pe `id`, nu doar pe `score`, ca să
nu colapseze cele două rânduri cu scor identic (4.00) într-unul
singur — fiecare rând original trebuie să rămână în rezultat, chiar
dacă rangul lui coincide cu al altuia.

E o soluție O(n²) prin natura `JOIN`-ului inegalitar (fiecare rând se
compară cu toate celelalte) — explică și `beats 10.17%`. O alternativă
mai rapidă pe MySQL 8+ ar fi `DENSE_RANK()` ca funcție de fereastră,
care face același lucru în O(n log n), printr-o sortare unică în loc
de o comparație pereche-cu-pereche.

## Complexity

- Time: O(n²), din auto-join-ul cu inegalitate
- Space: O(n) pentru rezultat
