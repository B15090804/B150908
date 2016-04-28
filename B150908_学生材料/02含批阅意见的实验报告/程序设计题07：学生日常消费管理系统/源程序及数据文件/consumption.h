/* ��consumption.h�ļ����������� */
#ifndef _CONSUMPTION															/*�������룬��ֹ�ظ������Ĵ���*/
#define _CONSUMPTION
#include <string.h>
#define NUM 30																	/*����ÿ���������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Date																		/*���ڵĽṹ�壬���ڴ洢���ڵ�������*/
{
	int year;
	int month;
	int day;
};
typedef struct Date Date;														/*��typedefΪ�ṹ�������*/

struct Consumption																/*���ѵĽṹ�壬���ڴ洢��ص�������Ϣ*/
{
	Date date;																	/*���ѵ�����*/
	double fourObj[4];															/*���������֣������ͨ�ĸ�������ֵ*/
	//char detail[40];															/*���յ���������*/
	double total;																/*���յ������ܶ�*/
	int rank;																	/*����������ܶ���һ�����е�����*/
};
typedef struct Consumption Consumption;

#define sizeCon sizeof(Consumption)												/*һ�����Ѽ�¼����Ҫ���ڴ�ռ��С*/

int readCon(Consumption *con,int n);											/*�������ѽṹ��ĸ���ֵ����¼��NUMʱֹͣ*/

void readDate(Consumption *c, int condition);									/*������������Ϊconsumption�������ڣ��ꡢ���¡�������*/

void printCon(Consumption  *con , int n, int condition);						/*��������������Ѽ�¼��ֵ*/

void reverse(Consumption con[],int n);											/*���Ѽ�¼����Ԫ�ص�����*/

void calcuTotal(Consumption con[],int n);										/*����ÿ���������ѵ��ܽ��*/

void calcuRank(Consumption con[],int n);										/*�����ܽ��������ѵ����Σ������в�������*/

void sortCon(Consumption con[],int n);											/*ѡ�񷨸������ڣ������գ���С��������*/

int searchCon(Consumption con[],int n,Consumption c,int condition,int f[]);		/*���ո����������������յ���Ϣ��������ص�����*/ 

int insertCon(Consumption con[],int n,Consumption c);							/*������������consumption�����в���һ��Ԫ��*/

int deleteCon(Consumption con[],int n,Consumption c);							/*��consumption������ɾ��һ��ָ�����ڵ�Ԫ��*/
#endif