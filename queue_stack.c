#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct queue{
	int *data;
	size_t start;
	size_t end;
};

struct stack{
	int *data;
	size_t now;
};

size_t capacity = 8;

void selectmode();

void initialize_q(struct queue *queue){
	queue -> start = 0;
	queue -> end = 0;
	if((queue -> data = (int *)malloc(sizeof(int) * capacity)) == NULL){
		printf("memory error.\n");
		exit(1);
	}
	printf("Initialized.\n");
}

void initialize_s(struct stack *stack){
	stack -> now = 0;
	if((stack -> data = (int *)malloc(sizeof(int) * capacity)) == NULL){
		printf("memory error");
		exit(1);
	}
	printf("Initialized.\n");
}

void stackset(struct stack *stack){
	int data;
	if(stack -> now >= capacity){
		int *buf;
		buf = stack -> data;
		printf("stack is full\n realloc...");
		capacity *= 2;
		if((buf = (int *)realloc(stack -> data, capacity)) == NULL){
			printf("memory realloc error\n");
			exit(1);
		}
		free(stack -> data);
		stack -> data = buf;
	}
	printf("Stack: Please set data.\n");
	scanf("%d", &data);
	stack -> data[stack -> now] = data;
	stack -> now++;
}

void stackout(struct stack *stack){
	int data;
	if(stack -> now == 0) printf("Error, Stack is empty.\n");
	else{
		data = stack -> data[stack -> now - 1];
		printf("%d\n", data);
		stack -> now--;
	}
}

void queueset(struct queue *queue){
	int data;
	size_t size = queue -> end;
	int *buf;
	if(queue -> end >= capacity){
		printf("queue is full.\nrealloc...\n");
		buf = queue -> data;
		capacity *= 2;
		if((buf = (int *)realloc(queue -> data, capacity)) == NULL){
			printf("memory realloc error");
			exit(1);
		}
		free(queue -> data);
		queue -> data = buf;
	}
	printf("Queue: Plese set data.\n");
	scanf("%d",&data);
	queue -> data[queue -> end] = data;
	queue -> end++;
}

void queueout(struct queue *queue){
	int data;
	if(queue -> start == queue -> end)	printf("Error.Queue is empty.\n");
	else{
		data = queue -> data[queue -> start];
		printf("%d\n",data);
		queue -> start++;
	}
}

void Queue_mode(struct queue *q){
	int data;
	while(1){
		printf("1->setdata\n2->initialize \n3->output\n4->back\nWhich?: ");
		scanf("%d",&data);
		if(data == 1){
			queueset(q);
		}else if(data == 2){
			free(q -> data);
			initialize_q(q);
		}else if(data == 3){
			queueout(q);
		}else if(data == 4){
			free(q -> data);
			selectmode();
		}else{
			printf("error.\n");
		}
	}
}

void Stack_mode(struct stack *s){
	int data;
	while(1){
		printf("1->setdata\n2->initialize \n3->output\n4->back\nWhich?: ");
		scanf("%d", &data);
		if(data == 1){
			stackset(s);
		}else if(data == 2){
				free(s -> data);
			initialize_s(s);
		}else if(data == 3){
			stackout(s);
		}else if(data == 4){
			free(s -> data);
			selectmode();
		}else{
			printf("error.\n");
		}
	}
}

void selectmode(){
	int which;
	struct queue q;
	initialize_q(&q);
	struct stack s;
	initialize_s(&s);
	while(1){
		printf("Queue? - 1  Stack? - 2\n");
		scanf("%d",&which); 
		if(which == 1){
			Queue_mode(&q);
		}else if(which == 2){
			Stack_mode(&s);
		}else{
			printf("error.\n");
		}
	}
}

int main(){
	selectmode();
	return 0;
}
