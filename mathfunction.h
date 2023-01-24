#ifndef MATHFUNCTION
#define MATHFUNCTION
void output (int **M, int n, int m);
void otshet (FILE *fr, int* nn, int* n);
void file (FILE **fr, int* nn, int* n, char* A);
void read_write (int ***M, FILE *fr, int n, int m, int flag);
void GetMatr(int **mas, int **p, int i, int j, int m);
int Determinant(int **mas, int m);
void minor(std::vector < std::vector <float > > &swapping, std::vector < std::vector <float> > &matrix,int line,int column);
vector < vector <float > > transported_matrix(const vector < vector <float > > &matrix);
void souz(std::vector < std::vector <float> > &matrix);
void obrat( std::vector < std::vector <float> > &matrix, float determinant);
void print_vector(const vector < vector <T > > &A);






#endif // MATHFUNCTION

