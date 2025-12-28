#include <stdio.h>
#include <stdlib.h>
//这是一道链表题，输入中已经保证两链表分别正向排序，题目要求合并两个有序链表，合并后的链表依然有序
//放上来的目的是比较一下两个链表的合并思路（vs gemini）请关注mergelists函数
struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); 
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode  *list1, *list2;

    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);
    
    return 0;
}

struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2)//合并两个有序链表
//version1
{
   if(list1==NULL)return list2;
   if(list2==NULL)return list1;//处理空链表情况
	struct ListNode *p, *pre, *phead=list1,*pi,*temp;
	p = list2;
	if (list2->data < list1->data)//确定合并后链表的头节点
	{
		while (p->data < list1->data)
		{
			pre = p;
			p = p->next;
		}
		pre->next = list1;//把list1接到pre后面
		phead = list2;
	}
   for(pi=p;pi!=NULL;pi=pi->next){//遍历list2中的每一个节点
      for(struct ListNode*i=list1;i!=NULL;i=i->next){//在list1中找到pi应该插入的位置
         if(i->next!=NULL){//避免i->next为空时访问出错(即最后一个结点）
         if(i->data<=pi->data&&(i->next->data)>=pi->data){
            temp=malloc(sizeof(struct ListNode));
            temp->data=pi->data;
            temp->next=i->next;
            i->next=temp;
            break;
         }}
         else if(i->data<=pi->data){//处理list2中节点比list1中所有节点都大的情况
            i->next=pi;
            return phead;//连上list2后续后直接返回
         }
      }
   }
   return phead;

}//评价：思路还行，但效率低，每次插入都需要遍历list1，时间复杂度较高。
/*version2 from gemini
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2)
{
    // 1. 处理特殊情况：如果有链表为空，直接返回另一个
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode *head = NULL, *tail = NULL;

    // 2. 确定合并后的头节点（谁小谁当头）
    // 注意这里用了 <=，处理了相等的情况
    if (list1->data <= list2->data) {
        head = tail = list1;
        list1 = list1->next;
    } else {
        head = tail = list2;
        list2 = list2->next;
    }

    // 3. 只要两个链表都还有节点，就不断比较、拼接
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) { // 谁小（或相等），谁接在后面
            tail->next = list1;   // 尾巴接上 list1
            list1 = list1->next;  // list1 指针后移
        } else {
            tail->next = list2;   // 尾巴接上 list2
            list2 = list2->next;  // list2 指针后移
        }
        tail = tail->next;        // 更新尾指针到最新节点
    }

    // 4. 如果有一个链表先走完了，把另一个链表剩下的所有节点直接接在后面
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return head;//评价：思路清晰，效率高，代码对称又整齐
}*/
struct ListNode *createlist() {
    struct ListNode *head = NULL, *tail = NULL, *p;
    int num;

    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break; // 如果输入是 -1，跳出循环，结束输入
        }

        // 申请内存
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->data = num;
        p->next = NULL;

        // 像上一题一样挂载节点
        if (head == NULL) {
            head = tail = p; // 第一个节点
        } else {
            tail->next = p;  // 接在尾部
            tail = p;        // 更新尾指针
        }
    }
    return head;
}
