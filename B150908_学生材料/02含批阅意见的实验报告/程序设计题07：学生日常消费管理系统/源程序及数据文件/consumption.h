/* ①consumption.h文件的完整内容 */
#ifndef _CONSUMPTION															/*条件编译，防止重复包含的错误*/
#define _CONSUMPTION
#include <string.h>
#define NUM 30																	/*定义每月天数，此处可以根据实际需要修改常量值*/
struct Date																		/*日期的结构体，用于存储日期的年月日*/
{
	int year;
	int month;
	int day;
};
typedef struct Date Date;														/*用typedef为结构体起别名*/

struct Consumption																/*消费的结构体，用于存储相关的消费信息*/
{
	Date date;																	/*消费的日期*/
	double fourObj[4];															/*餐饮，娱乐，购物，交通的各项金额数值*/
	//char detail[40];															/*当日的消费详情*/
	double total;																/*当日的消费总额*/
	int rank;																	/*当天的消费总额在一个月中的排名*/
};
typedef struct Consumption Consumption;

#define sizeCon sizeof(Consumption)												/*一个消费记录所需要的内存空间大小*/

int readCon(Consumption *con,int n);											/*读入消费结构体的各项值，记录到NUM时停止*/

void readDate(Consumption *c, int condition);									/*根据条件读入为consumption读入日期：年、年月、年月日*/

void printCon(Consumption  *con , int n, int condition);						/*根据条件输出消费记录的值*/

void reverse(Consumption con[],int n);											/*消费记录数组元素的逆置*/

void calcuTotal(Consumption con[],int n);										/*计算每天四项消费的总金额*/

void calcuRank(Consumption con[],int n);										/*根据总金额计算消费的名次，允许有并列名次*/

void sortCon(Consumption con[],int n);											/*选择法根据日期（年月日）从小到大排序*/

int searchCon(Consumption con[],int n,Consumption c,int condition,int f[]);		/*按照给定的条件（年月日的信息）进行相关的搜索*/ 

int insertCon(Consumption con[],int n,Consumption c);							/*按日期有序向consumption数组中插入一个元素*/

int deleteCon(Consumption con[],int n,Consumption c);							/*从consumption数组中删除一个指定日期的元素*/
#endif