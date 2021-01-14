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
    int nrFilm;
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

    // introducere, salvare si afisare filme in consola
    void getDate() {
        f.nrFilm++;
        cout << "Introdu titlul filmului: " << endl;
        cin >> f.titlu;
         cout << "Regizor: " << endl; 
         cin >> f.regizor;
         cout << "tara: " << endl;
         cin >> f.tara;
         cout << "An: " << endl;
         cin >> f.an;

        salvareDate();
    }
    void salvareDate() {
        fstream fout;
        fout.open("filme", ios::app);
        fout.write((char*)&f, sizeof(f));
        fout.close();
    }
    void citireDate() {
        cout << "Afiseaza toate filmele existente: \n" << endl;
        ifstream fin;
        fin.open("filme", ios::in);
        while (fin.read((char*)&f, sizeof(f)))
            afisareDate();
        fin.close();
    }
    void afisareDate() {
        cout << "Titlu: " << titlu << endl;
        cout << "Regizor: " << regizor << endl;
        cout << "Tara: " << tara << endl;
        cout << "An: " << an << endl;
    }
    void getNrFilm() {
        ifstream fin;
        fin.open("filme", ios::in);
        while (fin.read((char*)&f, sizeof(f))) {}
        fin.close();
    }
    void validareFilm() {
        int nr, found = 0;
        cout << "Introdu nr filmului: " << endl;
        cin >> nr;
        ifstream fin;
        fin.open("filme", ios::in);
        while (fin.read((char*)&f, sizeof(f))) {
            if (nrFilm == nr) {
                cout << "Film valid: " << endl;
                found = 1;
                afisareDate();
                break;
            }
        }
        if (found == 0) cout << "Film invalid" << endl;
        fin.close();
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

   
}f;

// operatorii << si >>
istream& operator>>(istream& in, Film& f) {
    cout << "Titlu: ";
    char titlu[40]; //variabila temporara in care citim titlul de la tastatura
    in.getline(titlu, 40); // citire cu spatii libere
    f.setTitlu(titlu);
    cout << "Regizor: ";
    string regizor;
    in >> regizor;
    f.setRegizor(regizor);
    cout << "Tara: ";
    string tara; 
    in >>tara; 
    f.setTara(tara);
    cout << "An: ";
    int an; 
    in >> an;
    f.setAn(an);
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

// derivare
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
    out << "Ai adaugat filmul " << d.getTitlu() << ", in regia lui " << d.getRegizor() << ", " << d.getTara() << ", " << d.getAn() << endl;
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

class rezervareBilet {
public: 
    int nrBilet;
   // float pret;
  //  Film f;
  //  int sala; // 1 si 2
  //  int nrLocuri;
  //  int totalLocuri;
    rezervareBilet() {
        nrBilet = 0;
    }
    
};




class Discount {
    void discountAngajat();
    void discountElevStudent();
};

int main() {
/*
       char test[] = { 't' };
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
    f.getNrFilm();
    do {
        cout << "1. Adauga film" << endl; // afisare filme disponibile numerotate
  //      cout << "2. Situatie locuri libere" << endl; //la fiecare apelare: --locuriLibere ->afiseaza locuri libere
        cout << "2. Afiseaza filme existente" << endl; 
        cout << "3. Valideaza film" << endl;
        cout << "4. Iesire" << endl;
        cout << "Alege o optiune: " << endl;
        cin >> x;
        switch (x) {
        case 1: f.getDate(); break;
        case 2: f.citireDate(); break;
        case 3: f.validareFilm(); break;
        case 4: exit(0); break;
        default: cout << "\n Optiune invalida.\n Alege din nou" << endl;
        }

    } while (x != 4);
 /*   Film f2;
    cin >> f2;
    cout << f2;
    ifstream f;
    f >> f2;
    ofstream x;
    x << f2;
    // scrierea in txt functioneaza, dar datele se salveaza peste cele existente :(
    // de facut asta in clasa Bilet, pentru emiterea unui bilet in txt
    f2.scriereFilmFisier();
    Film::citireFilmFisier();*/
 }
