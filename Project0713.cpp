#include <stdio.h>
#include <stdlib.h>

struct student{
	int Chin;//學號
	int Score;//分數
	student *link;
};
student *front,*rear;

void Cerate_node(void){
	front=(student*)malloc(sizeof(student));//建立空串列
	rear=(student*)malloc(sizeof(student));
	front->link=NULL;
	rear->link=NULL;
}
void insert(int key1,int key2){ //串尾端
	student *new_node;
	new_node=(student*)malloc(sizeof(student));
	new_node->Chin=key1;//設定學號
	new_node->Score=key2;;//設定分數
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
		printf("NO DATA\n");
}
void Change(int key){	//改節點
	student *this_node,*pre;

	pre = front;
	this_node = front->link;
	int Chan;
	while(this_node->link!=NULL){//搜尋欲改節點
		if(key==this_node->Chin){
			printf("\nEnter 修改\n");
			scanf("%d",&Chan);
			this_node->Score=Chan;
			return;
		}
		pre=this_node;
		this_node=this_node->link;
	}//改最後資料
	if(key == this_node->Chin){//搜尋欲改節點
			printf("\nEnter 修改\n");
			scanf("%d",&Chan);
			this_node->Score=Chan;
	}
	else
		printf("NO DATA\n");
}
void sort(student *p,int count){//串列排序
	int i,value,temp; 
	student *ptr; 
	ptr=p;

	for (i=1;i<=count;i++){
		while(ptr->link !=NULL){
			if ( ptr->link->Score < ptr->Score ){//分數比大小temp&value同時交換
				value=ptr->link->Score;
				temp=ptr->link->Chin;
				ptr->link->Score=ptr->Score;
				ptr->link->Chin=ptr->Chin;
				ptr->Score=value; 
				ptr->Chin=temp;
			} 
			ptr=ptr->link;
		}
	ptr=p;
	} 
} 
int length(student *front){//計算串列長度
	int count=0;
	student *temp;
	if(front->link!=NULL){//判斷是否NULL
		temp = front->link;
		while(temp->link!=NULL){
			count++;
			temp=temp->link;
		}
		count++;//算最後一個
	}
	return count;
}
void print(void){
	student *this_node;
	this_node=front->link;
	while(this_node->link!=NULL){//判斷是否NULL
		printf("學號%d:",this_node->Chin);
		printf("%d分 ",this_node->Score);
		this_node = this_node->link;
	}//印最後一個
	printf("學號%d:",this_node->Chin);
	printf("%d分 ",this_node->Score);
}

void main(void){

	Cerate_node();
	int i,N=10,DE,IN,CH,IN1;
	int a[] = {32,58,54,56,45,15,15,48,45,145};

	for(i=0 ; i<10 ; i++){
		insert(i+1,a[i]);
	}

	print();

	printf("\nEeter 插入\n");
	scanf("%d,%d",&IN);
	scanf("%d",&IN1);
	insert(IN,IN1);
	print();

	printf("\nEeter 修改 \n");
	scanf("%d",&CH);
	Change(CH);
	print();

	printf("\nEeter 刪除\n");
	scanf("%d",&DE);
	del(DE);
	print();

	printf("\n分數排序\n");
	sort(front,length(front));
	print();
	printf("\n%d筆資料",length(front));
}
