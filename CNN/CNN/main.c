#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "cnn.h"
#include "minst.h"
#include "cnn.h"

// 以下都是测试函数，可以不用管
// 测试Minst模块是否工作正常
// 
// void test_minst(){
// 	LabelArr testLabel=read_Lable("E:\\Code\\VS2010 code\\CNN\\Minst\\test-labels.idx1-ubyte");
// 	ImgArr testImg=read_Img("E:\\Code\\VS2010 code\\CNN\\Minst\\test-images.idx3-ubyte");
// 	save_Img(testImg,"E:\\Code\\VS2010 code\\CNN\\Minst\\testImgs\\");
// }
// 
// // 测试Mat模块是否工作正常
// void test_mat(){
// 	int i,j;
// 	nSize srcSize={6,6};
// 	nSize mapSize={4,4};
// 	srand((unsigned)time(NULL));
// 	float** src=(float**)malloc(srcSize.r*sizeof(float*));
// 	for(i=0;i<srcSize.r;i++){
// 		src[i]=(float*)malloc(srcSize.c*sizeof(float));
// 		for(j=0;j<srcSize.c;j++){
// 			src[i][j]=(((float)rand()/(float)RAND_MAX)-0.5)*2; 
// 		}
// 	}
// 	float** map=(float**)malloc(mapSize.r*sizeof(float*));
// 	for(i=0;i<mapSize.r;i++){
// 		map[i]=(float*)malloc(mapSize.c*sizeof(float));
// 		for(j=0;j<mapSize.c;j++){
// 			map[i][j]=(((float)rand()/(float)RAND_MAX)-0.5)*2; 
// 		}
// 	}
// 
// 	nSize cov1size={srcSize.c+mapSize.c-1,srcSize.r+mapSize.r-1};
// 	float** cov1=cov(map,mapSize,src,srcSize,full);
// 	//nSize cov2size={srcSize.c,srcSize.r};
// 	//float** cov2=cov(map,mapSize,src,srcSize,same);
// 	nSize cov3size={srcSize.c-(mapSize.c-1),srcSize.r-(mapSize.r-1)};
// 	float** cov3=cov(map,mapSize,src,srcSize,valid);
// 
// 	savemat(src,srcSize,"E:\\Code\\Matlab\\PicTrans\\src.ma");
// 	savemat(map,mapSize,"E:\\Code\\Matlab\\PicTrans\\map.ma");
// 	savemat(cov1,cov1size,"E:\\Code\\Matlab\\PicTrans\\cov1.ma");
// 	//savemat(cov2,cov2size,"E:\\Code\\Matlab\\PicTrans\\cov2.ma");
// 	savemat(cov3,cov3size,"E:\\Code\\Matlab\\PicTrans\\cov3.ma");
// 
// 	float** sample=UpSample(src,srcSize,2,2);
// 	nSize samSize={srcSize.c*2,srcSize.r*2};
// 	savemat(sample,samSize,"E:\\Code\\Matlab\\PicTrans\\sam.ma");
// }
// 
// void test_mat1()
// {
// 	int i,j;
// 	nSize srcSize={12,12};
// 	nSize mapSize={5,5};
// 	float** src=(float**)malloc(srcSize.r*sizeof(float*));
// 	for(i=0;i<srcSize.r;i++){
// 		src[i]=(float*)malloc(srcSize.c*sizeof(float));
// 		for(j=0;j<srcSize.c;j++){
// 			src[i][j]=(((float)rand()/(float)RAND_MAX)-0.5)*2; 
// 		}
// 	}
// 	float** map1=(float**)malloc(mapSize.r*sizeof(float*));
// 	for(i=0;i<mapSize.r;i++){
// 		map1[i]=(float*)malloc(mapSize.c*sizeof(float));
// 		for(j=0;j<mapSize.c;j++){
// 			map1[i][j]=(((float)rand()/(float)RAND_MAX)-0.5)*2; 
// 		}
// 	}
// 	float** map2=(float**)malloc(mapSize.r*sizeof(float*));
// 	for(i=0;i<mapSize.r;i++){
// 		map2[i]=(float*)malloc(mapSize.c*sizeof(float));
// 		for(j=0;j<mapSize.c;j++){
// 			map2[i][j]=(((float)rand()/(float)RAND_MAX)-0.5)*2; 
// 		}
// 	}
// 	float** map3=(float**)malloc(mapSize.r*sizeof(float*));
// 	for(i=0;i<mapSize.r;i++){
// 		map3[i]=(float*)malloc(mapSize.c*sizeof(float));
// 		for(j=0;j<mapSize.c;j++){
// 			map3[i][j]=(((float)rand()/(float)RAND_MAX)-0.5)*2; 
// 		}
// 	}
// 
// 	float** cov1=cov(map1,mapSize,src,srcSize,valid);
// 	float** cov2=cov(map2,mapSize,src,srcSize,valid);
// 	nSize covsize={srcSize.c-(mapSize.c-1),srcSize.r-(mapSize.r-1)};
// 	float** cov3=cov(map3,mapSize,src,srcSize,valid);
// 	addmat(cov1,cov1,covsize,cov2,covsize);
// 	addmat(cov1,cov1,covsize,cov3,covsize);
// 
// 
// 	savemat(src,srcSize,"E:\\Code\\Matlab\\PicTrans\\src.ma");
// 	savemat(map1,mapSize,"E:\\Code\\Matlab\\PicTrans\\map1.ma");
// 	savemat(map2,mapSize,"E:\\Code\\Matlab\\PicTrans\\map2.ma");
// 	savemat(map3,mapSize,"E:\\Code\\Matlab\\PicTrans\\map3.ma");
// 	savemat(cov1,covsize,"E:\\Code\\Matlab\\PicTrans\\cov1.ma");
// 	savemat(cov2,covsize,"E:\\Code\\Matlab\\PicTrans\\cov2.ma");
// 	savemat(cov3,covsize,"E:\\Code\\Matlab\\PicTrans\\cov3.ma");
// 
// }
// // 测试cnn模块是否工作正常
// void test_cnn()
// {
// 
// 	LabelArr testLabel=read_Lable("E:\\Code\\VS2010 code\\CNN\\Minst\\train-labels.idx1-ubyte");
// 	ImgArr testImg=read_Img("E:\\Code\\VS2010 code\\CNN\\Minst\\train-images.idx3-ubyte");
// 
// 	nSize inputSize={testImg->ImgPtr[0].c,testImg->ImgPtr[0].r};
// 	int outSize=testLabel->LabelPtr[0].l;
// 
// 	CNN* cnn=(CNN*)malloc(sizeof(CNN));
// 	cnnsetup(cnn,inputSize,outSize);
// 
// 	CNNOpts opts;
// 	opts.numepochs=1;
// 	opts.alpha=1;
// 	int trainNum=5000;
// 	cnntrain(cnn,testImg,testLabel,opts,trainNum);
// 
// 	FILE  *fp=NULL;
// 	fp=fopen("E:\\Code\\Matlab\\PicTrans\\cnnL.ma","wb");
// 	if(fp==NULL)
// 		printf("write file failed\n");
// 	fwrite(cnn->L,sizeof(float),trainNum,fp);
// 	fclose(fp);
// }
// 
// 
// /*主函数*/
// int predict()
// {
// 	// LabelArr trainLabel=read_Lable("./../Minst/train-labels-idx1-ubyte");
// 	// ImgArr trainImg=read_Img("./../Minst/train-images-idx3-ubyte");
// 	LabelArr testLabel=read_Lable("./../Minst/t10k-labels-idx1-ubyte");
// 	ImgArr testImg=read_Img("./../Minst/t10k-images-idx3-ubyte");
// 
// 	nSize inputSize={testImg->ImgPtr[0].c,testImg->ImgPtr[0].r};
// 	int outSize=testLabel->LabelPtr[0].l;
// 
// 	// CNN结构的初始化
// 	CNN* cnn=(CNN*)malloc(sizeof(CNN));
// 	cnnsetup(cnn,inputSize,outSize);
// 
// 
// 	// CNN测试
// 	importcnn(cnn,"minst.cnn");
// 	// int testNum=10000;
// 	int testNum=1;
// 	float incorrectRatio=0.0;
// 	incorrectRatio=cnntest(cnn,testImg,testLabel,testNum);
// 	printf("incorrectRatio=%f\ntest finished!!\n",incorrectRatio);
// 
// 	return 0;
// }

