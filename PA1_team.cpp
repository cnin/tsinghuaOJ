#include <stdio.h>
#include <string.h>
//#include <vector>
#define MAX 500010
int n, k;
int A[MAX], B[MAX], C[MAX];
int i;
int iA=0,iB=0,iC=0;
char Label[MAX];


int main(){
//    const int MAX=500010;
    memset(Label,'N',sizeof(Label));

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&B[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&C[i]);
    }
    scanf("%d",&k);

    for(int i=0;i<n;i++){
        int temp = 0;
        switch(i%3){
        case 0:
            temp=A[iA];
            while(Label[temp]!='N'){
                iA++;
                temp=A[iA];
            }
            if(Label[temp]=='N'){
                Label[temp]='A';
                iA++;
            }
            break;

        case 1:
            temp=B[iB];
            while(Label[temp]!='N'){
                iB++;
                temp=B[iB];
            }
            if(Label[temp]=='N'){
                Label[temp]='B';
                iB++;
            }
            break;

        case 2:
            temp=C[iC];
            while(Label[temp]!='N'){
                iC++;
                temp=C[iC];
            }
            if(Label[temp]=='N'){
                Label[temp]='C';
                iC++;
            }
            break;
        default:
            break;
        }

    }

    printf("%c\n",Label[k]);

    return 0;
}
