#include <string>
#include "StockMarket.h"

using namespace std;

void StockMarket ::setName(string name){
    Name=name;
}
string StockMarket::getName(){
    return Name;
}

void StockMarket::setPass(string pass){
    Pass=pass;
}

void StockMarket:: setSurname(string surname){
    Surname=surname;
}
string StockMarket:: getSurname(){
    return Surname;
}

string StockMarket::getPass() {
    return Pass;
}

void StockMarket::setSalePer(int salePer){
    SalePer=salePer;
}

int StockMarket:: getSalePer(){
    return SalePer;
}

void Corporate:: setCorWallet(int wallet){
    CorWallet=wallet;
}

int Corporate::getCorWallet(){
    return CorWallet;
}
void Corporate::setCorId(int Id){
    CorId=Id;
}
int Corporate::getCorId(){
    return CorId;
}

void Individual::setIndTc(int Tc) {
    IndTc=Tc;
}
int Individual::getIndTc(){
    return IndTc;
}
void Individual::setIndWallet(int wallet) {
    IndWallet=wallet;
}
int Individual::getIndWallet() {
    return IndWallet;
}
