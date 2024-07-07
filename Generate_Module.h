#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
double section_uniform(int a, int b, int sign);

double section_normal(double a, double b, int sign);

void rectangle_uniform(int a, int b, int c, int d, int sign, double* x, double* y);

void rectangle_normal(int a, int b, int c, int d, int sign, double* x, double* y);

void circle_uniform(int a, int sign, double* x, double* y);

void circle_normal(int a, int sign, double* x, double* y);

void paraped_uniform(int a, int b, int c, int d, int e, int f, int sign, double* x, double* y, double* z);

void paraped_normal(int a, int b, int c, int d, int e, int f, int sign, double* x, double* y, double* z);

void ball_uniform(int a, int sign, double* x, double* y, double* z);

void ball_normal(int a, int sign, double* x, double* y, double* z);
