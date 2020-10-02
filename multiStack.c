#include<stdio.h>
#include<stdlib.h>
#define max 20
typedef struct{
	int data[max];          //Stack size is 10
	int top;
 }STACK;
void push1(STACK* S, int v);
void push2(STACK* S, int v);
int pop1(STACK* S, int *v);
int pop2(STACK* S, int *v);
int main(){
	int i,val,num,val1,val2;
	STACK S1,S2;            //S1 denotes Stack 1 growing from 0th side, S2 denotes Stack 2 growing from nth side
	S1.top = -1;
	S2.top = max;
	printf("How Many Times You Want To Push On The Multistack?");
	scanf("%d",&num);
	for(i=0; i<num; i++){
		int choice;
		printf("On Which Stack Would You Like To Push?(1/2)");
		scanf("%d",&choice);
		if(choice == 1){          //choice 1 denotes Stack 1
			printf("Enter Data : ");
			scanf("%d",&val);
			push1(&S1,val);	
		}
		if(choice == 2){          //choie 2 denotes Stack 2
			printf("Enter Data : ");
			scanf("%d",&val);
			push2(&S2,val);		
		}	
	}
	printf("How many Times Do You Want To Pop On The MultiStack?");
	scanf("%d",&num);
	for(i=0;i<num;i++){
		if( S1.top + 1 == S2.top || S2.top - 1 == S1.top  ){
			printf("OverFlowed!!!");		
		}
		else{
		int choice;
		printf("On Which Stack Would You Like To Push?(1/2)");
		scanf("%d",&choice);
		if(choice == 1){          
			int p = pop1(&S1,&val);	
		}
		else {
			int q = pop2(&S2,&val);		
		}
		}	
	}
	printf("The 1st Stack is :- \n");
	while(S1.top != -1){
		pop1(&S1,&val1);
		printf("%d",val1);	
	}
	printf("\nThe 2nd Stack is :- \n");
	while(S2.top != max){
		pop2(&S2,&val2);
		printf("%d",val2);	
	}	
 }
void push1(STACK* S, int v){        //This push function works on the Stack growing from the 0th side
	S->top++;
	S->data[S->top] = v;	
 }
void push2(STACK* S, int v){        //This push function works on the Stack growing from the nth side
	S->top--;
	S->data[S->top] = v;
 }
int pop1(STACK* S, int *v){         //This pop function works on the Stack growing from the 0th side
	if(S->top == -1){     
		printf("UnderFlowed");	
	}
	*v = S->data[S->top];
	S->top--;	
 }    
int pop2(STACK* S, int *v){         //This pop function works on the Stack growing from the nth side
	if(S->top == max){
		printf("UnderFlowed");	
	}
	*v = S->data[S->top];
	S->top++;
 }
