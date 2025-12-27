#include <stdio.h>
#include <stdlib.h>
/*说明：本程序实现了创建学生链表和删除链表中成绩小于指定值的节点的功能。// 通过这道题目，我们可以学习链表的基本操作，包括创建链表、遍历链表以及删除节点等。*/
//另外，程序中还展示了两种不同的删除节点的方法，第一种方法在删除节点时需要遍历链表以找到前一个节点，而第二种方法通过使用前驱指针，提高了删除操作的效率。
struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};

struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );

int main()
{
    int min_score;
    struct stud_node *p, *head = NULL;

    head = createlist();
    scanf("%d", &min_score);
    head = deletelist(head, min_score);
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

/* 程序体 */struct stud_node *createlist(){// 创建链表
    struct stud_node *phead=NULL,*pfore,*pnew;
    do{
    pnew=(struct stud_node *)malloc(sizeof(struct stud_node));
    scanf("%d",&pnew->num);
    if(pnew->num==0){// 输入0结束
        free(pnew);
        break;
    }
    scanf("%s%d",pnew->name,&pnew->score);
    pnew->next=NULL;
    if(phead==NULL)
        phead=pnew;
    else{
        pfore->next=pnew;}
    pfore=pnew;
    }while(1);
    return phead;// 返回链表头指针
}
struct stud_node *deletelist( struct stud_node *head, int min_score ){ // 删除链表中成绩小于min_score的节点,这段代码反映了我们删除链表中的元素的思路（各个位置）
    for(struct stud_node *p=head;p!=NULL;p=p->next){
        if(p->score<min_score){
            if(p==head){// 删除头节点
                head=p->next;
                free(p);
            }
            else if(p->next==NULL){// 删除尾节点，这里也是我想放上来这道题的原因：我们在找要删除的结点时，无法找到它的前一个结点，必须遍历一遍，增加了时间。//
                struct stud_node *q=head;
                while(q->next!=p){
                    q=q->next;
                }
                q->next=NULL;
                free(p);
            }
            else{// 删除中间节点
                struct stud_node *q=head;
                while(q->next!=p){
                    q=q->next;
                }
                q->next=p->next;
                free(p);
            }
            }
        }
   return head;
}
/*下面展示一种更高效的删除方法*/
struct stud_node *deletelist_efficient( struct stud_node *head, int min_score ){
    struct stud_node *p=head;
    struct stud_node *prev=NULL;// 前驱指针
    while(p!=NULL){
        if(p->score<min_score){
            if(prev==NULL){//删除头节点（请注意，模拟第一轮，这里已经判断过头节点的分数情况）
                head=p->next;
                free(p);//提醒下：及时释放内存
                p=head;
            }
            else{// 删除中间或尾节点
                prev->next=p->next;
                free(p);
                p=prev->next;
            }
        }
        else{
            prev=p;// 更新前驱指针，这一步是灵魂，始终保留前驱节点
            p=p->next;
        }
    }
    return head;
}