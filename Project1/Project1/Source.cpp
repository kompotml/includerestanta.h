#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Film {
private:
    char* titlu;
    string regizor;
    string tara;
    const char* testChar = "nespecificat";
    int an;

public:
    // constructor implicit
    Film()
    {
        titlu = nullptr;
        regizor = "";
        tara = "";
        an = 0;
    }

    // constructor cu parametri
    Film(char* titlu, string regizor, string tara, int an) {
        this->regizor = regizor;
        this->tara = tara;
        this->an = an;
        if (titlu != nullptr) {
            this->titlu = new char[strlen(testChar) + 1];
            for (int i = 0; i < strlen(testChar) + 1; i++)
                this->titlu[i] = testChar[i];
        }
    }

    // constructor de copiere
    Film(const Film& f)
    {
        regizor = f.regizor;
        tara = f.tara;
        an = f.an;
        if (f.titlu != nullptr) {
            titlu = new char[strlen(f.titlu) + 1];
            for (int i = 0; i < strlen(f.titlu) + 1; i++)
                titlu[i] = f.titlu[i];
        }
        else {
            titlu = nullptr;
        }
    }

    //operator =
    Film& operator=(const Film& f) {
        if (titlu != nullptr) {
            delete[] titlu;
            titlu = nullptr;
        }
        regizor = f.regizor;
        tara = f.tara;
        an = f.an;
        if (f.titlu != nullptr) {
            titlu = new char[strlen(f.titlu) + 1];
            for (int i = 0; i < strlen(f.titlu) + 1; i++)
                titlu[i] = f.titlu[i];
        }
        else titlu = nullptr;
        return *this;
    }

    //destructor
    ~Film() {
        if (titlu != nullptr) {
            delete[] titlu;
        }
    }

    // getter si setter titlu
    char* getTitlu() {
        if (titlu != nullptr) {
            char* copie = new char[strlen(titlu) + 1];
            for (int i = 0; i < strlen(titlu) + 1; i++)
                copie[i] = titlu[i];
            return copie;
        }
        else return nullptr;
        //   return this->titlu;
    }

    void setTitlu(const char* titlu) {
        if (this->titlu)
            delete[] this->titlu;
        //       if (this->titlu != nullptr) {
        this->titlu = new char[strlen(titlu) + 1];
        for (int i = 0; i < strlen(titlu) + 1; i++)
            this->titlu[i] = titlu[i];
        //     }
         //    else this->titlu = nullptr;
    }

    // getter si setter regizor
    string getRegizor() {
        return regizor;
    }
    void setRegizor(string regizor) {
        this->regizor = regizor;
    }

    // getter si setter tara
    string getTara() {
        return tara;
    }
    void setTara(string tara) {
        this->tara = tara;
    }

    // getter si setter an
    int getAn() {
        return an;
    }
    void setAn(int an) {
        this->an = an;
    }

    void adaugaFilm() {
        string t, r, c, a;
        cout << "Numele filmului: ";
        getline(cin, t);
    }

    /////////////////// overload operatori ///////////////////
    // << >>
    friend istream& operator>>(istream&, Film&);
    friend ostream& operator<<(ostream&, Film);
    // []
    char operator[](int i) {
        if (this->titlu != NULL)
            if (i >= 0 && i < strlen(this->titlu)) {
                return titlu[i];
            }
    }
    // cast
    operator char* () {
        return this->titlu;
    }
    // int + 
    int operator+(Film& f) {
        return this->an + f.an;
    }
    // ++
    friend const Film& operator++(Film&);
    friend const Film operator++(Film&, int);
    // +
    friend int operator+(Film&, int);
    friend int operator+(int, Film&);
    // !
    friend bool operator!(Film);
    // <
    friend int operator<(Film& f, int x);
    // ==
    friend bool operator==(Film f1, Film f2);

    //meniu
    void meniu() {
        cout << "\t\t" << endl;
        cout << "\t\tSelecteaza o optiune" << endl;
        cout << "\t\t 1 Rezervare bilet" << endl;
        cout << "\t\t 2 Adaugare film" << endl;
        cout << "\t\t 3 Adaugare sala" << endl;
        cout << "\t\t 4 Adaugare program" << endl;
        cout << "\t\t 5 Raport locuri libere" << endl;
        cout << "\t\t 6 Raport filme existente" << endl;
    }
};

// operatorii << si >>
istream& operator>>(istream& in, Film& f) {
    cout << "Titlu: ";
    char titlu[40];
    in >> titlu;
    f.setTitlu(titlu);
    cout << "Regizor: ";
    in >> f.regizor;
    cout << "Tara: ";
    in >> f.tara;
    cout << "An: ";
    in >> f.an;
    return in;
}

ostream& operator<<(ostream& out, Film f) {
    out << "Filmul " << f.getTitlu() << ", in regia lui " << f.getRegizor() << ", " << f.getTara() << ", " << f.getAn() << endl;
    return out;
}

