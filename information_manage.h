#ifndef _INFORMATION_MANAGE_H
#define _INFORMATION_MANAGE_H
typedef struct _Item
{
	int id;
	char name[10];
	char message[256];
}Item;
typedef struct _Node
{
	Item itm;
	struct  Node *next;
}Node;
void print_manual();

void search(int the_id);
void create();
void read();
void update(int the_id);
void delete(int the_id);
#endif