/**
-------------------------------------------------------------------------------
  Week 1 Programming Task for ap886 for NST part IB Computation
  (i.e. C++ programming tutorial)

  SET TASK:
  To write a program (function), that will generate all prime numbers
  within a given range as optimally as possible.
  e.g.

  primes(a,b) will print to stdout all primes p\in [a,b]
*/
//----------------------------------------------------------------------------\\

#include <iostream>
#include <cmath>
using namespace std;

int upperBoundOnQuotients_Function(int p){
  // cerr<<"called upperBoundOnQuotients_Function with p"<<p<<endl;
  return (int)sqrt(p); //if the number wasn't divisible by then,
  //then it's definitely a prime.
}

bool isPrime(int p){
  // cerr<<"called isPrime, p="<<p<<endl;
  if(p<=1 || (p%2==0 && p!=2)) //from definition of Prime numbers
  return false;
  else{
    int upperBoundOnQuotients = upperBoundOnQuotients_Function(p);
    int quotient=3;
    //the loop checks if p is divisible by any odd quotient
    //This is the best we can do without Dynamic Programming/Memoization
    while(quotient <= upperBoundOnQuotients){
      if(p%quotient == 0){
        return 0;
      }
      else{
        quotient +=2;
      }
    }
    return true;
  }
}

void primes(int a, int b){
  // cerr<<"called primes, (a,b) = ("<<a<<", "<<b<<")"<<endl;
  int counter=a;
  while(counter<=b){
    if (isPrime(counter)) cout<<counter<<", ";
    counter++;
  }
  cout<<"...;"<<endl;
}

int main(){
  cout<<"This program is a dummy to test void primes(a,b)"<<endl;
  cout<<"enter comma (space) separated a & b, "<<endl;
  int a,b;
  cin>>a>>b;
  primes(a,b);

  return 0;
}
