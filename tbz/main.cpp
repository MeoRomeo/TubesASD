#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "tubes.h"

using namespace std;

int main()
{
    int pil;
    address P;
    infomotor x;
    listmotor L;
    createList(L);
    bool exit = false;
    while (exit == false)
    {
        system("cls");
        cout<<"1. Insert Data Motorcycle"<<endl;
        cout<<"2. Insert Data Feature"<<endl;
        cout<<"3. Delete Data Motorcycle"<<endl;
        cout<<"4. Delete Data Feature"<<endl;
        cout<<"5. View Data"<<endl;
        cout<<"6. Find Motorcycle"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Input Your Choice : ";
        cin>>pil;
        if (pil==1)
        {
            insertMotor(L);
        }
        else if (pil==2)
        {
            insertFitur(L);
        }
        else if (pil==3)
        {
            deleteMotor(L);
        }
        else if (pil==4)
        {
            deleteFitur(L);
        }
        else if (pil==5)
        {
            printInfo(L);
        }
        else if (pil==6)
        {
            cout<<"Input Motorcycle Name : ";
            cin>>x.nama;
            P = findElm(L,x);
            if (P==Nil)
            {
                cout<<"Data Not Found";
            }
            else
            {
                cout<<"Brand   : "<<info(P).merek<<endl;
                cout<<"Name  : "<<info(P).nama<<endl;
                cout<<"Year  : "<<info(P).tahun<<endl;
                cout<<"Color  : "<<info(P).warna<<endl;
                cout<<"CC     : "<<info(P).cc<<endl;
                cout<<"Price  : "<<info(P).harga<<endl;
                cout<<"Feature  : "<<endl;
                printInfoFitur(Lfitur(P));
            }
        }
        else if (pil==7)
        {
            exit = true;
        }
        else
        {
            cout<<"Wrong Choice";
        }
        getch();
    }
    return 0;
}
