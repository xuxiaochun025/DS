#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int a[], int n)//
{
	int t;
	int flag;
	for (int i = 0; i < n - 1; i++) {
		flag = 0;
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				flag = 1;
			}
		}
		if (flag == 0) {//�����Ѿ����
			break;
		}
	}
}

void SelectSort(int a[], int n)
{
	int min, t;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;//��¼�±꣬����Ƶ������
			}
		}
		t = a[i];
		a[i] = a[min];
		a[min] = t;
	}
}

void InsertSort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++) {
		t = a[i];
		for (j = i-1; j >= 0; j--) {
			if (t < a[j]) {
				a[j + 1] = a[j];
			}
			else {
				break;
			}
		}
		a[j + 1] = t;
	}
}

void ShellSort(int a[], int n)//InsertSort + ����
{
	int increasement = n;
	int i, j, t;
	for (int inc = increasement; inc >= 1; inc /= 2) {//����
		for (i = inc; i < n; i++) {//(0,inc-1)����(inc,n-1)����
			t = a[i];
			for (j = i - inc; j >= 0; j = j - inc) {
				if (t < a[j]) {
					a[j + inc] = a[j];
				}
				else {
					break;
				}
			}
			a[j + inc] = t;
		}
	}
}

void QuickSort(int a[], int start,int end)
{
	int i = start;
	int j = end;
	int t;
	if (i < j) {//�ݹ��������
		while (i < j) {
			while (i < j&&a[i] < a[j]) {
				j--;
			}
			//(i < j)��Ȼ����źõ����ٴν���
			if (i < j) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++;
			}
			while (i < j&&a[i] < a[j]) {
				i++;
			}
			if (i < j) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
				j--;
			}
		}
		QuickSort(a, start, i - 1);
		QuickSort(a, i + 1, end);
	}
}
//�������������кϲ���һ����������
void Merge(int a[], int ta[], int L, int R, int N)
{
	/* �������A[L]~A[R-1]��A[R]~A[N]�鲢��һ���������� */
	int i = L;
	int j = R;
	while (i <= R-1 && j <= N) {
		if (a[i] < a[j]) {
			ta[L++] = a[i++];
		}
		else {
			ta[L++] = a[j++];
		}
	}
	while (i <= R - 1) {
		ta[L++] = a[i++];
	}
	while (j <= N) {
		ta[L++] = a[j++];
	}
	for (int k = 0; k <= N; k++) {
		a[k] = ta[k];
	}
}
void MSort(int a[], int ta[], int l, int r)
{
	if (l < r) {
		int m = (l + r) / 2;//��·�鲢
		MSort(a, ta, l, m);
		MSort(a, ta, m + 1, r);
		Merge(a, ta, l, m + 1, r);
	}
}

void MergeSort(int a[], int n)
{
	int *ta = (int *)malloc(sizeof(int)*n);
	MSort(a, ta, 0, 6);
	free(ta);
}

//����Ϊ�󶥶�
void SiftBig(int a[], int p, int n)
{
	//p�Ǵ�����λ�ã�����Ŵ�1��ʼ��������a�ķ�Χ[1,n]��p�ķ�Χ[1,n/2]
	int i = p;
	int j = 2 * i;
	int t;
	while (j <= n) {
		if (j < n&&a[j] < a[j + 1]) {//���Һ��Ӵ����Ҵ�
			j++;
		}
		if (a[i] >= a[j]) {
			break;
		}
		else {
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i = j;//
			j = 2 * i;
		}
	}
}

void HeapSort(int a[], int n)
{
	int t;
	for (int i = n / 2; i >= 1; i--) {
		SiftBig(a, i, n);//��ʼ���󶥶�
	}
	for (int i = n; i >= 1; i--) {
		t = a[1];
		a[1] = a[i];
		a[i] = t;
		SiftBig(a, 1, i-1);
	}
}

void Print(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[] = { 1,7,3,-1,9,8,0,2 };
	Print(a,7);
	//BubbleSort(a, 7);
	//SelectSort(a, 7);
	//InsertSort(a, 7);
	//ShellSort(a, 7);
	//QuickSort(a, 0, 6);
	//MergeSort(a,7);
	HeapSort(a, 7);//0��Ԫ�ز���������
	Print(a, 8);
	return 0;
}