#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct node {

	struct node* next;
	int data;

} Node;

void push_to_tail(Node* list_copy, int data) 
{
	Node* tmp = (Node*)malloc(sizeof(Node));

	tmp->data = data;
	tmp->next = NULL;

	while ((list_copy->next) != NULL) 
		list_copy = list_copy->next; 
	list_copy->next = tmp;
}

void print_from_head(Node* list_copy) {

	if (list_copy == NULL) 
	{ 
		printf("List is empty.\n"); return; 
	}

	printf("Print list from HEAD: ");

	while (list_copy != NULL) 
	{
		printf("Elem - %d ", list_copy->data);
		list_copy = list_copy->next;
	}
	printf("\n");
}


void pushFirst(Node** head, int a)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = a;
	tmp->next = (*head);
	(*head) = tmp;
}

int search(Node* head, int x)
{
	Node* temp = head;

	bool flag = false;

	if (head == NULL || temp == NULL) return -1;

	while (temp != NULL)
	{
		if (temp->data == x)
		{
			return 1;

		}

		temp = temp->next;
	}

	return 0;
}

void create(Node* head1, Node* head2)
{
	Node* head3 = (Node*)malloc(sizeof(Node));

	head3 = NULL;


	while (head1 != NULL)
	{
		if (search(head2, head1->data) == 1)
		{
			pushFirst(&head3, head1->data);
			break;
		}
		head1 = head1->next;
	}
	head1 = head1->next;

	while (head1 != NULL)
	{

		if (search(head2, head1->data) == 1) 
			push_to_tail(head3, head1->data);

		head1 = head1->next;
	}
	print_from_head(head3);
}

void listEntry(Node** list, int len)
{
	int i = 0;

	while (i < len)
	{
		int tmp;
		scanf("%d", &tmp);

		if (i == 0) pushFirst(list, tmp);
		else push_to_tail(*list, tmp);

		i++;
	}
}

int main()
{
	Node* head1 = (Node*)malloc(sizeof(Node));

	head1 = NULL;

	Node* head2 = (Node*)malloc(sizeof(Node));

	head2 = NULL;

	int len1, len2, i = 0;

	printf("Enter count of the elements of list 1\n");
	scanf("%d", &len1);

	listEntry(&head1, len1);

	printf("Enter count of the elements of list 2\n");
	scanf("%d", &len2);

	listEntry(&head2, len2);

	print_from_head(head1);
	print_from_head(head2);

	create(head1, head2);

	free(head1);
	free(head2);

}
