#include <iostream>
#include <vector>
#include <string>
#include "StockMarket.h"

using namespace std;

int add (int mik,vector<Corporate> a, int ind) {
    int sum1=0;

    sum1=mik+a[ind].getCorWallet();

    return sum1;
}
int sub (int mik,vector<Corporate> a, int comp) {
    int sum1=0;
    int x;
    x=a[comp].getCorWallet();
    sum1=x-mik;

    return sum1;
}
int addI1 (int mik,vector<Individual> b, int ind) {
    int sum1=0;

    sum1=mik+b[ind].getIndWallet();

    return sum1;
}
int subI1 (int mik,vector<Individual> b, int comp) {
    int sum1=0;
    int x;
    x=b[comp].getIndWallet();
    sum1=x-mik;

    return sum1;
}
void List(vector<Corporate> a){
    for(auto & i : a){

        cout<<"Name: "<< i.getName()<<"\t"<<"Percent: "<<i.getSalePer()<<endl;
    }
}
int main (){
    StockMarket AccountList;
    vector<Corporate> a;
    vector<Individual> b;
    Individual d;
    Corporate c;
    int choise;
    string name, surname, pass;
    string war="Insufficient balance";
    int Id, Tc,r,add1,sub1,add2,sub2;

    cout<<endl<<"WELCOME TO STOCK MARKET SYSTEM"<<endl<<endl;

    do {
        cout <<"1.Member Login"<<endl;
        cout <<"2.Member Register"<< endl;
        cout <<"3.Anonymous"<<endl;
        cout <<"4.EXIT"<< endl;
        cout <<"Enter number (1 to 4): ";
        cin  >> choise;
        cout << endl;
        int choise2;
        int choise1;
        switch (choise) {
            case 1://üye girişi
                do {
                    cout<<"1.Corporate Account" << endl;
                    cout<<"2.Individual Account" << endl;
                    cout<<"3.Return the main menu" << endl;
                    cout<<"Enter number (1 to 3): ";
                    cin>> choise1;
                    cout<< endl;
                    switch (choise1) {
                        case 1:
                            cout<<"Corporate Name: ";
                            cin>>name;
                            cout<<"Corporate Surname: ";
                            cin>>surname;
                            cout<<"Id: ";
                            cin>>Id;
                            cout<<"Password: ";
                            cin>>pass;
                            cout<<endl;
                            for(int i=0;i<a.size(); i++){
                                if(a[i].getName() == name && a[i].getCorId()== Id && a[i].getPass()== pass){
                                    int chs=0;
                                    cout<<"Welcome "<<a[i].getName()<<endl;
                                    do {
                                        cout<<endl;
                                        cout<<"1.Money transfer to account"<<endl;
                                        cout<<"2.Purchase"<<endl;
                                        cout<<"3.Sale"<<endl;
                                        cout<<"4.Return menu"<<endl;
                                        cout << "Select: ";
                                        cin>> chs;
                                        int mik2;
                                        string name1;
                                        int newwallet;
                                        switch (chs) {
                                            case 1:
                                                cout<<"Quantity you want to load: ";
                                                cin>>newwallet;
                                                a[i].setCorWallet(newwallet);
                                                cout<<endl<<"New Balance: "<< a[i].getCorWallet()<<endl;
                                                break;
                                            case 2:
                                                cout<<"Which one will you buy from(Just Name)?: ";
                                                cin>>name1;
                                                List(a);
                                                for(int i=0; i<a.size(); i++){
                                                    if(a[i].getName()==name1){
                                                        cout<<"How much will you buy from "<< a[i].getName() <<"?: ";
                                                        cin>>mik2;
                                                        try {
                                                            for(int j=0;a.size(); j++){
                                                                if (a[j].getName() == name){
                                                                    if (a[i].getSalePer() >= mik2){
                                                                        add1=add(mik2,a,j);
                                                                        sub1=sub(mik2,a,i);
                                                                        a[i].setSalePer(sub1);
                                                                        a[j].setCorWallet(add1);//biz
                                                                        cout<<"Transaction completed successfully."<<endl;
                                                                        cout<<"New wallet: "<<a[j].getCorWallet()<<endl;
                                                                    }
                                                                    else{
                                                                        throw war;
                                                                    }
                                                                }
                                                            }
                                                        } catch (string war) {
                                                            cout<<war<<endl;
                                                        }
                                                    }
                                                }
                                                break;
                                            case 3:
                                                int mik5;
                                                cout<<"Current Wallet: "<< a[i].getCorWallet()<<endl;
                                                cout<<"How much do you want to sell ?: ";
                                                cin>>mik5;
                                                try{
                                                    if(a[i].getCorWallet()>=mik5){
                                                        r=sub(mik5,a,i);
                                                        a[i].setSalePer(mik5);
                                                        a[i].setCorWallet(r);
                                                        cout<<a[i].getSalePer()<<"Saleper"<<endl;
                                                        cout<<a[i].getCorWallet()<<"Wallet"<<endl;
                                                    }
                                                    else{
                                                        throw war;
                                                    }
                                                } catch (string war) {
                                                    cout<<war<<endl;
                                                }
                                                break;
                                            case 4:
                                                cout<<endl;
                                                cout<<"Menu :"<<endl<<endl;
                                                break;
                                            default:
                                                cout<<"You enter wrong number. Please try again..! "<<endl;
                                                break;
                                        }
                                    } while (chs!=4);
                                }
                            }
                            break;
                        case 2:
                            cout<<"Individual Name: ";
                            cin>>name;
                            cout<<"Individual Surname: ";
                            cin>>surname;
                            cout<<"Tc: ";
                            cin>>Tc;
                            cout<<"Password: ";
                            cin>>pass;
                            cout<<endl;
                            for(int i=0;i<b.size(); i++){
                                if(b[i].getName() == name && b[i].getIndTc()== Tc && b[i].getPass()== pass){
                                    int chs1=0;
                                    cout<<"Welcome "<<b[i].getName()<<endl;
                                    do{
                                        cout<<endl;
                                        cout<<"1.Money transfer to account"<<endl;
                                        cout<<"2.Purchase"<<endl;
                                        cout<<"3.Return menu"<<endl;
                                        cout << "Select: ";
                                        cin>> chs1;
                                        int mik3;
                                        string name2;
                                        int newwallet2;
                                        switch (chs1) {
                                            case 1:
                                                cout<<"Quantity you want to load: ";
                                                cin>>newwallet2;
                                                b[i].setIndWallet(newwallet2);
                                                cout<<endl<<"New Balance: "<< b[i].getIndWallet()<<endl;
                                                break;
                                                break;//ind para yükleme break

                                            case 2:
                                                List(a);
                                                cout<<"Which one will you buy from(Just Name)?: ";
                                                cin>>name2;
                                                for(int i=0; i<b.size(); i++){
                                                    if(a[i].getName()==name2){
                                                        cout<<"How much will you buy from "<< a[i].getName() <<"?: ";
                                                        cin>>mik3;
                                                        try {
                                                            for(int j=0; b.size(); j++){
                                                                    if (a[i].getSalePer() >= mik3){
                                                                        add2=addI1(mik3,b,j);
                                                                        sub2=subI1(mik3,b,i);
                                                                        b[i].setSalePer(sub2);
                                                                        b[j].setIndWallet(add2);
                                                                        cout<<"Transaction completed successfully."<<endl;
                                                                        cout<<"New Wallet: "<<b[j].getIndWallet()<<endl;
                                                                    }
                                                                    else{
                                                                        throw war;
                                                                    }
                                                            }
                                                        } catch (string war) {
                                                            cout<<war<<endl;
                                                        }
                                                    }
                                                }
                                                break;
                                        }
                                    } while (chs1!=3);
                                }
                            }
                            break;
                        case 3:
                            break;
                        default:
                            cout<<"You enter wrong number. Please try again..! "<<endl;
                            break;
                    }

                } while (choise1!=3);

                break;
            case 2:
                do {
                    cout<<endl;
                    cout<<"Which account would you like to sign up for :"<<endl;
                    cout <<"1.Corporate Account" << endl;
                    cout <<"2.Individual Account" << endl;
                    cout <<"3.Return the main menu" << endl;
                    cout <<"Select: ";
                    cin >> choise2;
                    switch (choise2) {
                        case 1:
                                cout<< "Corporate Name: ";
                                cin>>name;
                                c.setName(name);
                                cout<< "Corporate Surname: ";
                                cin>>surname;
                                c.setSurname(surname);
                                cout<<"Id: ";
                                cin>>Id;
                                c.setCorId(Id);
                                cout<<"Password: ";
                                cin>>pass;
                                c.setPass(pass);
                                cout<<endl;
                                a.push_back(c);
                            break;
                        case 2:
                                cout<<"Individual Name: ";
                                cin>>name;
                                d.setName(name);
                                cout<<"Individual Surname: ";
                                cin>>surname;
                                d.setSurname(surname);
                                cout<<"Tc: ";
                                cin>>Tc;
                                d.setIndTc(Tc);
                                cout<<"Password: ";
                                cin>>pass;
                                d.setPass(pass);
                                cout<<endl;
                                b.push_back(d);
                            break;
                        case 3:
                            cout<<endl;
                            cout<<"Main menu :"<<endl<<endl;
                            break;
                        default:
                            cout<<"You enter wrong number. Please try again..! "<<endl;
                            break;
                    }
                } while (choise2!=3);
                break;

            case 3:
                List(a);
                break;
            case 4:
                cout<<"Bye..!"<<endl;
                break;
            default:
                cout<<"You enter wrong number. Please try again..! "<<endl;
                break;
        }

    } while (choise!=4);

    return 0;
}