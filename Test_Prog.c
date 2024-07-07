#include "./Generate_Module.h"
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#define M 6
#define N 80
int main(void){
  setlocale(LC_ALL, "Rus");
  printf("Добро пожаловать в программу тестирования!\nВыберите действие:\n");
  double x;
  double y;
  double z;
  rectangle_uniform(-10, 10, -10, 10, 2, &x, &y);
  printf("%f\n", section_uniform(-10, 10, 2));
  printf("%f\n", section_uniform(-10, 10, 2));
  printf("%f\n", section_uniform(-10, 10, 2));
  // printf("%f\n", section_uniform(-6, 234, 2));

  // ball_normal(56, 2, &x, &y, &z);
  // printf("%f\t%f\t%f\n", x, y, z);
  // FILE *fp3=NULL;
  // fp3=fopen("gen1.txt","w");
  // for(int i=1;i<=10000;i++){
  //   rectangle_uniform(0, 100, 0, 100, 2, &x, &y);
  //   fprintf(fp3,"%f\t%f\t%f\n", x, y, z);
  // }
  return 0;
}
