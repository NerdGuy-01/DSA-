 // Step -1
for(int i =0;i<n;i++){
    if(a[i]!=0){
        temp.push(a[i]);
    }
}

// Step -2 
int nz = temp.size();
for(int i =0;i<nz;i++){
    a[i] = temp[i];
}

// Step - 3
for(int i=nz;i<ni++){
    a[i] = 0;

}
