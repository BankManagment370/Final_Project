#include <iostream>
#include "Banking_Functions.h"
#include <fstream>
using namespace std;
bankSkeleton::bankSkeleton() {

}
ifstream bankSkeleton::getFile(ifstream infile) {

}
string bankSkeleton::getMemberName(){
return accName;  
}
double bankSkeleton::getAccount() {
return account;
}
double bankSkeleton::getBalanceS() {

}
double bankSkeleton::getBalanceC() {

}
void bankSkeleton::setAccName() {

}
void bankSkeleton::setBalanceS() {
this.balanceS = balanceS;
}
void bankSkeleton::setBalanceC() {
this.balanceC = balanceC;
}
void bankSkeleton::withdraw(double w) {
cout<<"Enter amount"<<endl;
cin>>w;
if(accName == "Savings" || accName == "savings")
{
balanceS = balanceS - w;
}
if(accName == "Checking" || accName == "checking")
{
balanceC = balanceC - w;
}
}
void bankSkeleton::deposit(double d) {
cout<<"Enter amount"<<endl;
cin>>d;
if(accName == "Savings" || accName == "savings")
{
balanceS = balanceS + d;
}
if(accName == "Checking" || accName == "checking")
{
balanceC = balanceC + d;
}
}
