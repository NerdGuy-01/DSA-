// Brute force 
int n1 = a.size();
int n2 = b.size();
set<int> st;
for(int i =0;i<n1;i++){
    st.insert(a[i]);
}
for(int i =0;i<n2;i++){
    st.insert(b[i]);
}

vector<int> temp;
for(auto it : st){
    temp.push_back(it);
}
return temp;


// Optimal Solution

int n1 = a.size();
int n2 = b.size();
int i =0;
int j  = 0;
vector<int> unionArr;
while(i<n1 && j<n2){
    if(a[i]<=b[i]){
        if(unionArr.size()== 0 ||unionArr.back() != a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
    }
    else{
         if(unionArr.size()== 0 ||unionArr.back() != b[j]){
            unionArr.push_back(b[j]);
        }
        j++;   
    }
}

while(j<n2){
    if(unionArr.size()== 0 ||unionArr.back() != b[j]){
            unionArr.push_back(b[j]);
        }
        j++;  
}

while(i<n1){
    if(a[i]<=b[i]){
        if(unionArr.size()== 0 ||unionArr.back() != a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
}
}

return unionArr;

