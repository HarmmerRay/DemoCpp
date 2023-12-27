#include <stdio.h>

int a[1005];
int b[1005];
//�鲢����: [2,5,1,23,72,123] һ�����飬�ֳ����롣  ǰһ���ÿһ��Ԫ�����һ���ÿһ��Ԫ�����αȽϣ���С��Ԫ�ض�����ǰһ�룬ִ����Ϻ�
// ���뵽��һ�㣬��ʱ���鿴�����Ǳ��ֳ���4�룬ͬ���ĵ���Ƚ�ǰһ����һ�룬���е�СԪ�ض��������֮�󣬽��뵽��һ�㡣
// ֱ�����ÿ�αȽ� ����ֻʣһ��Ԫ����������һ��ֻ��һ��Ԫ�ص�����Ƚϣ��Ƚ����֮�������˴�С������������С�
void Merge(int left,int right,int middle){
	int i = left, j = middle+1, k=left;
	while(i <= middle && j<=right){
		if(a[i] <= a[j]) b[k++] = a[i++];
		else b[k++]=a[j++];  //b[]�ȴ洢С������
	}
	while ( i <= middle ) b[k++] = a[i++];
	while ( j <= right ) b[k++] = a[j++];
	for ( i =left; i <= right; i++) a[i] = b[i];
}
//���ܵ��£�һ��ʱ��ֻ��һ���£��Ժ�����ʱ���������δ����������Ĺ滮��
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