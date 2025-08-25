/*
Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix. We have to mark entire col and row as zero

Brute force : 
We will use two nested Loops to traverse all the cells of matrix if any element (i,j) contains value 0 we will mark call cells in rows i and column j with -1 except. 
We are using this approach considering array does not contain any negative element. If we mark all the row and  col as zero then when it will again look for zero it will change row and col of others again zero which will be wrong.
*/
