#include<bits/stdc++.h>
using namespace std;


class Node{
  public:
  int data;
  Node * next;
  public:
  Node(int data1, Node * next1){
    data = data1;
    next = next1;
  }
};

Node * convertArr2LL(vector<int> &arr){
 Node * head = new Node(arr[0],NULL);
 Node *mover = head;
 for(int i =1;i<arr.size();i++){
  Node * temp = new Node(arr[i],NULL);
  mover-> next = temp;
  mover = temp;
 }
 return head;
}

int main(){
  vector<int> arr = {12,5,8,7};
  Node * head = convertArr2LL(arr);
 Node *temp = head;
 while(temp != NULL){
  cout << temp->data  << " ";
  temp = temp-> next;
 }
 
}

// to find if the element is possible or not 

int checkIfPresent(Node * head,int val){
  Node * temp = head;
  while(temp){
    if(temp-> data==val) return 1;
    temp  = temp-> next;
  }
  return 0;
}

// to find lenght
int lengthOfLL(Node * head){
  int count = 0;
  // the traversal 
  Node *temp = head;
 while(temp != NULL){
  cout << temp->data  << " ";
  temp = temp-> next;
  count++;
 }
 return count;

}
