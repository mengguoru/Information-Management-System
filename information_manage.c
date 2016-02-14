#include "information_manage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_manual()
{
	printf("input choiece below:\n2: Search\n3: Create\n 4 : Read \n 5 : Update \n 6 : Delete \n");
}

void search_for()
{
	int n;
	printf("the id you want to search:");
	scanf("%d",&n);
	Node *head = read_data();
	Node *p = search(head,n);
	printf("%d %s %s\n", p->itm.id,p->itm.name,p->itm.message);
}

Node* search(Node *head,int id_search)
{
	Node *p = head;
	while(p != NULL)
	{
		if(p->itm.id == id_search)
			return p;
	}
	return NULL;
}

void create()
{
	Node *head = read_data();
	Node *Node_create = (Node *)malloc(sizeof(Node));
	Node_create->next = NULL;
	printf("input item id name message (example format: 10 xxx xxx):\n");
	scanf("%d %s %s",&(Node_create->itm.id),Node_create->itm.name,Node_create->itm.message);
	// test list
	print_list(Node_create);
	insert(head,Node_create);	
	print_list(head);
	write_data(head);
}

void read()
{
	FILE *fp;
	int id;
	char str1[10],str2[256];
	if((fp = fopen("information_manage.data","r")) == NULL)
	{
		printf("information_manage.data not exists\n");
		return;
	}
	while(!feof(fp))
	{
		fscanf(fp, "%d %s %s\n",&id,str1,str2);
		printf("%d %s %s\n",id,str1,str2);
	}
	fclose(fp);
}

Node* read_data()
{
	Node *p1 = NULL,*head = NULL;
	FILE *fp;
	if((fp = fopen("information_manage.data","r")) == NULL)
	{
		printf("information_manage.data open failed\n");
		return NULL;
	}
	while(!feof(fp))
	{
		Node *temp = (Node *)malloc(sizeof(Node));
		if(temp == NULL)
		{
			printf("malloc failed\n");
			return NULL;
		}
		fscanf(fp, "%d %s %s\n",&(temp->itm.id),temp->itm.name,temp->itm.message);
		if(head == NULL)
		{
			head = temp;
			p1 = head;
		}else{
			p1->next = temp;
			p1 = p1->next;
			p1->next = NULL;
		}
	}
	fclose(fp);
	return head;
}

int write_data(Node *head)
{
	FILE *fp;
	if((fp = fopen("information_manage.data","w")) == NULL)
	{
		printf("information_manage.data open failed\n");
		return -1;
	}
	Node *p = head;
	while(p != NULL)
	{
		fprintf(fp, "%d %s %s\n",p->itm.id,p->itm.name,p->itm.message );
		p = p->next;
	}
	fclose(fp);
	return 0;
}

void update()
{
	int id;
	char the_name[10],the_message[256];
	printf("the id you want to change:");
	scanf("%d\n",&id);
	printf("the name && message change to :");
	scanf("%s %s",the_name,the_message);
	Node *head = read_data();
	Node *p = search(head,id);
	strcpy(p->itm.name,the_name);
	strcpy(p->itm.message,the_message);
	write_data(head);
}

void delete2()
{
	int id;
	printf("the id you want to delete");
	scanf("%d",&id);
	Node *head = read_data();
	Node *p1 = head;
	while(p1->next!= NULL)
	{
		if(p1->next->itm.id == id)
			p1->next = p1->next->next;
		free(p1->next);
	}
	write_data(head);
}

void delete(Node *head,int the_id)
{
	printf("call delete()\n");
}

// insert to tail
void insert(Node *head ,Node *Node_insert)
{
	Node *p1 = head;
	while(p1 != NULL)
		p1 = p1->next;
	p1 = Node_insert;
	p1 ->next = NULL;
}

// for test
void print_list(Node *head)
{
	Node *p1 = head;
	while(p1 != NULL)
	{
		printf("%d %s %s\n",p1->itm.id,p1->itm.name,p1->itm.message );
		p1 = p1->next;
	}
}