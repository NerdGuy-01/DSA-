Try to name variables and functions according to question dont give x,y,z 

/*
Finding second largest element in an array

Thought process -> You can't use sort and then print n-2 element cause what if max number has duplicates

Brute force -> 
 for(int i =n-2;i>=0;i--){
        if(nums[i]!=largest){
            second = nums[i];
        break;
        }
       }

       T.C. : Nlong(N)+O(N)

       Better ->
       take second largest = -1 then check if every element is greater than -1 but smaller then largest
       largest = nums[0];
       second_largest = -1;
       for(int i =0;i<n;i++){
       if(nums[i]>largest){
       largest = nums[i];
       }
       }
      
       for(int i =0;i<n;i++){
           if(nums[i]>second_largest && nums[i]!=largest){
           second_largest =  nums[i];
           }
       }

       T.C. : O(N+N) = O(2N);


       Optimal ->

       largest =1, and second largest = -1 assuming this array does not contain any negative element
*/


// Optimal 

// for second_largest
int second_largest(vector<int>a,int n){
  int largest = a[0];
  int s_largest = -1;
  for(int i =1;i<n;i++){
    if(a[i]> largest){
      s_largest = largest;
      largest = a[i];
    }
    else if(a[i]< largest && a[i]>s_largest){
      s_largest = a[i];
    }
  }
  return s_largest;
}

// for second_minimum
int second_minimum(vector<int>a,int n ){
  int smallest = a[0];
  int second_smallest = INT_MAX;
  for(int i =1;i<n;i++){
    if(a[i]<smallest){
     s_smallest = smallest;
      smallest = a[i];
    }
    else if(a[i]!=smallest && a[i]<s_smallest){
      s_smallest = a[i];
  }
  
}
  return s_smallest
}


    int s_largest = second_largest(a,n);
        int s_smallest = second_smallest(a,n);
        return {largest,second_largest}
      
