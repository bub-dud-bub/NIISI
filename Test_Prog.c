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
	fprintf(stdout, "Нажмите Enter чтобы продолжить\n\n");
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
	fprintf(stdout, "Нажмите Enter чтобы продолжить\n\n");
	fflush(gnuplot);
	getchar();
	pclose(gnuplot);	
}
void graph3(){
	FILE *gnuplot = popen("gnuplot", "w");
	if (!gnuplot) {
	  perror("popen");
	  exit(EXIT_FAILURE);
	}
	fprintf(gnuplot, "load 'plot3.gnu'\n");
	fprintf(stdout, "Нажмите Enter чтобы продолжить\n\n");
	fflush(gnuplot);
	getchar();
	pclose(gnuplot);	
}
void test1(double a, double b, int sign, int size){
   int X;
   int A = a;
   int B = b;
   double x;
   double n1 = 0;
   double Xi = 0;
   double count = size/(b-a+1);
   int stat[B-A+1];
   for (int i=0;i<=b-a;i++){
   	stat[i]=0;
   }
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
   printf("1)Равномерное на отрезке [%f,%f] с выборкой %d значений:\n", a, b, size);
   printf("\tЗначение Хи-квадрат:%f\n", Xi);
   printf("\tСреднее значение:%f\n\n", n1);
   fclose(fp3);
   graph1();
}
void test2(double a, double b, int sign, int size){
   int X;
   int A = a;
   int B = b;
   double x;
   double n1 = 0;
   double n2 = 0;
   double n3 = 0;
   double n4 = 0;
   double Q;
   double count = size/(b-a+1);
   int stat[B-A+1];
   for (int i=0;i<=b-a;i++){
   	stat[i]=0;
   }
   count = size/(b-a+1);
   FILE *fp3=NULL;
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
   	n2+=pow(i+a-n1,2)*stat[i];
   	n3+=pow(i+a-n1,3)*stat[i];
   	n4+=pow(i+a-n1,4)*stat[i];
   }
   Q = sqrt(n2/size);
   printf("2)Нормальное на отрезке [%f,%f] с выборкой %d значений:\n", a, b, size);
   printf("\tАссиметрия:%f\n", (n3/size)/pow(Q,3));
   printf("\tЭксцесс:%f\n", (n4/size)/pow(Q,4)-3);
   printf("\tСреднее значение:%f\n\n", n1);
   fclose(fp3);
   graph1();
}
void test3(double a, double b, double c, double d, int sign, int size){
   int X;
   int Y;
   int A = a;
   int B = b;
   int C = c;
   int D = d;
   double x;
   double y;
   double n1 = 0;
   double v1 = 0;
   double Xi = 0;
   double count = size/(b-a+1);
   int stat[B-A+1];
   for (int i=0;i<=b-a;i++){
   	stat[i]=0;
   }
   int stat2[D-C+1];
   for (int i=0;i<=d-c;i++){
   	stat2[i]=0;
   }
   count = size/(b-a+1);
   FILE *fp3=NULL;
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
   printf("3)Равномерное на прямоугольнике с выборкой %d значений:\n", size);
   printf("Интервал [%f,%f]:\n", a, b);
   printf("\t3начение Хи-квадрат:%f\n", Xi);
   printf("\tСреднее значение:%f\n\n", n1);
   count = size/(d-c+1);
   Xi=0;
   for (int i=0;i<=abs(d-c);i++){
   	Xi += pow(stat2[i] - count, 2)/count;
   }
   v1 /= size;
   printf("Интервал [%f,%f]:\n", c, d);
   printf("\tЗначение Хи-квадрат:%f\n", Xi);
   printf("\tСреднее значение:%f\n\n", v1);
   fclose(fp3);
   graph2();
}
void test4(double a, double b, double c, double d, int sign, int size){
   int X;
   int Y;
   int A = a;
   int B = b;
   int C = c;
   int D = d;
   double x;
   double y;
   double v1 = 0;
   double Xi = 0;
   double count = size/(b-a+1);
   int stat[abs(B-A+1)];
   for (int i=0;i<=b-a;i++){
   	stat[i]=0;
   }
   int stat2[(D-C+1)];
   for (int i=0;i<=d-c;i++){
   	stat2[i]=0;
   }
   double n1 = 0;
   double n2 = 0;
   double n3 = 0;
   double n4 = 0;
   double Q;
   count = size/(abs(b-a+1));
   FILE *fp3=NULL;
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
   	n2+=pow(i+a-n1,2)*stat[i];
   	n3+=pow(i+a-n1,3)*stat[i];
   	n4+=pow(i+a-n1,4)*stat[i];
   }
   Q = sqrt(n2/size);
   printf("4)Нормальное на прямоугольнике с выборкой %d значений:\n", size);
   printf("Интервал  [%f,%f]:\n", a, b);
   printf("\tАссиметрия:%f\n", (n3/size)/pow(Q,3));
   printf("\tЭкцесс:%f\n", (n4/size)/pow(Q,4)-3);
   printf("\tСреднее значение:%f\n\n", n1);
   count = size/(abs(d-c+1));
   v1/=size;
   n2 = 0;
   n3 = 0;
   n4 = 0;
   for (int i=0;i<=abs(d-c);i++){
   	n2+=pow(i+c-v1,2)*stat2[i];
   	n3+=pow(i+c-v1,3)*stat2[i];
   	n4+=pow(i+c-v1,4)*stat2[i];
   }
   Q = sqrt(n2/size);
   printf("Интервал  [%f,%f]:\n", c, d);
   printf("\tАссиметрия:%f\n", (n3/size)/pow(Q,3));
   printf("\tЭкцесс:%f\n", (n4/size)/pow(Q,4)-3);
   printf("\tСреднее значение:%f\n\n", v1);
   fclose(fp3);
   graph2();
}

