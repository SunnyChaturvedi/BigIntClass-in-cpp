#include "BigInt.cpp"
#include <iostream>

int main(){
    
   BigInt ans(1),o(1),z(0),n;
   cin >> n;

   while(n > o) {
   	 cout << ans << endl;
   	 ans = ans * n;
   	 n = n - o;
   }

   cout << ans << endl;
 
 }