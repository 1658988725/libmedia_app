#include "stdio.h"
#include "stdlib.h"
#include "media.h"

long _get_runtime(void) {
	long ret = 0;
	struct timespec tmspc;
	clock_gettime(CLOCK_MONOTONIC,&tmspc);
	
	return tmspc.tv_sec;
}

int _savefile(char *buff,int len,char *filename) {
    FILE *stream;
    if ((stream = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "Cannot open output file.\n");
        return 1;
    }
    fwrite(buff,len, 1, stream);
    fclose(stream); 
    return 0;
}

int saveyuv(unsigned char *buff,int len,int w,int h,int count) {
    FILE *stream;
	char filename[128];
	sprintf(filename,"%d_%dx%d.yuv",count,w,h);
  	_savefile(buff,len,filename);
	printf("save %s\n",filename);
	system("chmod -R 777 *.yuv");
    return 0;
}

int savejpg(unsigned char *buff,int len,int count) {
    FILE *stream;
	char filename[128];
	sprintf(filename,"%d.jpg",count);
  	_savefile(buff,len,filename);
	printf("save %s\n",filename);
	system("chmod -R 777 *.jpg");
    return 0;
}


int main(void)
{
	media_init("ar0144.ini");
	media_startstream("main",554);
	media_run();
	IPX_IMAGE_S* pImg = NULL;	
	int count = 0;
	int pretime = _get_runtime();
	int w = 0;
	int h = 0;
	char *pjpg = (char*)malloc(1024*1024);
	while(1)
	{
		pImg = media_getframe();
		if(pImg) 
		{
			count ++;
			w = pImg->u32Width;
			h = pImg->u32Height;

			//printf("get frame[%d]:%dx%d u64PTS:%ld\n",\
			//count++,pImg->u32Width,pImg->u32Height,pImg->u64PTS);	
			

			//saveyuv((unsigned char *)pImg->au64VirAddr[0],w*h*3/2,w,h,count);
			
			int size = media_encodejpg(pImg,NULL,pjpg);
			if(size > 0) {
				printf("encode jpg size:%d\n",size);
				savejpg(pjpg,size,count);
				
			}	
/*			// calc frame count per second
			if(pretime != _get_runtime())
			{
				printf("get frame pre second count:%d\n",count);	
				pretime =  _get_runtime();
				count = 0;
			}
*/			
		}
			
	}
	
	return 0;
}