void test5(double r, int sign, int size){
   int X;
   int Y;
   int R =r;
   double x;
   double y;
   double n1 = 0;
   double v1 = 0;
   double Xi = 0;
   double count = size/(r*2+1);
   int stat[R*2+1];
   for (int i=0;i<=R*2;i++){
   	stat[i]=0;
   }
   int stat2[R*2+1];
   for (int i=0;i<=R*2;i++){
   	stat2[i]=0;
   }
   FILE *fp3=NULL;
   fp3=fopen("gen.txt","w");
   for(int i=1;i<=size;i++){
     circle_uniform(r, 0, &x, &y);
     fprintf(fp3, "%f\t%f\n", x, y);
     X = x+R;
     Y = y+R;
     stat[X]++;
     stat2[Y]++;
     n1+=x;
     v1+=y;
   }
   
   for (int i=0;i<=r*2;i++){
   	Xi += pow(stat[i] - count, 2)/count;
   }
   n1 /= size;
   printf("5)Равномерное на круге с радиусом %f с выборкой %d значений:\n", r, size);
   printf("Точки по оси Х:\n");
   printf("\tЗначение Хи-квадрат:%f\n", Xi);
   printf("\tСреднее значение:%f\n\n", n1);
   Xi=0;
   for (int i=0;i<=r*2;i++){
   	Xi += pow(stat2[i] - count, 2)/count;
   }
   v1 /= size;
   printf("Точки по оси У:\n");
   printf("\tЗначение Хи-квадрат:%f\n", Xi);
   printf("\tСреднее значение:%f\n\n", v1);
   fclose(fp3);
   graph2();
}

