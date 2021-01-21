#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Cladire
{
private:
	string denumire;
	int nrEtaje;
	double suprafata;
	string tip;
	string zona;
public:
	Cladire(string denumire, int nrEtaje, double suprafata, string tip, string zona)
	{
		this->denumire = denumire;
		this->nrEtaje = nrEtaje;
		this->suprafata = suprafata;
		this->tip = tip;
		this->zona = zona;
	}

	Cladire()
	{
		this->denumire = "RANDOM";
		this->nrEtaje = 0;
		this->suprafata = 0;
		this->tip = "RANDOM";
		this->zona = "RANDOM";
	}

	Cladire(string denumire, int nrEtaje, double suprafata, string tip)
	{
		this->denumire = denumire;
		this->nrEtaje = nrEtaje;
		this->suprafata = suprafata;
		this->tip = tip;
		this->zona = "RANDOM";
	}

	Cladire(const Cladire& c)
	{
		this->denumire = c.denumire;
		this->nrEtaje = c.nrEtaje;
		this->suprafata = c.suprafata;
		this->zona = c.zona;
		this->tip = c.tip;
	}

	Cladire& operator=(const Cladire& c)
	{
		this->nrEtaje = c.nrEtaje;
		this->suprafata = c.suprafata;
		this->denumire = c.denumire;
		this->tip = c.tip;
		this->zona = c.zona;
		return *this;
	}

	Cladire& operator/=(const Cladire& c)
	{
		this->nrEtaje /= c.nrEtaje;

		return *this;
	}

	Cladire& operator-=(const Cladire& c)
	{
		this->suprafata -= c.suprafata;
	}

	Cladire& operator+=(const Cladire& c)
	{
		this->suprafata += c.suprafata;
		return *this;
	}

	bool operator==(Cladire c)
	{
		return this->suprafata == c.suprafata;
	}

	bool operator>(const Cladire c)
	{
		if (this->suprafata > c.suprafata)
			return true;
		else return false;
	}

	bool operator<(const Cladire c)
	{
		if (this->suprafata < c.suprafata)
			return true;
		else return false;
	}

	friend istream& operator >>(std::istream& f, Cladire& c) // supraincarc >>
	{
		f >> c.denumire;
		f >> c.nrEtaje;
		f >> c.suprafata;
		f >> c.tip;
		f >> c.zona;
		return f;
	}

	friend ostream& operator << (std::ostream& g, Cladire& c) // supraincarc <<
	{
		g << c.denumire;
		g << c.nrEtaje;
		g << c.suprafata;
		g << c.tip;
		g << c.zona;
		return g;
	}

	~Cladire()
	{

	}

	double getSuprafata()
	{
		return suprafata;
	}
	void setSuprafata(double suprafata)
	{
		if (suprafata < 0)
			throw 101;
		else this->suprafata = suprafata;
	}

	string getDenumire()
	{
		return denumire;
	}

	void setDenumire(string denumire)
	{
		if (denumire.length() > 1) {
			this->denumire = denumire;
		}
	}

	int getnrEtaje()
	{
		return nrEtaje;
	}

	void setnrEtaje(int nrEtaje)
	{
		if (nrEtaje > 0) {
			this->nrEtaje = nrEtaje;
		}
	}

	string getTip()
	{
		return tip;
	}

	void setTip(string tip)
	{
		if (tip.length() > 0) {
			this->tip = tip;
		}
	}

	string getZona()
	{
		return zona;
	}

	void setZona(string zona)
	{
		if (zona.length() > 0) {
			this->zona = zona;
		}
	}
};

//Rezolvare tema: spital si hotel min 5 atribute
class  Hotel : public Cladire   // prima clasa Hotel
{
	Cladire c;
private:
	string nume_hotel; // atr 1
	static int nr_camere; // atr 2
	const  int nr_paturi; // atr 3
	char* adresa_hotel; // atr 4
	float cost_camera; // atr 5
	vector<int> vect_etaj;  // atr 6

public:
	static int i;

	Hotel() :nr_paturi() //constructor fara param
	{
		this->nume_hotel = "";
		this->nr_camere = 0;
		this->adresa_hotel = new char;
		this->cost_camera = 0;
		this->vect_etaj = vect_etaj;
	}
	Hotel(string nume_hotel, int nr_camere, char* adresa_hotel, float cost_camera) :nr_paturi(nr_camere*2) // constr cu param
	{
		this->nume_hotel = nume_hotel;
		this->nr_camere = nr_camere;
		this->adresa_hotel = adresa_hotel;
		this->cost_camera = cost_camera;
		//this->vect_etaj = vect_etaj;
	}

