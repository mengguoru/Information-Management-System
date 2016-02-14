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
	struct  _Node *next;
}Node;

#define QUIT 0
#define MAINTAIN 1
#define SEARCH 2
#define CREATE 3
#define READ 4
#define UPDATE 5
#define DELETE 6

void print_manual();

void search_for();
Node* search(int id_search);
void create();
void read();
void update(int the_id);
void delete(int the_id);

Node* read_data();
int write_data(Node *head);
void insert(Node *head ,Node *Node_insert);
// below function is for test
void print_list(Node *head);
#endif