void test6(double r, double sign, int size){
   double l = r-r*2;
   int X;
   int Y;
   int R =r;
   double x;
   double y;
   double v1 = 0;
   double Xi = 0;
   double count = size/(r*2+1);
   int stat[R*2+1];
   for (int i=0;i<=R*2;i++){
   	stat[i]=0;
   }
   int stat2[R*2+1];
   for (int i=0;i<=R*2;i++){
   	stat2[i]=0;
   }
   double n1 = 0;
   double n2 = 0;
   double n3 = 0;
   double n4 = 0;
   double Q;   
   FILE *fp3=NULL;
   fp3=fopen("gen.txt","w");
   for(int i=1;i<=size;i++){
     circle_normal(r, 0, &x, &y);
     fprintf(fp3, "%f\t%f\n", x, y);
     X = x+R;
     Y = y+R;
     stat[X]++;
     stat2[Y]++;
     n1+=x;
     v1+=y;
   }
   n1/=size;
   for (int i=0;i<=abs(r-l);i++){
   	n2+=pow(i+l-n1,2)*stat[i];
   	n3+=pow(i+l-n1,3)*stat[i];
   	n4+=pow(i+l-n1,4)*stat[i];
   }
   Q = sqrt(n2/size);
   printf("6)Нормальное на круге с радиусом %f с выборкой %d значений:\n", r, size);
   printf("Точки по оси Х:\n");
   printf("\tАссиметрия:%f\n", (n3/size)/pow(Q,3));
   printf("\tЭкцесс:%f\n", (n4/size)/pow(Q,4)-3);
   printf("\tСреднее значение:%f\n\n", n1);
   v1/=size;
   n2 = 0;
   n3 = 0;
   n4 = 0;
   for (int i=0;i<=abs(r-l);i++){
   	n2+=pow(i+l-v1,2)*stat2[i];
   	n3+=pow(i+l-v1,3)*stat2[i];
   	n4+=pow(i+l-v1,4)*stat2[i];
   }
   Q = sqrt(n2/size);
   printf("Точки по оси У:\n");
   printf("\tАссиметрия:%f\n", (n3/size)/pow(Q,3));
   printf("\tЭкцесс:%f\n", (n4/size)/pow(Q,4)-3);
   printf("\tСреднее значение:%f\n\n", v1);
   fclose(fp3);
   graph2();
}

void test7(double a, double b, double c, double d, double e, double f, int sign, int size){
   int X;
   int Y;
   int Z;
   int A = a;
   int B = b;
   int C = c;
   int D = d;
   int E = c;
   int F = d;
   double x;
   double y;
   double z;
   double n1 = 0;
   double v1 = 0;
   double k1 = 0;
   double Xi = 0;
   double count = size/(b-a+1);
   int stat[abs(B-A+1)];
   for (int i=0;i<=abs(b-a);i++){
   	stat[i]=0;
   }
   int stat2[abs(D-C+1)];
   for (int i=0;i<=abs(D-C);i++){
   	stat2[i]=0;
   }
   int stat3[abs(F-E+1)];
   for (int i=0;i<=abs(F-E);i++){
   	stat3[i]=0;
   }
   count = size/(abs(B-A+1));
   FILE *fp3=NULL;
   fp3=fopen("gen.txt","w");
   for(int i=1;i<=size;i++){
     paraped_uniform(a, b, c, d, e, f, sign, &x, &y, &z);
     fprintf(fp3, "%f\t%f\t%f\n", x, y, z);
     X = x;
     Y = y;
     Z = z;
     stat[X+abs(A)]++;
     stat2[Y+abs(C)]++;
     stat3[abs(Z+E)]++;
     n1+=X;
     v1+=Y;
     k1+=Z;
   }
   for (int i=0;i<=abs(b-a);i++){
   	Xi += pow(stat[i] - count, 2)/count;
   }
   n1 /= size;
   printf("7)Равномерное на параллелепипиде с выборкой %d значений:\n", size);
   printf("Интервал [%f,%f]:\n", a, b);
   printf("\tЗначение Хи-квадрат:%f\n", Xi);
   printf("\tСреднее значение:%f\n\n", n1);
   count = size/(abs(d-c+1));
   Xi=0;
   for (int i=0;i<=abs(d-c);i++){
   	Xi += pow(stat2[i] - count, 2)/count;    	  	
   }
   v1 /= size;
   printf("Интервал [%f,%f]:\n", c, d);
   printf("\tЗначение Хи-квадрат:%f\n", Xi);
   printf("\tСреднее значение:%f\n\n", v1);
   count = size/(abs(f-e+1));
   Xi=0;
   for (int i=0;i<=abs(f-e);i++){
   	Xi += pow(stat3[i] - count, 2)/count;
   }
   k1 /= size;
   printf("Интервал [%f,%f]:\n", e, f);
   printf("\tЗначение Хи-квадрат:%f\n", Xi);
   printf("\tСреднее значение:%f\n\n", k1);
   fclose(fp3);
   graph3();
}