	Hotel(const Hotel& h) :nr_paturi() // constr de copiere
	{
		this->nume_hotel = h.nume_hotel;
		this->nr_camere = h.nr_camere;
		this->adresa_hotel = h.adresa_hotel;
		this->cost_camera = h.cost_camera;
		this->vect_etaj = h.vect_etaj;
	}

	Hotel operator = (const Hotel& h) // operatorul egal
	{
		this->nume_hotel = h.nume_hotel;
		this->nr_camere = h.nr_camere;
		this->adresa_hotel = h.adresa_hotel;
		this->cost_camera = h.cost_camera;
		this->vect_etaj = h.vect_etaj;
		return (*this);
	}

	~Hotel() // destructorul
	{
		//this->i--;
		delete adresa_hotel;
	}

	void adaugare_camere(int camere) {  //alocarea dinamica
		if (vect_etaj.size() >this-> nr_camere)
			cout << "Prea multe camere adaugate";
		else
			vect_etaj.push_back(camere);
	}


	friend istream& operator >>(std::istream& f, Hotel& h) // supraincarc >>
	{
		f >> h.nume_hotel;
		f >> h.nr_camere;
		f >> h.cost_camera;
		f >> h.adresa_hotel;
		for (int i = 0; i < h.vect_etaj.size(); i++)
			f >> h.vect_etaj[i];
		return f;
	}

	friend ostream& operator << (std::ostream& g, Hotel& h) // supraincarc <<
	{
		g << h.nume_hotel;
		g << h.nr_camere;
		g << h.cost_camera;
		g << h.adresa_hotel;
		for (int i = 0; i < h.vect_etaj.size(); i++)
			g << h.vect_etaj[i];
		return g;
	}


	bool operator>(const Hotel h)
	{
		if (this->nr_camere > h.nr_camere)
			return true;
		else return false;
	}

	int camera(int cost_maxim)  // metoda 1 de procesare, calc
	{
		int preturi[100];
		for (int i = 0; i < this->vect_etaj.size(); i++)
		{
			int pret_etaj = cost_maxim;
			this->cost_camera = pret_etaj - vect_etaj[i] * 10;
			preturi[i] = this->cost_camera;
		}
		return *preturi;
	}

	/* int numarpaturi(int numar_camere)    // metoda 2 de procesare
	{
		const int** ptr_nr_paturi = &nr_paturi;
		int* ptr;
		*ptr = &ptr_nr_paturi;
		numar_camere = this->nr_camere;
		(*ptr) = 2 * numar_camere;
		return this->nr_paturi;
	} */


	int mic_dejun() // metoda 2 de procesare !!! vect etaj, verifica daca este stuat la parter, at are micul dejun inclus
	{
		for (i = 0; i < vect_etaj.size(); i++)
			if (i == 0)
				cout << " Sunt" << vect_etaj[i] << "care vor avea mic dejun inclus";

	}

	string getnume_hotel() {   // getter nume hotel, atr 1
		return nume_hotel;
	}
	void setnume_hotel(string nume_hotel) { /// setter nume hotel, atr 1
		this->nume_hotel = nume_hotel;
	}

	 static int getnr_camere() // getter numar camere, atr 2
	{
		return nr_camere;
	}

	static void setnr_camere(int nr_camere)  // setter numar camere, atr 2
	{
		nr_camere = nr_camere;
	}
	int show_nr_paturi(){return nr_paturi;}

	const int getNr_paturi()   ////getter nr paturi, atr 3
	{
		return nr_paturi;
	}
	const void setNr_paturi(int nr_paturi) //// setter nr paturi, atr 3
	{
		nr_paturi = nr_paturi;
	}

	char* getAdresa_hotel() //// getter adresa hotel, atr 4
	{
		return adresa_hotel;
	}

	void setAdresa_hotel(const char* adresa_hotel) /// setter varianta 1 adresa hotel, atr 4
	{
		if (this->adresa_hotel != NULL)
			delete[]this->adresa_hotel;

		this->adresa_hotel = new char[strlen(adresa_hotel) + 1];
		strcpy(this->adresa_hotel, adresa_hotel);

	}

