#include <stdio.h>
#include "listlinier.c"

int main(){
    int n;
    scanf("%i", &n);
    int i, temp, idx, val;
    List l;
    CreateList(&l);
    for(i = 0; i < n; i++){
        insertLast(&l, i+1);
    }
    int q;
    scanf("%i", &q);
    for(i=1; i <= q; i++){
        boolean hit = false;
        scanf("%i", &temp);
        idx = indexOf(l,temp);
        if(idx != IDX_UNDEF){
            hit = true;
        }
        if(hit){
            deleteAt(&l, idx, &val);
            insertFirst(&l, val);
            printf("hit ");
            displayList(l);
        }
        else{
            deleteLast(&l, &val);
            insertFirst(&l, temp);
            printf("miss ");
            displayList(l);
        }
        printf("\n");
    }


}