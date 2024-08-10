

## Question

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

## Example

- Example 1:

  * Input: strs = ["flower","flow","flight"]
  * Output: "fl"
- Example 2:

  * Input: strs = ["dog","racecar","car"]
  * Output: ""
  * Explanation: There is no common prefix among the input strings.

## Constraints:

    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters.

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
    <td>7.88</td>
  </tr>
  <tr>
    <td>APT</td>
    <td>0</td >
    <td>11.26</td>
  </tr>
  <tr>
    <td>Dung</td>
    <td>7</td>
    <td>11.2</td>
  </tr>
</table>


### Analysis
1. Rio 
![im](img/rio.png)
2. APT
![img](img/apt.png)
3. Dung
![img](img/dung.png)