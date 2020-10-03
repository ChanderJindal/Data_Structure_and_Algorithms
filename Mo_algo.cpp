#include <bits/stdc++.h>

using namespace std;

/*
In an Array of size n
q queries are given in which we have to implement some function (probably of addition or subtraction)
over the sub-array (part of original array) like add 5 from i to j ; 0 <= i <= j <= n
The Brute force Approach says to just run a loop (Complexity O(j-i) for that 1 query)
Instead a separate array of size n can be created to reduce Time Complexity
All the changes to do done can be stored in that array and can be implemented in 1 loop of O(n)
see the function mo_algo() for it
*/

void mo_algo(){

int n = 100 ; // value of n can be anything
int arr[n];
for(int i = 0 ;i<n ;i++)
    arr[i] = i;
int tasks_to_perform = 20;
int changes_in_array[n+1];
for(int i = 0;i<= n ;i++)
    changes_in_array[i] = 0;   // in case the array didn't had all the initial values set to zero
int left_edge,right_edge;
while(tasks_to_perform --> 0){ // a simple for loop too will do fine
 int temp1,temp2;
 temp1 = rand()%n ; // here I am using a random function to get the boundaries
 temp2 = rand()%n;
 right_edge = max(temp1,temp2);
 left_edge = min(temp1,temp2); // so that right_edge is right to left_edge
 changes_in_array[left_edge] += 5; // assuming the function is to add 5 to every element in the sub-array
 changes_in_array[right_edge+1] -= 5;
}
for(int i = 0 ;i<n ;i++){
    arr[i] += changes_in_array[i];
}
/* array has been updated
 here the time complexity would had been O(n*q) [2000 here] (worst case) by brute force
 using this algo it was O(q+n) [120 here] (all the cases are equal)
 */
for(int i = 0 ; i<n ; i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}

int main() {
    /*
     This is c++ Code for Mo's Algorithm
     This Algorithm is very simple and can help change time complexity to space complexity
    */
    mo_algo();
return 0;
}
