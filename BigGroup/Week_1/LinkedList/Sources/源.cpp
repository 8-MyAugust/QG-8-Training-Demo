#include "标头.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct two {
	int i;
	struct two* next;
	struct two* pre;
}Two;
Two* head = NULL;
int n;//用于统计结点个数
int flag = 1;//信号量，判断是否停止

int main() {
	int choice;

	do {
		menu_1();
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			InitTwoList();
			break;
		case 2:
			InsertList();
			break;
		case 3:
			TraverseList();
			break;
		case 4:
			DestroyList();
			break;
		case 5:

			break;
			/*case 6:
				Reverse();
				break;
			case 7:
				Bye();
				break;*/
		default:
			printf("您当前输入的请求不存在,请重新输入：");

		}
	} while (true);



	return 0;


}
////创建单向链表的函数
//One* Create1() {
//	One* head, * p1, * p2;
//	n = 1;	//初始化单向链表	//这里还可以加个判断该链表是不是空链表(还没写)
//	p1 = p2 = (One*)malloc(LEN1);//开辟一个新单元
//	printf("请输入第%d个节点的值\n", n);
//	scanf_s("%d", & (p1->i));//输入数据
//	printf("第%d个节点创建成功，若链表创建完毕，请输入0；若仍需创建节点，请输入1\n",n);
//	head = NULL;
//	while (flag!=0) {
//		n++;//节点个数统计
//		if (n == 2)head = p1;
//		else p2->next = p1;
//		p2 = p1;
//		p1  = (One*)malloc(LEN1);
//		printf("请输入第%d个节点的值\n", n);
//		scanf_s("%d", &(p1->i));//输入数据
//		printf("第%d个节点创建成功！若链表创建完毕，请输入0；若仍需创建节点，请输入1\n",n);
//		scanf_s("%d",&flag);
//
//	}
//	(p2->next) = NULL;
//	printf("单向链表创建成功！链表长度为%d!",n);
//	return head;
//}
void InitTwoList() {//创建新链表
	Two* node;
	node = (Two*)malloc(sizeof(Two));
	if (node == NULL) {
		printf("空间开辟失败\n");
		return;
	}
	node->next = NULL;
	node->pre = NULL;
	head = node;
	printf("初始化成功！\n");
}
void InsertList() {//插入数据
	if (head == NULL) {
		printf("该链表尚未创建，请先创建链表！\n");
	}
	Two* newNode;
	newNode = (Two*)malloc(sizeof(Two));//开辟新节点
	printf("请输入要添加的数据：");
	scanf("%d ", &newNode->i);
	Two* current = head;
	while (current->next != NULL) {//尾插法遍历链表
		current = current->next;
	}
	current->next = newNode;//尾节点指向新节点
	newNode->pre = current;//双向链表往回指
	newNode->next = NULL;
	printf("数据插入成功！\n");
}
void TraverseList() {//遍历链表
	if (head == NULL || head->next == NULL) {
		printf("链表为空，无需遍历\n");
		return;
	}
	printf("链表数据如下:\n");
	while (head != NULL) {//遍历链表，打印数据
		head = head->next;
		printf("%d\t", head->i);
	}
	printf("\n");
}
void DestroyList() {//摧毁链表
	if (head == NULL) {
		printf("链表为空，无需销毁！\n");
		return;
	}
	Two* p;
	while (head != NULL) {
		p = head;//记录head节点，以此在后面释放空间
		head = head->next;
		free(p);
	}
	printf("链表销毁成功！\n");
}
/*Two * Create2() {

	return
}*/
void menu_1() {
	printf("*************************************************\n");
	printf("********1.创建新的双向链表     ******************\n");
	printf("********2.向双向链表插入数据   ******************\n");
	printf("********3.遍历双向链表         *******************\n");
	printf("********4.摧毁双向链表         ******************\n");
	printf("********5.退出程序             ******************\n");
	printf("*************************************************\n");
	printf("请输入你的需求（1-5）：\n");
}