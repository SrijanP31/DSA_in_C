#include <stdio.h>

struct stack{
	int stack_arr[10];
	int top;
};

void push(struct stack* inp, int data){
	if(inp->top == 9){
		printf("Stack overflow");
	}else{
		inp->top = inp->top + 1;
		inp->stack_arr[inp->top] = data;
	}
}

int pop(struct stack* inp){
	int val;
	if(inp->top == -1)
		printf("Stack underflow");
	else{
		val = inp->stack_arr[inp->top];
		inp->top = inp->top - 1;
	}
	return val;
}

int main(){
	
	struct stack my_stack;
	push(&my_stack, 5);
	push(&my_stack,7);
	printf("First pop: %d\n",pop(&my_stack));
	printf("Second pop: %d\n",pop(&my_stack));
	return 0;
}


