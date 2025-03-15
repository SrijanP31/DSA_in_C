#include <stdio.h>

struct node{
	int data;
	struct node* next;
};

void print_CLL(struct node* head){
	struct node* curr = head;
	
	do{
		printf("%d -> ",curr->data);
		curr = curr->next;
	}while(curr != head);
}


void insert_mid(int k, struct node* new, struct node* head){
	struct node* curr = head;
	struct node* temp;
	
	//For reaching the node right before insertion
	while(k > 1){
		curr = curr->next;
		k--;
	}
	
	//Insertion step
	temp = curr->next;
	curr->next = new;
	new->next = temp;
		
}

struct node* delete_head(struct node* head){
	struct node* curr = head;
	struct node* temp;
	while(curr->next != head)
		curr = curr->next;
		
	temp = head->next;
	curr->next = temp;
	
	free(head);
	
	return temp;
}

int main(){
	
	struct node* head = calloc(1,sizeof(struct node));
	struct node* node1 = calloc(1,sizeof(struct node));
	struct node* node2 = calloc(1,sizeof(struct node));
	struct node* node3 = calloc(1,sizeof(struct node));
	struct node* node4 = calloc(1,sizeof(struct node));
	
	node4->data = 7;
		
	head->data = 1;
	head->next = node1;
	
	node1->data = 2;
	node1->next = node2;
	
	node2->data = 3;
	node2->next = node3;
	
	node3->data = 4;
	node3->next = head;
	
	printf("Before adding new node: ");
	print_CLL(head);
	printf("\n");
	
	insert_mid(2,node4,head);
	
	printf("After add new node: ");
	print_CLL(head);
	printf("\n");
	
	head = delete_head(head);
	
	printf("After deleting the current head node:");
	print_CLL(head);
	
	return 0;
}
