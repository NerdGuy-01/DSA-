/*
Pascal Triangle -> at both start and end are 1 and in middle are their sum 
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 

Types of questions 
1. Given row and colums find the element at that place 
2. Print any Nth row of pascal 
3. Given N print entire pascal Triangle 


for 1 answer 
Brute force is print entire pascal triangle and then get element but another way use 
permutation 
do r-1 then c-1 and then do permutation of given 
to find the permutations do this 
*/

int ncr(int n , int r){
    long long res = 1;
    for(int i = 0;i<r;i++){
        res = res*(n-1);
        res = res/(i+1); // to divide like 10/1* 9/2 *8/3 
    }
}
// for use :  element = ncr(n-1,r-1); return element;