void test8(double a, double b, double c, double d, double e, double f, int sign, int size){
   int X;
   int Y;
   int Z;
   int A = a;
   int B = b;
   int C = c;
   int D = d;
   int E = c;
   int F = d;
   double x;
   double y;
   double z;
   double v1 = 0;
   double k1 = 0;
   double count = size/(b-a+1);
   int stat[abs(B-A+1)];
   for (int i=0;i<=abs(b-a);i++){
   	stat[i]=0;
   }
   int stat2[abs(D-C+1)];
   for (int i=0;i<=abs(D-C);i++){
   	stat2[i]=0;
   }
   int stat3[abs(F-E+1)];
   for (int i=0;i<=abs(F-E);i++){
   	stat3[i]=0;
   }
   double n1 = 0;
   double n2 = 0;
   double n3 = 0;
   double n4 = 0;
   double Q;
   count = size/(abs(B-A+1));
   FILE *fp3=NULL;
   fp3=fopen("gen.txt","w");
   for(int i=1;i<=size;i++){
     paraped_normal(a, b, c, d, e, f, sign, &x, &y, &z);
     fprintf(fp3, "%f\t%f\t%f\n", x, y, z);
     X = x;
     Y = y;
     Z = z;
     stat[X+abs(A)]++;
     stat2[Y+abs(C)]++;
     stat3[abs(Z+E)]++;
     n1+=X;
     v1+=Y;
     k1+=Z;
   }
   n1/=size;
   for (int i=0;i<=abs(b-a);i++){
   	n2+=pow(i+a-n1,2)*stat[i];
   	n3+=pow(i+a-n1,3)*stat[i];
   	n4+=pow(i+a-n1,4)*stat[i];
   }
   Q = sqrt(n2/size);
   printf("8)Нормальное на параллелепипиде с выборкой %d значений:\n", size);
   printf("Интервал  [%f,%f]:\n", a, b);
   printf("\tАссиметрия:%f\n", (n3/size)/pow(Q,3));
   printf("\tЭкцесс:%f\n", (n4/size)/pow(Q,4)-3);
   printf("\tСреднее значение:%f\n\n", n1);
   count = size/(abs(d-c+1));
   v1/=size;
   n2 = 0;
   n3 = 0;
   n4 = 0;
   for (int i=0;i<=abs(D-C);i++){
   	n2+=pow(i+c-v1,2)*stat2[i];
   	n3+=pow(i+c-v1,3)*stat2[i];
   	n4+=pow(i+c-v1,4)*stat2[i];
   }
   Q = sqrt(n2/size);
   printf("Интервал  [%f,%f]:\n", c, d);
   printf("\tАссиметрия:%f\n", (n3/size)/pow(Q,3));
   printf("\tЭкцесс:%f\n", (n4/size)/pow(Q,4)-3);
   printf("\tСреднее значение:%f\n\n", v1);
   count = size/(abs(F-E+1));
   k1/=size;
   n2 = 0;
   n3 = 0;
   n4 = 0;
   for (int i=0;i<=abs(f-e);i++){
   	n2+=pow(i+e-k1,2)*stat3[i];
   	n3+=pow(i+e-k1,3)*stat3[i];
   	n4+=pow(i+e-k1,4)*stat3[i];
   }
   Q = sqrt(n2/size);
   printf("Интервал  [%f,%f]:\n", e, f);
   printf("\tАссиметрия:%f\n", (n3/size)/pow(Q,3));
   printf("\tЭкцесс:%f\n", (n4/size)/pow(Q,4)-3);
   printf("\tСреднее значение:%f\n\n", k1);
   fclose(fp3);
   graph3();
}   

