// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 29 September 2022
// Topik praktikum  : ADT Mesin Kata
// Deskripsi        : File "wordmachine.c"

#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
   while (currentChar == BLANK) {
      ADV();
   }
}
void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : endWord = true, dan currentChar = MARK;
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
   START();
   IgnoreBlanks();
   if (currentChar == MARK){
      endWord = true;
   }
   else{
      endWord = false;
      CopyWord();
   }
}

void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
   IgnoreBlanks();
   if (currentChar == MARK){
      endWord = true;
   }
   else{
      CopyWord();
      IgnoreBlanks();
   }
}

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
   int i = 0;
   while (currentChar != MARK && currentChar != BLANK){
      currentWord.TabWord[i] = currentChar;
      ADV();
      i++;
   }

   if (i > NMax){
      currentWord.Length = NMax;
   }

   else{
      currentWord.Length = i;
   }
}

void LowerCase()

/* I.S. currentword terdefinisi sembarang tetapi tidak kosong */

/* F.S. currentword menjadi lowercase di setiap karakternya */
{
   int i;
   for (i = 0; i < currentWord.Length; i++){
      if (currentWord.TabWord[i] >= 'A' && currentWord.TabWord[i] <= 'Z'){
         currentWord.TabWord[i] = currentWord.TabWord[i] + 'a' - 'A';
      }
   }
}