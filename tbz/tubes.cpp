#include "tubes.h"
#include <iostream>
#include <string>

using namespace std;

void createList(listmotor &L)
{
    first(L) = Nil;
}

void createListFitur(listfitur &Lfitur)
{
    first(Lfitur) = Nil;
    last(Lfitur) = Nil;
}


address alokasi(infomotor x)
{
    address P = new ElmListMotor;
    info(P).merek = x.merek;
    info(P).nama = x.nama;
    info(P).warna = x.warna;
    info(P).tahun = x.tahun;
    info(P).cc = x.cc;
    info(P).harga = x.harga;
    next(P) = Nil;
    prev(P) = Nil;
}

addressF alokasiFitur(infofitur x)
{
    addressF P = new ElmListFitur;
    info(P).namafitur = x.namafitur;
    info(P).keterangan = x.keterangan;
    next(P) = Nil;
    prev(P) = Nil;
}


void dealokasi(address &P)
{
    delete P;
}

void dealokasiFitur(addressF &P)
{
    delete P;
}

address findElm(listmotor L, infomotor x)
{
    address P = first(L);
    if ( first(L) == Nil )
    {
        return Nil;
    }
    else
    {
        do
        {
            if ( info(P).nama == x.nama )
            {
                return P;
            }
            else
            {
                P = next(P);
            }
        } while ( P != first(L) );
        return Nil;
    }
}

addressF findElmFitur(listfitur Lfitur, infofitur x)
{
    addressF P = first(Lfitur);
    if ( first(Lfitur) == Nil )
    {
        return Nil;
    }
    else
    {
        while ( P != Nil )
        {
            if ( info(P).namafitur == x.namafitur )
            {
                return P;
            }
            else
            {
                P = next(P);
            }
        }
        return Nil;
    }
}

void insertFirst(listmotor &L, address P)
{
    if ( first(L) == Nil )
    {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
    }
    else
    {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
        first(L) = P;
    }
    cout<<"Succeed";
}

void insertLast(listmotor &L, address P)
{
    if ( first(L) == Nil )
    {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
    }
    else
    {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
    }
    cout<<"Succeed";
}

