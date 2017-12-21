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
	//�Զ����Ƹ�ʽ��ȡrawͼ
	filebuf *rawBuf; //ͼ���׵�ַ
	ifstream rawFileIn;
	long long size = 0;
	rawFileIn.open(filename, ios::binary); //�Զ�������ʽ��ȡrawͼ
	if (!rawFileIn.is_open())
	{
		cerr << "ͼ���޷���ȡ����" << endl;
		return 0;
	}
	rawBuf = rawFileIn.rdbuf(); //��ȡͼ���׵�ַ

	//��ȡͼ���С
	size = rawBuf->pubseekoff(0,ios::end,ios::in);
	rawBuf->pubseekpos(0, ios::in);
	//cout<<rawFileIn.seekg(0,ios::end)<<endl;

	fileBuffer = new char[size]; //�����ڴ�ռ�
	rawBuf->sgetn(fileBuffer,size);
	cout << "The size of the RAW is :" << size << endl;
	rawFileIn.close();
	return 1;
}

int iniConfig()
{
	//��ʼ��������
	return 1;
}

int getConfig()
{
	//��ȡ�����ļ�������
	return 1;

}

int extractFromPDRAW()
{
	//��ȡbuffer�е�PD��
	return 1;
}

int writeIntoFile()
{
	//д���ļ�
	return 1;
}
