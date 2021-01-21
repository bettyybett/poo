#include <iostream>
#include <vector>
#include<stdlib.h>
#include <string.h>
using namespace std;
struct adresa
{
    int sector;
    char numar,strada;
};
int n,m,k,i,j;
class transport
{   protected:
        int *v;
        char tip;
        int n;
        adresa info;
     public:
        friend struct adresa;
        void lista_mijloace_transport(int *v,int n );
        transport(int *p,int r);
        transport (int p)
        {
            n=p;
        }
        transport(const transport &t);
        transport operator = (const transport &p);
        ~ transport();

};
transport::transport(int *p,int r)
{
    v=p;
    n=r;

}
transport::transport(const transport &t)
{
    v=t.v;
    n=t.n;

}
/*transport::transport operator =(const transport &p)
{
    v=p; //nu compileaza "transport names constructor,not type"
}*/
void transport::lista_mijloace_transport(int *v,int n)
{   v=new int (n);
    for(int i=1;i<=n;i++);
           v[i]= rand();
}
transport::~transport()
{
    delete []v;
}
class tip_oras: public transport
{ protected:
    bool urban,extraurban;
    int punct_legitimatii=0;
public:
    void cod_intern(char tip,long nr);
    void tip_statie(int legitimatie);
    tip_oras(int *p,int r);
    tip_oras(const tip_oras &p);
    tip_oras(int p);
    tip_oras operator =(const tip_oras&);
    ~tip_oras();

};
/*tip_oras::tip_oras(int *p,int r)
{
    v=p; // considera ca nu ii gaseste tipul in clasa transport
    n=r;
}*/
/*tip_oras::tip_oras(int p)
{
    punct_legitimatii=p; // considera ca nu ii gaseste tipul in clasa transport
}*/
tip_oras::~tip_oras(){}
/*void tip_oras::tip_statie(int legitimatie)
{
    if(urban==1)
        cout<<"orasul este urban";
    else cout<<"orasul este extraurban";
    try {
        if(legitimatie!=0)  //eroare considera o parte din clasa tip oras ca fiind privata si neaccesibila
    {
        throw cout<<"statia este importanta";
    }
    catch{punct_legitimatii++;
    cout<<punct_legitimatii;}
}*/
void tip_oras::cod_intern(char tip,long nr)
{
    for(i=1;i<n;i++)
        if(urban==1)
            cout<<"SU"<<"-"<<nr;
            else cout<<"SE"<<"-"<<nr;

}
int main()
{
//  transport ;
 //cout<<T.info.numar;
    return 0;
}
