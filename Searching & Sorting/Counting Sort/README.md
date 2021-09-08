# ***Counting Sort***

Counting sort is a sorting algorithm that sorts the elements of an array by counting the number of occurrences of each unique element in the array. The count is stored in an auxiliary array and the sorting is done by mapping the count as an index of the auxiliary array.

---  
**Algorithm:**

- Find out the maximum element from the given array  
- Initialize an array of length max+1 with all elements 0. This array is used for storing the count of the elements in the array  
- Store the count of each element at their respective index in count array  
- Store cumulative sum (prefix sum) of the elements of the count array. It helps in placing the elements into the correct index of the sorted array  
- Create a temporary array to store the sorted elements  
- Traverse the array backwards. For each element find the cumulative sum and place the element in temp array at  (cumulative sum - 1) index  
- Copy all the sorted elements back to the original array  

**Time Complexity: O(n+k)**  
[n is the number of elements in the array and k is the range of the elements]   
