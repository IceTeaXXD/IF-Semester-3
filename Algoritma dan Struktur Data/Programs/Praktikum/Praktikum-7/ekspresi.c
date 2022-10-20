// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 20 Oktober 2022
// Topik praktikum  : ADT Stack
// Deskripsi        : File "stack.c"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.c"
#include "wordmachine.c"

int evaluate (int a, int b, char t){
    if(t == '+'){
        return a+b;
    }
    else if(t == '-'){
        return a-b;
    }
    else if(t == '*'){
        return a*b;
    }
    else if(t == '/'){
        return a/b;
    }
    else if(t == '^'){
        int i;
        int ret = a;
        for (i = 1 ; i < b ; i++){
            ret = ret * a;
        }
        return ret;
        // return pow(a,b);
    }
}

boolean isOp(char c)
{
    int i;
    char tokens[] = "+-*/^";
    boolean flag = false;
    for(i = 0; i < 5; i++){
        if(c == tokens[i]){
            flag = true;
        }
    }
    return flag;
}

int main()
{
    Stack S;
    int temp1, temp2;
    int i;
    int val = 0;
    int mult = 1;
    CreateEmpty(&S);
    STARTWORD();
    if (endWord)
    {
        printf("Ekspresi kosong\n");
    }

    else{
        while(!endWord){
            if (!isOp(currentWord.TabWord[i])){
                val = 0;
                mult = 1;
                for (i = currentWord.Length - 1 ; i >= 0 ; i--){
                    val = val + ((currentWord.TabWord[i]-48)*mult);
                    mult *=10;
                }
                Push(&S, val);
                printf("%i\n",val);
            }
            else{
                Pop(&S, &temp2);
                Pop(&S, &temp1);
                printf("%i %c %i\n", temp1, currentWord.TabWord[i], temp2);
                int temp = evaluate(temp1, temp2, currentWord.TabWord[i]);
                Push(&S, temp);
                printf("%d\n", InfoTop(S));
            }
            ADVWORD();
            i++;
        }
        printf("Hasil=%d\n",InfoTop(S));
    }
}