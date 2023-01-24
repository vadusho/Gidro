
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <iterator>
#include <math.h>
using namespace std;

void output (int **M, int n, int m){
int i,j;

for (i=0;i<n; i++){
for (j=0;j<m; j++){
printf("%d ", M[i][j]);
}
printf("\n");
}
}


void otshet (FILE *fr, int* nn, int* n){
char cm;
int pr=0, slash=0, num=0, num1=0;
while ((cm = fgetc(fr)) != EOF){
if (cm == ',' || cm == ' ' || cm == '\n' || cm == '1'|| cm == '0'|| cm == '2'|| cm == '3'|| cm == '4'|| cm == '5'|| cm == '6'|| cm == '7'|| cm == '8'|| cm == '9'|| cm == '-'){
if (cm == ',' || cm == ' ' ){
pr++;
if (slash==0)
    num1++;
    num++;
}
if (cm == '\n'){
slash++;
pr++;
if (num!=num1)
{ printf("Не верный формат данных в файле");
    exit(1);
}
num=0;
}
}
else{
printf("Некорректные значения в файле");
//return 0;
}
}
*n = slash + 1;
*nn = (pr+1)/(*n);
/*if (n!=nn){
printf("Данные в файле не верны\n");
return 0;
}*/
}

void file (FILE **fr, int* nn, int* n, char* A){
//char B[256]=A;{"g.2.txt"};
res3:/* printf("Введите имя файла: \n");
scanf("%s",A);*/
(*fr)=fopen(A,"r");
if (fr==0){
printf("\n Файла нет ");
goto res3;
}
otshet(*fr, &(*nn), &(*n));
fseek(*fr,0L,SEEK_SET);
}



void read_write (int ***M, FILE *fr, int n, int m, int flag){
int i,j;
for (i=0;i<n; i++){
for (j=0;j<m; j++){
    if (flag==0)
fscanf(fr,"%d",&(*M)[i][j] );
else
    fprintf(fr,"%d ",(*M)[i][j]);
   }
fprintf(fr,"\n");
}
 fclose(fr);
}



void GetMatr(int **mas, int **p, int i, int j, int m) {
  int ki, kj, di, dj;
  di = 0;
  for (ki = 0; ki<m - 1; ki++) { // проверка индекса строки
    if (ki == i) di = 1;
    dj = 0;
    for (kj = 0; kj<m - 1; kj++) { // проверка индекса столбца
      if (kj == j) dj = 1;
      p[ki][kj] = mas[ki + di][kj + dj];
    }
  }
}
// Рекурсивное вычисление определителя
int Determinant(int **mas, int m) {
  int i, j, d, k, n;
  int **p;
  p = new int*[m];
  for (i = 0; i<m; i++)
    p[i] = new int[m];
  j = 0; d = 0;
  k = 1; //(-1) в степени i
  n = m - 1;
  if (m<1)
    std::cout << "Определитель вычислить невозможно!";
  if (m == 1) {
    d = mas[0][0];
    return(d);
  }
  if (m == 2) {
    d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
    return(d);
  }
  if (m>2) {
    for (i = 0; i<m; i++) {
      GetMatr(mas, p, i, 0, m);
      std::cout << mas[i][j] << std::endl;
      d = d + k * mas[i][0] * Determinant(p, n);
      k = -k;
    }
  }
  return(d);
}

/*

float** sum_ranz(float **mas1,float **mas2, int i1, int j1,int i2, int j2, int c){
    float **swap_;
int i,j;
 if ( i1==i2&&j1==j2 ){
swap_ = malloc(i1*sizeof(float*));
for (i=0; i<j1; i++){
swap_[i] = malloc(j1*sizeof(float));
}
if (c==0){
    for (i=0;i<i1;i++){
        for (j=0;j<j1;j++){
       swap_[i][j]=mas1[i][j]+mas2[i][j];
        }
    }
}
else{
    for (i=0;i<i1;i++){
        for (j=0;j<j1;j++){
       swap_[i][j]=mas1[i][j]-mas2[i][j];
        }
    }
}
 }
 return swap_;
}*/

/*
void umnoj (float **mas1,float **mas2, int i1, int j1,int i2, int j2 ){
float **swap_=NULL;
int i,j,k;
if (j1==i2){

swap_ = malloc(i1*sizeof(float*));
for (i=0; i<j2; i++){
swap_[i] = malloc(j2*sizeof(float));
}
for(i = 0; i < i1; i++)
    for(j = 0; j <j2; j++)
    {
        for(k = 0; k <j1; k++)
            swap_[i][j]=mas1[i][k]*mas2[k][j];
    }
}
return (swap_);
} */

