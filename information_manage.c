#include "information_manage.h"
#include <stdio.h>
void print_manual()
{
	printf("input choiece below:\n1:xxx\n2:xxx\n");
}

void search(int the_id)
{
	printf("call search()\n");
}

void create()
{
	printf("call create()\n");
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

void update(int the_id)
{
	printf("call update()\n");
}

void delete(int the_id)
{
	printf("call delete()\n");
}