#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Node{
	int val;
	struct Node *next;
}Node;

typedef struct Info{
	int *arr;
	int size;
}Info;
int ascendingOrder (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
Node **linkedList(Node **list,int size){
	int i;
    
	for(i = 0; i < size-1; i++){
		list[i]->next = list[i+1];
	}
	return list;
}
Node **createList(int nums[],int size){
	
	Node **list = (Node**)malloc(sizeof(Node*)*size); 
	int i;

	for(i = 0; i<size; i++){
        list[i] = (Node*)malloc(sizeof(Node));		
		list[i]->val = nums[i];
	    list[i]->next = NULL;
	    
	    
	    
	    
	    
	}
	
	return linkedList(list,size);
}
int *sortedArray(Node **list1,Node **list2,Node **list3,int total_size){
	int *nums = (int*)malloc(sizeof(int)*total_size);
	int count = 0;
   Node *header;
   header = list1[0];
   int i = 0;
   while(1){
   	
   nums[i] = header->val;
   header = header->next;
   i++;
   if(header == NULL){
   	
   	if(count == 0){
   	header = list2[0];
   	count++;
    }
    else if(count == 1){
    header = list3[0];
    count++;
	}
	else{
		break;
	}
	
   	
   	
   }
   
}


qsort(nums,total_size,sizeof(int),ascendingOrder);
   
   
   return nums;
}
void printList(Node **list){
	Node *header;
	header = list[0];
	while(header != NULL){
		printf("%d\n",header->val);
		header = header->next;
	}
	return;
}
int main(void) {
	Info array[3];
	int i,j;
	int total_size = 0;
	for(i = 0;i < 3; i++){
		printf("Input %d. array's size: ",i+1);
		scanf("%d",&array[i].size);
		array[i].arr = (int*)malloc(sizeof(int)*(array[i].size));
		total_size += array[i].size;
		for(j = 0; j < array[i].size; j++){
			printf("Input the %d. element of array: ",j+1);
			scanf("%d",&array[i].arr[j]);
		}
		
	}
	Node **list1 = createList(array[0].arr,array[0].size);
	Node **list2 = createList(array[1].arr,array[1].size);
	Node **list3 = createList(array[2].arr,array[2].size);
	int *sorted_array = sortedArray(list1,list2,list3,total_size);
	Node **sortedList = createList(sorted_array,total_size);
	
	printList(sortedList);
	

	return 0;
}
