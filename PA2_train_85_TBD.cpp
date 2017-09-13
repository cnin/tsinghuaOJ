#include <stdio.h>
#include <string.h>
int top = 0;


int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	int *out = new int[n];
	int *stack = new int[n-2];

	memset(out,0,n*sizeof(int));
	memset(stack,0,(n-2)*sizeof(int));

	int i;

	for(i=0;i<n;i++){
		scanf("%d", &out[i]);
	}

	int j=0;

	for(i=0;i<n;i++){
		if( stack[top] > out[i] ){
			printf("No\n");
			return 0;
		}
		if( j < out[i] ){
			while(out[i] != j)
			{
				stack[++top] = ++j;
			}
		}

		if( top > m )
		{
			printf("No\n");
			return 0;
		}

		if( out[i] == stack[top] )
		{
			top--;
		}
	}

	printf("Yes\n");

	delete[] out;
	delete[] stack;
	return 0;
}
// #include <stdio.h>

// const int SZ = 1 << 20;  //提升IO buff 
// struct fastio{
// 	char inbuf[SZ];
// 	char outbuf[SZ];
// 	fastio(){
// 		setvbuf(stdin, inbuf, _IOFBF, SZ);
// 		setvbuf(stdout, outbuf, _IOFBF, SZ);
// 	}
// }io;

// #define N 1600001
// int stack[N];
// int num[N-1];

// int out[2 * N];		// 1-push;0-pop

// int main()
// {
// 	int n, m;
// 	scanf("%d %d", &n, &m);
// 	for (int i = 0; i < n; i++)
// 		scanf("%d", &num[i]);

// 	int flag = 1;	// 1-可行；0-no
	
// 	int k = 0;		// out的下标
// 	int top = 0;	// stack的下标

// 	for (int i = 1,j = 0; i <= n && j < n; i++)
// 	{
// 		if (top < m) {
// 			out[k++] = 1;
// 			stack[top++] = i;
// 		} else {
// 			flag = 0;
// 			break;
// 		}
// 		if (i == num[j]) {
// 			j++;
// 			stack[--top] = 0;
// 			out[k++] = 0;

// 			while (top > 0 && stack[top - 1] == num[j]) {
// 				j++;
// 				stack[--top] = 0;
// 				out[k++] = 0;
// 			}
// 		}
// 	}

// 	if (flag == 0 || top != 0) printf("No\n");
// 	else printf("Yes\n");
// 	return 0;
// }


// #include <iostream>
// #include<stack>
 
// using namespace std;
// int const MAX = 1000;
 
// int testOrder(int n)
// {
//     stack<int> train;
//     int ch[MAX];
//     int curA=1,curB=1;
//     for(int i =1; i<=n; i++){
//         cin>>ch[i];
//         if(ch[i] ==0){
//             return 0;
//         }
//     }
//     while(curB<=n){
//         if(ch[curB] == curA){
//             curB++;
//             curA++;
//         }else if(!train.empty() && ch[curB] == train.top()){
//             train.pop();
//             curB++;
//         }else if(curA<=n){
//             train.push(curA++);
//         }else{
//             cout<<"No"<<endl;
//             return 1;
//         }
 
//     }
//     cout<<"Yes"<<endl;
//     return 1;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     do{
//         while(testOrder(n)==1);
//         cin>>n;
//         if(n!=0) cout<<endl;
//     }while(n != 0);
//     return 0;
// }


// #include <stdio.h>
// #define MANX 100005

// int Stack[MANX];
// int Out[MANX];
// int sTop=0;	//栈顶指针

// void push(int a)
// {
// 	Stack[++sTop]=a;
// }

// void pop()
// {
// 	sTop--;
// }

// int top()
// {
// 	return Stack[sTop];
// }

// int main()
// {
// 	// in 的时候一定是{1, 2, ..., n}
// 	int n,m;
// 	scanf("%d%d",&n,&m);
	
