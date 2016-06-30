/*************************************************************************
	> File Name: linklist.c
	> Author: 
	> Mail: 
	> Created Time: 2016年06月30日 星期四 14时15分01秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
    int data;
    struct LNode * next;
}LNode, * LinkList;

void print_list_l(LinkList l);

int get_elem_l(LinkList l,int i,int * e){
    
    LinkList p = l->next;
    int j = 1;
    while ( p && j < i ) {
        p = p->next;
        j++;
    }
    if(!p || j>i) {
        return 0;
    }
    *e = p->data;
    return 1;
}

int insert_list_l(LinkList l,int i,int e){
    
    LinkList p = l;
    int j = 0;

    while(p && j<i-1) {
        p = p->next;
        j++;
    }

    if(!p || j>i-1) {
        return 0;
    }

    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;

}

int delete_list_l(LinkList l,int i,int * e) {
   LinkList p = l;
    int j = 0;
    while(p && j < i-1 ) {
        p = p->next;
        j++;
    }
    if(!p || j > i-1) {
        return 0;
    }
    LinkList q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return 1;
}

int create_list_l(LinkList * l,int n) {
    * l = (LinkList)malloc(sizeof(LNode));
    (* l)->next =(void *)0;//this is very importment , if not may be there is a posive value to zhe attribute.
    for(int i = n;i>0;i--) {
        //if((*l)->next) {
        //    printf(" *l->next : %d ",(*l)->next->data);
        //}
        LinkList p = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&(p->data));
        p->next = (*l)->next;
        (*l)->next = p;
    }

    //print_list_l(*l);

}

int merge_list_l(LinkList la,LinkList lb,LinkList * lc) {

    LinkList pa = la->next , pb = lb->next , pc = * lc = la;
    

    while(pa && pb){
        if(pa->data <= pb->data) {
            pc->next = pa;
            pa = pa->next;
        }else{
            pc->next = pb;
            pb = pb->next;
        }
        pc = pc->next;
    }

    if(pa) {
        pc->next=pa;
    }

    if(pb) {
        pc=pb;
    }

    free(lb);

}


void print_list_l(LinkList l) {
    LinkList p = l->next;
    while(p) {
        printf(" %d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main() {
   
    printf("linklist start\n");
    
    LinkList l;

    create_list_l(&l,5);

    
    print_list_l(l);
   
    insert_list_l(l,5,6);

    print_list_l(l);

    int e;

    get_elem_l(l,5,&e);
    printf("get e = %d \n",e);

    delete_list_l(l,5,&e);
    printf("delete e = %d \n",e);

    

    printf("l : ");
    print_list_l(l);

    LinkList lb;
    create_list_l(&lb,3);

    printf("lb : ");
    print_list_l(lb);

    LinkList lc;
    merge_list_l(l,lb,&lc);
   
    printf("lc : ");
    print_list_l(lc);

    printf("\n");

    printf("linklist end\n");

}

