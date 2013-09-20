/*
 * 《算法设计与分析基础》(ISBN:9787302142836) 
 *
 * P53 习题11
 * 冯诺依曼邻居问题
 * 某算法从一个1*1的方格开始，每次都会在上次图形的周围加上一圈方格，在第n次的时候要生成多少个方格？（根据元胞自动机理论的说法，问题的答案等于n阶冯诺依曼邻居中的元胞数。）
 *
 * 解题思路：
 * 设S(n)为第n步时边的数量，B(n)为第n步时方格的数量。则S(0)=4，B(0)=1。
 * n每次增加时，增加的方块分为两部分：
 * 1. D1方向上的四个方格，它们与上一步的一个边相邻，所以每个方格增加了2条边。
 * 2. D2方向上增加的方格都与上一步的两条边相邻，又增加了两条边，所以没有改变边的数量。
 * 因此得到结论
 *
 * S(n) = S(n-1) + 8 && S(0) = 4  (等差数列)
 * =>
 * S(n) = 8*n + 4(n>=0)
 *
 * 根据上面的分析，B(n)相对于B(n-1)增加的方格分为两部分：
 * 1. D1方向上的四个方格。
 * 2. D2方向上增加的方格。
 * 所以得到关系：
 * B(n) = B(n-1) + 4 + [S(n-1)-4] / 2 
 *      = B(n-1) + 4*n (n>=1)
 *      = 2*n*n + 2*n + 1
 *
 * 参考资料：
 * http://www.cnblogs.com/anderslly/archive/2012/04/15/von-neumann-neighborhood.html
 *
 *
 *
 * p60 习题10
 *
 */
#include<stdio.h>
int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", 2*n*n + 2*n +1);
    }

    return 0;
}
