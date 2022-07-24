#include<cstdio>
int main(){
    int D, I, t;
    scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &D, &I);
        int k = 1;
        for(int i = 0; i < D-1; i++){
        	/* 
			当I是奇数时, 往左走 , 并且它是往左走的第(I+1)/2个小球  
        	这里算数的意义指的是I中有几个奇数,由于只有奇数才会往左走 
        	*/ 
        	if(I%2)
				k*=2, I = (I+1)/2;
			/*
			当I是偶数时，往右走 
			同理算数的意义指的是I中有几个偶数，只有偶数才会往右走
			它是往右走的第I/2个小球 
			*/ 
            else
				k = k*2+1, I /= 2;
		}
        printf("%d\n",k);
    }
}
/*
Sample Input
5
4 2
3 4
10 1
2 2
8 128
-1
Sample Output
12
7
512
3
255
*/ 
 