void test9(double r, int sign, int size){
   int X;
   int Y;
   int Z;
   int R =r;
   double x;
   double y;
   double z;
   double n1 = 0;
   double v1 = 0;
   double k1 = 0;
   double Xi = 0;
   double count = size/(r*2+1);
   int stat[R*2+1];
   for (int i=0;i<=R*2;i++){
   	stat[i]=0;
   }
   int stat2[R*2+1];
   for (int i=0;i<=R*2;i++){
   	stat2[i]=0;
   }
   int stat3[R*2+1];
   for (int i=0;i<=R*2;i++){
   	stat3[i]=0;
   }
   FILE *fp3=NULL;
   fp3=fopen("gen.txt","w");
   for(int i=1;i<=size;i++){
     ball_uniform(r, 0, &x, &y, &z);
     fprintf(fp3, "%f\t%f\t%f\n", x, y, z);
     X = x+R;
     Y = y+R;
     Y = z+R;
     stat[X]++;
     stat2[Y]++;
     stat3[Y]++;
     n1+=x;
     v1+=y;
     k1+=z;
   }
   for (int i=0;i<=r*2;i++){
   	Xi += pow(stat[i] - count, 2)/count;
   }
   n1 /= size;
   printf("9)Равномерное на шаре с радиусом %f с выборкой %d значений:\n", r, size);
   printf("Точки по оси Х:\n");
   printf("\tЗначение Хи-квадрат:%f\n", Xi);
   printf("\tСреднее значение:%f\n\n", n1);
   Xi=0;
   for (int i=0;i<=r*2;i++){
   	Xi += pow(stat2[i] - count, 2)/count;
   }
   v1 /= size;
   printf("Точки по оси У:\n");
   printf("\tЗначение Хи-квадрат:%f\n", Xi);
   printf("\tСреднее значение:%f\n\n", v1);
   Xi=0;
   for (int i=0;i<=r*2;i++){
   	Xi += pow(stat3[i] - count, 2)/count;
   }
   k1 /= size;
   printf("Точки по оси Z:\n");
   printf("\tЗначение Хи-квадрат:%f\n", Xi);
   printf("\tСреднее значение:%f\n\n", k1);
   fclose(fp3);
   graph3();
}

void test10(double r, double sign, int size){
   double l = r-r*2;
   int X;
   int Y;
   int Z;
   int R =r;
   double x;
   double y;
   double z;
   double v1 = 0;
   double k1 = 0;
   double count = size/(r*2+1);
   int stat[R*2+1];
   for (int i=0;i<=R*2;i++){
   	stat[i]=0;
   }
   int stat2[R*2+1];
   for (int i=0;i<=R*2;i++){
   	stat2[i]=0;
   }
   int stat3[R*2+1];
   for (int i=0;i<=R*2;i++){
   	stat3[i]=0;
   }
   double n1 = 0;
   double n2 = 0;
   double n3 = 0;
   double n4 = 0;
   double Q;
   FILE *fp3=NULL;
   fp3=fopen("gen.txt","w");
   for(int i=1;i<=size;i++){
     ball_normal(r, 0, &x, &y, &z);
     fprintf(fp3, "%f\t%f\t%f\n", x, y, z);
     X = x+R;
     Y = y+R;
     Y = z+R;
     stat[X]++;
     stat2[Y]++;
     stat3[Y]++;
     n1+=x;
     v1+=y;
     k1+=z;
   }
   n1/=size;
   for (int i=0;i<=r-l;i++){
   	n2+=pow(i+l-n1,2)*stat[i];
   	n3+=pow(i+l-n1,3)*stat[i];
   	n4+=pow(i+l-n1,4)*stat[i];
   }
   Q = sqrt(n2/size);
   printf("10)Нормальное на шаре с радиусом %f с выборкой %d значений:\n", r, size);
   printf("Точки по оси Х:\n");
   printf("\tАссиметрия:%f\n", (n3/size)/pow(Q,3));
   printf("\tЭкцесс:%f\n", (n4/size)/pow(Q,4)-3);
   printf("\tСреднее значение:%f\n\n", n1);
   v1/=size;
   n2 = 0;
   n3 = 0;
   n4 = 0;
   for (int i=0;i<=r-l;i++){
   	n2+=pow(i+l-v1,2)*stat2[i];
   	n3+=pow(i+l-v1,3)*stat2[i];
   	n4+=pow(i+l-v1,4)*stat2[i];
   }
   Q = sqrt(n2/size);
   printf("Точки по оси У:\n");
   printf("\tАссиметрия:%f\n", (n3/size)/pow(Q,3));
   printf("\tЭкцесс:%f\n", (n4/size)/pow(Q,4)-3);
   printf("\tСреднее значение:%f\n\n", v1);
   k1/=size;
   n2 = 0;
   n3 = 0;
   n4 = 0;
   for (int i=0;i<=r-l;i++){
   	n2+=pow(i+l-k1,2)*stat3[i];
   	n3+=pow(i+l-k1,3)*stat3[i];
   	n4+=pow(i+l-k1,4)*stat3[i];
   }
   Q = sqrt(n2/size);
   printf("Точки по оси У:\n");
   printf("\tАссиметрия:%f\n", (n3/size)/pow(Q,3));
   printf("\tЭкцесс:%f\n", (n4/size)/pow(Q,4)-3);
   printf("\tСреднее значение:%f\n\n", k1);
   fclose(fp3);
   graph3();
}

