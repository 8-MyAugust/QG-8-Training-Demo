#include "��ͷ.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct two {
	int i;
	struct two* next;
	struct two* pre;
}Two;
Two* head = NULL;
int n;//����ͳ�ƽ�����
int flag = 1;//�ź������ж��Ƿ�ֹͣ

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
			printf("����ǰ��������󲻴���,���������룺");

		}
	} while (true);



	return 0;


}
////������������ĺ���
//One* Create1() {
//	One* head, * p1, * p2;
//	n = 1;	//��ʼ����������	//���ﻹ���ԼӸ��жϸ������ǲ��ǿ�����(��ûд)
//	p1 = p2 = (One*)malloc(LEN1);//����һ���µ�Ԫ
//	printf("�������%d���ڵ��ֵ\n", n);
//	scanf_s("%d", & (p1->i));//��������
//	printf("��%d���ڵ㴴���ɹ�������������ϣ�������0�������贴���ڵ㣬������1\n",n);
//	head = NULL;
//	while (flag!=0) {
//		n++;//�ڵ����ͳ��
//		if (n == 2)head = p1;
//		else p2->next = p1;
//		p2 = p1;
//		p1  = (One*)malloc(LEN1);
//		printf("�������%d���ڵ��ֵ\n", n);
//		scanf_s("%d", &(p1->i));//��������
//		printf("��%d���ڵ㴴���ɹ�������������ϣ�������0�������贴���ڵ㣬������1\n",n);
//		scanf_s("%d",&flag);
//
//	}
//	(p2->next) = NULL;
//	printf("�����������ɹ���������Ϊ%d!",n);
//	return head;
//}
void InitTwoList() {//����������
	Two* node;
	node = (Two*)malloc(sizeof(Two));
	if (node == NULL) {
		printf("�ռ俪��ʧ��\n");
		return;
	}
	node->next = NULL;
	node->pre = NULL;
	head = node;
	printf("��ʼ���ɹ���\n");
}
void InsertList() {//��������
	if (head == NULL) {
		printf("��������δ���������ȴ�������\n");
	}
	Two* newNode;
	newNode = (Two*)malloc(sizeof(Two));//�����½ڵ�
	printf("������Ҫ��ӵ����ݣ�");
	scanf("%d ", &newNode->i);
	Two* current = head;
	while (current->next != NULL) {//β�巨��������
		current = current->next;
	}
	current->next = newNode;//β�ڵ�ָ���½ڵ�
	newNode->pre = current;//˫����������ָ
	newNode->next = NULL;
	printf("���ݲ���ɹ���\n");
}
void TraverseList() {//��������
	if (head == NULL || head->next == NULL) {
		printf("����Ϊ�գ��������\n");
		return;
	}
	printf("������������:\n");
	while (head != NULL) {//����������ӡ����
		head = head->next;
		printf("%d\t", head->i);
	}
	printf("\n");
}
void DestroyList() {//�ݻ�����
	if (head == NULL) {
		printf("����Ϊ�գ��������٣�\n");
		return;
	}
	Two* p;
	while (head != NULL) {
		p = head;//��¼head�ڵ㣬�Դ��ں����ͷſռ�
		head = head->next;
		free(p);
	}
	printf("�������ٳɹ���\n");
}
/*Two * Create2() {

	return
}*/
void menu_1() {
	printf("*************************************************\n");
	printf("********1.�����µ�˫������     ******************\n");
	printf("********2.��˫�������������   ******************\n");
	printf("********3.����˫������         *******************\n");
	printf("********4.�ݻ�˫������         ******************\n");
	printf("********5.�˳�����             ******************\n");
	printf("*************************************************\n");
	printf("�������������1-5����\n");
}