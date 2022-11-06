#include<stdio.h>
void main(){
	int a[10],i,j,k,n,temp;
	printf("Enter the size of the Array(MAX_10):");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				printf("\nPass %d => ",i+1);
				for(k=0;k<n;k++){
				printf("%d\t",a[k]);
			}
			printf("\n");
			}
		}
	}
	printf("\nFinal Sorted Array is:\n");
	for(k=0;k<n;k++){
		printf("%d\t",a[k]);
	}
}
