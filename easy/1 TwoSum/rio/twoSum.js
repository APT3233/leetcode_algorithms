/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var res = [0,0];
    for(let i = 0; i < nums.length -1; i++){
        let remainVal = target - nums[i];
        for( let j = i+1; j < nums.length; j++){
            if(nums[j] == remainVal){
                res[0] = i;
                res[1] = j;
                break;
            }
        }
    }
    return res;
};