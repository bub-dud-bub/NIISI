#include "./Generate_Module.h"
int q = 16807;
int m = 0x7fffffff;
long int seed;
double section_uniform(int a, int b, int sign){
    sign = pow(10, sign);
    a *= sign;
    b *= sign;
    double z0;
    if (seed==0){
      seed = time(0);
    }
    do{
      seed = seed * q % m;
      z0 = (seed%(b+sign-a)+a);
    }
    while(z0<a||z0>b);
    return z0/sign;
}
double section_normal(double a, double b, int sign){
    sign = pow(10, sign);
    double x;
    double y;
    double s;
    double z0;
    double z1;
    double S;
    if (seed==0){
      seed = time(0);
    }
    do{
      seed = seed * q % m;
      x = seed%1000000/1000000.0;
      seed = (seed * q % m);
      y = seed%1000000/1000000.0;
      z0 = cos(2.0*M_PI*y)*sqrt(-2.0*log(x));
      z1 = sin(2.0*M_PI*y)*sqrt(-2.0*log(x));
      z0 = z0*((b-a)/7.5) + a+(b-a)/2;
      if (z0>b||z0<a){
         z0 = z1;
         z0 = z0*((b-a)/7.5) + a+(b-a)/2;
      }
    }
    while(z0>b||z0<a);
    return round(z0*sign)/sign;
}

void rectangle_uniform(int a, int b, int c, int d, int sign, double* x, double* y){
  sign = pow(10, sign);
  a *= sign;
  b *= sign;
  c *= sign;
  d *= sign;
  if (seed==0){
    seed = time(0);
  }
  do{
    seed = seed * q % m;
    *x = (seed%(b+sign-a)+a);
    seed = seed * q % m;
    *y = (seed%(d+sign-c)+c);
  }
  while(*x<a||*x>b||*y<c||*y>d);
  *x /= sign;
  *y /= sign;
}

void rectangle_normal(int a, int b, int c, int d, int sign, double* x, double* y){
  sign = pow(10, sign);
  double X;
  double Y;
  double s;
  double z0;
  double z1;
  double S;
  if (seed==0){
    seed = time(0);
  }
  do{
    do{
      seed = seed * q % m;
      X = seed%1000000/1000000.0;
      seed = (seed * q % m);
      Y = seed%1000000/1000000.0;
    }
    while(X<0||Y<0);
    z0 = cos(2.0*M_PI*Y)*sqrt(-2.0*log(X));
    z1 = sin(2.0*M_PI*Y)*sqrt(-2.0*log(X));
    z0 = z0*((b-a)/7.5) + a+(b-a)/2;
    z1 = z1*((d-c)/7.5) + c+(d-c)/2;
  }
  while(z0>b||z0<a||z1>d||z1<c);
  *x = round(z0*sign)/sign;
  *y = round(z1*sign)/sign;
}

void circle_uniform(int a, int sign, double* x, double* y){
  sign = pow(10, sign);
  a *= sign;
  int b = a - a*2;
  double v;
  double w;
  if (seed==0){
    seed = time(0);
  }
  do{
    seed = seed * q % m;
    v = seed%((a+sign-b))+b;
    seed = seed * q % m;
    w = seed%(a+sign-b);
  }
  while(sqrt(v*v+w*w)>a);
  *x = v / sign;
  *y = w / sign;

}

void circle_normal(int a, int sign, double* x, double* y){
  sign = pow(10, sign);
  a *= 10;
  int b = a - a*2;
  double z0;
  double z1;
  double X;
  double Y;
  if (seed==0){
    seed = time(0);
  }
  do{
    do{
      seed = seed * q % m;
      X = seed%1000000/1000000.0;
      seed = (seed * q % m);
      Y = seed%1000000/1000000.0;
    }
    while(X<0||Y<0);
    z0 = cos(2.0*M_PI*Y)*sqrt(-2.0*log(X));
    z1 = sin(2.0*M_PI*Y)*sqrt(-2.0*log(X));
    z0 = z0*((a-b)/7.5);
    z1 = z1*((a-b)/7.5);
  }
  while(z0>a||z0<b||z1>a||z1<b||sqrt(z0*z0+z1*z1)>a);
  *x = round(z0*sign)/sign;
  *y = round(z1*sign)/sign;
}

