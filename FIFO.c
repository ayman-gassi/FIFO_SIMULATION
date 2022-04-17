#include<stdio.h>
#include<stdlib.h>

typedef struct pro{
    int id;
    int r_time;   //remaining time
    int a_time;   //arrival time
    int priority;
    struct pro* next;
}process;


process* create_process(int id1,int r_time1,int a_time1,int priority1){
    process* NOUVEAU=(process*)malloc(sizeof(process));
    NOUVEAU->id=id1;
    NOUVEAU->a_time=a_time1;
    NOUVEAU->priority=priority1;
    NOUVEAU->r_time=r_time1;
    NOUVEAU->next=NULL;
    return NOUVEAU;
}

typedef struct {
    process *head;
    process *tail;
    int size;
    int quantum;  // UNTIL "TOURNIQET"
}queue;

queue* ini_queue(){
    queue* NB=(queue*)malloc(sizeof(queue));
    NB->head=NULL;
    NB->tail=NULL;
    NB->size=0;
    NB->quantum=0;
    return NB;
}

process* pop_process(queue* Lis){
    process* ND=NULL;
    if(Lis->head==NULL)exit(1);
    else if(Lis->head==Lis->tail){
    	ND=Lis->head;
        Lis->head=NULL;
	}
	else{
        ND=Lis->head;
        Lis->head=Lis->head->next;
    }
    
    ND->next==NULL;
    return ND;
}
void push(queue* Lis,process* Aux){
    if(Lis->head==NULL){
        Lis->head=Lis->tail=Aux;
    }
    else{
        Lis->tail->next=Aux;
        Lis->tail=Lis->tail->next;
    }
}
int EXECUTION(queue* Lis,int Y){
	int i;
	process* NB=NULL;
	for(i=0;i<Y;i++)
		printf(" ");
	while(Lis->head->r_time!=0){
		Lis->head->r_time--;
		Y++;
		printf("X");
	}
	NB=pop_process(Lis);
	return Y;
}

void GANTTDIAGRAMM(queue* Lis){
	int Y=0;
	int i=1;
	while(Lis->head!=NULL){
		printf("PROCESS Num %d : ",Lis->head->id);
		Y=EXECUTION(Lis,Y);
		printf("\n");
		i++;
	}
}


void AFFICHAGE(queue* Lis){
    process* Aux=Lis->head;
    while(Aux!=NULL){
        printf("------------------PROCESS ID %d   ------------------:\n",Aux->id);
        Aux=Aux->next;
    }
}

process* search_fifo(queue Lis,process* proc){
	queue Lis1=Lis;
	while(Lis1.head->a_time<proc->a_time&&Lis.head->next!=NULL){
		Lis1.head=Lis1.head->next;
	}
	return Lis1.head;
}

queue* push_fifo1(queue* Lis,process* proc,process* search_v){
	queue* F2=ini_queue();
	if(Lis->head->a_time<proc->a_time)
	    push(F2,pop_process(Lis));
	else{
	while(Lis->head!=search_v){
	push(F2,pop_process(Lis));
    }
  }
	push(F2,proc);
	while(Lis->head!=Lis->tail){
		push(F2,pop_process(Lis));
	}
	push(F2,pop_process(Lis));
	return F2;
	}
	
queue* create_fifo1(){
	int i,N,ident,e_tempo,r_tempo,a_tempo,priorite;
	queue* Lis=ini_queue();
	process* Aux=NULL;
	printf("HOW MANY PROCESS YOU WANNA ENTER ?:");
	scanf("%d",&N);
	for(i=0;i<N;i++){
		printf("\n------------------- PROCESS N.%d -------------------\n",i);
		printf("ENTER ID.:");
		scanf("%d",&ident);
		printf("ENTER REMAINING TIME :");
		scanf("%d",&r_tempo);
		printf("ENTER ACCESS TIME :");
		scanf("%d",&a_tempo);
		printf("ENTER PRIORITE :");
		scanf("%d",&priorite);
		Aux=create_process(ident,r_tempo,a_tempo,priorite);
		if(Lis->head==NULL){
			push(Lis,Aux);
		}
		else{
		printf("\n\n  PROCESS ID: %d \n\n",Aux->id);
		Lis=push_fifo1(Lis,Aux,search_fifo(*Lis,Aux));	
	    	AFFICHAGE(Lis);
}}
	return Lis;
}

int main(){
    queue* Lis=create_fifo1();
    GANTTDIAGRAMM(Lis);
    return 0;
}
