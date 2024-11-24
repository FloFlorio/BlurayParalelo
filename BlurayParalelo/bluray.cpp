#include <bits/stdc++.h>

using namespace std;

#define MAX 5012

int n, k;
int file_size[MAX];
int memo[60][60][60];

void solve(int capacity[3], int nCapacities) {
	for (int c1 = 0; c1 <= capacity[0]; c1++) {
        	for (int c2 = 0; c2 <= capacity[1]; c2++) {
                	for (int c3 = 0; c3 <= capacity[2]; c3++) {
                    	memo[c1][c2][c3] = 0;
                	}
        	}
	}
   
	for (int i = 0; i < n; i++) {
        	for (int c1 = 0; c1 <= capacity[0]; c1++) {
                	for (int c2 = 0; c2 <= capacity[1]; c2++) {
            	for (int c3 = 0; c3 <= capacity[2]; c3++) {
               	 
                    	if (file_size[i] <= c1) {
memo[c1][c2][c3] = max(memo[c1][c2][c3], memo[c1 - file_size[i]][c2][c3] + file_size[i]);

                	}
               	 
                    	if (file_size[i] <= c2 && nCapacities >= 2) {
                            	memo[c1][c2][c3] = max(memo[c1][c2][c3], memo[c1][c2 - file_size[i]][c3] + file_size[i]);

                	}
               	 
                    	if (file_size[i] <= c3 && nCapacities == 3) {
                            	memo[c1][c2][c3] = max(memo[c1][c2][c3], memo[c1][c2][c3 - file_size[i]] + file_size[i]);


                            	}
                    	}
                	}
        	}
}
}

int main() {
	int capacity[3] = {0,0,0};
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
        	scanf("%d", &file_size[i]);
	}

	for (int i = 0; i < k; i++) {
        	scanf("%d", &capacity[i]);
	}
    
	int nCapacities = 0;
	for(int i = 0; i < k; i++){
  	scanf("%d",&capacity[nCapacities]);
  	nCapacities++;
  	}
 	 

	solve(capacity, nCapacities);

	int result = 0;
	for (int c1 = 0; c1 <= capacity[0]; c1++) {
        	for (int c2 = 0; c2 <= capacity[1]; c2++) {
                	for (int c3 = 0; c3 <= capacity[2]; c3++) {
                    	result = max(result, memo[c1][c2][c3]);
                	}
        	}
	}

	printf("%d\n", result);
	return 0;
}