void paraped_uniform(int a, int b, int c, int d, int e, int f, int sign, double* x, double* y, double* z){
  sign = pow(10, sign);
  a *= sign;
  b *= sign;
  c *= sign;
  d *= sign;
  e *= sign;
  f *= sign;
  if (seed==0){
    seed = time(0);
  }
  do{
    seed = seed * q % m;
    *x = (seed%(b+sign-a)+a);
    seed = seed * q % m;
    *y = (seed%(d+sign-c)+c);
    seed = seed * q % m;
    *z = (seed%(f+sign-e)+e);
  }
  while(*x<a||*x>b||*y<c||*y>d||*z<e||*z>f);
  *x /= sign;
  *y /= sign;
  *z /= sign;
}

void paraped_normal(int a, int b, int c, int d, int e, int f, int sign, double* x, double* y, double* z){
  sign = pow(10, sign);
  double X;
  double Y;
  double Z;
  double s;
  double z0;
  double z1;
  double z2;
  double S;
  if (seed==0){
    seed = time(0);
  }
  do{
    do{
      seed = seed * q % m;
      X = seed%1000000/1000000.0;
      seed = (seed * q % m);
      Y = seed%1000000/1000000.0;
      seed = (seed * q % m);
      Z = seed%1000000/1000000.0;
    }
    while(X<0||Y<0||Z<0);
    z0 = cos(2.0*M_PI*Y)*sqrt(-2.0*log(X));
    z1 = sin(2.0*M_PI*Y)*sqrt(-2.0*log(X));
    z2 = cos(2.0*M_PI*Z)*sqrt(-2.0*log(X));
    z0 = z0*((b-a)/7.5) + a+(b-a)/2;
    z1 = z1*((d-c)/7.5) + c+(d-c)/2;
    z2 = z2*((f-e)/7.5) + e+(f-e)/2;
  }
  while(z0>b||z0<a||z1>d||z1<c||z2>f||z2<e);
  *x = round(z0*sign)/sign;
  *y = round(z1*sign)/sign;
  *z = round(z2*sign)/sign;
}

void ball_uniform(int a, int sign, double* x, double* y, double* z){
  sign = pow(10, sign);
  a *= sign;
  int b = a - a*2;
  double z0;
  double z1;
  double z2;
  if (seed==0){
    seed = time(0);
  }
  do{
    seed = seed * q % m;
    z0 = seed%((a+sign-b))+b;
    seed = seed * q % m;
    z1 = seed%(a+sign-b);
    seed = seed * q % m;
    z2 = seed%(a+sign-b);
  }
  while(sqrt(z0*z0+z1*z1)>a||sqrt(z0*z0+z2*z2)>a||sqrt(z2*z2+z1*z1)>a);
  *x = z0 / sign;
  *y = z1 / sign;
  *z = z2 / sign;
}

void ball_normal(int a, int sign, double* x, double* y, double* z){
  sign = pow(10, sign);
  a *= sign;
  int b = a - a*2;
  double z0;
  double z1;
  double z2;
  double X;
  double Y;
  double Z;
  if (seed==0){
    seed = time(0);
  }
  do{
    do{
      seed = seed * q % m;
      X = seed%1000000/1000000.0;
      seed = (seed * q % m);
      Y = seed%1000000/1000000.0;
      seed = (seed * q % m);
      Z = seed%1000000/1000000.0;
    }
    while(X<0||Y<0||Z<0);
    z0 = cos(2.0*M_PI*Y)*sqrt(-2.0*log(X));
    z1 = sin(2.0*M_PI*Y)*sqrt(-2.0*log(X));
    z2 = cos(2.0*M_PI*Z)*sqrt(-2.0*log(X));
    z0 = z0*((a-b)/7.5);
    z1 = z1*((a-b)/7.5);
    z2 = z2*((a-b)/7.5);
  }
  while(z0>a||z0<b||z1>a||z1<b||z2>a||z2<b||sqrt(z0*z0+z1*z1)>a||sqrt(z0*z0+z2*z2)>a||sqrt(z2*z2+z1*z1)>a);
  *x = round(z0*sign)/sign;
  *y = round(z1*sign)/sign;
  *z = round(z2*sign)/sign;
}
