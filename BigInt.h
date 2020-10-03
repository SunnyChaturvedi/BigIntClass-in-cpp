#include <vector>
#include <string>
#include <iostream>

using namespace std;
class BigInt {
private:
        // digit at 0th index is LSB i.e. least significant digit
        vector<int> digit;

        //  sign denotes of sign of the integer,
        //  -1 for negative, 1 for positive and 0 for zero.
    
        int sign;

        //  size denotes the no. of digits in decimal representation of the number.
        int size;

        // karatsuba multiplication algorithm
        void karatsubaMultiply(int* a, int n, int* b, int m, int* res);

 public:
        
        BigInt();                               // Default constructor, incase no arguement is provided.
        BigInt(long long x);                    //  Constructor, when an integer(in-built type) is provided as an arguement.
        BigInt(const string &s);                      //  Constructor, when an string(in-built type) is provided as an arguement.
        void trim();                            // To remove leading zeroes from the intger
        void operator=(long long v);            // Declaring operator overloading for '=' if user inputs long long into bigInt class
        void readString(const string &s);       // A fuction to read a string and convert it to vector<int>
        void operator=(const string &s); //Declaring overloading for '=' if user inputs string into bigInt class
        bool operator>(const BigInt &b) const;  // Declaring comparison operator
        bool operator<(const BigInt &b) const;  // Declaring comparison operator

         // Function to calculate abs() eg - b.abs()
        BigInt abs() const;

        // overloading unary minus operator for usage in situations like b = -b
        BigInt operator-() const;

        // Declaring operator overloading for '+'
        BigInt operator+(const BigInt &b) const;

        // Declaring operator overloading for '-'
        BigInt operator-(const BigInt &b) const;

        // Overload '<<' operator
        friend ostream& operator<<(ostream &output, BigInt const &b);

        // Overload '>>' operator
        friend istream& operator>>(istream &input, BigInt &b);

        // Overload  '*' operator
        BigInt operator *(BigInt&b);

        // Overload '==' operator
        bool operator ==(const BigInt& b) const;

        // Overload '!=' operator
        bool operator !=(const BigInt& b) const;


};