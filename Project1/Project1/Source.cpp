#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Film {
private:
    char* titlu;
    string regizor;
    string tara;
    int an;
    const char* testChar = "nespecificat";

public:
    // constructor implicit
    Film()
    {
        titlu = nullptr;
        regizor = " ";
        tara = " ";
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
        delete[] this->titlu;
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
    }

    void setTitlu(const char* titlu) {
        if (this->titlu != nullptr)
            delete[] this->titlu;
        if (this->titlu != nullptr) {
            this->titlu = new char[strlen(titlu) + 1];
            for (int i = 0; i < strlen(titlu) + 1; i++)
                this->titlu[i] = titlu[i];
        }
        else this->titlu = nullptr;
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

class Sala {
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
};

class Program {
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

};

class Bilet {
private:
    double pret;
    int id;
    int numar;
    int locuriDisponibile;
public:
    Program p;
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
        p.program1();
        cout << "Alege ora: " << endl;
        int x;
        cin >> x;
        switch (x) {
        case 1: cout << "16:00" << endl; p.setOraFilm("16:00"); break;
        case 2: cout << "18:00" << endl; p.setOraFilm("18:00"); break;
        case 3: cout << "20:00" << endl; p.setOraFilm("20:00"); break;
        case 4: cout << "22:00" << endl; p.setOraFilm("22:00"); break;
        }
    }

    void film2() {
        cout << "Program filme" << endl;
        p.program1();
        cout << "Alege ora: " << endl;
        int x;
        cin >> x;
        switch (x) {
        case 1: cout << "16:00" << endl; p.setOraFilm("16:00"); break;
        case 2: cout << "18:00" << endl; p.setOraFilm("18:00"); break;
        case 3: cout << "20:00" << endl; p.setOraFilm("20:00"); break;
        case 4: cout << "22:00" << endl; p.setOraFilm("22:00"); break;
        }
    }
    void film3() {
        cout << "Program filme" << endl;
        p.program1();
        cout << "Alege ora: " << endl;
        int x;
        cin >> x;
        switch (x) {
        case 1: cout << "16:00" << endl; p.setOraFilm("16:00"); break;
        case 2: cout << "18:00" << endl; p.setOraFilm("18:00"); break;
        case 3: cout << "20:00" << endl; p.setOraFilm("20:00"); break;
        case 4: cout << "22:00" << endl; p.setOraFilm("22:00"); break;
        }
    }
    void film4() {
        cout << "Program filme" << endl;
        p.program1();
        cout << "Alege ora: " << endl;
        int x;
        cin >> x;
        switch (x) {
        case 1: cout << "16:00" << endl; p.setOraFilm("16:00"); break;
        case 2: cout << "18:00" << endl; p.setOraFilm("18:00"); break;
        case 3: cout << "20:00" << endl; p.setOraFilm("20:00"); break;
        case 4: cout << "22:00" << endl; p.setOraFilm("22:00"); break;
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
}