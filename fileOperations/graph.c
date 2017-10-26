#include<stdio.h>
#include<stdlib.h>

struct graphNode{
	int data;
	struct graphNode *links[10];
};

struct graph{
	struct graphNode *node;
	struct graph *next;
}*g = NULL;

struct graphNode* createGraphNode(int data){
	struct graphNode *ptr = (struct graphNode*) malloc(sizeof(struct graphNode*));
	ptr->data = data;
	int i = 0;
	for(i=0; i<10; i++){
		ptr->links[i] = NULL;
	}
	return ptr;
}

void addLinks(struct graphNode *from, struct graphNode *to){
	int i = 0;
	for(i = 0; i<10; i++){
		if((from->links[i] == NULL)&&(from->links[i]!=to)){
			break;
		}
	}
	from->links[i] = to;
}

struct graph* createGraph(int data){
	printf("Here's the problem\n");
	struct graph *ptr = (struct graph*) malloc(sizeof(struct graph*));
	printf("Here topoo!!\n");
	ptr->node = createGraphNode(data);
	printf("But not here tho \n");
	ptr->next = NULL;
	return ptr;
}

void addNode(int data){
	struct graph *cur = g;
	printf("Hello\n");
	int flag = 0;
	while(cur!=NULL){
		if(cur->node->data == data){
			flag = 1;
			break;
		}
		cur = cur->next;
	}
	if(flag == 0){
		cur = g;
		if(g == NULL){
			g = createGraph(data);
		}
		else{
			printf("Here\n");
			while(cur->next!=NULL){
				cur = cur->next;
			}
			cur->next = createGraph(data);
		}
		printf("Outa here\n");
	}
}

void displayGraph(){
	struct graph *cur = g;
	printf("Wanna go?\n");
	while(cur!=NULL){	
		printf("%d:", cur->node->data);
		int i = 0;
		for(i = 0; i<10; i++){
			printf(" %d,", cur->node->links[i]->data);
		}
		printf("\n");
		cur = cur->next;
	}
	printf("Bye\n");
}

int main(){
	addNode(1);
	addNode(2);
	displayGraph();	
	return 0;
}
