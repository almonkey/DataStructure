/*************************************************************************
	> File Name: arraylist.c
	> Author: 
	> Mail: 
	> Created Time: 2016年06月29日 星期三 16时35分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 100 
#define LISTINCREMENT 10 

typedef struct {
    int * elem;
    int length;
    int listsize;
} ArrayList;

int init_list_sq(ArrayList *l){
    (* l).elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int));
    if(!(* l).elem) {
        exit(0);
    }
    (* l).length = 0;
    (* l).listsize = LIST_INIT_SIZE;
    return 1;
}

int insert_list_sq(ArrayList *l,int i,int e ) {
    if(i < 1 || i > (* l).length + 1) {
        return 0;
    }
    if((* l).length >= (* l).listsize) {
        int * newbase = (int *)realloc((* l).elem, ((* l).listsize+LISTINCREMENT)*sizeof(int) );
        if(!newbase) {
           exit(0);
        }
        (* l).elem = newbase;
        (* l).listsize += LISTINCREMENT;
    }
    int * q = &((* l).elem[i-1]);
    for(int * p = &((* l).elem[(* l).length-1]);p>=q;--p) {
        *(p+1) = *p;
    }
    *q = e;
    ++(* l).length;
    return 1;
}

int delete_list_sq(ArrayList *l,int i ,int * e) {
    if( i<1 || i > (* l).length  ) {
        return 0;
    }
    int * p = &((* l).elem[i-1]);
    *e = *p;
    int * q = (* l).elem + (* l).length -1;
    for(++p;p <=q;++p) {
        *(p-1) = *p;
    }
    --((* l)).length;
    return 1;
}

int locate_elem_sq(ArrayList *l , int e , int (* compare)(int , int ) ) {
    int i = 1;
    int * p = (* l).elem;
    while(i <= (* l).length && !( (* compare)(*p++,e)) ) {
        i++;
    }
    if( i <= (* l).length ) {
        return i;
    }else{
        return 0;
    }
}

int merge_list_sq( ArrayList la,ArrayList lb,ArrayList *lc ) {
    int * pa = la.elem , * pb = lb.elem;
    (* lc).listsize = (* lc).length = la.length + lb.length;
    int * pc = (* lc).elem = (int *)malloc((* lc).listsize * sizeof(int));
    if(!(* lc).elem) {
        exit(0);
    }
    int * pa_last = pa + la.length - 1;
    int * pb_last = pb + lb.length - 1;
    while( (pa <= pa_last) && ( pb <= pb_last )  ) {
        if( * pa <= * pb  ) {
            * pc++ = * pa++;
        }else{
            * pc++ = * pb++;
        }
    }

    while(pa <= pa_last) {
        * pc++ = * pa++; 
    }
    while(pb <= pb_last) {
        * pc ++ = * pb++;
    }

    return 1;
}


int main() {
    
    printf("arraylist start\n"); 
    
    ArrayList al;
    init_list_sq(&al);
    int * af = al.elem;

    printf("listsize : %d \n",al.listsize);


    int a[5] = {1,2,4,5,6};

    for(int i=0;i<5;i++) {
        (* (al.elem + i)) = a[i];
        //printf("  %d ",*(al.elem +i));
    }
    al.length = 5;

    for (int i = 0;i < al.length;i++) {
        printf(" %d ", * (al.elem+i));
    }
    printf("\n");
   

    insert_list_sq(&al,3,3);
    
    for (int i = 0;i < al.length;i++) {
        printf(" %d ", * (al.elem+i));
    }
    
    printf("\n");
   
    int e;
    delete_list_sq(&al,4,&e);

    printf("delete e : %d ",e);

    printf("\n");
   
    for (int i = 0;i < al.length;i++) {
        printf(" %d ", * (al.elem+i));
    }    

    printf("\n");

    
    ArrayList bl;
    init_list_sq(&bl);
    int * bf = bl.elem;
    
     int b[5] = {7,8,9,10,11};

    for(int i=0;i<5;i++) {
        (* (bl.elem + i)) = b[i];
    }
    bl.length = 5;

    for (int i = 0;i < bl.length;i++) {
        printf(" %d ", * (bl.elem+i));
    }
    printf("\n");
   
    ArrayList cl;
    merge_list_sq(al,bl,&cl);

     for (int i = 0;i < cl.length;i++) {
        printf(" %d ", * (cl.elem+i));
    }

    free(af);
    free(bf);
    free(cl.elem);


    printf("\nlistsize : %d \n",al.listsize);

    printf("arraylist end\n"); 


    return 0;
}


