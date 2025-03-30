#include <iostream>
#include <vector>

using namespace std;

class Kalkulator {
private:
    vector<int> v1, v2;
    int dlugoscwyniku;

public:
    Kalkulator(int rozmiar1, int rozmiar2) {
        cout << "Podaj liczby dla pierwszego wektora:\n";
        v1 = wczytaj_wektor(rozmiar1);
        cout << "Podaj liczby dla drugiego wektora:\n";
        v2 = wczytaj_wektor(rozmiar2);
    }

    void wyrownaj_wektory() {
        int roznica = v1.size() - v2.size();
        if (roznica > 0) {
            v2.insert(v2.begin(), roznica, 0);
        } else if (roznica < 0) {
            v1.insert(v1.begin(), -roznica, 0);
        }
        dlugoscwyniku = v1.size();
    }

    vector<int> dodawanie() {
        wyrownaj_wektory();
        vector<int> wynik(dlugoscwyniku);
        int przeniesienie = 0;

        for (int i = dlugoscwyniku - 1; i >= 0; i--) {
            int suma = v1[i] + v2[i] + przeniesienie;
            wynik[i] = suma % 10;
            przeniesienie = suma / 10;
        }

        if (przeniesienie > 0) {
            wynik.insert(wynik.begin(), przeniesienie);
        }

        return wynik;
    }

    vector<int> odejmowanie() {
        wyrownaj_wektory();
        vector<int> wynik(dlugoscwyniku);
        int przeniesienie = 0;
        bool ujemny = false;
        if(v1<v2){
            swap(v1, v2);
            ujemny = true;
        }
        for (int i = dlugoscwyniku - 1; i >= 0; i--) {
            int roznica = v1[i] - v2[i] - przeniesienie;
            if (roznica < 0) {
                roznica += 10;
                przeniesienie = 1;
            } else {
                przeniesienie = 0;
            }
            wynik[i] = roznica;
        }

        // Usunięcie zer
        while (wynik.size() > 1 && wynik[0] == 0) {
            wynik.erase(wynik.begin());
        }
        if (ujemny) {
            wynik[0] *= -1;
        }
        return wynik;
    }

    static vector<int> wczytaj_wektor(int rozmiar) {
        vector<int> wektor(rozmiar);
        cout << "Podaj liczbe (cyfry bez spacji, np. 12345): ";
        string liczba;
        cin >> liczba;

        for (int i = 0; i < rozmiar; i++) {
            wektor[i] = liczba[i] - '0';
        }

        return wektor;
    }

    static void wypisz_wektor(const vector<int>& wektor) {
        for (int val : wektor) {
            cout << val;
        }
        cout << endl;
    }
};

int main() {
    int rozmiar1, rozmiar2;
    cout << "Podaj dlugosc pierwszej liczby: ";
    cin >> rozmiar1;
    cout << "Podaj dlugosc drugiej liczby: ";
    cin >> rozmiar2;

    Kalkulator kalkulator(rozmiar1, rozmiar2);

    cout << "\nWybierz operację:\n";
    cout << "1. Dodawanie (+)\n";
    cout << "2. Odejmowanie (-)\n";
    int wybor;
    cin >> wybor;

    switch (wybor) {
        case 1: {
            vector<int> wynik = kalkulator.dodawanie();
            cout << "\nWynik dodawania: ";
            Kalkulator::wypisz_wektor(wynik);
            break;
        }
        case 2: {
            vector<int> wynik = kalkulator.odejmowanie();
            cout << "\nWynik odejmowania: ";
            Kalkulator::wypisz_wektor(wynik);
            break;
        }
        default:
            cout << "Zly wybor!" << endl;
    }

    return 0;
}
