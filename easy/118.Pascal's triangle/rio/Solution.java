class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>(); //final result 


        List<Integer> firstRow = new ArrayList<>();
        firstRow.add(1); // add the value for first row, which is 1 element is '1'; 
        result.add(firstRow); // add the first row to the final result;

        if(numRows == 1){
            return result;  //if the triangle have 1 row, return triangle
        }else if(numRows < 1){
            return null; // if the numRow is less than 1, which is invalid input, return null value
        }else{
            for(int i = 1; i < numRows; i++){
                List<Integer> prev_Row = result.get(i - 1); // create a list to store previous row value 

                List<Integer> curr_Row = new ArrayList<>(); // create a new list for the current row 
                curr_Row.add(1); // add the value for the first element in the current row
                for(int j = 0; j < i - 1 ; j++){ //looping , to calculate the value at the index i
                    curr_Row.add(prev_Row.get(j) + prev_Row.get(j+1));  // calculate the current value for the element in list by multiple the  element at position j &j j + 1 in the prev_Row
                }
                curr_Row.add(1); // add value for the end element of row

                result.add(curr_Row); // add current row to the final result list
            } //continue the loop or break it
        }
    return result; // return list 
    }
}