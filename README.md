# BigIntClass-in-C++
This project was done to provide the functionality of usage of numbers having more bits than 64 (highest possible in C++) in C++.

__Motivation__ : I happen to come across this problem in my Freshamn Year \
https://www.hackerrank.com/challenges/extra-long-factorials/problem 

It required me sometime to think, but eventually I solved it, however when I saw the submission of users who code in Python\
I was a bit shocked, they wrote only a 2-3 liner code to solve the same thing I did in over 100 lines and 2-3 days of my\
time (I was a bit noob back then). 

&nbsp;

I decided to implement some template or snippet which would make my work as simple as its in Python.
However due to lack of knowledge of Object Oriented Principles of Design I was unable to implement all functionalities\
hence I had to wait sometime first to learn them and implement it. 

After learning I have implemented some basic arithmetic unary & assignment operations along with manipulation of input and output streams via Operator Overloading to take input from console directly, I have also provided functionality to directly initialise a BigInt number from a string or long long int(this automatially ensure i can take input from int directly as long long int lies up in precision diagram).
\
\
Finally I was able to calculate the extra long factorials :)  \
using just the code 
```cpp
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
```

&nbsp;

![](demo%20gif.gif)

(Video present in Github for references)
