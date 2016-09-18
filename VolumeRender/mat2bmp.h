#ifndef MAT2BMP
#define MAT2BMP
/*
typedef struct {  
    DWORD  biSize;        // BITMAPINFOHEADER�ṹ����ֽڴ�С  
    LONG   biWidth;       //ͼ��Ŀ��  
    LONG   biHeight;       //ͼ��ĸ߶�  
    WORD   biPlanes;       //Ŀ���豸ƽ����Ŀ������Ϊ1  
    WORD   biBitCount;       //ÿ�����ص���ɫλ��,��ȡ1,4,8,16,24,32  
    DWORD  biCompression;     //ѹ�����ͣ�������Ҫ�ǹ�עû��ѹ���ģ���BI_RGB  
    DWORD  biSizeImage;     //ͼ�����ݵ��ֽڴ�С������������ͷ����  
    LONG   biXPelsPerMeter;   
    LONG   biYPelsPerMeter;  
    DWORD  biClrUsed;  
    DWORD  biClrImportant;  
} BITMAPINFOHEADER;  */



//WriteBitmapFile
//����bitmapData�ģ�RGB�����ݣ�����bitmap
//filename��Ҫ���浽����Ӳ�̵��ļ���������·����
BOOL WriteBitmapFile(char * filename,int width,int height,unsigned char * bitmapData)
{
    //���BITMAPFILEHEADER
    BITMAPFILEHEADER bitmapFileHeader;
    memset(&bitmapFileHeader,0,sizeof(BITMAPFILEHEADER));
    bitmapFileHeader.bfSize = sizeof(BITMAPFILEHEADER);
    bitmapFileHeader.bfType = 0x4d42;	//BM
    bitmapFileHeader.bfOffBits =sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    //���BITMAPINFOHEADER
    BITMAPINFOHEADER bitmapInfoHeader;
    memset(&bitmapInfoHeader,0,sizeof(BITMAPINFOHEADER));
    bitmapInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
    bitmapInfoHeader.biWidth = width;
    bitmapInfoHeader.biHeight = height;
    bitmapInfoHeader.biPlanes = 1;
    bitmapInfoHeader.biBitCount = 24;
    bitmapInfoHeader.biCompression = BI_RGB;
    bitmapInfoHeader.biSizeImage = width * abs(height) * 3;

    //////////////////////////////////////////////////////////////////////////
    FILE * filePtr;			//����Ҫ�����bitmap�ļ���
    unsigned char tempRGB;	//��ʱɫ��
    int imageIdx;

    //����R��B������λ��,bitmap���ļ����õ���BGR,�ڴ����RGB
    for (imageIdx = 0;imageIdx < bitmapInfoHeader.biSizeImage;imageIdx +=3)
    {
        tempRGB = bitmapData[imageIdx];
        bitmapData[imageIdx] = bitmapData[imageIdx + 2];
        bitmapData[imageIdx + 2] = tempRGB;
    }

    filePtr = fopen(filename,"wb");
    if (NULL == filePtr)
    {
        return FALSE;
    }

    fwrite(&bitmapFileHeader,sizeof(BITMAPFILEHEADER),1,filePtr);

    fwrite(&bitmapInfoHeader,sizeof(BITMAPINFOHEADER),1,filePtr);

    fwrite(bitmapData,bitmapInfoHeader.biSizeImage,1,filePtr);

    fclose(filePtr);
    return TRUE;
}
#endif
