#include <stdio.h>
#include <stdlib.h>

struct student{
	int Chin;
	int Math;
	student *link;
};
student *front,*rear;

void Cerate_node(void){
	front=(student*)malloc(sizeof(student));
	rear=(student*)malloc(sizeof(student));
	front->link=NULL;
	rear->link=NULL;
}
void insert(int key1,int key2){ //串尾端
	student *new_node;
	new_node=(student*)malloc(sizeof(student));
	new_node->Chin=key1;
	new_node->Math=key2;
	new_node->link=NULL;
	if(front->link==NULL){
		front->link=new_node;
		rear->link=new_node;
	}
	else{
		rear->link->link = new_node;
		rear->link = new_node;
	}
}
void del(int key){	//刪節點
	student *temp_node,*this_node,*pre;

	pre = front;
	this_node = front->link;

	while(this_node->link!=NULL){//搜尋欲刪除節點
		if(key==this_node->Chin){
			temp_node=this_node;
			pre->link=this_node->link;
			free(temp_node);
			return;
		}
		pre=this_node;
		this_node=this_node->link;
	}//刪最後資料
	if(key == this_node->Chin){//搜尋欲刪除節點
		temp_node=this_node;
		pre->link=NULL;
		rear->link=pre;
		free(temp_node);
	}
	else
		printf("NO\n");
}

void Change(int key){	//改節點
	student *temp_node,*this_node,*pre;

	pre = front;
	this_node = front->link;
	int Chan;
	while(this_node->link!=NULL){//搜尋欲改節點
		printf("CHANGE1");
		scanf("%d",&Chan);
		this_node->Chin=Chan;
		return;
		}
		pre=this_node;
		this_node=this_node->link;
	//改最後資料
	if(key == this_node->Chin){//搜尋改刪除節點
		printf("CHANGE");
		scanf("%d",&Chan);
		this_node->Chin=Chan;
	}
	else
		printf("NO123\n");
	}

void print(void){
	student *this_node;
	this_node=front->link;
	while(this_node->link!=NULL){
		printf("%d->",this_node->Chin);
		this_node = this_node->link;
	}
	printf("%d",this_node->Chin);
}

void main(void){

	Cerate_node();
	int i,N=10,DE,IN;
	int a[] = {32,58,54,56,45,15,15,48,45,145};

	for(i=0 ; i<10 ; i++){
		insert(a[i],20);
	}
	print();
	printf("\nEeter 刪除\n");
	scanf("%d",&DE);
	del(DE);
	print();
	printf("\nEeter 插入\n");
	scanf("%d",&IN);
	insert(IN,20);
	print();
	Change(58);
	print();
}
