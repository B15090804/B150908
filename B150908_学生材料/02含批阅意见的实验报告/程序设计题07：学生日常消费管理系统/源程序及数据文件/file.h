 /*③ file.h文件的内容如下：*/
#include <stdio.h>
#include <stdlib.h>
#include "consumption.h"        
int createFile(Consumption con[])								/*建立初始的数据文件*/
{
	FILE *fp;
	int n = 0;
	int i, j;
   	if((fp=fopen("d:\\consumption.txt", "w")) == NULL)			/*指定好文件名，以写入方式打开*/
	{
	    printf(" 打开文件失败 !\n");							/*若打开失败，输出提示信息*/
	    exit(0);												/*然后退出*/
    }
	printf(" 请输入账单信息 :\n");
	n=readCon(con,NUM);											/*调用Consumption.h中的函数读数据*/
	fprintf(fp,"日期			餐饮		娱乐		购物		交通		总额		排名\n");
	for (i=0; i<n; i++)											/*将刚才读入的所有记录一次性写入文件*/
			{
				fprintf(fp,"%d/%d/%d\t",con[i].date.year,con[i].date.month,con[i].date.day);
				for (j=0; j<4; j++)
				{	
					fprintf(fp,"%.2f\t",con[i].fourObj[j]);
				}
				fprintf(fp,"%.2f\t%d\t\n",con[i].total,con[i].rank);
			}
 	fclose(fp);													/*关闭文件*/
	return n;
}

int readFile(Consumption con[])									/*将文件中的内容读出置于结构体数组con[]中格式化的存储，便于直接在.bat文件进行编辑*/
{
   	FILE *fp;
	int i = 0;
	int j;
	if((fp=fopen("d:\\consumption.txt", "r")) == NULL)			/*以读的方式打开指定文件*/
	{
	    printf(" 文件不存在，请重新创建:\n");					/*如果打开失败输出提示信息*/
	    return 0;												/*然后返回0*/
	}
	fscanf(fp,"日期			餐饮		娱乐		购物		交通		总额		排名\n");
	fscanf(fp,"%d/%d/%d\t",con[i].date.year,con[i].date.month,con[i].date.day);
	fscanf(fp,"%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%d\n",con[i].fourObj[0],con[i].fourObj[1],con[i].fourObj[2],con[i].fourObj[3],con[i].total,con[i].rank);
	while(!feof(fp))											/*文件未结束时循环*/
	{
		i++;
		fscanf(fp,"%d/%d/%d\t",con[i].date.year,con[i].date.month,con[i].date.day);
		for (j=0; j<4; j++)
		{	
			fscanf(fp,"%.2f\t",con[i].fourObj[j]);
		}
		fscanf(fp,"%.2f\t%d\t\n",con[i].total,con[i].rank);			/*再读出下一条记录*/
    }
	fclose(fp);													/*关闭文件*/
	return i;  
}

void saveFile(Consumption con[],int n)							/*将结构体数组con[]的内容写入文件*/
{   			 
  	FILE *fp;
	int i, j;
   	if((fp=fopen("d:\\Consumption.txt", "w")) == NULL)			/*以写的方式打开指定文件*/
	{
		printf(" 文件打开失败 !\n");							/*如果打开失败，输出提示信息*/
		exit(0);												/*然后退出*/
	}
    fprintf(fp,"日期			餐饮		娱乐		购物		交通		总额		排名\n");
	for (i=0; i<n; i++)											/*将刚才读入的所有记录一次性写入文件*/
			{
				fprintf(fp,"%d/%d/%d\t",con[i].date.year,con[i].date.month,con[i].date.day);
				for (j=0; j<4; j++)
				{	
					fprintf(fp,"%.2f\t",con[i].fourObj[j]);
				}
				fprintf(fp,"%.2f\t%d\t\n",con[i].total,con[i].rank);
			}
	fclose(fp);													/*关闭文件*/
}
