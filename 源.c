#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<windows.h>

struct S
{
	char name[20];
	char sex[5];
	int age;
	float height;
};
int main()
{
	struct S s = { "joyce","male",21,181.5 };
	char buf[1024];
	sprintf(buf, "%s %s %d %f", s.name, s.sex, s.age, s.height);
	 把s中的数据格式化存储到buf中
	printf("%s ", buf);	// 其中joyce 21, 185,5已经全部转化为字符串格式

	struct S tmp = { 0 };
	sscanf(buf, "%s %s %d %f", &(tmp.name), &(tmp.sex), &(tmp.age), &(tmp.height));
	 把buf中格式化的数据输出到（存储到）字符串
	printf("%s %s %d %f", tmp.name, tmp.sex, tmp.age, tmp.height);

	
	return 0;
}

	scanf  /  printf	是针对标准输入流/输出流的 格式化输入/输出语句
	fscanf / fprintf	是针对所有输入流/输出流的 格式化输入/输出语句

	sscanf	从字符串中读取格式化的数据 
	sprintf	把格式化的数据输出成(存储到)字符串  


struct S
{
	char name[20];
	int age;
	double height;
};
int main()
{
	struct S arr = { "joyce",21,181.5 };
	struct S tmp = { 0 };
	FILE* pf = fopen("test.txt", "wb");
	FILE* pf = fopen("test.txt", "rb");
	if (pf == NULL)
	{
		return 0;
	}
	fwrite(&arr, sizeof(struct S), 1, pf);
		二进制的形式写数据到文件
	fread(&tmp, sizeof(struct S), 1, pf);
	printf("%s %d %.1lf", tmp.name, tmp.age, tmp.height);
	fclose(pf);
	pf == NULL;
	return 0;
}

int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
	
	fseek(pf, 5, SEEK_SET);	// - f		偏移量5
	fseek(pf, -1, SEEK_END);	// - f		偏移量5		定位文件指针，进行偏移
		流	  偏移量 - 字节		偏移的起始位置 - 1.SEEK_SET - 文件的开始
												 2.SEEK_END - 文件的末尾
	//											 3.SEEK_CUR - 文件当前指向的位置
	
	int ch = fgetc(pf);
	//	读取文件
	printf("%c ", ch);

	fgetc(pf);	// 读取完pf里的一个字符a，指向b = 偏移1
	fgetc(pf);	// 偏移2
	int pos=ftell(pf);
		ftell - 返回文件指针相对于起始位置的偏移量

	printf("%d ", pos);	// 2
	rewind(pf); // 使文件指针回到文件的起始位置	

	pos = ftell(pf);
	printf("%d ", pos); // 0
	fclose(pf);
	pf = NULL;
	return 0;
}


int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("");

		return 0;
	}
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		putchar(ch);
		putc(ch,stdout);
	}
	Sleep(1000);
	printf("\n");
	if (ferror(pf))		// 出错
	{	
		printf("error\n");
	}
	else if (feof(pf))	// 结束
	{
			feof - 判断文件结束时，是因为遇到文件尾结束，还是因为读取文件失败导致的结束
			fgetc 判断是否为EOF / fgets 判断是否为NULL
				二进制读取时用fread 判断
		printf("end of file");
	}
	
	fclose(pf);
	pf = NULL;
	return 0;

}
