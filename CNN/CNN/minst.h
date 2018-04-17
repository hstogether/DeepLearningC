#ifndef __MINST_
#define __MINST_
/*
MINST数据库是一个手写图像数据库，里面
*/

typedef struct MinstImg{
	// long s;        // 图像宽 和 高 [0, 0, c, r] default
	long** ImgData;   // 图像数据二维动态数组
}MinstImg;

typedef struct MinstImgArr{
	long ImgNum;        // 存储图像的数目 [0, 0, 0, n]
	MinstImg* ImgPtr;   // 存储图像数组指针
}*ImgArr;               // 存储图像数据的数组

typedef struct MinstLabel{
	int l;            // 输出标记的长 [0, 0, 0, l]
	float* LabelData;   // 输出标记数据
}MinstLabel;

typedef struct MinstLabelArr{
	int LabelNum;
	MinstLabel* LabelPtr;
}*LabelArr;              // 存储图像标记的数组

LabelArr read_Lable(const char* filename); // 读入图像标记

ImgArr read_Img(const char* filename); // 读入图像

// void save_Img(ImgArr imgarr,char* filedir); // 将图像数据保存成文件

#endif
