#include <stdio.h>
#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabInt *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    (*T).Neff = 0;
    int i;
    for (i = IdxMin; i <= IdxMax; i++)
    {
        (*T).TI[i] = IdxUndef;
    }
}
/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    return T.Neff;
}
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
{
    return IdxMax - IdxMin + 1;
}
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
    return IdxMin;
}
IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
{
    return IdxMax;
}
ElType GetElmt (TabInt T, IdxType i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
{
    return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
{
    *Tout = Tin;
}
void SetEl (TabInt *T, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
{
    (*T).TI[i] = v;
}
void SetNeff (TabInt *T, IdxType N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
    (*T).Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
    return (T.Neff == 0);
}
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (T.Neff == MaxNbEl(T));
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
{ 
    if (IsEmpty(T))
    {
        printf("Tabel kosong");
    }
    else
    {
        int i;
        for (i = 0 ; i <= T.Neff ; i++)
        {
            printf("%d:%d\n", i, T.TI[i]);
        }
    }
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
{
    TabInt T;
    MakeEmpty(&T);
    int i;
    for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
    {
        SetEl(&T, i, GetElmt(T1, i) + GetElmt(T2, i));
    }
    return T;
}

TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */
{
    TabInt T;
    MakeEmpty(&T);
    int i;
    for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
    {
        SetEl(&T, i, GetElmt(T1, i) - GetElmt(T2, i));
    }
    return T;
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    ElType max = GetElmt(T, GetFirstIdx(T));
    int i;
    for (i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if (GetElmt(T, i) > max)
        {
            max = GetElmt(T, i);
        }
    }
    return max;
}
ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
    ElType min = GetElmt(T, GetFirstIdx(T));
    int i;
    for (i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if (GetElmt(T, i) < min)
        {
            min = GetElmt(T, i);
        }
    }
    return min;
}
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
{
    IdxType max = GetFirstIdx(T);
    int i;
    for (i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if (GetElmt(T, i) > GetElmt(T, max))
        {
            max = i;
        }
    }
    return max;
}
IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
{
    IdxType min = GetFirstIdx(T);
    int i;
    for (i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if (GetElmt(T, i) < GetElmt(T, min))
        {
            min = i;
        }
    }
    return min;
}