#include <iostream>
#include <string>
#include <stdlib.h>

int* populateMatrix(int,std::string,std::string,int,int);

int main(){
	int n;
	std::cout<<"length of gene:";
	std::cin>>n;
	std::string s1,s2;
	std::cout <<"Enter gene 1:";
	std::cin>>s1;
	std::cout << "Enter gene 2:";
	std::cin>>s2;
	std::cout<<std::endl;
	std::cout<<s1<<std::endl<<s2;
	int gap_penalty = 1;
	int gap_cost = 1;
	int* matrix = populateMatrix(n,s1,s2,gap_penalty,gap_cost);
	for(int i = 0;i<n;i++){
		std::cout<<std::endl;
		for(int j = 0;j<n;j++){
			std::cout<<*(matrix+i+n*j)<<" ";
		}
	}
	return 0;
}

int max(int,int,int);

int* populateMatrix(int n,std::string s1, std::string s2, int gap_penalty, int gap_cost){
	int* matrix = (int*)malloc(sizeof(int)*n*n);
	for(int i = 0;i <n*n;i++){
		*(matrix+i) = 0;
	}
	for(int i=0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(s1[i] == s2[j]){
				if(i == 0 && j == 0){
					*(matrix + i +n*j) = 2;
					std::cout<<"Hi"<<std::endl;
				}
				else if(i == 0 and j != 0){
					*(matrix + i +n*j) = max(0,0,*(matrix + i + n*(j-1))) + 2;
					std::cout<<"He"<<std::endl;
				}
				else if(i != 0 && j == 0){
					*(matrix + i +n*j) = max(0,0,*(matrix + i-1 + n*j)) + 2;
					std::cout<<"Ho"<<std::endl;
				}
				else{
					*(matrix+ i + n*j) = max(*(matrix+ i-1 + n*j),*(matrix+ i + n*(j-1)),*(matrix+ i-1 + n*(j-1))) + 2;
				}
			}
			else{
				int y = *(matrix + i + n*j);
				*(matrix + i + n*j) = max(*(matrix+ i-1 + n*j),*(matrix+ i + n*(j-1)),*(matrix+ i-1 + n*(j-1))) - (gap_penalty + y*gap_cost);
				if( i != n-1){
					*(matrix + i+1 + n*j) = y+1;
				}
				if(j != n-1){
					*(matrix + i + n*(j+1)) = y+1;
				}
			}
		}
	}
	return matrix;
}

int max(int a, int b, int c){
	if(a > b && a> c){
		return a;
	}
	if(b > c){
		return b;
	}
	return c;
}

