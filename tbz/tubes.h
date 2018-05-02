#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>

using namespace std;

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define Lfitur(P) (P)->Lfitur
#define first(L) (L).first
#define last(L) (L).last
#define first(Lfitur) ((Lfitur).first)
#define last(Lfitur) ((Lfitur).last)

typedef struct motor
{
    string merek;
    string nama;
    string warna;
    int tahun;
    int cc;
    long harga;
};

typedef struct fitur
{
    string namafitur;
    string keterangan;
};

typedef motor infomotor;
typedef fitur infofitur;

typedef struct ElmListMotor *address;
typedef struct ElmListFitur *addressF;

typedef struct ElmListFitur
{
    infofitur info;
    addressF next;
    addressF prev;
};

typedef struct listfitur
{
    addressF first;
    addressF last;
};

typedef struct ElmListMotor
{
    infomotor info;
    listfitur Lfitur;
    address next;
    address prev;
};

typedef struct listmotor
{
    address first;
};

void createList(listmotor &L);
void createListFitur(listfitur &Lfitur);
address alokasi(infomotor x);
addressF alokasiFitur(infofitur x);
void dealokasi(address &P);
void dealokasiFitur(addressF &P);
address findElm(listmotor L, infomotor x);
addressF findElmFitur(listfitur Lfitur, infofitur x);
void insertFirst(listmotor &L, address P);
void insertLast(listmotor &L, address P);
void insertAfter(listmotor &L, address Prec, address P);
void insertMotor(listmotor &L);
void insertFirstFitur(listfitur &Lfitur, addressF P);
void insertLastFitur(listfitur &Lfitur, addressF P);
void insertAfterFitur(listfitur &Lfitur, addressF Prec, addressF P);
void insertFitur(listmotor &L);
void deleteFirst(listmotor &L, address &P);
void deleteLast(listmotor &L, address &P);
void deleteAfter(listmotor &L, address Prec, address &P);
void deleteMotor(listmotor &L);
void deleteFirstFitur(listfitur &Lfitur, addressF &P);
void deleteLastFitur(listfitur &Lfitur, addressF &P);
void deleteAfterFitur(listfitur &Lfitur, addressF Prec, addressF &P);
void deleteFitur(listmotor &L);
void printInfo(listmotor L);
void printInfoFitur(listfitur Lfitur);

#endif


