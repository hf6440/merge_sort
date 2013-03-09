#include <iostream>
using namespace std;
void merge_sort(int * const a,int p,int r);
void merge(int * const a,int p,int r);
int static num;
int main()
{
	int cut;
	int test1[10]={30,29,28,27,26,25,24,23,22,10};
	int test2[10]={2,8,9,3,6,20,13,14,18,15};
	int test3[100];
	for(int x=0;x<100;x++){
		test3[x]=x*x*x*x/2-3*x*x*x+2*x*x+20;
	}
	cin>>cut;//2457
	num=0;
	merge_sort(test1,0,9);
	cout<<num<<" ";
	for(int i=0;i<10;i++){
		cout<<test1[i]<<" ";
	}
	return 0;
}
void merge_sort(int * const a,int p,int r)
{
	if(p<(r+p)/2){
		merge_sort(a,p,(r+p)/2);
		merge_sort(a,(r+p)/2+1,r);
	}
	merge(a,p,r);
}
void merge(int * const a,int p,int r)
{
	int mid=(p+r)/2;
	int dor[200],tor[200];
	int j=0;
	for(int i=p;i<mid+1;i++,j++){
		dor[j]=a[i];
	}
	dor[j]=999999;
	j=0;
	for(int i=mid+1;i<r+1;i++,j++){
		tor[j]=a[i];
	}
	tor[j]=99999;
	int i_d=0;
	int i_t=0;
	j=0;
	while(j<r-p+1){
		if(dor[i_d]<tor[i_t]){
			a[j+p]=dor[i_d];
			j++;
			i_d++;
			num++;
		}
		else{
			a[j+p]=tor[i_t];
			j++;
			i_t++;
			num++;
		}
	}
}