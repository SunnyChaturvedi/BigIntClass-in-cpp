# BigIntClass-in-C++
This project was done to provide the functionality of usage of numbers having more bits than 64 (highest possible in C++) in C++. \
(2^64 = 18,446,744,073,709,551,616) 2^64 is order of 10 ^ 19.

__Motivation__ : I happen to come across this problem in my Freshamn Year \
https://www.hackerrank.com/challenges/extra-long-factorials/problem 

It required me sometime to think, but eventually I solved it, however when I saw the submission of users who code in Python\
I was a bit shocked, they wrote only a 2-3 liner code to solve the same thing I did in over 100 lines and 2-3 days of my\
time (I was a bit noob back then). 

&nbsp;

I decided to implement some template or snippet which would make my work as simple as its in Python. However I faced the challenges :

 -  Didn't knew about classes hence implemented separate functions for input and arithmetic .
 -  Didn't knew operator overloading therefore had to take input in a string and pass it to a function every time (O(n) space wasted :( ).
 -  Forget operator overloading, I didn't even knew about streams.
 -  Didn't knew about modular coding, hence wrote a very big single file.(I still have to use it in online platforms as they take only one file as input :( )

Due to my lack of knowledge of Object Oriented Principles of Design I faced many challenges, 
hence I had to wait sometime first to learn them and implement it. 

After learning I have implemented some basic arithmetic unary & assignment operations along with manipulation of input and output streams via Operator Overloading to take input from console directly, I have also provided functionality to directly initialize a BigInt number from a string or long long int(this automatically ensure i can take input from int directly as long long int is higher in precision and can accommodate int too).
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

__Demonstration__ : Printing Factorials of all numbers smaller than given input number.

![](demo%20gif.gif)

(Video present in Github Repo for further references)

__Code Layout__ :


**BigInt.h** : Contains initial declarations of BigInt class and associated variables along with member functions

**BigInt.cpp** : Contains implementation of declared functions using object oriented design. All the corrressponding operaters are overloaded accordingly to enable the functionality similar to smaller integers.

**main.cpp** : Code which takes input n from stdin and returns its factorial to stdout
