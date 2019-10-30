#include <iostream>
#include <cmath>
using namespace std;
class Numar_Complex
{
private:
    double partea_reala;
    double partea_imaginara;

public:
    Numar_Complex(double pr = 0, double pi = 0)
    {
        //partea_reala=partea_reala;
        //partea_imaginara=pi;
        set_partea_reala(pr);
        set_partea_imaginara(pi);
    }

    ~Numar_Complex()
    {
        cout << "destructor" << endl;
    }

    Numar_Complex(const Numar_Complex &ob)
    {
        partea_reala = ob.partea_reala;
        partea_imaginara = ob.partea_imaginara;
    }

    void set_partea_reala(double pr)
    {
        partea_reala = pr;
    }

    void set_partea_imaginara(double pi)
    {
        partea_imaginara = pi;
    }

    double get_partea_reala()
    {
        return partea_reala;
    }

    double get_partea_imaginara()
    {
        return partea_imaginara;
    }

    void afisare()
    {
        if(partea_imaginara == 0)
            cout << partea_reala << endl;
        else
        {
            if(partea_reala == 0)
            {
                if(partea_imaginara > 0)
                    cout << "i*" << partea_imaginara << endl;
                else
                    cout << "-i*" << -1 * partea_imaginara << endl;

            }
            else
            {
                if(partea_imaginara > 0)
                    cout << partea_reala << "+i*" << partea_imaginara << endl;
                else
                    cout << partea_reala << "-i*" << -1 * partea_imaginara << endl;
            }
        }
    }

    void citire()
    {
        cout << "introdu partea reala" << endl;
        cin >> partea_reala;
        cout << "introdu partea imaginara" << endl;
        cin >> partea_imaginara;

    }

    double modul()
    {
        double m;
        m = sqrt((partea_reala * partea_reala) + (partea_imaginara * partea_imaginara));
        return m;
    }


    Numar_Complex sqrt1()
    {
        double a, b;
        a = sqrt((partea_reala + sqrt(partea_reala * partea_reala + partea_imaginara * partea_imaginara)) / 2);
        b = (partea_imaginara / abs(partea_imaginara)) * sqrt((-partea_reala + sqrt(partea_reala * partea_reala + partea_imaginara * partea_imaginara)) / 2);
        return Numar_Complex(a, b);
    }


    Numar_Complex operator+(Numar_Complex op);
    Numar_Complex operator*(Numar_Complex op);
    Numar_Complex operator-(Numar_Complex op);
    friend Numar_Complex operator*(int a, Numar_Complex op);
    Numar_Complex operator/(Numar_Complex op);
    friend ostream& operator<<(ostream &, Numar_Complex&);
    friend istream& operator>>(istream &, Numar_Complex &);
    friend void rezolvare_ecuatie_gradul_doi(Numar_Complex a, Numar_Complex b, Numar_Complex c);
};

class Nr_obiecte
{
    int n;
    Numar_Complex *v;


public:
    void citire_vector();
    void afisare_vector();
};


ostream& operator<<(ostream &out, Numar_Complex& c)
{
    c.afisare();
    //out<<c.partea_reala<<" "<<c.partea_imaginara;
    return out;
}

istream& operator>>(istream& in, Numar_Complex& c)
{
    c.citire();
    //in>>c.partea_reala>>c.partea_imaginara;
    return in;
}

void Nr_obiecte::citire_vector()
{
    cout << "introdu numarul de elemente" << endl;
    cin >> n;
    v = new Numar_Complex[n];
    for(int i = 0; i < n; i++)
        //v[i].citire();
        cin >> v[i];
}

void Nr_obiecte::afisare_vector()
{
    for(int i = 0; i < n; i++)
        v[i].afisare();
        //cout << v[i] << " ";
}

Numar_Complex Numar_Complex::operator+(Numar_Complex op)
{
    Numar_Complex temp;
    temp.partea_reala = op.partea_reala + partea_reala;
    temp.partea_imaginara = op.partea_imaginara + partea_imaginara;
    return temp;
}

