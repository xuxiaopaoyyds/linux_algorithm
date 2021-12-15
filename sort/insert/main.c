#include<stdio.h>

int insert_sort(int *data, int size);

int main(void)
{
	int data[10] = {9, 2, 3, 7, 4, 5, 0, 1, 6, 8};
	int size = 0;

	size = sizeof(data)/sizeof(int);

	printf("insert_sort size = %d, data = %p\n",size, data);
	printf("9 2 3 7 4 5 0 1 6 8\n");
	insert_sort(data, size);

	return 0;
}


int insert_sort(int *data, int size)
{
	int i = 0, j = 0, z = 0;
	int temp = 0;
	
	printf("data= %p\n", data);
	for(i = 1; i < size; i++) {
		//nedd insert data
		temp = data[i];
		//shift
		for(j = i; j > 0; j--) {	
			if(data[j-1] > temp) {	
				data[j] = data[j-1];
			}
			else {//find insert index j
				break;	
			}
		}
		//insert
		data[j] = temp;
		//debug
		for(z = 0; z < size; z++) {
			printf("%d ",data[z]);
		}
                printf("\n");
	}
}