// post si pre ++
const Film& operator++(Film& f) {
    f.an++;
    return f;
}
const Film operator++(Film& f, int i) {
    Film aux = f;
    f.an++;
    return aux;
}
// int +
int operator+(Film& f, int x) {
    return f.an + x;
}
int operator+(int x, Film& f) {
    return f.an + x;
}
// !
bool operator!(Film f) {
    return f.an != 2021;
}
// <
int operator<(Film& f, int x) {
    return f.an < x;
}
// ==
bool operator==(Film f1, Film f2) {
    return f1.an == f2.an;
}

// exemplu derivare
class DesenAnimat : public Film {
private:
    string dublajLbRomana;
public:
    DesenAnimat() {
        dublajLbRomana = "Nu";
    }
    DesenAnimat(char* titlu, string regizor, string tara, int an, string dublajLbRomana) : Film(titlu, regizor, tara, an) {
        this->dublajLbRomana = dublajLbRomana;
    }
    // getter si setter
    string getDublaj() {
        return dublajLbRomana;
    }

    void setDublaj(string dublaj) {
        this->dublajLbRomana = dublaj;
    }
    /////////////////// overload operatori ///////////////////
   // << >>
    friend istream& operator>>(istream&, DesenAnimat&);
    friend ostream& operator<<(ostream&, DesenAnimat);
    // []
    char operator[](int i) {
        if (this->getTitlu() != NULL)
            if (i >= 0 && i < strlen(this->getTitlu())) {
                return getTitlu()[i];
            }
    }
    // cast
    operator char* () {
        return this->getTitlu();
    }
    // int + 
    int operator+(DesenAnimat& d) {
        return this->getAn() + d.getAn();
    }
    // ++
    friend const DesenAnimat& operator++(DesenAnimat&);
    friend const DesenAnimat operator++(DesenAnimat&, int);
    // +
    friend int operator+(DesenAnimat&, int);
    friend int operator+(int, DesenAnimat&);
    // !
    friend bool operator!(DesenAnimat);
    // <
    friend int operator<(DesenAnimat& d, int x);
    // ==
    friend bool operator==(DesenAnimat d1, DesenAnimat d2);

};

// operatorii << si >>
istream& operator>>(istream& in, DesenAnimat& d) {
    cout << "Titlu: ";
    char titlu[40];
    in >> titlu;
    d.setTitlu(titlu);
    cout << "Regizor: ";
    string regizor;
    in >> regizor;
    d.setRegizor(regizor);
    cout << "Tara: ";
    string tara;
    in >> tara;
    d.setTara(tara);
    cout << "An: ";
    int an;
    in >> an;
    d.setAn(an);
    cout << "Dublaj: ";
    string dublaj;
    in >> dublaj;
    d.setDublaj(dublaj);
    return in;
}

ostream& operator<<(ostream& out, DesenAnimat d) {
    out << "Filmul " << d.getTitlu() << ", in regia lui " << d.getRegizor() << ", " << d.getTara() << ", " << d.getAn() << endl;
    return out;
}

// post si pre ++
const DesenAnimat& operator++(DesenAnimat& d) {
    d.getAn();
    return d++;
}
const DesenAnimat operator++(DesenAnimat& d, int i) {
    DesenAnimat aux = d;
    d.getAn();
    return aux++;
}
// int +
int operator+(DesenAnimat& d, int x) {
    return d.getAn() + x;
}
int operator+(int x, DesenAnimat& d) {
    return d.getAn() + x;
}
// !
bool operator!(DesenAnimat d) {
    return d.getAn() != 2021;
}
// <
int operator<(DesenAnimat& d, int x) {
    return d.getAn() < x;
}
// ==
bool operator==(DesenAnimat d1, DesenAnimat d2) {
    return d1.getAn() == d2.getAn();
}

class Program {
private:
    int h;
    int m;
public:
    Program() {
        h = 0;
        m = 0;
    }
    Program(int h, int m) {
        this->h = h;
        this->m = m;
    }
    int getH() {
        return h;
    }
    void setH(int h) {
        this->h = h;
    }
    int getM() {
        return m;
    }
    void setM(int m) {
        this->m = m;
    }
    // << >>
    friend istream& operator>>(istream&, Program&);
    friend ostream& operator<<(ostream&, Program);

    // TO DO [] si cast

    // int + 
    int operator+(Program& p) {
        return this->h + p.h;
    }
    friend const Program& operator++(Program&);
    friend const Program operator++(Program&, int);
    // +
    friend int operator+(Program&, int);
    friend int operator+(int, Program&);
    // !
    friend bool operator!(Program);
    // <
    friend int operator<(Program& p, int x);
    // ==
    friend bool operator==(Program p1, Program p2);
};
// operatorii << si >>
istream& operator>>(istream& in, Program& p) {
    cout << "Introdu ora: ";
    in >> p.h;
    while (p.h < 0 || p.h > 23) {
        cout << "Invalid, incearca din nou: ";
        in >> p.h;
    }   
    cout << "Min: ";
    in >> p.m;
    while (p.m < 0 || p.h > 59) {
        cout << "Invalid, incearca din nou: ";
        in >> p.m;
    }
    return in;
}

