/** 
 * @param {string} s 
 *@return {boolean} 
 */ 
 var isValid = function (s) {
    const parentheses = { ")": "(", "]": "[", "}": "{" };
    const stack = [];
    for (const char of s) {
      if (!parentheses[char]) {
        stack.push(char);
        continue;
      }
      if (stack.pop() !== parentheses[char]) {
        return false;
      }
    }
    if (stack.length) return false;
    return true;
  };
  