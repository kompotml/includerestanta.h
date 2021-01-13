#include <stdio.h>
#include <iostream>
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

/*class Sala {
private:
    string sala;
public:
    Sala() {
        this->sala = "";
    }
    void setSala(string s) {
        this->sala = s;
}
    string getSala() {
        return sala;
    }
};*/

class Program {
    string ora;
    Program() {
        ora = "";
    }
    Program(string ora) {
        this->ora = ora;
    }
};


/*class Program {
private:
    string oraFilm;
public:
    Program() {
        this->oraFilm = "";
    }
    void setOraFilm(string of) {
        this->oraFilm = of;
    }
    string getOraFilm() {
        return oraFilm;
    }
    void program1() {
        cout << "1. 16:00" << endl;
    }
    void program2() {
        cout << "2. 18:00" << endl;
    }
    void program3()
    {
        cout << "3. 20:00" << endl;
    }
    void program4() {
        cout << "4. 22:00" << endl;
    }

};*/

class Bilet {
private:
    double pret;
    int id;
    int numar;
    int locuriDisponibile;
public:
    Film f;
    Bilet() {
        this->id = 100000;
        this->pret = 0.0;
        this->locuriDisponibile = 100;
    }
    void setId(int id) {
        this->id = id;
    }
    int getId() {
        return id;
    }
    void setLoc(int loc) {
        this->locuriDisponibile = loc;
    }
    int getLoc() {
        return locuriDisponibile;
    }
    //   void locuriDisponibile();
    void setPret(double pret) {
        this->pret = pret;
    }
    double getPret() {
        return pret;
    }
    void setNumar(int numar) {
        this->numar = numar;
    }
    int getNumar() {
        return numar;
    }

    void film1() {
        cout << "Program filme" << endl;
        //p.program1();
        cout << "Alege ora: " << endl;
        int x;
        cin >> x;
        switch (x) {
      //  case 1: cout << "16:00" << endl; p.setOraFilm("16:00"); break;
      //  case 2: cout << "18:00" << endl; p.setOraFilm("18:00"); break;
      //  case 3: cout << "20:00" << endl; p.setOraFilm("20:00"); break;
      //  case 4: cout << "22:00" << endl; p.setOraFilm("22:00"); break;
        }
    }

    void film2() {
        cout << "Program filme" << endl;
        //p.program1();
        cout << "Alege ora: " << endl;
        int x;
        cin >> x;
        switch (x) {
      //  case 1: cout << "16:00" << endl; p.setOraFilm("16:00"); break;
      //  case 2: cout << "18:00" << endl; p.setOraFilm("18:00"); break;
      //  case 3: cout << "20:00" << endl; p.setOraFilm("20:00"); break;
      //  case 4: cout << "22:00" << endl; p.setOraFilm("22:00"); break;
        }
    }
    void film3() {
        cout << "Program filme" << endl;
        //p.program1();
        cout << "Alege ora: " << endl;
        int x;
        cin >> x;
        switch (x) {
       // case 1: cout << "16:00" << endl; p.setOraFilm("16:00"); break;
       // case 2: cout << "18:00" << endl; p.setOraFilm("18:00"); break;
       // case 3: cout << "20:00" << endl; p.setOraFilm("20:00"); break;
       // case 4: cout << "22:00" << endl; p.setOraFilm("22:00"); break;
        }
    }
    void film4() {
        cout << "Program filme" << endl;
        //p.program1();
        cout << "Alege ora: " << endl;
        int x;
        cin >> x;
        switch (x) {
       // case 1: cout << "16:00" << endl; p.setOraFilm("16:00"); break;
       // case 2: cout << "18:00" << endl; p.setOraFilm("18:00"); break;
       // case 3: cout << "20:00" << endl; p.setOraFilm("20:00"); break;
       // case 4: cout << "22:00" << endl; p.setOraFilm("22:00"); break;
        }
    }

    void tipBilet() {
        int x;
        cout << "1. Pret intreg: 25 lei" << endl;
        cout << "2. Pret discount angajat: 17 lei" << endl;
        cout << "3. Pret discount elev/student: 15 lei" << endl;
        cout << "Alege tipul biletului: " << endl;
        switch (x) {
        case 1: setPret(25); break;
        case 2: setPret(17); break;
        case 3: setPret(15); break;
        }

    }
    void afiseaza();
    void program();
    void afisareBileteRezervate();
    void afisarePret();
    void numarBilete();
};
class Discount {
    void discountAngajat();
    void discountElevStudent();
};

int main() {

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
}