	/*
	void setAdresa_hotel(const char* adresa_hotel) { // setter varianta 2 pentru adresa_hotel care este char*, atr 4
				if (adresa_hotel != NULL) {
					if (strlen(adresa_hotel) > 4) {
						if (this->adresa_hotel != NULL) {
							delete[]this->adresa_hotel;
						}
						this->adresa_hotel = new char[strlen(adresa_hotel) + 1];
						strcpy(this->adresa_hotel, adresa_hotel);
					}
					else {
						throw "Caracteristica incorecta";
					}
				}
				else {
					throw "Pointer NULL";
				}
			}


	*/

	float getCost_camera() ///// getter cost camera, atr 5
	{
		return this->cost_camera;
	}
	void setCost_camera(float cost_camera) /// setter cost camera, atr 5
	{
		this->cost_camera = cost_camera;
	}

	friend void afisare();


};

int Hotel::nr_camere;
int Hotel::i = 0;

class  Spital : public Cladire   // A doua clasa, Spital
{
	Cladire c;
private:
	string nume_spital; //atr 1
	static int nr_saliOperatie; //atr 2
	const  int nr_meseOperatie = 0; // atr 3
	char* adresa_spital; // atr 4
	float cost_operatie; // atr 5
	vector<int> vect_saliSectie; // atr 6

public:
	static int i;

	Spital() :nr_meseOperatie() //constructor fara param
	{
		this->nume_spital = "";
		this->nr_saliOperatie = 0;
		this->adresa_spital = new char;
		this->cost_operatie = 0;
		this->vect_saliSectie = vect_saliSectie;
	}
	Spital(string nume_spital, int nr_saliOperatie, char* adresa_spital, float cost_operatie, vector <int> vect_sectie) :nr_meseOperatie() // constr cu param
	{
		this->nume_spital = nume_spital;
		this->nr_saliOperatie = nr_saliOperatie;
		this->adresa_spital = adresa_spital;
		this->cost_operatie = cost_operatie;
		this->vect_saliSectie = vect_saliSectie;
	}

	Spital(const Spital& s) :nr_meseOperatie() // constr de copiere
	{
		this->nume_spital = s.nume_spital;
		this->nr_saliOperatie = s.nr_saliOperatie;
		this->adresa_spital = s.adresa_spital;
		this->cost_operatie = s.cost_operatie;
		this->vect_saliSectie = s.vect_saliSectie;
	}

	Spital operator = (const Spital& s) // operatorul egal
	{
		this->nume_spital = s.nume_spital;
		this->nr_saliOperatie = s.nr_meseOperatie;
		this->adresa_spital = s.adresa_spital;
		this->cost_operatie = s.cost_operatie;
		this->vect_saliSectie = s.vect_saliSectie;
		return (*this);
	}

	~Spital() // destructorul
	{
		//this->i--;
		delete adresa_spital;
	}

	void adaugare_saliOperatie(int sali) {  // alocare dinamica
		if (vect_saliSectie.size() > nr_saliOperatie)
			cout << "Prea multe sali de operatie adaugate in sectie";
		else
			vect_saliSectie.push_back(sali);
	}

	friend istream& operator >>(std::istream& f, Spital& s) // supraincarc >>
	{
		f >> s.nume_spital;
		f >> s.nr_saliOperatie;
		f >> s.cost_operatie;
		f >> s.adresa_spital;
		for (int i = 0; i < s.vect_saliSectie.size(); i++)
			f >> s.vect_saliSectie[i];
		return f;
	}

	friend ostream& operator << (std::ostream& g, Spital& s) // supraincarc <<
	{
		g << s.nume_spital;
		g << s.nr_saliOperatie;
		g << s.cost_operatie;
		g << s.adresa_spital;
		for (int i = 0; i < s.vect_saliSectie.size(); i++)
			g << s.vect_saliSectie[i];
		return g;
	}

	bool operator<(const Spital s)   //supraincarcare <
	{
		if (this->nr_saliOperatie > s.nr_saliOperatie)
			return true;
		else return false;
	}

	int camera(int cost_maximOperatie)  // metoda 1 de procesare, calc
	{
		int preturi[50];
		for (int i = 0; i < this->vect_saliSectie.size(); i++)
		{
			int pret_sectie = cost_maximOperatie;
			this->cost_operatie = pret_sectie - vect_saliSectie[i] * 20;
			preturi[i] = this->cost_operatie;
		}
		return *preturi;
	}

	int cost_acop_de_asigurare(int procent) // metoda 2 de procesare
	{
		int pret_asigurare = (this->cost_operatie * procent) / 100;
		return pret_asigurare;
	}
	string getNume_spital() {   // getter nume spital, atr 1
		return nume_spital;
	}
	void setNume_spital(string nume_spital) { /// setter nume spital, atr 1
		this->nume_spital = nume_spital;
	}

