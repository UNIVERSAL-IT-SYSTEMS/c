#include <stdio.h>
#include <string.h>
int main()
{
   //多维数组的定义声明和初始化
   //       [行][列]
   int array1[3][3]={1,2,3,
                     4,5,6,
                     7,8,9};//多维数组主要用于有逻辑有条理的管理同类型的数据
   //在逻辑上可将第一维看成是行,第二维看成是列
   int array2[3][3]={{1,2,3},{4,5},{6}};
   int array3[ ][3]={1,2,3,4,5,6,7,8,9};
   //int arrayTest[3][ ]={1,2,3,4,5,6,7,8,9};//碰到{{1,2,3},{1},{2}};会无法处理
   int arrayTest1[ ][3][3]={1,2,3,4,5,6,7,8,9};
   int arrayTest2[ ][1][3][3]={1,2,3,4,5,6,7,8,9};
   //像这样的四维数组可理解为[章][页][行][列] <--可看成是索引的具体的实现
   //多维数组的定义初始化必须至少指定除第一维以外的其它维度的元素个数
   
   //定义动态自动多维数组
   int x=3,y=6,w=0,i,c;
   int array4[x][y]; 
   memset(array4,0,sizeof(array4));
   
   for(i=0;i<x;i++)for(c=0;c<y;c++)array4[i][c]=w++;

   printf("array1:");
   for(i=0;i<3;i++)for(c=0;c<3;c++)printf("%d ",array1[i][c]);printf("\n");
   printf("array2:");
   for(i=0;i<3;i++)for(c=0;c<3;c++)printf("%d ",array2[i][c]);printf("\n");
   printf("array3:");
   for(i=0;i<3;i++)for(c=0;c<3;c++)printf("%d ",array3[i][c]);printf("\n");
   printf("array4:");
   for(i=0;i<3;i++)for(c=0;c<3;c++)printf("%d ",array4[i][c]);printf("\n");

   //多维数组的层次和地址运算关系,及内容值的输出形式
   printf("array size:%d %d \naddress:%p %p %p %p \nvalue:%d %d %d %d\n",
          sizeof(array4),sizeof(array4[1]),array4,array4+1,array4[1],
          array4[1]+1,*(array4[1]+0),*(array4[1]+1),array4[1][0],array4[1][1]);
   //1. array4是整体的数组名,有第一第二属性,array4[1]可看作是所在行的所有列元素的数组名,也有第一第二属性 

   //2. 像array4+1这样的地址运算不是简单的算术运算:
   //   array4+1:地址加1实际加了1行的空间占用值24.
   //   array4[1]+1:实际加了1列的空间用占值4
   //   地址运算的单位值具有一个放大(缩小)的属性(因子).具体放大(缩小)多少字节,看参与运算的对象是什么数据类型和第二属性情况如何:就是具体某一维的地址运算放大(缩小)因子取决于它下一维的第二属性.
                               
   //3. *(array4[1]+0)可以简写为*array4[1]  <--array4[1]输出时不是内容值,而是地址值,即[]下标运算符不是仅仅来用指代内容值的,只有在底部那个层面才是表示所在空间,及内容值
   
   for(i=0;i<x*y;i++)printf("%d ",array4[0][i]); printf("\n");
   //这是把一个多维数组当作是一个只有一行的二维数组来输出,说明行与行之间的空间也是连续排列的.这其实也是一种合理的越界访问.

}