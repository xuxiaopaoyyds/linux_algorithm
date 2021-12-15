#include<stdio.h>

int bubble_sort(int *data, int size);

int main(void)
{
	int data[10] = {9, 2, 3, 7, 4, 5, 0, 1, 6, 8};
	int size = 0;

	size = sizeof(data)/sizeof(int);

	printf("bubble_sort size = %d, data = %p\n",size, data);
	printf("9 2 3 7 4 5 0 1 6 8\n");
	bubble_sort(data, size);

	return 0;
}


int bubble_sort(int *data, int size)
{
	int i = 0, j = 0, z = 0;
	int temp = 0;
	
	printf("data= %p\n", data);
	for(i = 0; i < size - 1; i++) {
		for(j = 0; j < size - i - 1; j++) {
			if(data[j] > data[j+1]) {
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;	
				for(z = 0; z < size; z++) {
					printf("%d ",data[z]);
				}
				printf("\n");
			}
			//printf("data[%d]=%d, data[%d]=%d\n",i, data[i], j, data[j]);
		}
	}
}
