## Question

75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

## Example

- Example 1:

    *Input: nums = [2,0,2,1,1,0]

    *Output: [0,0,1,1,2,2]


Explanation: The root-to-leaf path with the target sum is shown.

- Example 2:

    *Input: nums = [2,0,1]

    *Output: [0,1,2]


## Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.


### Runtime

<table>
  <tr>
    <th>Author</th>
    <th>Speed(ms)</th>
    <th>Memory(MB)</th>
  </tr>
  <tr>
    <td>Rio</td>
    <td>5</td >
    <td>9.85</td>
  </tr>
</table>

### Analysis

1. Rio
   ![im](img/rio.png)
