#include<stdio.h>
void main(){
	int i,j,k,a[10],n,ind;
	printf("Enter the Size of the Array(MAX_10): ");
	scanf("%d",&n);
	printf("Enter the Elements of the Array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++){
		ind=a[i];
		for(j=i; j>0 && a[j-1]>ind;j--){
			a[j]=a[j-1];
		}
		a[j]=ind;
		printf("Pass %d => \n",i);
		for(k=0;k<n;k++){
			printf("%d\t",a[k]);
		}
		printf("\n");
	}
	printf("The Sorted Array is :\n");
	for(k=0;k<n;k++){
		printf("%d\t",a[k]);
	}
}
