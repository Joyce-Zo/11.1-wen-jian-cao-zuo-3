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
	 ��s�е����ݸ�ʽ���洢��buf��
	printf("%s ", buf);	// ����joyce 21, 185,5�Ѿ�ȫ��ת��Ϊ�ַ�����ʽ

	struct S tmp = { 0 };
	sscanf(buf, "%s %s %d %f", &(tmp.name), &(tmp.sex), &(tmp.age), &(tmp.height));
	 ��buf�и�ʽ����������������洢�����ַ���
	printf("%s %s %d %f", tmp.name, tmp.sex, tmp.age, tmp.height);

	
	return 0;
}

	scanf  /  printf	����Ա�׼������/������� ��ʽ������/������
	fscanf / fprintf	���������������/������� ��ʽ������/������

	sscanf	���ַ����ж�ȡ��ʽ�������� 
	sprintf	�Ѹ�ʽ�������������(�洢��)�ַ���  


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
		�����Ƶ���ʽд���ݵ��ļ�
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
	
	fseek(pf, 5, SEEK_SET);	// - f		ƫ����5
	fseek(pf, -1, SEEK_END);	// - f		ƫ����5		��λ�ļ�ָ�룬����ƫ��
		��	  ƫ���� - �ֽ�		ƫ�Ƶ���ʼλ�� - 1.SEEK_SET - �ļ��Ŀ�ʼ
												 2.SEEK_END - �ļ���ĩβ
	//											 3.SEEK_CUR - �ļ���ǰָ���λ��
	
	int ch = fgetc(pf);
	//	��ȡ�ļ�
	printf("%c ", ch);

	fgetc(pf);	// ��ȡ��pf���һ���ַ�a��ָ��b = ƫ��1
	fgetc(pf);	// ƫ��2
	int pos=ftell(pf);
		ftell - �����ļ�ָ���������ʼλ�õ�ƫ����

	printf("%d ", pos);	// 2
	rewind(pf); // ʹ�ļ�ָ��ص��ļ�����ʼλ��	

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
	if (ferror(pf))		// ����
	{	
		printf("error\n");
	}
	else if (feof(pf))	// ����
	{
			feof - �ж��ļ�����ʱ������Ϊ�����ļ�β������������Ϊ��ȡ�ļ�ʧ�ܵ��µĽ���
			fgetc �ж��Ƿ�ΪEOF / fgets �ж��Ƿ�ΪNULL
				�����ƶ�ȡʱ��fread �ж�
		printf("end of file");
	}
	
	fclose(pf);
	pf = NULL;
	return 0;

}