Numar_Complex Numar_Complex::operator*(Numar_Complex op)
{
    Numar_Complex temp;
    temp.partea_reala = op.partea_reala * partea_reala - op.partea_imaginara * partea_imaginara;
    temp.partea_imaginara = op.partea_reala * partea_imaginara + op.partea_imaginara * partea_reala;
    return temp;
}

Numar_Complex operator*(int a, Numar_Complex op)
{
    Numar_Complex temp;
    temp.partea_reala = op.partea_reala * a;
    temp.partea_imaginara = op.partea_imaginara * a;
    return temp;
}

Numar_Complex Numar_Complex::operator/(Numar_Complex op)
{
    Numar_Complex temp;
    temp.partea_reala = ((partea_reala * op.partea_reala) + (partea_imaginara * op.partea_imaginara)) / ((op.partea_reala * op.partea_reala) + (op.partea_imaginara * op.partea_imaginara));
    temp.partea_imaginara = ((partea_imaginara * op.partea_reala) - (partea_reala * op.partea_imaginara)) / ((op.partea_reala * op.partea_reala) + (op.partea_imaginara * op.partea_imaginara));
    return temp;

}

Numar_Complex Numar_Complex::operator-(Numar_Complex op)
{
    Numar_Complex temp;
    temp.partea_reala = partea_reala - op.partea_reala;
    temp.partea_imaginara = partea_imaginara - op.partea_imaginara;
    return temp;
}

void rezolvare_ecuatie_gradul_doi(Numar_Complex a, Numar_Complex b, Numar_Complex c)
{
    Numar_Complex alfa, beta, sqrt_alfa, sqrt_beta, delta;

    delta = (b * b) - (4 * a * c);

    alfa = ((-1 * b) + delta.sqrt1()) / (2 * a);
    beta = ((-1 * b) - delta.sqrt1()) / (2 * a);

    alfa.afisare();
    beta.afisare();
}
int main()
{
    ///Citire si afisare numar complex

    cout << "Citire si afisare numar complex" << endl;
    Numar_Complex c1;
    c1.citire();
    c1.afisare();
    cout << endl;

    ///Afisare modul numar complex


    Numar_Complex c2, modul;
    cout << "Afisare modul numar complex" << endl;
    c2.citire();
    modul = c2.modul();
    modul.afisare();
    cout << endl;

    ///Suma doua numere complexe

    Numar_Complex c3, c4, suma;
    cout << "Suma doua numere complexe" << endl;
    c3.citire();
    c4.citire();
    suma = c3 + c4;
    suma.afisare();
    cout << endl;

    ///Produsul a doua numere complexe

    Numar_Complex c5, c6, produs;
    cout << "Produsul a doua numere complexe" << endl;
    c5.citire();
    c6.citire();
    produs = c5 * c6;
    produs.afisare();
    cout << endl;

    ///Impartirea a doua numere complexe

    Numar_Complex c7, c8, impartire;
    cout << "Impartirea a doua numere complexe" << endl;
    c7.citire();
    c8.citire();
    impartire = c7 / c8;
    impartire.afisare();
    cout << endl;

    ///Radical de ordin 2 al unui numar complex

    cout << "Radical de ordin 2 al unui numar complex" << endl;
    Numar_Complex c9, radical;
    c9.citire();
    radical = c9.sqrt1();
    radical.afisare();
    cout << endl;

    ///Rezolvarea ecuatiei de ordin 2 cu coeficienti complecsi

    cout << "Rezolvarea ecuatiei de ordin 2 cu coeficienti complecsi" << endl;
    Numar_Complex a, b, c;
    a.citire();
    b.citire();
    c.citire();
    rezolvare_ecuatie_gradul_doi(a, b, c);
    cout << endl;

    ///Citire si afisare vector de numere complexe

    cout<<"Citire si afisare vector de numere complexe"<<endl;
    Nr_obiecte ob;
    ob.citire_vector();
    ob.afisare_vector();
    cout<<endl;


    return 0;
}
