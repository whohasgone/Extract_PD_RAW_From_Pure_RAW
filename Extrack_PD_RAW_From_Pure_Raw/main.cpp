#include <iostream>
#include <fstream>
#include "RAW.h"
#include <windows.h>
using namespace std;

int getRawBuffer(char *,char *);



void main()
{	

	char filename[100] = "E:\\VS_work\\GitHub\\Extract_PD_RAW\\Extract_PD_RAW_From_Pure_RAW\\Debug\\test.raw";
	char * fileBuffer = NULL; 
	if (!getRawBuffer(filename, fileBuffer))
	{
		cout << "Read file Error!!" << endl;
		return;
	}
	
	
	
	system("pause");
	return;
}

int getRawBuffer(char *filename, char *fileBuffer)
{
	//以二进制格式读取raw图
	filebuf *rawBuf; //图像首地址
	ifstream rawFileIn;
	long long size = 0;
	rawFileIn.open(filename, ios::binary); //以二进制形式读取raw图
	if (!rawFileIn.is_open())
	{
		cerr << "图像无法读取！！" << endl;
		return 0;
	}
	rawBuf = rawFileIn.rdbuf(); //获取图像首地址

	//获取图像大小
	size = rawBuf->pubseekoff(0,ios::end,ios::in);
	rawBuf->pubseekpos(0, ios::in);
	//cout<<rawFileIn.seekg(0,ios::end)<<endl;

	fileBuffer = new char[size]; //分配内存空间
	rawBuf->sgetn(fileBuffer,size);
	cout << "The size of the RAW is :" << size << endl;
	rawFileIn.close();
	return 1;
}

int iniConfig()
{
	//初始化配置类
	return 1;
}

int getConfig()
{
	//获取配置文件并解析
	return 1;

}

int extractFromPDRAW()
{
	//提取buffer中的PD点
	return 1;
}

int writeIntoFile()
{
	//写入文件
	return 1;
}
