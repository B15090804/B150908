 /*�� file.h�ļ����������£�*/
#include <stdio.h>
#include <stdlib.h>
#include "consumption.h"        
int createFile(Consumption con[])								/*������ʼ�������ļ�*/
{
	FILE *fp;
	int n = 0;
	int i, j;
   	if((fp=fopen("d:\\consumption.txt", "w")) == NULL)			/*ָ�����ļ�������д�뷽ʽ��*/
	{
	    printf(" ���ļ�ʧ�� !\n");							/*����ʧ�ܣ������ʾ��Ϣ*/
	    exit(0);												/*Ȼ���˳�*/
    }
	printf(" �������˵���Ϣ :\n");
	n=readCon(con,NUM);											/*����Consumption.h�еĺ���������*/
	fprintf(fp,"����			����		����		����		��ͨ		�ܶ�		����\n");
	for (i=0; i<n; i++)											/*���ղŶ�������м�¼һ����д���ļ�*/
			{
				fprintf(fp,"%d/%d/%d\t",con[i].date.year,con[i].date.month,con[i].date.day);
				for (j=0; j<4; j++)
				{	
					fprintf(fp,"%.2f\t",con[i].fourObj[j]);
				}
				fprintf(fp,"%.2f\t%d\t\n",con[i].total,con[i].rank);
			}
 	fclose(fp);													/*�ر��ļ�*/
	return n;
}

int readFile(Consumption con[])									/*���ļ��е����ݶ������ڽṹ������con[]�и�ʽ���Ĵ洢������ֱ����.bat�ļ����б༭*/
{
   	FILE *fp;
	int i = 0;
	int j;
	if((fp=fopen("d:\\consumption.txt", "r")) == NULL)			/*�Զ��ķ�ʽ��ָ���ļ�*/
	{
	    printf(" �ļ������ڣ������´���:\n");					/*�����ʧ�������ʾ��Ϣ*/
	    return 0;												/*Ȼ�󷵻�0*/
	}
	fscanf(fp,"����			����		����		����		��ͨ		�ܶ�		����\n");
	fscanf(fp,"%d/%d/%d\t",con[i].date.year,con[i].date.month,con[i].date.day);
	fscanf(fp,"%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%d\n",con[i].fourObj[0],con[i].fourObj[1],con[i].fourObj[2],con[i].fourObj[3],con[i].total,con[i].rank);
	while(!feof(fp))											/*�ļ�δ����ʱѭ��*/
	{
		i++;
		fscanf(fp,"%d/%d/%d\t",con[i].date.year,con[i].date.month,con[i].date.day);
		for (j=0; j<4; j++)
		{	
			fscanf(fp,"%.2f\t",con[i].fourObj[j]);
		}
		fscanf(fp,"%.2f\t%d\t\n",con[i].total,con[i].rank);			/*�ٶ�����һ����¼*/
    }
	fclose(fp);													/*�ر��ļ�*/
	return i;  
}

void saveFile(Consumption con[],int n)							/*���ṹ������con[]������д���ļ�*/
{   			 
  	FILE *fp;
	int i, j;
   	if((fp=fopen("d:\\Consumption.txt", "w")) == NULL)			/*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf(" �ļ���ʧ�� !\n");							/*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);												/*Ȼ���˳�*/
	}
    fprintf(fp,"����			����		����		����		��ͨ		�ܶ�		����\n");
	for (i=0; i<n; i++)											/*���ղŶ�������м�¼һ����д���ļ�*/
			{
				fprintf(fp,"%d/%d/%d\t",con[i].date.year,con[i].date.month,con[i].date.day);
				for (j=0; j<4; j++)
				{	
					fprintf(fp,"%.2f\t",con[i].fourObj[j]);
				}
				fprintf(fp,"%.2f\t%d\t\n",con[i].total,con[i].rank);
			}
	fclose(fp);													/*�ر��ļ�*/
}
