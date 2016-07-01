/*************************************************************************
	> File Name: slinklist.c
	> Author: 
	> Mail: 
	> Created Time: 2016年06月30日 星期四 18时20分07秒
 ************************************************************************/

#include<stdio.h>

#define MAXSIZE 20

typedef struct{
    int data;
    int cur;
}component,SLinkList[MAXSIZE];

void printf_sl(SLinkList sl,int s);

int locate_elem_sl(SLinkList s,int i,int * prev_i,int e) {
    i = s[i].cur;
    while( i && s[i].data != e ){
        printf("locate i : %d ",i);
        *prev_i = i;
        i = s[i].cur;
    }
    printf("locate result : %d ",i);
    return i;
}

void init_space_sl(SLinkList * space) {
    for(int i=0;i < MAXSIZE-1;++i) {
        (* space)[i].cur = i+1;
    }
    (* space)[MAXSIZE-1].cur = 0;
}

int malloc_sl(SLinkList * space) {
    int i = (*space)[0].cur;
    if((*space)[0].cur) {
        (*space)[0].cur = (*space)[i].cur;
        (*space)[i].cur=0;
    }
    return i;
}

int free_sl(SLinkList * space,int k ) {
    (* space)[k].cur = (* space)[0].cur;
    (* space)[k].data = 0;
    (* space)[0].cur = k;
    return 1;
}

void difference(SLinkList * space,int * s) {
    init_space_sl(space);
    (* s)= malloc_sl(space);
    

    int r = (* s);
    int la,lb;
    printf("input A and B's length: ");
    scanf("%d,%d",&la,&lb);
    printf("A's length is %d,B's length is %d \n",la,lb);
    
    printf("input the A's element:\n");
    for(int i = 0; i < la;i++) {
        int e;
        scanf("%d",&e);
        int ti = malloc_sl(space);
        //printf("ti : %d \n",ti);
        //printf("r : %d \n",r);
        (* space)[r].cur=ti;
        (* space)[ti].data = e;
        r = ti;
    }

    printf_sl(* space,* s);

    printf("input the B's element:\n");
    for(int i = 0;i < lb;i++) {
        //printf("i : %d,lb : %d \n",i,lb);
        int e;
        scanf("%d",&e);
        //find e is exists in A
        int prev_i;
        int ti = locate_elem_sl(*space,*s,&prev_i,e);
        //printf("ti : %d \n",ti);
        if(ti) {
            //delete ti
            (* space)[prev_i].cur = (* space)[ti].cur;
            free_sl(space,ti);
        }else{
            ti = malloc_sl(space);
            (* space)[r].cur=ti;
            (* space)[ti].data = e;
            r = ti;
        }
        printf_sl(* space,* s);
    }
    printf_sl(* space,* s);
}

void printf_sl(SLinkList sl,int s) {
    printf("\nlist : ");
    s = sl[s].cur;
    while(s){
        printf(" %d ",sl[s].data);
        s = sl[s].cur;
    }
    printf("\n");
}

int main() {

    printf("slinklist start \n");

    SLinkList space;
    int s;
    difference(&space,&s);

    printf("slinklist end \n");

}