int main(void){
  double x;
  double y;
  double z;
  setlocale(LC_ALL, "Rus");
  printf("Добро пожаловать в программу тестирования!\n\n");
  printf("Розыгрыш одной величины:\n");
  printf("Равномерное на отрезке [%d,%d]: %.2f\n", -10, 10, section_uniform(-10, 10, 2));
  printf("Нормальное на отрезке [%d,%d]: %.2f\n", -10, 10, section_normal(-10, 10, 2));
  rectangle_uniform(-10, 10, -20, 20, 2, &x, &y);
  printf("Равномерное на прямоугольнике [%d,%d]*[%d,%d]: %.2f, %.2f\n", -10, 10, -20, 20, x, y);
  rectangle_normal(-10, 10, -20, 20, 2, &x, &y);
  printf("Нормальное на прямоугольнике [%d,%d]*[%d,%d]: %.2f, %.2f\n", -10, 10, -20, 20, x, y);
  circle_uniform(10, 2, &x, &y);
  printf("Равномерное на круге [%d]: %.2f, %.2f\n", 10, x, y);
  circle_normal(10, 2, &x, &y);
  printf("Нормальное на круге [%d]: %.2f, %.2f\n", 10, x, y);
  paraped_uniform(-10, 10, -20, 20, -30, 30, 2, &x, &y, &z);
  printf("Равномерное на параллелепипеде [%d,%d]*[%d,%d]*[%d,%d]: %.2f, %.2f, %.2f\n", -10, 10, -20, 20, -30, 30, x, y, z);
  paraped_normal(-10, 10, -20, 20, -30, 30, 2, &x, &y, &z);
  printf("Нормальное на параллелепипеде [%d,%d]*[%d,%d]*[%d,%d]: %.2f, %.2f, %.2f\n", -10, 10, -20, 20, -30, 30, x, y, z);
  ball_uniform(10, 2, &x, &y, &z);
  printf("Равномерное на шаре [%d]: %.2f, %.2f, %.2f\n", 10, x, y, z);
  ball_normal(10, 2, &x, &y, &z);
  printf("Нормальное на шаре [%d]: %.2f, %.2f, %.2f\n", 10, x, y, z);
  printf("Нажмите Enter чтобы продолжить\n\n");
  getchar();   
   
  int size = 10000;
   test1(0, 9, 0, size);
   test2(0, 9, 0, size);
   test3(0, 25, -25, 0, 0, size);
   test4(0, 25, -25, 0, 0, size);
   test5(25, 0, size);
   test6(25, 0, size);
   test7(0, 25, -25, 0, 0, 25, 0, size);
   test8(0, 25, -25, 0, 0, 25, 0, size);
   test9(25, 0, size);
   test10(25, 0, size);
   return 0;
}
