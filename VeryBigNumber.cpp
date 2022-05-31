#include <iostream>
#include <cstring>  // for strlen()
#include <cctype>   // for isdigit()

using namespace std;

#define max 100
class BigInt {
    friend ostream& operator<<(ostream& , const BigInt&);
    private:              // encaptulation
      short num[max];   
    public:
      BigInt(long value=0) {   // default constructor but also constructor with long int paarameter
          for(int i=0; i<max; i++)
             num[i]=0;
          for(int i=max-1; i>=0 && value!=0; i--){
              num[i]= value % 10;
              value = value / 10;
          }
      }
      BigInt(char *str) {    // constructor with a pointer to string parameter
          for(int i=0; i<max; i++)
             num[i]=0;
          int len = strlen(str);
          for(int j=max-len, k=0; j<max; j++,k++){
              if (isdigit(str[k])) num[j]=str[k] - '0';
          }
      }
      BigInt operator+(const BigInt & op2) const {   // b1=b2+b3;  b3 is parameter object 
            BigInt temp;
            int carry=0;
            for(int i=(max-1); i>=0; i--)  {             // b2 is host object
                 int tnum = num[i] + op2.num[i] + carry;
                 if (tnum>9) {
                     temp.num[i]=tnum % 10;
                     carry=1;
                 }
                 else {
                     temp.num[i]= tnum;
                     carry=0;
                 }
            }
            return temp;
      }            
};


ostream& operator<<(ostream& out, const BigInt & n){  // cout << b1;
    int i;                                  
    for(i=0; (n.num[i]==0) && (i<=(max-1)); i++); 
    
    if (i==max) out << 0;
    else  {
        for(; i<max; i++)
            out << n.num[i];
    }
    return out;
}

int main(){
    BigInt b1(1234), b2(12345678);
    BigInt b3("12345678000000000000000000000000000000000");
    cout << b1 << endl;
    cout << b2 << endl; 
    cout << b3 << endl;
    b1 = b2 + b3;
    //b1 = -b2;
    cout << b1 << endl;
}