void minor(std::vector < std::vector <float > > &swapping, std::vector < std::vector <float> > &matrix,int line,int column);
vector < vector <float > > transported_matrix(const vector < vector <float > > &matrix);
void souz(std::vector < std::vector <float> > &matrix);
void obrat( std::vector < std::vector <float> > &matrix, float determinant);

float opredel( std::vector < std::vector <float> > &matrix){
    int sign=1;
    float det=0;
    std::vector < std::vector <float > > swapping;
    if (matrix.size()==1){
    det=matrix[0][0];
    return(det);
    }
    if (matrix.size()==2){
     det=matrix[0][0]*matrix[1][1]*-matrix[0][1]*matrix[1][0];
     return(det);
    }
    if (matrix.size()==3){
     det=matrix[0][0]*matrix[1][1]*matrix[2][2]+matrix[1][0]*matrix[2][1]*matrix[0][2]+matrix[0][1]*matrix[1][2]*matrix[2][0]-matrix[0][2]*matrix[1][1]*matrix[2][0]-matrix[1][0]*matrix[0][1]*matrix[2][2]-matrix[2][1]*matrix[1][2]*matrix[0][0];
     return(det);
    }
    if(matrix.size()>3){
        for (int i=0;i<matrix.size();i++){
            minor(swapping,matrix,i,0);
            det=det+sign*matrix[i][0]*opredel(swapping);
            sign*=-1;
            for (int k=0;k<swapping.size();k++)
                swapping[k].clear();
            swapping.clear();
        }
    return(det);
    }
}

template <typename T>
void print_vector(const vector < vector <T > > &A);

void minor(std::vector < std::vector <float > > &swapping, std::vector < std::vector <float> > &matrix,int line,int column){
int x=0;
  swapping.push_back(std::vector <float >());
  for(int i = 0; i < matrix.size(); ++i ) {
          int y = 0;
          if( i != line ) {
              for(int j = 0; j < matrix.size(); ++j ) {
                  if( j != column ) {
                      swapping[x].push_back(matrix[i][j]);
                  }
              }
              x++;
             swapping.push_back(std::vector <float >());
          }
      }
      swapping.erase(swapping.end());
  /*
      swapping=matrix;
      for(int i = 0; i < swapping.size(); i++ )
      swapping[i].erase(swapping[i].begin()+column);
      swapping.erase(swapping.begin()+line);*/
}


vector < vector <float > > transported_matrix(const vector < vector <float > > &matrix){
    std::vector < std::vector <float > > swapping;
    for (int i = 0; i < matrix[0].size(); i++)
        swapping.push_back(std::vector <float >());
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++)
            swapping[j].push_back(matrix[i][j]);
     return swapping;
}



void souz(std::vector < std::vector <float> > &matrix){
   std:: vector < std::vector <float > > swapping;
    if (matrix.size()==2){
        swapping.push_back(std::vector <float >());
        swapping[0].push_back(matrix[1][1]);
        swapping[1].push_back(matrix[1][0]);
        swapping.push_back(std::vector <float >());
        swapping[0].push_back(matrix[0][1]);
        swapping[1].push_back(matrix[0][0]);
    }
if (matrix.size()>2){
  for (int i=0;i<matrix.size();i++){
      swapping.push_back(std::vector <float >());
    for (int j=0;j<matrix.size();j++){
        std::vector < std::vector <float > > swapping_temp;
        minor(swapping_temp,matrix,i,j);
        swapping[i].push_back((-1, i+j)*opredel(swapping_temp));
  }
}
}
matrix.swap(swapping);
}

void obrat( std::vector < std::vector <float> > &matrix, float determinant){

  souz(matrix);
  transported_matrix(matrix);
  for (int i=0;i<matrix.size();i++){
  for (int j=0;j<matrix.size();j++){
        matrix[i][j]=matrix[i][j]/determinant;
  }
}
}

vector < vector <float > >  multiply_matrix(const vector < vector <float > > &matrix_one, float value){
      vector < std::vector <float > > swapping=matrix_one;
        for (int i=0; i<matrix_one.size(); i++ )
            for (int j=0; j<matrix_one[0].size(); j++ )
                swapping[i][j]=value*swapping[i][j];
    return swapping;
}

