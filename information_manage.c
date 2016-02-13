#include "information_manage.h"
#include <stdio.h>
#include <stdlib.h>
void print_manual()
{
	printf("input choiece below:\n1:xxx\n2:xxx\n");
}

Node* search()
{
	printf("call search()\n");

}

void create()
{
	printf("call create()\n");
	Node *head = read_data();
	// test list
	print_list(head);
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
		printf("information_manage.data not exists\n");
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

void update(int the_id)
{
	printf("call update()\n");
}

void delete(int the_id)
{
	printf("call delete()\n");
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