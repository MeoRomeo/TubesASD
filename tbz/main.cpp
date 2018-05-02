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
        cout<<"1. Insert Data Motor"<<endl;
        cout<<"2. Insert Data Fitur"<<endl;
        cout<<"3. Delete Data Motor"<<endl;
        cout<<"4. Delete Data Fitur"<<endl;
        cout<<"5. Lihat Data Keseluruhan"<<endl;
        cout<<"6. Cari Data Motor"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Masukkan Pilihan : ";
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
            cout<<"Masukkan Nama Motor : ";
            cin>>x.nama;
            P = findElm(L,x);
            if (P==Nil)
            {
                cout<<"Data Motor Tidak Ditemukan";
            }
            else
            {
                cout<<"Merk   : "<<info(P).merek<<endl;
                cout<<"nama  : "<<info(P).nama<<endl;
                cout<<"Tahun  : "<<info(P).tahun<<endl;
                cout<<"Warna  : "<<info(P).warna<<endl;
                cout<<"CC     : "<<info(P).cc<<endl;
                cout<<"Harga  : "<<info(P).harga<<endl;
                cout<<"Fitur  : "<<endl;
                printInfoFitur(Lfitur(P));
            }
        }
        else if (pil==7)
        {
            exit = true;
        }
        else
        {
            cout<<"Pilihan Salah";
        }
        getch();
    }
    return 0;
}
