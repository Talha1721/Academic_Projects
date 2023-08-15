#include<stdio.h>

int main()
 {
    int i, c = 0;
	int a[128];
    int n, sum, maxHeight, moves, temp;

    while (scanf("%d", &n) && n){
        moves = sum = 0;
        c++;

        for (i = 0; i < n; ++i){
            scanf("%d", &a[i]);
            sum += a[i];
        }

        maxHeight = sum / n;

        for (i = 0; i < n; ++i){
            if(a[i] > maxHeight)
                moves += a[i] - maxHeight;
        }

        printf("Set #%d\nThe minimum number of moves is %d.\n\n",c,moves);
    }
    return 0;
}
