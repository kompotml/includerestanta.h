#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
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
    //!!!!!!! cumva returneaza si ora inainte de derularea mesajului
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

class SalaCinema {
public:
    int coloane = 5;
    int randuri = 22;
    int totalLocuri = coloane * randuri;
    int nrSala = 3;
    int*salaRanduri = new int[nrSala + 1]{ 0,4,8,10 };
    double* salaPret = new double[nrSala + 1]{ 0,50,15,10 };
    bool* locuri = new bool[totalLocuri];
    int* locuriDisponibile = new int[nrSala + 1]{ 0,4 * coloane, 8 * coloane, 10 * coloane };
// stergere locuri
    void stergeLocuri() {
        for (int i = 0; i <= totalLocuri; i++)
            locuri[i] = false;
    }
// afisare locuri disponibile si rezervate
    void afisareLocuri() {
        for (int i = 1; i <= totalLocuri; i++) {
            if (locuri[i])
                cout << setw(5) << i << ",X" << "\t";
            else
                cout << setw(5) << i << ",0" << "\t";
            if (!(i % coloane)) cout << endl;
        }
    }
// afisare ultimul loc din sala
    int locSala(int sala) {
        int sum = 0;
        for (int i = sala; i >= 0; i--)
            sum += salaRanduri[i];
        return sum * coloane;
    }
// afisare locuri disponibile/rezervate sala
    void afisareLocuriSala(int sala) {
        int from = locSala(sala - 1) + 1;
        int to = locSala(sala);
        for (int i = from; i <= to; i++) {
            if (locuri[i])
                cout << setw(5) << i << ",X" << "\t";
            else
                cout << setw(5) << i << ",0" << "\t";
            if (!(i % coloane)) cout << endl;
        }
    }
// rezervare loc -> true daca e valida, false daca locul e deja rezervat
    bool rezervareLoc(int nrLoc, int sala) {
        if (!locuri[nrLoc] && nrLoc > locSala(sala - 1) && nrLoc <= locSala(sala)) {
            locuri[nrLoc] = true;
            locuriDisponibile[sala]--;
            return true;
        }
        return false;
    }
// anulare rezervare loc -> true daca e valida, false daca locul nu este rezervat sau nu se afla in sala
    bool anulareLoc(int nrLoc, int sala) {
        if (!locuri[nrLoc] && nrLoc > locSala(sala - 1) && nrLoc <= locSala(sala)) {
            locuri[nrLoc] = false;
            locuriDisponibile[sala]++;
            return true;
        }
        return false;
    }
};

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

    SalaCinema s;
    s.stergeLocuri();
    while (true) {
        int meniu;
        cout << "\n Selecteaza o optiune: \n1: Rezervare bilet\n2: Anulare rezervare\n3: Resetare rezervari existente\n4: Afisare sala cinema\n5: Iesire\n\n\n";
        cout << "\n 6: Setari";
        cin >> meniu;
        int sala, loc, nrBilet, anulare = 0;
        bool esc = false;
        system("cls"); // clears screen
        switch (meniu) {
        case 1: cout << "Alege sala " << endl;
            cin >> sala;
            system("cls");
            s.afisareLocuriSala(sala);
            cout << "Locuri disponibile: " << s.locuriDisponibile[sala] << endl;
            cout << "Pret: " << s.salaPret[sala] << endl;
            cout << "Cate bilete doriti?" << endl;
            cin >> nrBilet;
            system("cls");
            if (nrBilet <= s.locuriDisponibile[sala]) {
                for (int i = 0; i < nrBilet; i++) {
                    cout << "Alege locul " << " (" << i + 1 << "/" << nrBilet << ")" << endl;
                    cin >> loc;
                    while (!s.rezervareLoc(loc, sala)) {
                        cout << "Locul este deja rezervat sau invalid. \n Alege alt loc" << endl;
                        cin >> loc;
                    }
                    cout << "Rezervare efectuata! Locul: " << loc << "a fost rezervat" << endl;
                }
                cout << fixed << setprecision(2) << "Total cost: " << s.salaPret[sala] * nrBilet << endl;
            }
            else cout << "Sala nu mai are locuri disponibile. Revenire la meniul principal" << endl;
            break;

        case 2: anulare = 0;
            esc = false;
            cout << "In ce sala vrei sa anulezi rezervarea?" << endl;
            cin >> sala;
            s.afisareLocuriSala(sala);
            cout << "Cate rezervari doresti sa anulezi?" << endl;
            cin >> nrBilet;
            system("cls");
            for (int i = 0; i < nrBilet; i++) {
                cout << "Care este locul pe care doresti sa-l anulezi?" << " (" << i + 1 << "/" << nrBilet << ")" << endl;
                cin >> loc;
                while (!s.anulareLoc(loc, sala)) {
                    cout << "Locul ales nu este rezervat ori valid. Alege un loc valid sau tasteaza -1 pentru a reveni la meniul principal" << endl;
                    cin >> loc;
                    if (loc == -1) { esc = true; break; }
                }
                if (esc) break;
                cout << "Locul " << loc << "a fost anulat cu succes" << endl;
                anulare++;
            }
            cout << fixed << setprecision(2) << "Suma returnata " << s.salaPret[sala] * anulare << endl;
            break;
        case 3: cout << "Resetare in curs\n Sala a fost resetata\n Revenire la meniu principal" << endl;
            s.stergeLocuri();
            break;
        case 4: s.afisareLocuri();
            break;
        case 5: return 0;
        case 6: 
        }

    }
}