// 	int i;
// 	for(i=0;i<n;i++)
// 		scanf("%d",&Out[i]);
	
// 	//算法开始
// 	int j=0;
// 	for(i=0;i<n;i++)
// 	{
// 		//如果小于栈顶元素，直接可判断在栈中而无法出栈
// 		if(Out[i]<top())
// 		{
// 			printf("No\n");
// 			return 0;
// 		}

// 		//直到 Out[i] 的元素全部加入栈
// 		if(j<Out[i])
// 			while(j!=Out[i])
// 				push(++j);
		
// 		if(sTop>m)
// 		{
// 			printf("No\n");
// 			return 0;
// 		}
		
// 		if(Out[i]==top())
// 			pop();
// 	}

// 	printf("Yes\n");
	
// 	return 0;
// }


// #include <iostream>
// #include <cstdio>
// #include <cstring>

// #define MAX 20000000
// //#define DEBUG
// using namespace std;
// int outArray[MAX];
// char resultBuffer[50000000];
// int resultLen = 0;
// class MyStack
// {
// public:
//     MyStack(int capacity)
//     {
//        this->capacity = capacity;
//        currentSize = 0;
//        st = new int[capacity];
//     }
//     bool push(int e)
//     {
//        if(currentSize<capacity)
//        {
//           strcpy(resultBuffer+resultLen,"push\n");
//           resultLen += 5;
//           st[currentSize++] = e;
//           return true;
//        }
//        else
//        {
//            return false;
//        }
//     }
//     int top()
//     {
//         return st[currentSize-1];
//     }

//     int pop()
//     {
//         strcpy(resultBuffer+resultLen,"pop\n");
//         resultLen += 4;
//         currentSize--;
//         return st[currentSize-1];
//     }
//     bool empty()
//     {
//         return (currentSize == 0);
//     }
//     bool full()
//     {
//         return (currentSize == capacity);
//     }

// private:
//     int *st;
//     int currentSize;
//     int capacity;
// };
// int main()
// {
//     int m,n,i,j,r;
//     scanf("%d%d",&n,&m);
//     if(m == 0)
//     {
//         printf("No\n");
//         return 0;
//     }
//     for(i=0;i<n;i++)
//     {
//       scanf("%d",&outArray[i]);
//     }
//     MyStack stack(m);
//     i=0,j=0,r=1;
//     while(i<n)
//     {
//         if(outArray[i] == r)
//         {
//             if(stack.full())
//             {
//                 printf("No\n");
//                 return 0;
//             }
// #ifdef DEBUG
//             cout<<"push "<<r<<endl<<"pop "<<r<<endl;
// #endif
//             strcpy(resultBuffer+resultLen,"push\npop\n");
//             resultLen += 9;
//             i++;
//             r++;
//             continue;
//         }
//         if(outArray[i]<r)
//         {
//             if(outArray[i] == stack.top())
//             {
// #ifdef DEBUG
//                 cout<<"pop "<<outArray[i]<<endl;
// #endif
//                 stack.pop();
//                 i++;
//                 continue;
//             }
//             else
//             {
//                 printf("No\n");
//                 return 0;
//             }
//         }
//         if(outArray[i] > r)
//         {
//             while(outArray[i] > r)
//             {
//                 if(stack.full())
//                 {
//                     printf("No\n");
//                     return 0;
//                 }
// #ifdef DEBUG
//                 cout<<"push "<<r<<endl;
// #endif
//                 stack.push(r++);
//             }
//             if(stack.full())
//             {
//                 printf("No\n");
//                 return 0;
//             }
// #ifdef DEBUG
//                 cout<<"push "<<r<<endl<<"pop "<<r<<endl;
// #endif

//             strcpy(resultBuffer+resultLen,"push\npop\n");
//             resultLen += 9;
//             r++;
//             i++;
//         }
//     }
// 	printf("%s",resultBuffer);
// 	printf("Yes\n");
//     return 0;
// }