int test_read_Img()
{
 	ImgArr testImg=read_Img("./image1.H");
        int number_of_images=testImg->ImgNum;
        int n_rows=testImg->ImgPtr[0].r;
        int n_cols=testImg->ImgPtr[0].c;
        int n_cols_h=(n_cols+3)/4;
        printf("LabelNum=%d\n",number_of_images);
        printf("n_cols=%d\n",n_cols);
        printf("n_rows=%d\n",n_rows);
        printf("n_cols_h=%d\n\n",n_cols_h);
 
        for(int i=0;i<number_of_images;i++){
          for(int r=0;r<n_rows;r++){
            for(int c=0;c<n_cols_h;c++){
              printf("%016lx ",(long)(testImg->ImgPtr[i].ImgData[r][c]));
            }
            printf("\n");
          }
          printf("\n");
        }
        printf("\n");
 
 	return 0;
}

int test_initCovLayer()
{
  nSize inSize;
  inSize.c=28;
  inSize.r=28;
  CovLayer* covL=initCovLayer(inSize.c,inSize.r,5,1,6);

  int inChannels=covL->inChannels;
  int outChannels=covL->outChannels;
  int mapSize=covL->mapSize;
  int inputHeight=covL->inputHeight;
  int inputWidth=covL->inputWidth;
  int n_cols=(mapSize+3)/4;

  printf("inChannels=%d\n",inChannels);
  printf("outChannels=%d\n",outChannels);
  printf("mapSize=%d\n",mapSize);
  printf("inputHeight=%d\n",inputHeight);
  printf("inputHeight=%d\n",inputHeight);
  printf("n_cols=%d\n\n",n_cols);

  int i,j,c,r;
  for(i=0;i<inChannels;i++){
    for(j=0;j<outChannels;j++){
      for(r=0;r<mapSize;r++){
        for(c=0;c<n_cols;c++){
          printf("%016lx ",covL->mapData[i][j][r][c]);
        }
        printf("\n");
      }
      printf("\n");
    }
    printf("\n");
  }
  printf("\n");

  return 0;
}

int main()
{
  test_read_Img();
  test_initCovLayer();
  return 0;
}
