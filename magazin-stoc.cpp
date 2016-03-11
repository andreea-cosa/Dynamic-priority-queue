//Coskun Ibrahim Grupa 132 GNU Codeblocks
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class lot
{
protected:
    double nrb, pu;
    struct data
    {
        int z,l,an;
    }dp;
public:
    lot(int n=0)
    {
        nrb=n;
    }
    virtual void citire(){};
    virtual void afisare(){};
    virtual bool vanz(char *x,double h){};
    virtual bool vanzm(char *x,double h){};
    virtual double pret(){};
    virtual bool vala(){};
    ~lot()
    {
    }
};
class produs:public lot
{
protected:
    char *um, *nume;
public:
    produs():lot()
    {
        um=new char [255];
        nume= new char [255];
    }
    virtual void citire()
    {
        cout<<"Numele produsului: ";
        cin.getline(nume,255);
        cin.getline(nume,255);
        cout<<"Dati unitatea de masura: ";
        cin.getline(um,255);
        cout<<endl<<"Numarul de bucati/unitate de masura:";
        cin>>nrb;
        cout<<endl<<"Pretul pe unitate: ";
        cin>>pu;
        cout<<endl<<"Data primirii lotului (zi/luna/an): ";
        cin>>dp.z>>dp.l>>dp.an;
    }
    friend istream &operator<<(istream &i, produs & P);
    virtual void afisare()
    {
        cout<<"Pe data de "<<dp.z<<"."<<dp.l<<"."<<dp.an<<", magazinul a primit un lot de "<<nrb<<" "<<um<<" de "<<nume<<", la pretul de "<<pu<<"lei pe "<<um;
    }
    void afisare(char *x)
    {
        if(strcmp(nume,x)==0)
            cout<<"Pe data de "<<dp.z<<"."<<dp.l<<"."<<dp.an<<", magazinul a primit un lot de "<<nrb<<" "<<um<<" de "<<nume<<", la pretul de "<<pu<<"lei pe "<<um;;
    }
    bool vanz(char *x,double h);
    bool vanzm(char *x,double h);
    double pret()
    {
        cout<<pu*nrb;
    }
    virtual bool vala(){};
    ~produs()
    {
        delete []um;
        delete []nume;
    }
};
bool produs::vanz(char *x,double h)
{
    if(h==nrb && strcmp(nume,x)==0 )
        return 1;
    return 0;
}
bool produs::vanzm(char *x, double h)
{
    if(h==nrb && strcmp(nume,x)==0 )
        return 1;
    return 0;
}
istream &operator<<(istream &i, produs & P)
{
     cout<<"Numele produsului: ";
        i.getline(P.nume,255);
        i.getline(P.nume,255);
        cout<<"Dati unitatea de masura: ";
        i.getline(P.um,255);
        cout<<endl<<"Numarul de bucati/unitate de masura:";
        i>>P.nrb;
        cout<<endl<<"Pretul pe unitate: ";
        i>>P.pu;
        cout<<endl<<"Data primirii lotului (zi/luna/an): ";
        i>>P.dp.z>>P.dp.l>>P.dp.an;
}
class perisabil:public produs
{
protected:
    struct data
    {
        int z,l,an;
    }pv;
public:
    perisabil():produs()
    {
    }
    void citire();
    friend istream &operator<<(istream &i, perisabil & P);
    void afisare();
    void termen();
    bool vala()
    {
        int z,l,an;
        an=pv.an-dp.an;
        l=pv.l-dp.l;
        if(l<0 && pv.an>=dp.an)
            l=l*(-1);
        z=pv.z-dp.z;
        if((z<0 && pv.an>dp.an && pv.l>=dp.l)||(z<0 && pv.an==dp.an && pv.l>dp.l))
        z=z*(-1);
        if(z>0 && l>0 && an>0)
            return 1;
        return 0;
    }
    ~perisabil()
    {
    }
};
istream &operator<<(istream &i, perisabil & P)
{
         cout<<"Numele produsului: ";
        i.getline(P.nume,255);
        i.getline(P.nume,255);
        cout<<"Dati unitatea de masura: ";
        i.getline(P.um,255);
        cout<<endl<<"Numarul de bucati/unitate de masura:";
        i>>P.nrb;
        cout<<endl<<"Pretul pe unitate: ";
        i>>P.pu;
        cout<<endl<<"Data primirii lotului (zi/luna/an): ";
        i>>P.dp.z>>P.dp.l>>P.dp.an;
        cout<<endl<<"Data expirarii lotului (zi/luna/an): ";
        i>>P.pv.z>>P.pv.l>>P.pv.an;
}
void perisabil::citire()
{
    cout<<"Numele produsului: ";
    cin.getline(nume,255);
    cin.getline(nume,255);
    cout<<"Dati unitatea de masura: ";
    cin.getline(um,255);
    cout<<endl<<"Numarul de bucati/unitate de masura:";
    cin>>nrb;
    cout<<endl<<"Pretul pe unitate: ";
    cin>>pu;
    cout<<endl<<"Data primirii lotului (zi/luna/an): ";
    cin>>dp.z>>dp.l>>dp.an;
    cout<<endl<<"Data expirarii lotului (zi/luna/an): ";
    cin>>pv.z>>pv.l>>pv.an;
}
void perisabil::afisare()
{
    cout<<"Pe data de "<<dp.z<<"."<<dp.l<<"."<<dp.an<<", magazinul a primit un lot de "<<nrb<<" "<<um<<" de "<<nume<<", cu termen de valabilitate de ";
    termen();
    cout<<", la pretul de "<<pu<<"lei pe "<<um;
}
void perisabil::termen()
{
    int z,l,an;
    an=pv.an-dp.an;
    l=pv.l-dp.l;
    if(l<0 && pv.an>=dp.an)
        l=l*(-1);
    z=pv.z-dp.z;
    if((z<0 && pv.an>dp.an && pv.l>=dp.l)||(z<0 && pv.an==dp.an && pv.l>dp.l))
        z=z*(-1);
    cout<<"zile: "<<z<<", luni: "<<l<<", ani: "<<an;
}
class promotie:public perisabil
{
protected:
    double disc;
public:
    promotie(int n=0):perisabil()
    {
        disc=n;
    }
    friend istream &operator<<(istream &i, promotie & P);
    void citire();
    void afisare();
    ~promotie()
    {
    }
};
istream &operator<<(istream &i, promotie &P)
{
    cout<<"Numele produsului: ";
    i.getline(P.nume,255);
    i.getline(P.nume,255);
    cout<<"Dati unitatea de masura: ";
    i.getline(P.um,255);
    cout<<endl<<"Numarul de bucati/unitate de masura:";
    i>>P.nrb;
    cout<<endl<<"Pretul pe unitate: ";
    i>>P.pu;
    cout<<endl<<"Data primirii lotului (zi/luna/an): ";
    i>>P.dp.z>>P.dp.l>>P.dp.an;
    cout<<endl<<"Data expirarii lotului (zi/luna/an): ";
    i>>P.pv.z>>P.pv.l>>P.pv.an;
    cout<<"Dati discountul: ";
    i>>P.disc;
}
void promotie::citire()
{
    cout<<"Numele produsului: ";
    cin.getline(nume,255);
    cin.getline(nume,255);
    cout<<"Dati unitatea de masura: ";
    cin.getline(um,255);
    cout<<endl<<"Numarul de bucati/unitate de masura:";
    cin>>nrb;
    cout<<endl<<"Pretul pe unitate: ";
    cin>>pu;
    cout<<endl<<"Data primirii lotului (zi/luna/an): ";
    cin>>dp.z>>dp.l>>dp.an;
    cout<<endl<<"Data expirarii lotului (zi/luna/an): ";
    cin>>pv.z>>pv.l>>pv.an;
    cout<<"Dati discountul: ";
    cin>>disc;
}
void promotie::afisare()
{
    cout<<"Pe data de "<<dp.z<<"."<<dp.l<<"."<<dp.an<<", magazinul a primit un lot de "<<nrb<<" "<<um<<" de "<<nume<<", cu termen de valabilitate de ";
    termen();
    cout<<", la pretul de "<<pu <<"lei pe "<<um<<", la care decide sa aplice un discount de "<<disc<<"%";
}
int main()
{
    lot *v[255];
    int n=0;
    cout<<"Dati numarul de loturi: ";
    cin>>n;
    int ok;
    for(int i=0;i<n;i++)
    {
        ok=0;
        char r[255];
        cout<<"Produsul este cu discount?";
        cin>>r;
        if(strcmp(r,"Da")==0 || strcmp(r,"da")==0 || strcmp(r,"dA")==0 || strcmp(r,"DA")==0)
        {
            v[i]=new promotie;
            ok=1;
        }
        if(ok==0)
        {
            cout<<"Produsul este perisabil?";
            cin>>r;
            if(strcmp(r,"Da")==0 || strcmp(r,"da")==0 || strcmp(r,"dA")==0 || strcmp(r,"DA")==0)
            {
                ok=1;
                v[i]=new perisabil;
            }
            if(ok==0)
            {
                cout<<"Produsul este neperisabil?";
                cin>>r;
                if(strcmp(r,"Da")==0 || strcmp(r,"da")==0 || strcmp(r,"dA")==0 || strcmp(r,"DA")==0)
                    v[i]=new produs;
                ok=1;
            }
        }
        v[i]->citire();
    }
    cout<<"Dati produsul dorit spre vanzare: ";
    char pr[255];
    cin.getline(pr,255);
    cin.getline(pr,255);
    cout<<"Dati cantitatea dorita spre vanzare: ";
    double h;
    cin>>h;
    int ook=0;
    for(int i=0;i<n;i++)
        if(v[i]->vanz(pr,h)==1 && v[i]->vala()==1)
        {
            cout<<v[i]->pret();
            ook=1;
        }
    if(ook==0)
         for(int i=0;i<n;i++)
            if(v[i]->vanzm(pr,h)==1 && v[i]->vala()==1)
            {
                cout<<v[i]->pret();
                ook=1;
            }
    if(ook==0)
        for(int i=0;i<n;i++)
            if(v[i]->vanzm(pr,h)==1 && v[i]->vala()==1)
                v[i]->afisare();
    int k;
    while(true)
    {
    cout<<endl<<endl;
    cout<<"Dati varianta dorita: ";
    cout<<endl<<"1.Adaugati un produs nou.";
    cout<<endl<<"2.Afisati toate produsele.";
    cout<<endl<<"3.Adaugati un lot nou.";
    cin>>k;
    switch(k)
    {
    case 1:
        {
             ok=0;
        char r[255];
        cout<<"Produsul este cu discount?";
        cin>>r;
        if(strcmp(r,"Da")==0 || strcmp(r,"da")==0 || strcmp(r,"dA")==0 || strcmp(r,"DA")==0)
        {
            v[n]=new promotie;
            ok=1;
        }
        if(ok==0)
        {
            cout<<"Produsul este perisabil?";
            cin>>r;
            if(strcmp(r,"Da")==0 || strcmp(r,"da")==0 || strcmp(r,"dA")==0 || strcmp(r,"DA")==0)
            {
                ok=1;
                v[n]=new perisabil;
            }
            if(ok==0)
            {
                cout<<"Produsul este neperisabil?";
                cin>>r;
                if(strcmp(r,"Da")==0 || strcmp(r,"da")==0 || strcmp(r,"dA")==0 || strcmp(r,"DA")==0)
                    v[n]=new produs;
                ok=1;
            }
        }
        v[n]->citire();
	n++;
        break;
        }
    case 2:
        {
             for(int j=0;j<n;j++)
            {
                v[j]->afisare();
                cout<<endl;
            }
            cout<<endl<<endl;
            break;
        }
    case 3:
        {
    for(int i=n;i<n+1;i++)
    {
        ok=0;
        char r[255];
        cout<<"Produsul este cu discount?";
        cin>>r;
        if(strcmp(r,"Da")==0 || strcmp(r,"da")==0 || strcmp(r,"dA")==0 || strcmp(r,"DA")==0)
        {
            v[i]=new promotie;
            ok=1;
        }
        if(ok==0)
        {
            cout<<"Produsul este perisabil?";
            cin>>r;
            if(strcmp(r,"Da")==0 || strcmp(r,"da")==0 || strcmp(r,"dA")==0 || strcmp(r,"DA")==0)
            {
                ok=1;
                v[i]=new perisabil;
            }
            if(ok==0)
            {
                cout<<"Produsul este neperisabil?";
                cin>>r;
                if(strcmp(r,"Da")==0 || strcmp(r,"da")==0 || strcmp(r,"dA")==0 || strcmp(r,"DA")==0)
                    v[i]=new produs;
                ok=1;
            }
        }
        v[i]->citire();
    }
    cout<<endl;
    n++;
    break;
        }
    default:
        {
            break;
        }
    }
    }
    return 0;
}
