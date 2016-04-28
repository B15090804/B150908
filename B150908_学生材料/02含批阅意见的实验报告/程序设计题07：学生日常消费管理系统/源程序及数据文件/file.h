 /*�� file.h�ļ����������£�*/
#include <stdio.h>
#include <stdlib.h>
#include "consumption.h"        
int createFile(Consumption con[])								/*������ʼ�������ļ�*/
{
	FILE *fp;
	int n = 0;
   	if((fp=fopen("d:\\consumption.dat", "wb")) == NULL)			/*ָ�����ļ�������д�뷽ʽ��*/
	{
	    printf(" ���ļ�ʧ�� !\n");							/*����ʧ�ܣ������ʾ��Ϣ*/
	    exit(0);												/*Ȼ���˳�*/
    }
	printf(" �������˵���Ϣ :\n");
	n=readCon(con,NUM);											/*����Consumption.h�еĺ���������*/
	fwrite(con,sizeCon,n,fp);									/*���ղŶ�������м�¼һ����д���ļ�*/
 	fclose(fp);													/*�ر��ļ�*/
	return n;
}

int readFile(Consumption con[])									/*���ļ��е����ݶ������ڽṹ������con[]��*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\consumption.dat", "rb")) == NULL)			/*�Զ��ķ�ʽ��ָ���ļ�*/
	{
	    printf(" �ļ������ڣ������´���:\n");					/*�����ʧ�������ʾ��Ϣ*/
	    return 0;												/*Ȼ�󷵻�0*/
	}	 
    fread(&con[i],sizeCon,1,fp);								/*������һ����¼*/
   	while(!feof(fp))											/*�ļ�δ����ʱѭ��*/
	{
		i++;
	    fread(&con[i],sizeCon,1,fp);							/*�ٶ�����һ����¼*/
     }
	fclose(fp);													/*�ر��ļ�*/
	return i;													/*���ؼ�¼����*/
}

void saveFile(Consumption con[],int n)							/*���ṹ������con[]������д���ļ�*/
{   			 
  	FILE *fp;	
   	if((fp=fopen("d:\\Consumption.dat", "wb")) == NULL)			/*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf(" �ļ���ʧ�� !\n");							/*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);												/*Ȼ���˳�*/
	}
	fwrite(con,sizeCon,n,fp);        
	fclose(fp);													/*�ر��ļ�*/
}
