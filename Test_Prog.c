#include "./Generate_Module.h"
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#define M 6
#define N 80

void graph1(){
	FILE *gnuplot = popen("gnuplot", "w");
	if (!gnuplot) {
	  perror("popen");
	  exit(EXIT_FAILURE);
	}
	fprintf(gnuplot, "load 'plot1.gnu'\n");
	fprintf(stdout, "Click Ctrl+d to quit...\n");
	fflush(gnuplot);
	getchar();
	pclose(gnuplot);	
}
void graph2(){
	FILE *gnuplot = popen("gnuplot", "w");
	if (!gnuplot) {
	  perror("popen");
	  exit(EXIT_FAILURE);
	}
	fprintf(gnuplot, "load 'plot2.gnu'\n");
	fprintf(stdout, "Click Ctrl+d to quit...\n");
	fflush(gnuplot);
	getchar();
	pclose(gnuplot);	
}
int main(void){
  setlocale(LC_ALL, "Rus");
  printf("Добро пожаловать в программу тестирования!\nВыберите действие:\n");
  double x;
  double y;
  double z;
  int t;
  int count = 1000;
  double Xi;
  double average;
  int sign;
  int stat[10];
  int size = 10000;
  // printf("%f\n", section_uniform(-6, 234, 2));

  // ball_normal(56, 2, &x, &y, &z);
   
   
   //1:
   FILE *fp3=NULL;
   fp3=fopen("gen.txt","w");
   fprintf(fp3,"%d\n", 1);
   for(int i=1;i<=size;i++){
     t = section_uniform(0, 9, 0);
     fprintf(fp3,"%d\n", t);
     stat[t]++;
   }
   for (int i=0;i<=9;i++){
   	Xi += pow(stat[i] - count, 2)/count;
   	average += abs(stat[i] - count);
   }
   average /= 10;
   printf("Xi:%f\n", Xi);
   printf("average:%f\n", average);
   fclose(fp3);
   graph1();
   
   
   //2:
   memset(stat, 0, sizeof(stat));
   double n1;
   double n2;
   double n3;
   double n4;
   double Q;
   fp3=fopen("gen.txt","w");
   for(int i=1;i<=size;i++){
     t = section_normal(0, 9, 0);
     fprintf(fp3,"%d\n", t);
     stat[t]++;
     n1+=t;
   }
   n1/=size;
   for (int i=0;i<=9;i++){
   	n2+=pow(i-n1,2)*stat[i];
   	n3+=pow(i-n1,3)*stat[i];
   	n4+=pow(i-n1,4)*stat[i];
   }
   Q = sqrt(n2/size);
   printf("Ax:%f\n", (n3/size)/pow(Q,3));
   printf("Ex:%f\n", (n4/size)/pow(Q,4)-3);
   printf("Ex:%f\n", Q);
   fclose(fp3);
   graph1();
   
   
   //3:
   memset(stat, 0, sizeof(stat));
   int X;
   int Y;
   int stat2[10];
   average=0;
   Xi=0;
   fp3=fopen("gen.txt","w");
   for(int i=1;i<=size;i++){
     rectangle_uniform(0, 9, -9, 0, 0, &x, &y);
     fprintf(fp3, "%f\t%f\n", x, y);
     X = x;
     Y = y;
     stat[X]++;
     stat2[Y+9]++;
   }
   for (int i=0;i<=9;i++){
   	Xi += pow(stat[i] - count, 2)/count;
   	average += abs(stat[i] - count);
   }
   average /= 10;
   printf("Xi:%f\n", Xi);
   printf("Average:%f\n", average);
   average=0;
   Xi=0;
   for (int i=0;i<=9;i++){
   	Xi += pow(stat[i] - count, 2)/count;
   	average += abs(stat2[i] - count);
   }
   average /= 10;
   printf("Xi:%f\n", Xi);
   printf("Average:%f\n", average);
   fclose(fp3);
   graph2();
   
  return 0;
}
