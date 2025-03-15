#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* prev;
	struct node* next;
};

void print_dll(struct node* head){
	struct node* temp = head;
	while(temp != NULL){
		printf("%d --> ",temp->data);
		temp = temp->next;
	}
	printf("NULL \n");
}
struct node* add_front(struct node* temp, struct node* head){
	temp->prev = NULL;
	temp->next = head;
	head->prev = temp;
	head = temp;
	return head;
}

struct node* add_end(struct node* temp,struct node* head){
	struct node* curr = head;
	while(curr->next != NULL){
		curr = curr->next;
	}
	temp->prev = curr;
	temp->next = NULL;
	curr->next = temp;
	return head;
}

struct node* add_mid(struct node* temp, struct node* head, int pos){
	struct node* curr = head;
	while((pos-- != 1) && (curr->next != NULL))
		curr = curr->next;
	temp->prev = curr;
	temp->next = curr->next;
	curr->next->prev = temp;
	curr->next = temp;
	return head;
}

struct node* del_front(struct node* head){
	struct node* temp = head;
	head = head->next;
	head->prev = NULL;
	free(temp);
	return head;
}

struct node* del_end(struct node* head){
	struct node* temp = head;
	struct node* del;
	while(temp->next != NULL)
		temp = temp->next;
	del = temp;
	temp = temp->prev;
	temp->next = NULL;
	free(del);
	return head;
}

int main(){
	struct node* head = (struct node*) malloc(sizeof(struct node));
	struct node* node1 = (struct node*) malloc(sizeof(struct node));
	struct node* node2 = (struct node*) malloc(sizeof(struct node));
	struct node* node3 = (struct node*) malloc(sizeof(struct node));
	
	head->prev = NULL;
	head->data = 3;
	head->next = node1;
	
	node1->prev = head;
	node1->data = 7;
	node1->next = node2;
	
	node2->prev = node1;
	node2->data = 5;
	node2->next = NULL;
	
	node3->prev = NULL;
	node3->data = 1;
	node3->next = NULL;
	
	printf("Initial DLL: \n");
	print_dll(head);
	
	printf("Adding node in middle: \n");
	head = add_mid(node3,head,1);
	print_dll(head);
	
	printf("Removing tail node: \n");
	head = del_end(head);
	print_dll(head);
	
	return 0;
}
