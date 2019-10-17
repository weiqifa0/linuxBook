#include<stdio.h>
main()
{ 
  char c[16]={'\0'}; //字符数组初始值为0 
  int i,j,n;
  FILE *fp;
  if((fp=fopen("Yulong_sas35xMfgEval_20190423_c1c2c3.bin","rb"))==NULL)//路径为文件存放位置 
   { printf("Cannot open");
     return 0;
   }
   n=0;
    while(!feof(fp)) //判断文件是否结束 
   { 
    
     for(i=0;i<16;i++)
       c[i]=fgetc(fp);  //每次从文件中读出一个字符赋给字符数组的元素中 
	
     printf("%07d0h: ",n); //输出左侧的偏移量，但是这里有点问题 
	 for(j=0;j<16;j++)
	  printf("%02X ",c[j]); //输出十六进制代码 
	 printf("; ");
	 for(j=0;j<16;j++)
	  printf("%c ",c[j]);  //输出相对应的字符 
	 printf("\n");
     n++;
   }
   
   fclose(fp);
  
}

