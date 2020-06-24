#include<stdio.h>
#include<string.h>
// 1.2.3.4个数字，可以组成多个不相同，且不重复的3位数
int e1()
{
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            for (int k = 1; k < 5; k++) {
                if (i == j) {
                    continue;
                }
                if (i == k) {
                    continue;
                }
                if (j == k) {
                    continue;
                }
                printf("%d, %d, %d\n",i,j,k);
            }
        }
    }
}

// 两个正整数，m,n 求最大公约数和最小公倍数
int e2()
{
    int m;
    int n;
    int tmp;
    scanf("%d, %d",&m,&n);

    if (m < n) {
        tmp = m;
        m = n;
        n = tmp;
    }

    printf("%d, %d\n",m,n);

}

//字符串的全排列
int main()
{
 
    char a[5];
    char b[5];
 
    scanf("%c%c%c%c",&a[0],&a[1],&a[2],&a[3]);
    printf("str is %s\n",a);
     
    printf("str len : %d\n",strlen(a));     

    for (int i = 0; i < strlen(a) - 1; i++) {
        char tmp;
        tmp = a[i];
        a[i] = a[i+1];
        a[i+1] = tmp; 
        printf("str is %s\n",a);
    }

    return 0;
}
