
 // Shift by 1 Place 
int temp = arr[0];
 for(int i =1;i<n;i++){
    arr[i-1] = arr[i];
 }
 arr[n-1] =  temp;
 return arr;

// shift by d Places             
d = d%n;                        
int temp[d];
for(int i =0;i<d;i++){
    temp[i] = arr[i];
}

for(int i = d;i<n;i++){
    arr[i-d] = arr[i];
}

for(int i = n-d;i<n;i++){
    arr[i] = temp[i-(n-d)];
}

// Another approach to reduce The space Complexity 

reverse(a,a+d);
reverse(a+d,a+n);
reverse(a,a+n);

// if reverse function is not provided then do this 
void reverse(int arr[],int start,int end ){
    while(start<= end){
        int temp = arr[start];
        arr[start] = arr[end];
        start++;
        end--;
    }
}