vector < vector <float > >  multiply_matrix(const vector < vector <float > > &matrix_one,const  vector < vector <float > > &matrix_two){

  if ( matrix_one[0].size()!=matrix_two.size())
    cout<<"ERROR matrix mult!"<<endl;

  vector < vector <float > > A;

    for (int i=0; i<matrix_one.size(); i++ ){
        A.push_back(vector <float> ());
      for (int j=0; j<matrix_two[0].size(); j++ ){
        float sum=0;
        for (int g=0; g<matrix_one[0].size(); g++ ){
        sum+=matrix_one[i][g]*matrix_two[g][j];
        }
        A[i].push_back(sum);
      }
    }

  return A;
}

vector < vector <float > >  sqrt_matrix(const vector < vector <float > > &matrix_one){
  vector < vector <float > > A;

    for (int i=0; i<matrix_one.size(); i++ ){
        A.push_back(vector <float> ());
      for (int j=0; j<matrix_one[0].size(); j++ ){
            if ( matrix_one[i][j] <0 )
             A[i].push_back(sqrtf(abs(matrix_one[i][j]))*-1);
      else
        A[i].push_back(sqrtf(matrix_one[i][j]));
      }
    }

  return A;
}

vector < vector <float > > sum_minus(const vector < vector <float > > &matrix_one,const  vector < vector <float > > &matrix_two, string fun){
  std:: vector < std::vector <float > > swapping;
  if (fun=="sum"){
    for (int i=0;i<matrix_one.size();i++){
        swapping.push_back(vector <float> ());
        for (int j=0;j<matrix_one[0].size();j++){
          swapping[i].push_back(matrix_one[i][j]+matrix_two[i][j]);
        }
    }
  }
  else{
    for (int i=0;i<matrix_one.size();i++){
        swapping.push_back(vector <float> ());
        for (int j=0;j<matrix_one[0].size();j++){
         swapping[i].push_back(matrix_one[i][j]-matrix_two[i][j]);
        }
    }
  }

   return swapping;
}




int Gauss(double **matrica_a, int n, double *massiv_b, double *x)
{
    int i, j, k, r;
    double c, M, max, s, **a, *b; a = new double *[n];
    for (i = 0; i<n; i++)
      a[i] = new double[n];
    b = new double[n];
    for (i = 0; i<n; i++)
        for (j = 0; j<n; j++)
          a[i][j] = matrica_a[i][j];
          for (i = 0; i<n; i++)
          b[i] = massiv_b[i];
            for (k = 0; k<n; k++){
        max = fabs(a[k][k]);
        r = k;
        for (i = k + 1; i<n; i++)
            if (fabs(a[i][k])>max){
                max = fabs(a[i][k]);
                r = i;}
        for (j = 0; j<n; j++){
            c = a[k][j];
            a[k][j] = a[r][j];
            a[r][j] = c;}
        c = b[k]; b[k] = b[r]; b[r] = c; for (i = k + 1; i<n; i++){
            for (M = a[i][k] / a[k][k], j = k; j<n; j++)
                a[i][j] -= M * a[k][j]; b[i] -= M * b[k];}

    }
    if (a[n - 1][n - 1] == 0) if (b[n - 1] == 0)return-1; else return-2;
    else {
        for (i = n - 1; i >= 0; i--){
            for (s = 0, j = i + 1; j<n; j++)
                s += a[i][j] * x[j]; x[i] = (b[i] - s) / a[i][i];
        }return 0;
    } for (i = 0; i<n; i++) delete[] a[i]; delete[] a;
    delete[] b;

}

vector < vector <float > > INVERSE (const vector < vector <float > > &matrix_one){
    int res,n;
    double *b, *x;
    n=matrix_one.size();
    double **a, **y;
    a= new double*[n];
    y= new double*[n];
    for (int i=0;i<n; i++){
      a[i]=new double[n];
      y[i]=new double[n];
    }
      for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++){
          a[i][j]=matrix_one[i][j];
          if (i==j)
            y[i][j]=1;
          else
             y[i][j]=0;
        }
    b = new double[n];
    x = new double[n];
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++)
            if (j == i)
              b[j] = 1;
              else b[j] = 0;
               res = Gauss(a, n, b, x);
               if (res != 0)
                break;
               else
                for (int j = 0; j < n; j++) {
                   y[j][i] = x[j];}
    }
    delete[] x;
    delete[] b;
    vector < vector <float > > inverse_vector;
    for (int i=0; i<n;i++){
      inverse_vector.push_back(vector <float >());
      for (int j=0; j<n;j++){
        inverse_vector[i].push_back(y[i][j]);
      }
    }
    return inverse_vector;
   // if (res != 0)
   //   return -1;
  //  else return 0;
}








