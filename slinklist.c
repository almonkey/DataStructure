/*************************************************************************
	> File Name: slinklist.c
	> Author: 
	> Mail: 
	> Created Time: 2016年06月30日 星期四 18时20分07秒
 ************************************************************************/

#include<stdio.h>

#define MAXSIZE 1000

typedef struct{
    int data;
    int cur;
}component,SLinkList[MAXSIZE];

int locate_elem_sl(SLinkList s,int e) {
    int i = s[0].cur;
    while( i && s[i].data != e ){
        i = s[i].cur;
    }
    return i;
}



int main() {

    printf("slinklist start \n");



    printf("slinklist end \n");

}





