#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>

using namespace std;


template <class T> class lista_dubl
{
protected:
    struct nod
{
    T inf;
    nod *urm,*pre;
};
    nod *s,*temp,*p;

public :
    lista_dubl()
    {
        p=NULL;
    }

    virtual void adaug_inceput(T n);
    virtual void adaug_dupa(int poz,T n);
    virtual void sterge_elem(T n);
    void operator +(lista_dubl x);

friend istream& operator>>(istream &in,lista_dubl &x)
    {
        int n;
        cout<<"Numarul de elemente adaugate = ";
        in>>n;
    for(int i=1;i<=n;i++)
    {
        x.temp=new(struct nod);
        in>>x.temp->inf;
        x.temp->urm=NULL;
        if(x.p==NULL)
        {
            x.temp->pre=NULL;
            x.p=x.temp;
        }
        else
        {
            x.s=x.p;
            while(x.s->urm!=NULL)
                x.s=x.s->urm;
            x.s->urm=x.temp;
            x.temp->pre=x.s;
        }
    }
    return in;
    }



friend ostream &operator<<( ostream &out,lista_dubl &x)
      {
        if(x.p!=NULL)
        {
            x.s=x.p;
            out<<"Afisare lista in ambele sensuri :\n";
            while(x.s->urm!=NULL)
            {
                out<<x.s->inf<<" ";
                x.s=x.s->urm;
                if(x.s->urm==NULL)
                    out<<x.s->inf<<" "<<endl;
            }
            while(x.s!=NULL)
            {
                out<<x.s->inf<<" ";
                x.s=x.s->pre;
            }
            out<<endl;
            return out;
        }
        else
        {
            out<<"Lista e vida"<<endl;
            return out;
        }
      }

};
    template<class T>void lista_dubl <T>::adaug_inceput(T n)
    {
        if(p==NULL)
        {
            cout<<"Prima oara creeaza o lista";
            return;
        }
        class nod *q;
        q->pre=NULL;
        q->inf=n;
        q->urm=p;
        p->pre=q;
        p=q;
    }

    template<class T>void lista_dubl<T>::adaug_dupa(int poz,T n)
    {
        if(p==NULL)
        {
            cout<<"Prima oara creaza o lista"<<endl;
            return;
        }
        struct nod *temp, *q;
        q=new(struct nod);
        q=p;
        for(int i=1;i<poz;i++)
        {
            q=q->urm;
            if(q==NULL)
            {
                cout<<"Pozitia introdusa e prea mare"<<endl;
                return;
            }
        }
        temp=new(struct nod);
        temp->inf=n;
        if(q->urm==NULL)
        {
            q->urm=temp;
            temp->urm=NULL;
            temp->pre=q;
        }
        else
        {
            temp->urm=q->urm;
            temp->urm->pre=temp;
            q->urm=temp;
            temp->pre=q;
        }
    }

    template <class T>void lista_dubl <T>::sterge_elem(T n)
    {
        struct nod *temp,*q;
        if(p->inf==n)
        {
            temp=p;
            p=p->urm;
            p->pre=NULL;
            free(temp);
            return;
        }
        q=p;
        while(q->urm->urm!=NULL)
            {
                if(q->urm->inf==n)
                {
                    temp=q->urm;
                    q->urm=temp->urm;
                    temp->urm->pre=q;
                    free(temp);
                    return;
                }
            q=q->urm;
            }
    if(q->urm->inf==n)
    {
        temp=q->urm;
        free(temp);
        q->urm=NULL;
        return;
    }
    cout<<"Valoarea introdusa nu exista in lista";
    }

    template <class T>void lista_dubl <T>::operator+(lista_dubl y)
    {   //cazul in care prima lista e vida si a 2 nevida
        if(p==NULL)
        {
            if(y.p!=NULL)
            {
                p=y.p;
                p->urm=y.p->urm;
                p->pre=NULL;
                s=p;
                y.s=y.p;
                s=y.s;
                while(y.s->urm!=NULL)
                {
                    s->urm=y.s->urm;
                    s->pre=y.s->pre;
                    s->inf=y.s->inf;
                    s=s->urm;
                    y.s=y.s->urm;
                }
            return;
            }
            //amandoua vide
            else
            {
                if(y.p==NULL)
                    return;
            }
        }
        //ambele nevide
        if(p!=NULL)
        {
            s=p;
            y.s=y.p;
            while(s->urm!=NULL)
                s=s->urm;
            if(y.s!=NULL)
            {
                if(s->urm==NULL )
                {
                    s->urm=y.s;
                    y.s->pre=s;
                    s=s->urm;
                }
                while(y.s->urm!=NULL)
                {
                    s->urm=y.s->urm;
                    s->pre=y.s->pre;
                    s->inf=y.s->inf;
                    s=s->urm;
                    y.s=y.s->urm;
                }
                if(y.s->urm==NULL)
                {
                    s->urm=NULL;
                    s->pre=y.s->pre;
                    s->inf=y.s->inf;
                }
            return;
            }
            //prima nevida a doua vida
            else
                s->urm=NULL;
                return;
        }
    }
