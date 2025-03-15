#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void print_LL(struct node* head){
    struct node* cur = head;
    while(cur != NULL){
        printf("%d->",cur->data);
        cur = cur->next;
    }
    printf("NULL. \n");
}

struct node* insert_head(struct node* head, struct node* new){
    new->next = head;
    head = new;
    return head;
}

struct node* insert_tail(struct node* head, struct node* new){
    struct node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new;
    new->next = NULL;
    return head;
}

struct node* insert_mid(struct node* head, struct node* new,int pos){
	struct node* temp=head;
	while((pos-- != 1) && (temp != NULL))
		temp = temp->next;
	
	new->next = temp->next;
	temp->next = new;
	return head;
}

struct node* del_head(struct node* head){
	struct node* temp=head;
	head = head->next;
	return head;
}

struct node* del_tail(struct node* head){
	struct node *temp,*cur;
	cur = head;
	while(cur->next != NULL){
		temp = cur;
		cur = cur->next;
	}
	temp->next = NULL;
	return head;
}

struct node* del_mid(struct node* head, int pos){
	struct node* temp = head;
	while(pos-- != 1)
		temp = temp->next;
	temp->next = temp->next->next;
	return head;
}

void main() {

    struct node node1;
    struct node node2;
    struct node node3;
    struct node node4;
    struct node node5;
    struct node node6;

    struct node* head1;

    node1.data = 1;
    node1.next = &node2;

    node2.data = 2;
    node2.next = &node3;
    
    node3.data = 3;
    node3.next = NULL;
    
    head1 = &node1;
    
    printf("Initial Linked List: \n");
    print_LL(head1);
    printf("\n");

    //New node
    node4.data = 4;
    node4.next = NULL;
    
    node5.data = 5;
    node5.next = NULL;
    
    node6.data = 6;
    node6.next = NULL;

    head1 = insert_head(head1,&node4);
    printf("After head insert of node 4: \n");
    print_LL(head1);
    printf("\n");

    head1 = insert_tail(head1,&node5);
    printf("After tail insert of node 5: \n");
    print_LL(head1);
    printf("\n");
    
    head1 = insert_mid(head1,&node6,3);
    printf("After mid insert of node 6 at pos 3: \n");
    print_LL(head1);
    printf("\n");
    
    head1 = del_head(head1);
    printf("After deleting head:\n");
    print_LL(head1);
    printf("\n");
    
    head1 = del_tail(head1);
    printf("After deleting tail: \n");
    print_LL(head1);
    printf("\n");
    
    head1 = del_mid(head1,2);
    printf("After deleting middle pos 2:\n");
    print_LL(head1);

}
