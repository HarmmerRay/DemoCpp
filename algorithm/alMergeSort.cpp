#include <stdio.h>

int a[1005];
int b[1005];
//归并排序: [2,5,1,23,72,123] 一个数组，分成两半。  前一半的每一个元素与后一半的每一个元素依次比较，把小的元素都放在前一半，执行完毕后。
// 进入到下一层，此时数组看起来是被分成了4半，同样的道理比较前一半后后一半，所有的小元素都放置完成之后，进入到下一层。
// 直到最后每次比较 都是只剩一个元素数组与另一个只有一个元素的数组比较，比较完成之后就完成了从小到大的数组排列。
void Merge(int left,int right,int middle){
	int i = left, j = middle+1, k=left;
	while(i <= middle && j<=right){
		if(a[i] <= a[j]) b[k++] = a[i++];
		else b[k++]=a[j++];  //b[]先存储小的数字
	}
	while ( i <= middle ) b[k++] = a[i++];
	while ( j <= right ) b[k++] = a[j++];
	for ( i =left; i <= right; i++) a[i] = b[i];
}
//享受当下，一个时间只做一件事，以后做的时候就最多想的未来就是明天的规划。
void MergeSort(int left,int right){
	if(left < right) {
		int middle = left + (right - left) /2 ;
		MergeSort(left , middle );
		MergeSort(middle+1 , right);
		Merge(left,right,middle);
	}
}

int main(){
	int arr[] = {7,24,5,7,98,3,15};
	for ( int i = 0; i <= 6;i++){
		a[i] = arr[i];
	}

	MergeSort(0,6);
	for ( int j = 0; j <=6; j++){
		printf("%d ", a[i] );
	}
	return 0;
}