#include <stdio.h>
 #include <stdlib.h>

 typedef struct Node
 {
     int data;
     struct Node *next, *pre;
 }node, *pnode;

 typedef struct Count
 {
     int data, num;
     struct Count *next, *pre;
 }count, *pcount;

 int main(void)
 {
     pnode shead = (pnode)malloc(sizeof(node));
     pnode tmp1, stail = shead;

     pcount phead = (pcount)malloc(sizeof(count));
     pcount tmp2, ptail = phead;

     int n;

     scanf("%d", &n);

     for (int i = 0; i < n; ++i)
     {
         char ch;
         int x, a;

         do
         {
             ch = getchar();
         } while ((ch != 'E') && (ch != 'M') && (ch != 'D'));

         switch (ch)
         {
             case 'E':
                 scanf("%d", &x);

                 // x into s
                 tmp1 = (pnode)malloc(sizeof(node));
                 tmp1->data = x;
                 stail->next = tmp1; tmp1->pre = stail; stail = tmp1;

                 // prepare num for x into p
                 a = 1;
                 tmp2 = (pcount)malloc(sizeof(count));
                 ptail->next = tmp2; tmp2->pre = ptail; ptail = tmp2;
                 while ((ptail->pre != phead) && (ptail->pre->data <= x))
                 {
                     a += ptail->pre->num;

                     tmp2 = ptail->pre;
                     tmp2->pre->next = ptail;
                     ptail->pre = tmp2->pre;
                     delete tmp2;
                 }

                 // x into p
                 ptail->data = x; ptail->num = a;

                 break;
             case 'D':
                 printf("%d\n", shead->next->data);
                 shead = shead->next;
                 delete shead->pre;

                 if (!(--(phead->next)->num))
                 {
                     phead = phead->next;
                     delete phead->pre;
                 }
                 break;
             case 'M':
                 printf("%d\n", phead->next->data);
                 break;
         }
     }

     return 0;
 }
