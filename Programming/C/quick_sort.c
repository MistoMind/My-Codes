#include <stdio.h>

void qsort(int ary[], int left, int right);
void swap(int ary[], int i, int j);

int main(){

	int len=0;
	printf("Enter the lenght of the array: ");
	scanf("%d", &len);
	int ary[len];

	for(int i=0;i<len;i++){
		printf("Enter an other number: ");
		scanf("%d", &ary[i]);
	}

	int left = 0;
	int right = len-1;
	qsort(ary, left, right);

	for(int i=0;i<len;i++)
		printf("%d ", ary[i]);
	printf("\n");
}

void qsort(int ary[], int left, int right){
	int i, last;

	if(left>=right)
		return;
	swap(ary, left, (left+right)/2);
	last = left;

	for(i = left+1;i<=right;i++)
		if(ary[i]<ary[left])
			swap(ary, ++last, i);
	swap(ary, left, last);
	qsort(ary, left, last-1);
	qsort(ary, last+1, right);
}

void swap(int ary[], int i, int j){
	int temp = ary[i];
	ary[i] = ary[j];
	ary[j] = temp;
}