

## Question

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. <br>
X can be placed before L (50) and C (100) to make 40 and 90. <br>
C can be placed before D (500) and M (1000) to make 400 and 900.<br>

Given a roman numeral, convert it to an integer.

## Example

- Example 1:

    * Input: s = "III"
    Output: 3
    Explanation: III = 3.
- Example 2:

    * Input: s = "LVIII"
    * Output: 58
    * Explanation: L = 50, V= 5, III = 3.
- Example 3:

    * Input: s = "MCMXCIV"
    * Output: 1994
    * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

## Constraints:

    1 <= s.length <= 15
    s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    It is guaranteed that s is a valid roman numeral in the range [1, 3999]

### Rutime
<table>
  <tr>
    <th>Author</th>
    <th>Speed(ms)</th>
    <th>Memory(MB)</th>
  </tr>
  <tr>
    <td>Rio</td>
    <td>0</td>
    <td>10.52</td>
  </tr>
  <tr>
    <td>APT</td>
    <td>30</td >
    <td>11.65</td>
  </tr>
  <tr>
    <td>Dung</td>
    <td>20</td>
    <td>17.8</td>
  </tr>
</table>


### Analysis
1. Rio 
![im](img/rio.png)
2. APT
![img](img/apt.png)
3. Dung
![img](img/dung.png)