#ifndef __MINST_
#define __MINST_
/*
MINST���ݿ���һ����дͼ�����ݿ⣬����
*/

typedef struct MinstImg{
	// long s;        // ͼ��� �� �� [0, 0, c, r] default
	long** ImgData;   // ͼ�����ݶ�ά��̬����
}MinstImg;

typedef struct MinstImgArr{
	long ImgNum;        // �洢ͼ�����Ŀ [0, 0, 0, n]
	MinstImg* ImgPtr;   // �洢ͼ������ָ��
}*ImgArr;               // �洢ͼ�����ݵ�����

typedef struct MinstLabel{
	int l;            // �����ǵĳ� [0, 0, 0, l]
	float* LabelData;   // ����������
}MinstLabel;

typedef struct MinstLabelArr{
	int LabelNum;
	MinstLabel* LabelPtr;
}*LabelArr;              // �洢ͼ���ǵ�����

LabelArr read_Lable(const char* filename); // ����ͼ����

ImgArr read_Img(const char* filename); // ����ͼ��

// void save_Img(ImgArr imgarr,char* filedir); // ��ͼ�����ݱ�����ļ�

#endif
