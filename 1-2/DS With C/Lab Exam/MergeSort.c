#include<stdio.h>

void merge(int a[], int left, int mid, int right){
	int i = left;
	int j=mid+1;
	int k=0;
	int tmpArr[right-left+1];
	
	while(i<=mid && j <= right){
		if(a[i] < a[j]){
			tmpArr[k++]=a[i];
			i++;
		}else{
			tmpArr[k++]=a[j];
			j++;
		}
	}
	
	while(i<=mid) tmpArr[k++]=a[i++];
	while(j<=right) tmpArr[k++]=a[j++];
	
	for(int i=0; i<right-left+1; i++)
		a[left+i]=tmpArr[i];	
}

void merge_sort(int a[], int left, int right){
	if(left>=right) return;
	
	merge_sort(a, left, (left+right)/2);
	merge_sort(a, ((left+right)/2)+1, right);
	
	merge(a, left, (left+right)/2, right);
}

int main(){
	int n;
	scanf("%d", &n);
	
	int a[n];
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	
	merge_sort(a, 0, n-1);
	
	for(int i=0; i<n; i++) printf("%d ", a[i]);
}