ostream& operator<<(ostream& out, Program p) {
    out << "Ai introdus ora " << p.getH() << ":" << p.getM() << endl; 
    return out;
}

// int +
int operator+(Program& p, int x) {
    return p.getH() + x;
}
int operator+(int x, Program& p) {
    return p.getH() + x;
}
// post si pre ++
const Program& operator++(Program& p) {
    p.h++;
    return p;
}
const Program operator++(Program& p, int i) {
    Program aux = p;
    p.h++;
    return aux;
}
// !
bool operator!(Program p) {
    return p.h > 24;
}
// <
int operator<(Program& p, int x) {
    return p.h < x;
}
// ==
bool operator==(Program p1, Program p2) {
    return p1.h == p2.h;
}

class Bilet {
public: 
    int nrBilet, d, m, y, nrRezervare, nrSala, H, M, ora, pers;
    float pret;
    char titluFilm[20];
    Bilet() {
        nrBilet = 0;
    }
    void getDate() {
        t.nrBilet++;
        cout << "Introdu numele filmului " << endl;
        cin >> t.titluFilm;
        cout << "Introdu pretul filmului " << endl;
        cin >> t.pret;
        cout << "Introdu data: dd mm yyyy " << endl;
        cin >> t.d >> t.m >> t.y;
        cout << "Introdu numarul rezervarii " << endl;
        cin >> t.nrRezervare;
        cout << "Introdu numarul salii " << endl;
        cin >> t.nrSala;
        cout << "Introdu ora/ minutul " << endl;
        cin >> t.H >> t.M;
        cout << "Introdu numarul de persoane " << endl;
        cin >> t.pers;

        salveazaDate();
    }
    void salveazaDate() {
        fstream fout;
        fout.open("file", ios::app);
        fout.write((char*)&t, sizeof(t));
        fout.close();
    }
    void citesteDate() {
        cout << "Afiseaza  toate biletele: \n" << endl;
        ifstream fin;
        fin.open("file", ios::in);
        while (fin.read((char*)&t, sizeof(t)))
            afiseazaDate();
        fin.close();
    }
    void afiseazaDate() {
        cout << "Nr bilet: " << nrBilet << endl;
        cout << "Ttitlu: " << titluFilm << endl;
        cout << "Pret bilet " << pret << endl;
        cout << "Nr persoane: " << pers << endl;
        cout << "Nr sala: " << nrSala << endl;
        cout << "Ora: " << ora << endl;
        cout << "Data: " << d << m << endl;

    }
    void getNrBilet() {
        ifstream fin;
        fin.open("file", ios::in);
        while(fin.read((char*)&t, sizeof(t))){}
        fin.close();
    }
    void validareBilet() {
        int nr, found = 0;
        cout << "Introdu nr biletului: " << endl;
        cin >> nr;
        ifstream fin;
        fin.open("file", ios::in);
        while (fin.read((char*)&t, sizeof(t))) {
            if (nrBilet == nr) {
                cout << "Bilet valid: " << endl;
                found = 1; 
                afiseazaDate();
                break;
            }
        }
        if (found == 0)
            cout << "Bilet invalid " << endl;
        fin.close();
    }
}t;


class Discount {
    void discountAngajat();
    void discountElevStudent();
};

int main() {

    /*   char test[] = { 't' };
       Film f1(test, "test", "test", 0);
       f1.setTitlu("Interstellar");
       f1.setRegizor("Christopher Nolan");
       f1.setTara("UK");
       f1.setAn(2014);

       cout << f1.getTitlu() << endl;
       cout << f1.getRegizor() << endl;
       cout << f1.getTara() << endl;
       cout << f1.getAn() << endl;

       Film f2;
       cin >> f2;
       cout << f2;

       cout << f1[0];
       DesenAnimat d1;
       DesenAnimat d2(test, "Anonim", "USA", 2017, "Nu");
       d2.setTitlu("Frozen");
       cout << d2.getTitlu() << endl;
       DesenAnimat d3;
       cin >> d3;
       cout << d3;

       Program p1;
       cin >> p1;
       cout << p1;*/
    system("Color E0");
    int x;
    t.getNrBilet();
    do {
        cout << "1. Rezerva bilet" << endl;
        cout << "2. Afiseaza bilete rezervate" << endl;
        cout << "3. Valideaza bilet" << endl;
        cout << "4. Iesire" << endl;
        cout << "Alege o optiune: " << endl;
        cin >> x;
        switch (x) {
        case 1: t.getDate(); break;
        case 2: t.citesteDate(); break;
        case 3: t.validareBilet(); break;
        case 4: exit(0); break;
        default: cout << "\n Optiune invalida.\n Alege din nou" << endl;
        }

    } while (x != 4);
 }