void insertAfter(listmotor &L, address Prec, address P)
{
    if ( first(L) == Nil )
    {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
    }
    else if ( Prec == prev(first(L)) )
    {
        insertLast(L,P);
    }
    else
    {
        prev(P) = Prec;
        next(P) = next(Prec);
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
    cout<<"Succeed";
}

void insertMotor(listmotor &L)
{
    int pil;
    infomotor x;
    address P,Q;
    cout<<"Masukkan Merek      : ";
    cin>>x.merek;
    cout<<"Masukkan Nama Motor : ";
    cin>>x.nama;
    cout<<"Masukkan Warna      : ";
    cin>>x.warna;
    cout<<"Masukkan Tahun      : ";
    cin>>x.tahun;
    cout<<"Masukkan CC         : ";
    cin>>x.cc;
    cout<<"Masukkan Harga      : ";
    cin>>x.harga;
    P = alokasi(x);
    cout<<endl<<"1. Insert First"<<endl;
    cout<<"2. Insert Last"<<endl;
    cout<<"3. Insert After"<<endl;
    cin>>pil;
    if (pil == 1)
    {
        insertFirst(L,P);
    }
    else if (pil==2)
    {
        insertLast(L,P);
    }
    else if (pil==3)
    {
        cout<<"Masukkan Nama Motor : ";
        cin>>x.nama;
        Q = findElm(L,x);
        if (Q==Nil)
        {
            cout<<"Motor Tidak Ditemukan";
        }
        else
        {
            insertAfter(L,Q,P);
        }
    }
    createListFitur(Lfitur(P));
}

void insertFirstFitur(listfitur &Lfitur, addressF P)
{
    if ( first(Lfitur) == Nil )
    {
        first(Lfitur) = P;
        last(Lfitur) = P;
    }
    else
    {
        next(P) = first(Lfitur);
        prev(first(Lfitur)) = P;
        first(Lfitur) = P;
    }
    cout<<"Succeed";
}

void insertLastFitur(listfitur &Lfitur, addressF P)
{
    if ( first(Lfitur) == Nil )
    {
        first(Lfitur) = P;
        last(Lfitur) = P;
    }
    else
    {
        next(last(Lfitur)) = P;
        prev(P) = last(Lfitur);
        last(Lfitur) = P;
    }
    cout<<"Succeed";
}

void insertAfterFitur(listfitur &Lfitur, addressF Prec, addressF P)
{
    if ( first(Lfitur) == Nil )
    {
        first(Lfitur) = P;
        last(Lfitur) = P;
    }
    else if ( Prec == last(Lfitur) )
    {
        insertLastFitur(Lfitur,P);
    }
    else
    {
        prev(P) = Prec;
        next(P) = next(Prec);
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
    cout<<"Succeed";
}

void insertFitur(listmotor &L)
{
    int pil;
    address P;
    addressF Q,F;
    infomotor x;
    infofitur y;
    cout<<"Masukkan Nama Motor : ";
    cin>>x.nama;
    P = findElm(L,x);
    if ( P == Nil )
    {
        cout<<"Motor Tidak Ditemukan";
    }
    else
    {
        cout<<"Masukkan Nama Fitur : ";
        cin>>y.namafitur;
        cout<<"Masukkan Keterangan : ";
        cin>>y.keterangan;
        Q = alokasiFitur(y);
        cout<<endl<<"1. Insert First"<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Insert After"<<endl;
        cin>>pil;
        if (pil==1)
        {
            insertFirstFitur(Lfitur(P),Q);
        }
        else if (pil==2)
        {
            insertLastFitur(Lfitur(P),Q);
        }
        else if (pil==3)
        {
            cout<<"Masukkan Nama fitur : ";
            cin>>y.namafitur;
            F = findElmFitur(Lfitur(P),y);
            if (F==Nil)
            {
                cout<<"Fitur Tidak Ditemukan";
            }
            else
            {
                insertAfterFitur(Lfitur(P),F,Q);
            }
        }
    }
}

void deleteFirst(listmotor &L, address &P)
{
    if ( first(L) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else if ( prev(first(L)) == first(L) )
    {
        P = first(L);
        first(L) = Nil;
        next(P) = Nil;
        prev(P) = Nil;
        cout<<"Succeed";
    }
    else
    {
        P = first(L);
        first(L) = next(first(L));
        prev(first(L)) = prev(P);
        next(prev(P)) = next(P);
        next(P) = Nil;
        prev(P) = Nil;
        cout<<"Succeed";
    }
}

void deleteLast(listmotor &L, address &P)
{
    if ( first(L) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else if ( first(L) == next(P) )
    {
        P = first(L);
        first(L) = Nil;
        next(P) = Nil;
        prev(P) = Nil;
        cout<<"Succeed";
    }
    else
    {
        P = prev(first(L));
        prev(first(L)) = prev(P);
        next(prev(P)) = next(P);
        next(P) = Nil;
        prev(P) = Nil;
        cout<<"Succeed";
    }

}

void deleteAfter(listmotor &L, address Prec, address &P)
{
    if ( first(L) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else if ( next(Prec) == first(L) )
    {
        deleteFirst(L,P);
    }
    else
    {
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        prev(P) = Nil;
        next(P) = Nil;
        cout<<"Succeed";
    }
}

void deleteMotor(listmotor &L)
{
    address P,Q;
    infomotor x;
    cout<<"Masukkan Nama Motor yang Akan Dihapus : ";
    cin>>x.nama;
    P = findElm(L,x);
    if ( P == Nil )
    {
        cout<<"Motor Tidak Ditemukan";
    }
    else
    {
        P = prev(P);
        deleteAfter(L,P,Q);
    }
}

void deleteFirstFitur(listfitur &Lfitur, addressF &P)
{
    if ( first(Lfitur) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else if ( first(Lfitur) == last(Lfitur) )
    {
        P = first(Lfitur);
        first(Lfitur) = Nil;
        last(Lfitur) = Nil;
        cout<<"Succeed";
    }
    else
    {
        P = first(Lfitur);
        first(Lfitur) = next(first(Lfitur));
        prev(first(Lfitur)) = first(Lfitur);
        next(P) = Nil;
        prev(P) = Nil;
        cout<<"Succeed";
    }
}

void deleteLastFitur(listfitur &Lfitur, addressF &P)
{
    if ( first(Lfitur) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else
    {
        P = last(Lfitur);
        last(Lfitur) = prev(P);
        next(prev(P)) = last(Lfitur);
        next(P) = Nil;
        prev(P) = Nil;
        cout<<"Succeed";
    }
}

void deleteAfterFitur(listfitur &Lfitur, addressF Prec, addressF &P)
{
    if ( first(Lfitur) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else if ( next(Prec) == first(Lfitur) )
    {
        deleteFirstFitur(Lfitur,P);
    }
    else
    {
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        prev(P) = Nil;
        next(P) = Nil;
        cout<<"Succeed";
    }
}

void deleteFitur(listmotor &L)
{
    address P;
    addressF Q,R;
    infomotor x;
    infofitur y;
    cout<<"Masukkan Nama Mobil : ";
    cin>>x.nama;
    P = findElm(L,x);
    if ( P == Nil )
    {
        cout<<"Mobil Tidak Ditemukan";
    }
    else
    {
        cout<<"Masukkan Nama Fitur : ";
        cin>>y.namafitur;
        Q = findElmFitur(Lfitur(P),y);
        if ( Q == Nil )
        {
            cout<<"Fitur Tidak Ditemukan";
        }
        else
        {
            deleteFirstFitur(Lfitur(P),R);
        }
    }
}

void printInfo(listmotor L)
{
    if ( first(L) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else
    {
        address P = first(L);
        do
        {
            cout<<"Merk   : "<<info(P).merek<<endl;
            cout<<"nama  : "<<info(P).nama<<endl;
            cout<<"Tahun  : "<<info(P).tahun<<endl;
            cout<<"Warna  : "<<info(P).warna<<endl;
            cout<<"CC     : "<<info(P).cc<<endl;
            cout<<"Harga  : "<<info(P).harga<<endl;
            cout<<"Fitur  : "<<endl;
            printInfoFitur(Lfitur(P));
            P = next(P);
        } while ( P != first(L) );
    }
}

void printInfoFitur(listfitur Lfitur)
{
    if ( first(Lfitur) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else
    {
        addressF P = first(Lfitur);
        int a=1;
        do
        {
            cout<<a<<". "<<info(P).namafitur<<endl;
            cout<<"Keterangan : "<<info(P).keterangan<<endl;
            a++;
            P = next(P);
        } while ( P != Nil );
    }
    cout<<endl;
}
