#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
#define M 10000

// *** CHAINING METHOD

int m;

int h(ULL k){ // hash function
    return k%m;
}

typedef struct Node{ // Linked list
    ULL key;
    struct Node* next;
} Node;

Node* T[M]{NULL};

Node* insertList(Node* head, ULL k){
    // Create new node
    Node* newNode=new Node();
    newNode->key=k;
    // Integrate the node into the linked list
    newNode->next=head;
    head=newNode;
    return head;
}

Node* findList(Node* head, ULL k){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->key==k) return temp;
        else temp=temp->next;
    }
    return temp;
}

int insertTable(ULL k){
    int i=h(k);
    // The head node of the linked list that is possible to include k in is T[i]
    Node* res=findList(T[i],k);
    if(res==NULL){
        T[i]=insertList(T[i],k);
        return 1;
    } else return 0;
}

// *** OPEN ADDRESSING METHOD
/* Some techniques:
    1/ Linear Probing
    2/ Quadratic Probing
    3/ Double Hashing
*/

void LinearProbing(int arr[],int s_arr,int Hash[]){ 
    // Elements are hashed following the rule: h(x)=(h(x)+i)%sizeoftable.
    // for(int i=0;i<s_arr;++i){
    //     int t=h(arr[i]);
    //     if(Hash[t]==0) Hash[t]=arr[i];
    //     else {
    //         while(Hash[t]!=0) t++;
    //         Hash[t]=arr[i];
    //     }
    // } // 1st way of implementation
    // 2nd way:
    for(int i=0;i<m;++i){
        if(!Hash[i]) break;
        else if(Hash[i] && i==m-1) return;
    } // Check whether the whole table is occupied
    for(int i=0;i<s_arr;++i){
        int t=h(arr[i]);
        while(Hash[t]!=0) t=(t+1)%m; // hash_size=m
        Hash[t]=arr[i];
    }
}

void QuadraticProbing(int arr[],int s_arr,int Hash[]){ // Incomplete method
    for(int i=0;i<s_arr;++i){
        int t=h(arr[i]);
        // Check whether the table is occupied.
        // The elements are hashed following the formula: h(x)=(h(x)+i*i)%sizeoftable.
        if(Hash[t]==0) Hash[t]=arr[i];
        else {
            for(int j=0;j<m;++j){
                int nt=(t+j*j)%m; // Finding the index of the table which is not occupied, where t remains unchanged
                if(!Hash[nt]){
                    Hash[nt]=arr[i];
                    break;
                }
            }
        }
    }
}

void printTable(int Hash[], int m){
    for(int i=0;i<m;++i) cout << Hash[i] << " "; 
    cout << endl;
}

int main(){
    cout << "Hash: "; cin>>m;
    int Hash[m]{0}; // Initialize an array Hash representing the Hash table, where all the values are 0
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;++i) cin>>arr[i];
    LinearProbing(arr,n,Hash);
    printTable(Hash,m);
    QuadraticProbing(arr,n,Hash);
    printTable(Hash,m);
    return 0;
}