#include <iostream>
#include <stdlib.h>
using namespace std;
class complex{
    float re,im;
public:
    static int n,m;
    complex();
    complex(float r);
    complex(int r,int i);
    complex(const complex&);
    ~complex();


};
struct nr{
double val;
nr *actual, *urm;};
complex::complex(int r,int i)
{
    re=r;
    im=i;
}
complex::complex(){re=0;im=0; }
complex::complex(float r)
{   re=r;
    im=0;
}
complex::complex(const complex &o)
{
        re=o.re;
        im=o.im;

}
complex::~complex(){}
class matrice: public complex
{
protected:
    unsigned int **matr;
   static int m,n,elem;
    nr *p;
public:
    void atribuire(matrice ob);
    void creare(nr *primul,nr *ultimul, int valoare);
    void afisare(nr *r);
    //void transformare();
    matrice();
    matrice(nr *cactual,nr *curm);
    matrice(const matrice& mat)
    {
        matr=new unsigned int *[20];
        for(int i; i<n;i++)
            for(int j;j<m;j++)
                matr[i][j]=mat.matr[i][j];

    }
    ~matrice(){delete []matr;};
    friend std::istream &operator >>(std::istream& f,matrice& mat);
    friend std::ostream &operator<<(std::ostream& g,matrice& p);
    matrice operator=(matrice& mat);
};
istream &operator >>(istream &f,matrice & mat)
{   int i;
    f>>mat.n;
    for(i=1;i<=mat.n;i++)
        for(int j=1;j<=mat.n;j++)
        f>>mat.matr[i][j];
    return f;
}
ostream &operator <<(ostream &g,matrice &p)
{
    int i,j;
    g<<p.m;
    for(i=1;i<=p.m;i++)
        for(j=1;j<=p.m;j++)
        g<<p.matr[i][j];
    return g;
}
matrice::matrice()
{   p->actual=NULL;
    p->urm=NULL;
}
matrice::matrice(nr *actual,nr *urm)
{
    actual=p->actual;
    urm=p->urm;
}
void matrice::atribuire(matrice ob)
{
    n=ob.n;
    m=ob.m;
    elem=ob.elem;
    for(int i=0;i<elem;i++)
        matr[i]=ob.matr[i];
}
void matrice::creare(nr *primul,nr *ultimul, int valoare)
{     nr *x;
      x=new nr;
       if(primul==0)
       {
           primul=new nr;
           primul->val=valoare;
           primul->actual=0;
           primul->urm=0;
           ultimul=primul;
       }
       else{
        x=new nr;
        x->val=valoare;
        ultimul->actual=x;
        x->urm=ultimul;
        ultimul=x;
        ultimul->actual=0;
       }
   }
void matrice::afisare(nr *r)
{
    nr *q=r;
    while(q!=0)
    {cout<<q->val<<" ";
        q=q->actual;
}}
matrice matrice::operator=(matrice &mat)
{
    matr=mat.matr;
    return (*this);
}
class matrice_oarecare:public matrice
{
    int lin, col;
public:
    matrice_oarecare()
    {
        lin=0;
        col=0;
    }
    matrice_oarecare(int l,int c)
    {
        l=lin;
        c=col;
    }
    matrice_oarecare(const matrice_oarecare &o)
    {
        matr=new unsigned int *[20];
        for(int i; i<lin;i++)
            for(int j;j<col;j++)
                matr[i][j]=o.matr[i][j];
    }
    ~matrice_oarecare(){}
    void matrice_triunghiulara();
};
void matrice_oarecare::matrice_triunghiulara()
{n=0;
matr= new unsigned int *[20];
for(int i=0;i<lin;i++)
    for(int j=0;j<col;j++)
        if(i==j)
{

}
    for(int j=0;j<col;j++)
{

}
}
class matrice_patratica:public matrice
{ int *dim;
public:
    matrice_patratica()
    {
        dim=0;
    }
    matrice_patratica(int *d)
    {
        dim=d;
    }
    matrice_patratica(const matrice_patratica &dm)
    {
        dim=dm.dim;
    }
    ~matrice_patratica(){delete dim;}
    void determinant();
};
void matrice_patratica::determinant()
{
    int det;
    double **mat;
    mat=new double *[20];
    for(int x=0;x<=elem;x++)
    {
           {for(int i=0;i<n;i++)

                    {for(int j=0;j<m;j++)
                        if(j==x)
                            mat[i][j]=matr[i][j];
                        }}
}}
int main()
{

    return 0;
}