template <class T> class coada_prio : public lista_dubl<T>
{
struct nod
{
    T inf;
    nod *urm,*pre;
};
    nod *s,*temp,*p;
public:
    coada_prio()
    {
        p=NULL;
    }
    void creare_coada(int nrpr,coada_prio<T> &y)
    {
        for(int i=1;i<=nrpr;i++)
        {
            s=p;
            while(s->urm!=NULL)
            {
                if(s->prio==i)
                //baga in coada
                {
                    y.temp=new nod;
                //cout<<"Informatia: "<<s->inf;
                y.temp->inf=s->inf;
                //cout<<"Prioritatea: "<<s->prio<<endl;
                y.temp->prio=s->prio;
                y.temp->urm=NULL;
                if(y.p==NULL)
                {
                    y.temp->pre=NULL;
                    y.p=y.temp;
                    s=s->urm;
                }
                else
                {
                    y.s=y.p;
                    while(y.s->urm!=NULL)
                        y.s=y.s->urm;
                    y.s->urm=y.temp;
                    y.temp->pre=y.s;
                    s=s->urm;
                }
                }
                else
                s=s->urm;
            }

            if(s->urm==NULL)
            {
                if(s->prio==i)
                //baga in coada
                {
                    y.temp=new(nod);
                    //cout<<"Informatia: "<<s->inf;
                    y.temp->inf=s->inf;
                    //cout<<"Prioritatea: "<<s->prio<<endl;
                    y.temp->prio=s->prio;
                    y.temp->urm=NULL;
                    if(y.p==NULL)
                    {
                        y.temp->pre=NULL;
                        y.p=y.temp;
                        s=s->urm;
                    }
                    else
                    {
                        y.s=y.p;
                        while(y.s->urm!=NULL)
                            y.s=y.s->urm;
                        y.s->urm=y.temp;
                        y.temp->pre=y.s;
                        s=s->urm;
                    }
                }
            }

            }

        }
    void afisare_coada()
    {
        if(p!=NULL)
        {
            s=p;
            while(s->urm!=NULL)
            {
                cout<<s->inf<<" ";
                s=s->urm;
                if(s->urm==NULL)
                    cout<<s->inf<<" "<<endl;
            }
            while(s!=NULL)
            {
                cout<<s->inf<<" ";
                s=s->pre;
            }
            cout<<endl;
        }
    }

    void agaug_inceput(T n)
    {
      if(p==NULL)
        {
            cout<<"Prima oara creeaza o lista";
            return;
        }
        nod *q;
        q=new nod;
        q->pre=NULL;
        q->inf=n;
        q->urm=p;
        p->pre=q;
        p=q;
        p->prio=1;
    }
    void adaug_dupa(int pr,T n)
    {
        if(p==NULL)
        {
            cout<<"Prima oara creaza o lista"<<endl;
            return;
        }
        struct nod *temp, *q;
        q=new(struct nod);
        q=p;
        while(q->urm->prio<pr)
        {
            q=q->urm;

        }
        temp=new(struct nod);
        temp->inf=n;
        temp->prio=pr;
        if(q->urm==NULL)
        {
            q->urm=temp;
            temp->urm=NULL;
            temp->pre=q;
        }
        else
        {
            temp->urm=q->urm;
            temp->urm->pre=temp;
            q->urm=temp;
            temp->pre=q;
        }
    }
    void sterge_elem(int n)
    {

        if(p->prio>200)
        p->prio=1;
        nod *temp,*q;
        if(p->prio==n)
        {
            temp=p;
            p=p->urm;
            p->pre=NULL;
            free(temp);
            return;
        }
        q=p;
        while(q->urm->urm!=NULL)
            {
                if(q->urm->prio==n)
                {
                    temp=q->urm;
                    q->urm=temp->urm;
                    temp->urm->pre=q;
                    free(temp);
                    return;
                }
            q=q->urm;
            }
    if(q->urm->prio==n)
    {
        temp=q->urm;
        free(temp);
        q->urm=NULL;
        return;
    }
    }
};
int main()
{
    int alege,poz;
    char elem;
    lista_dubl<char> a,b;
    ifstream f("in.txt");
    while(1)
    {
        cout<<"Lista de optiuni"<<endl<<endl;
        cout<<"1.Citeste lista  din consola"<<endl;
        cout<<"2.Citeste lista din fisier"<<endl;
        cout<<"3.Afiseaza lista in ambele sensuri"<<endl;
        cout<<"4.Adauga nod la inceput"<<endl;
        cout<<"5.Adauga nod dupa o pozitie"<<endl;
        cout<<"6.Sterge nodul cu o anumita valoare"<<endl;
        cout<<"7.Concatenarea a 2 liste"<<endl;
        cout<<"8.Iesi din program"<<endl;
        cin>>alege;
        switch(alege)
        {
        case 1:
            cout<<"Citeste lista din consola "<<endl;
            cin>>a;
            cout<<endl;
            break;
        case 2:
            cout<<"Citeste lista din fisier "<<endl;
            f>>a;
            cout<<endl;
            break;
        case 3:
            cout<<"Afiseaza lista in ambele sensuri "<<endl;
            cout<<a<<endl;
            break;
        case 4:
            cout<<"Valoarea nodului introdus ";
            cin>>elem;
            cout<<endl;
            a.adaug_inceput(elem);
            break;
        case 5:
            cout<<"Adauga nodul cu valoarea ";
            cin>>elem;
            cout<<"Pozitia ";
            cin>>poz;
            cout<<endl;
            a.adaug_dupa(poz,elem);
            break;
        case 6:
            cout<<"Sterge nodul cu valoarea ";
            cin>>elem;
            cout<<endl;
            a.sterge_elem(elem);
            break;
        case 7:
            cout<<"Concatenarea a 2 liste "<<endl;
            cout<<"Citeste cea de-a 2 lista ";
            cin>>b;
            a+b;
            break;
        case 8:
            exit(1);
            return 0;
        default:
            cout<<"Ai introdus optiunea gresita! "<<endl;

        }
    }
    return 0;

}
