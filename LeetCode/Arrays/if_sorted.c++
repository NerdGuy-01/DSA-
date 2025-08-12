/*
Check if an array is sorted or not 

My mistake I store all elements in vector thinking then I would just compare both new vector and old vector but no vector store in same order

Brute force -> check for every Element 
bool isSorted(vector<int>arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[i])
        return false;
    }
  }

  Time Complexity: O(N^2)

Space Complexity: O(1)

Optimal -> We know in sorted previous element is smaller and the next one so we can do just one parsing, if not return false if yes then return true
*/

// optimal 
bool isSorted(vector<int>arr, int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1])
      return false;
  }

  return true;
}
