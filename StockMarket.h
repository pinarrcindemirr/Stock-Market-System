#ifndef PROJE_STOCKMARKET_H
#define PROJE_STOCKMARKET_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StockMarket{
private:
    string Name;
    string Surname;
    string Pass;
    int SalePer=0;


public:

    void setName(string name);
    void setSurname(string surname);
    void setPass(string pass);

    string getName();
    string getSurname();
    string getPass();


    void setSalePer(int salePer);
    int getSalePer();

};
class Corporate:public StockMarket{
private:
    int CorWallet;//Ana bakiye
    int CorId;

public:


    void setCorWallet(int wallet);
    int getCorWallet();
    void setCorId(int Id);
    int getCorId();


};
class Individual:public StockMarket{
private:
    int IndTc;
    int IndWallet;

public:
    void setIndWallet(int wallet);
    int getIndWallet();
    void setIndTc(int Tc);
    int getIndTc();


};


#endif //PROJE_STOCKMARKET_H
