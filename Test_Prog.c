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
  double n1;
  int count = 1000;
  double Xi;
  double average;
  int sign;
  int stat[10];
  int size = 10000;
  double a = 0;
  double b = 9;
  double c = -9;
  double d = 0;
  // printf("%f\n", section_uniform(-6, 234, 2));

  // ball_normal(56, 2, &x, &y, &z);
   
   
   //1:
   int X;
   int A = a;
   FILE *fp3=NULL;
   fp3=fopen("gen.txt","w");
   fprintf(fp3,"%d\n", 1);
   for(int i=1;i<=size;i++){
     x = section_uniform(a, b, 0);
     X = x;
     fprintf(fp3,"%f\n", x);
     stat[X+abs(A)]++;
     n1+=x;
   }
   for (int i=0;i<=abs(b-a);i++){
   	Xi += pow(stat[i] - count, 2)/count;
   }
   n1 /= size;
   printf("1)Равномерное на отрезке:\n");
   printf("Значение Хи-квадрат:%f\n", Xi);
   printf("Среднее значение:%f\n", n1);
   fclose(fp3);
   graph1();
   
   
   //2:
   memset(stat, 0, sizeof(stat));
   n1 = 0;
   double n2;
   double n3;
   double n4 = 0;
   double Q;
   fp3=fopen("gen.txt","w");
   for(int i=1;i<=size;i++){
     x = section_normal(a, b, 0);
     fprintf(fp3,"%f\n", x);
     X = x;
     stat[X+abs(A)]++;
     n1+=x;
   }
   n1/=size;
   for (int i=0;i<=abs(b-a);i++){
   	n2+=pow(i-n1,2)*stat[i];
   	n3+=pow(i-n1,3)*stat[i];
   	n4+=pow(i-n1,4)*stat[i];
   }
   Q = sqrt(n2/size);
   printf("2)Нормальное на отрезке:\n");
   printf("Ассиметрия:%f\n", (n3/size)/pow(Q,3));
   printf("Эксцесс:%f\n", (n4/size)/pow(Q,4)-3);
   printf("Среднее значение:%f\n", n1);
   fclose(fp3);
   graph1();
   
   
   //3:
   memset(stat, 0, sizeof(stat));
   int Y;
   int stat2[10];
   n1 = 0;
   double v1 = 0;
   Xi=0;
   int C = c;
   fp3=fopen("gen.txt","w");
   for(int i=1;i<=size;i++){
     rectangle_uniform(a, b, c, d, 0, &x, &y);
     fprintf(fp3, "%f\t%f\n", x, y);
     X = x;
     Y = y;
     stat[X+abs(A)]++;
     stat2[Y+abs(C)]++;
     n1+=X;
     v1+=Y;
   }
   for (int i=0;i<=abs(b-a);i++){
   	Xi += pow(stat[i] - count, 2)/count;
   }
   n1 /= size;
   printf("3)Равномерное на прямоугольнике:\n");
   printf("Интервал [a,b]:\n");
   printf("Xi:%f\n", Xi);
   printf("Average:%f\n", n1);
   Xi=0;
   for (int i=0;i<=abs(d-c);i++){
   	Xi += pow(stat2[i] - count, 2)/count;
   }
   v1 /= size;
   printf("Интервал [c,d]:\n");
   printf("Значение Хи-квадрат:%f\n", Xi);
   printf("Среднее значение:%f\n", v1);
   fclose(fp3);
   graph2();
   
   
   //4:
   memset(stat, 0, sizeof(stat));
   memset(stat2, 0, sizeof(stat));
   n1 = 0;
   v1 = 0;
   n2 = 0;
   n3 = 0;
   n4 = 0;
   fp3=fopen("gen.txt","w");
   for(int i=1;i<=size;i++){
     rectangle_normal(a, b, c, d, 0, &x, &y);
     fprintf(fp3, "%f\t%f\n", x, y);
     X = x;
     Y = y;
     stat[X+abs(A)]++;
     stat2[Y+abs(C)]++;
     n1+=x;
     v1+=y;
   }
   n1/=size;
   for (int i=0;i<=abs(b-a);i++){
   	n2+=pow(i-n1,2)*stat[i];
   	n3+=pow(i-n1,3)*stat[i];
   	n4+=pow(i-n1,4)*stat[i];
   }
   Q = sqrt(n2/size);
   printf("4)Равномерное на прямоугольнике:\n");
   printf("Интервал [a,b]:\n");
   printf("Ассиметрия:%f\n", (n3/size)/pow(Q,3));
   printf("Экцесс:%f\n", (n4/size)/pow(Q,4)-3);
   printf("Среднее значение:%f\n", n1);
   v1/=size;
   n2 = 0;
   n3 = 0;
   n4 = 0;
   for (int i=0;i<=abs(d-c);i++){
   	n2+=pow(i-n1,2)*stat[i];
   	n3+=pow(i-n1,3)*stat[i];
   	n4+=pow(i-n1,4)*stat[i];
   }
   Q = sqrt(n2/size);
   printf("Интервал [c,d]:\n");
   printf("Ассиметрия:%f\n", (n3/size)/pow(Q,3));
   printf("Экцесс:%f\n", (n4/size)/pow(Q,4)-3);
   printf("Среднее значение:%f\n", n1);
   fclose(fp3);
   graph2();
   
   
   //5:
   memset(stat, 0, sizeof(stat));
   memset(stat2, 0, sizeof(stat));
   int Y;
   double r = 10;
   int R =r;
   n1 = 0;
   double v1 = 0;
   Xi=0;
   int C = c;
   fp3=fopen("gen.txt","w");
   for(int i=1;i<=size;i++){
     circle_uniform(r, 0, &x, &y);
     fprintf(fp3, "%f\t%f\n", x, y);
     X = x;
     Y = y;
     stat[X+R]++;
     stat2[Y+R]++;
     n1+=X;
     v1+=Y;
   }
   for (int i=0;i<=r*2;i++){
   	Xi += pow(stat[i] - count, 2)/count;
   }
   n1 /= size;
   printf("5)Равномерное на круге:\n");
   printf("Точки по оси Х:\n");
   printf("Xi:%f\n", Xi);
   printf("Average:%f\n", n1);
   Xi=0;
   for (int i=0;i<=r*2;i++){
   	Xi += pow(stat2[i] - count, 2)/count;
   }
   v1 /= size;
   printf("Точки по оси У:\n");
   printf("Значение Хи-квадрат:%f\n", Xi);
   printf("Среднее значение:%f\n", v1);
   fclose(fp3);
   graph2();
  return 0;
}