	 static int getNr_saliOperatie() // getter numar sali de operatie, atr 2
	{
		return nr_saliOperatie;
	}

	static void setSr_saliOperatie(int nr_saliOperatie)  // setter numar sali de operatie, atr 2
	{
		nr_saliOperatie = nr_saliOperatie;
	}

	const int getNr_meseOperatie()   ////getter nr mese de operatie, atr 3
	{
		return nr_meseOperatie;
	}
	const void setNr_meseOperatie(int nr_meseOperatie) //// setter nr mese de operatie, atr 3
	{
		nr_meseOperatie = nr_meseOperatie;
	}

	char* getAdresa_spital() //// getter adresa spital, atr 4
	{
		return adresa_spital;
	}

	void setAdresa_spital(const char* adresa_spital) /// setter varianta 1 adresa spital, atr 4
	{
		if (this->adresa_spital != NULL)
			delete[]this->adresa_spital;

		this->adresa_spital = new char[strlen(adresa_spital) + 1];
		strcpy(this->adresa_spital, adresa_spital);

	}

	/*
	void setAdresa_spital(const char* adresa_spital) { // setter varianta 2 pentru adresa_spital care este char*, atr 4
				if (adresa_spital != NULL) {
					if (strlen(adresa_spital) > 4) {
						if (this->adresa_spital != NULL) {
							delete[]this->adresa_spital;
						}
						this->adresa_spital = new char[strlen(adresa_spital) + 1];
						strcpy(this->adresa_apital, adresa_spital);
					}
					else {
						throw "Caracteristica incorecta";
					}
				}
				else {
					throw "Pointer NULL";
				}
			}


	*/

	float getCost_operatie() ///// getter cost operatie, atr 5
	{
		return this->cost_operatie;
	}
	void setCost_operatie(float cost_operatie) /// setter cost operataie, atr 5
	{
		this->cost_operatie = cost_operatie;
	}


	friend void afisare();

};

int Spital::nr_saliOperatie = 35;
int Spital::i = 0;

void afisare()
{
	/*Cladire c1, c2; */

	Hotel h;
	Spital s;

	h.setnume_hotel("Bla");
	h.c.setDenumire("Hotel");
	h.c.setnrEtaje(3);
	h.c.setSuprafata(200.0);
	h.c.setTip("Hotel de 3 stele");
	h.c.setZona("Hotel");
	s.c.setDenumire("Spital");
	s.c.setnrEtaje(4);
	s.c.setSuprafata(300.0);
	s.c.setTip("Spital privat");
	s.c.setZona("Spital");
	h.setnume_hotel("Anubis");
	h.setAdresa_hotel("Soseaua Bucuresti-Targoviste nr. 214");
    Hotel::nr_camere = 20;
    //h.setNr_paturi(h.getnr_camere()*2);
    Hotel ob(h.getnume_hotel(),h.getnr_camere(),h.getAdresa_hotel(),h.getCost_camera());
    int bla = ob.show_nr_paturi();
	cout << "Denumirea cladirii: "; cout << h.c.getDenumire()<<endl;
	cout << "Numarul etajelor este: "; cout << h.c.getnrEtaje() << endl;
	cout << "Suprafata este: "; cout << h.c.getSuprafata() << endl;
	cout << "Tipul cladirii este: "; cout << h.c.getTip() << endl;
	cout << "Zona in care se afla cladirea este: "; cout << h.c.getZona() << endl;

	cout << "Denumirea cladirii: "; cout << s.c.getDenumire() << endl;
	cout << "Numarul etajelor este: "; cout << s.c.getnrEtaje() << endl;
	cout << "Suprafata este: "; cout << s.c.getSuprafata() << endl;
	cout << "Tipul cladirii este: "; cout << s.c.getTip() << endl;
	cout << "Zona in care se afla cladirea este: "; cout << s.c.getZona() << endl;

	cout << "Denumirea hotelului: "; cout << h.getnume_hotel() << endl;
	cout << "Numarul camerelor este: "; cout << h.getnr_camere() << endl;
	cout << "Numarul de paturi este: "; cout << bla << endl;
	cout << "Adresa hotelului este: "; cout << h.getAdresa_hotel() << endl;
}


int main()
{

	/*Cladire c;

	Hotel h;
	int i = h.camera(100); // apelare pt metoda 1 de procesare
	cout << i;*/

	afisare();

	return 0;
}
