#include "BigInt.h"
BigInt::BigInt() : sign(0) {}

BigInt::BigInt(long long x) {
    *this = x;
}

BigInt::BigInt(const string &s) {
    readString(s);
}

void BigInt::trim() {
    while(!digit.empty() && digit.back() == 0)
        digit.pop_back();
   
    if(digit.empty())
        sign = 0;
}
void BigInt::readString(const string &s) {
    digit.clear();
    sign = 1;
    if(s[0] == '-')
        sign = -1;

    for(int i = (int)s.size()-1; i >= 0; i--) {
        if(isdigit(s[i])) {
            digit.push_back(s[i] - '0');
        }
    }

    trim();
}

void BigInt::operator=(long long v) {
    digit.clear();

    if(v > 0)
        sign = 1;
    else if(v < 0)
    {
        sign = -1;
        v *= -1;
    }
    else 
        sign = 0;

    while(v > 0) {
        digit.push_back(v%10);
        v /= 10;
    }
}

void BigInt::operator=(const string &s) { 
	readString(s);
} 

BigInt BigInt::operator-() const {
    BigInt res;
    res.digit = digit;
    res.sign *= -1;
    return res;
}

BigInt BigInt::operator+(const BigInt &b) const {

   if(sign == b.sign)
   {
       // We can perform add operation
        BigInt res;
        res = b;
        for(int i = 0, carry = 0; i < max(b.digit.size(), digit.size()) || carry; i++)
        {
            if(i == (int)res.digit.size())
                res.digit.push_back(0);
            
            res.digit[i] += carry + (i < digit.size())?digit[i] : 0;
            carry = res.digit[i] >= 10;
            if(carry)
                res.digit[i] -= 10;
        }
        return res;
   }

   return *this - (-b);
}

BigInt BigInt::operator-(const BigInt &b) const {
    if(sign == b.sign)
    {
        if(abs() > b.abs()) {
            BigInt res = *this;
            int l1 = res.digit.size();
            int l2 = b.digit.size();
            vector <int> v;int x = 0;
            while(x < l2){ v.push_back(b.digit[x]);x++;}
            while(x < l1) {v.push_back(0);x++;}
       
            for(int i = 0;i < l1 ;++i){

            	res.digit[i] -= v[i];

            	int carry = (res.digit[i] < 0);
                if(carry){
                    res.digit[i] += 10;
                	res.digit[i+1] -= 1;
                }

                //cout<<res.digit
           }
            res.trim();
            return res;
        }

        return -(b - *this);
    }

    return *this + (-b);
}

bool BigInt::operator>(const BigInt &b) const {
    if(sign != b.sign)
        return (sign > b.sign);
    if(sign == 0)
        return false;
    if(digit.size() != b.digit.size())
        return (digit.size() * sign > b.digit.size() * b.sign);
    
    for(int i = digit.size() - 1; i >= 0; i--)
    {
        if(digit[i] == b.digit[i])
            continue;
        return (digit[i] * sign > b.digit[i] * b.sign);
    }

    return false; // since the numbers are equal
}

bool BigInt::operator<(const BigInt &b) const {
    return *this > b;
}

BigInt BigInt::abs() const{
    BigInt res = (*this);
    res.sign *= res.sign;
    return res;
}

ostream& operator<<(ostream &output, const BigInt &b) {
    if(b.sign == 0)
        output << 0;
    if(b.sign == -1)
        output << '-';
    for(int i = b.digit.size() - 1; i >= 0; i--)
        output << b.digit[i];
    return output;
}

istream& operator>>(istream &input, BigInt &b) {
    string s;
    input >> s;
    b.readString(s);
    return input;
}

void BigInt::karatsubaMultiply(int* a, int n, int *b, int m, int* res)
{
    if(min(n,m) <= 32)
    {   
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                res[i+j] += a[i] * b[j];
        }
        return;
    }

    const int x = min(n, m);
    if(n > m)
        karatsubaMultiply(a + x, n - x, b, m, res + x);
    if(m > n)
        karatsubaMultiply(a, n, b + x, m - x, res + x);

    // a0 -> LSB half of a
    // a1 -> MSB half of a
    // b0 -> LSB half of b
    // b1 -> MSB half of b
    // z0 = a0 * b0, z1 = a1 * b1, z2 = (a0 + a1) * (b0 + b1) - z1 - z0

    const int left = (x + 1)/2;
    const int right = x/2;

    vector<int> v(left + right - 1);

    
    karatsubaMultiply(a, left, b, left, v.data()); // z0

    for(int i = 0; i < 2 * left - 1; i++)
    {
        res[i] += v[i]; // adding z0
        res[i + left] -= v[i]; // subtracting z0 from z2
        v[i] = 0;
    }

    karatsubaMultiply(a + left, right, b + left, right, v.data());  // z1

    for(int i = 0; i < 2 * right - 1; i++)
    {
        res[i + 2*left] += v[i]; // adding z1
        res[i + left] -= v[i];   // subtracting z1 from z2
    }


    // if x is odd
    v[left - 1] = a[left - 1];
    v[left + left - 1] = b[left - 1];

    // storing (a0 + a1) and (b0 + b1) in vector v
    for(int i = 0; i < right; i++)
    {
        v[i] = a[i] + a[right + i];
        v[i + left] = b[i] + b[left + i];
    }

    karatsubaMultiply(v.data(), left, v.data() + left, left, res);

}


BigInt BigInt::operator*(BigInt &b) 
{
    BigInt res;
    res.sign = sign * b.sign;
    vector<int> temp(digit.size() + b.digit.size() - 1, 0);
    karatsubaMultiply(digit.data(), digit.size(), b.digit.data(), b.digit.size(), temp.data());
    int carry = 0;
    for(int u: temp)
    {
        res.digit.push_back((carry + u)%10);
        carry = (carry + u)/10;
    }
    while(carry != 0)
    {
        res.digit.push_back(carry%10);
        carry /= 10;
    }
    res.trim();
    return res;
}

bool BigInt::operator ==(const BigInt& b) const
{
    if(sign != b.sign)
        return false;
    if(digit.size() != b.digit.size())
        return false;
    for(int i = 0; i < digit.size(); i++)
    {
        if(digit[i] != b.digit[i])
            return false;
    }
    return true;
}

bool BigInt::operator !=(const BigInt& b) const
{	
	BigInt x = *this;
    if(x == b) return false;
    else return true;
}
