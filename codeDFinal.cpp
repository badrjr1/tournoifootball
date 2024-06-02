#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<conio.h>
#include<cstdlib>
using namespace std ;

class Equipe {
	private:
		int idEp;
		string nom;
		
	public: 
		bool qualifie ; // true oui, false non
		static int idep;
		Equipe(int id):idEp(id){}
		Equipe(){
			qualifie=false ;
        	this->idEp=idep;
        	idep++; 
    	}
		Equipe(string nom){
			qualifie=false ;
			this->nom=nom;
			this->idEp=idep;
			idep++;
		}
		virtual void affciheEquipe(){ 
			cout<<idEp<<" "<<nom<<endl;
		}
		virtual string getNom(){return nom;}
		virtual int getId(){return idEp;}
		void Eqpqualifie(){this->qualifie=true;}
		void setqualifie(){qualifie=false;}
		bool getQualifie(){return qualifie;}
		Equipe *getequipe(){return this;}
		void modifiereqp(){
			cout<<" Entre le nouveau nom";
			cin>>this->nom;
		}
};
int Equipe::idep=6000;
class Equipe_pnts: public Equipe {
	private:
		int point;
		int win;
		int lose;
		int draw;
		int goalsout;
		int goalsin;
	public: 
	Equipe_pnts(Equipe e):Equipe(e),point(0),win(0),lose(0),draw(0),goalsin(0),goalsout(0){}
	
	void afficheEquipepnt(){
		cout<<getNom()<<"|"<<point<<"|"<<win<<"|"<<lose<<"|"<<draw<<"|"<<goalsout<<"|"<<goalsin<<"|"<<endl;
		cout<<"______________________________"<<endl;
	}
		
	void modfierpoint(int Go,int Gi){
		goalsin+=Gi;
		goalsout+=Go;
		if(Go>Gi)
		{
			point+=3;
			win++;
		}
		else if(Go==Gi)
		{
			point+=1;
			draw ++;
		}
		else	// Go<Gi
			lose++;
	}
	
	int getPnts(){return point;}
	Equipe getEquip(){return *Equipe::getequipe();}
};
class Arbitre {
	private:
		int id;
		string nom;
		vector<string> decisions;
	public: 
		static int idArb ;
		Arbitre(int id):id(id){}
		Arbitre(){
			this->id=idArb;
			idArb++;
		}
		Arbitre(string nom):id(idArb),nom(nom){idArb++;}
		void modifierarbitre(){
			cout<<" -Entre le nv nom: ";
			cin>>this->nom;
		}
		void decision()
		{
			int decision;
			cout<<"1:declarer debut du match"<<endl<<"2:declarer fin du 1er mi-temps"<<endl<<"3:declarer debut du 2eme mi-temps"<<endl<<
			"4:declarer fin du 2eme mi-temps"<<endl<<"5:carte jaune"<<endl<<"6:carte rouge"<<endl<<"7:avertissement verbal"<<endl<<
			"8:tir au but"<<endl<<"9:coup franc"<<endl<<"10:corner";
			cout<<" -Entre le nbr de la decision : "<<endl;
			cin>>decision;
			switch(decision){
				case 1:
					cout<<" debut du match"<<endl;
					decisions.push_back(" debut du match");
					break;
				case 2:
					cout<<"fin du 1er mi-temp"<<endl;
					decisions.push_back(" fin du 1er mi-temp");
				break;
				case 3:
					cout<<" debut du 2eme mi-temps"<<endl;
					decisions.push_back(" debut du 2eme mi-temps");
					break;
				case 4:
					cout<<"  fin du 2eme mi-temps"<<endl;
					decisions.push_back(" fin du 2eme mi-temps");
					break;
				case 5:
					cout<<" carte jaune"<<endl;
					decisions.push_back("carte jaune");
					break;
				case 6:
					cout<<" carte rouge"<<endl;
					decisions.push_back(" carte rouge");
					break;
				case 7:
					cout<<"  avertissement verbal"<<endl;
					decisions.push_back("  avertissement verbal");
					break;
				case 8:
					cout<<" tir au but"<<endl;
					decisions.push_back(" tir au but");
					break;
				case 9:
					cout<<" coup franc"<<endl;
					decisions.push_back("  coup franc");
					break;
				case 10:
					cout<<" coup de pied de coin"<<endl;
					decisions.push_back(" coup de pied de coin");
					break;
				default:
					cout<<"---------------ERROR------------------"<<endl;
					cout<<" Entre un chiffre valide entre 1 et 10"<<endl;
			}
		}
		void afficherArbitre(int d){
			cout<<"L'Arbitre: "<<endl<<" -ID: "<<idArb<<endl<<" -Nom: "<<nom<<endl;
			if(d!=-1){
				cout<<"Ces decisions: "<<endl;
				for(int i=0;i<this->decisions.size();i++){
				cout << decisions[i] ;
				}
				cout<<endl;
			}
        }
		int getId(){return id;}
};
int Arbitre::idArb= 4000;
class Categorie{
	private:
		string nom;
		double prix ;
	public :
		void saisirCategorie(string nom,double prix ){
			this->nom=nom;
			this->prix=prix;	
		}
		void affichecategorie(){
			
			cout<<" 	Nom      : "<<nom<<endl;
			cout<<" 	Prix     : "<<prix<<endl;
		}
		string getNom(){return nom;}
		double getprix(){return prix ;}
		void setNom(string nom){this->nom=nom;}
		void setPrix(double prix){this->prix=prix;}
};

class Ticket {
private:
	int id;
	bool dispo; // 1 disponible, 0 reserve
	Categorie categorie ;//vip cat2 cta3 cta4
public: 
	static int idTick;
	Ticket(){id=idTick;idTick++;}
	void setValues(Categorie Cate){
		categorie=Cate;
	}
	string getCat(){return categorie.getNom();}
	double getprix(){return categorie.getprix() ;}
	void afficheTicket(){
		cout<<"------------------------------------"<<endl;
		cout<<"| id: "<<id<<" prix: "<<categorie.getprix()<<" Categorie: "<<categorie.getNom()<<" |"<<endl;
		cout<<"------------------------------------"<<endl;
	}
};
Ticket tkt ; 
int Ticket::idTick=7000;
class Terrain {
protected: 
	int id ;
	string nom;
	vector <int> capacite;
	string adresse;
	vector <Categorie> cate ;
	vector <Ticket> billets;
public:
	static int idterrain ;
	Terrain(int id):id(id){}
	Terrain(){id=idterrain;
	idterrain++;}
	Terrain(string nom , int capacite , string adresse)
	:nom(nom),adresse(adresse){
		id=idterrain;
		idterrain++;
		for (int i = 0; i < 4; i++)
		{
			this->capacite.push_back(capacite/4);
		}
		Categorie ct;
		ct.saisirCategorie("vip",200);
		cate.push_back(ct);
		ct.saisirCategorie("cat2",80);
		cate.push_back(ct);
		ct.saisirCategorie("cat3",50);
		cate.push_back(ct);
		ct.saisirCategorie("cat4",30);
		cate.push_back(ct);
	}
	void saisirdonneterrain(){
		Categorie ct ;
		double p ;
		cout<<" Entre les donne terrain :"<<id<<endl;
		cout<<" 	Nom : ";
		cin>>nom;
		cout<<" 	Adresse : ";
		cin>>adresse;
		cout<<" 	Information par categorie: ";
		cout<<" 		Capacite vip : ";
		cin>>capacite[0];
		cout<<" 		prix : ";
		cin>>p;
		ct.saisirCategorie("vip",p);
		cate.push_back(ct);
		cout<<" 		Capacite cat2 : ";
		cin>>capacite[1];
		cout<<" 		prix : ";
		cin>>p;
		ct.saisirCategorie("cat2",p);
		cate.push_back(ct);
		cout<<" 		Capacite cat3 : ";
		cin>>capacite[2];
		cout<<" 		prix : ";
		cin>>p;
		ct.saisirCategorie("cat3",p);
		cate.push_back(ct);
		cout<<" 		Capacite cat4 : ";
		cin>>capacite[3];
		cout<<" 		prix : ";
		cin>>p;
		ct.saisirCategorie("cat4",p);
		cate.push_back(ct);
	}
	void affciheTerrain(){
		int cap=capacite[0]+capacite[1]+capacite[2]+capacite[3];
		cout<<" Terrain: "<<nom<<endl<<" Capacite: "<<cap<<endl<<" Adresse: "<<adresse<<endl;
	}
	string getNom(){
		return nom;
	}
	int nbrvip(){
		int s=0;
		for(int i=0;i<cate.size();i++)
			if(cate[i].getNom()=="vip")
			s++;
		
		return s;
	}
	Ticket* achterBillet(){
		
		if(billets.size()<(capacite[0]+capacite[1]+capacite[2]+capacite[3]))
		{
			int v=0 , c2=0,c3=0,c4=0;
			for(int i=0;i<billets.size();i++)
			{
				if(billets[i].getCat()=="vip")
				v++;
				if(billets[i].getCat()=="cat2")
				c2++;
				if(billets[i].getCat()=="cat3")
				c3++;
				if(billets[i].getCat()=="cat4")
				c4++;
			}
			cout<<" Categorie : "<<endl;
			for (int i=0;i<cate.size();i++)
			{
				cout<<i+1<<": ";
				cate[i].affichecategorie();
				cout<<endl;
			}
			
			cout<<" Choisir un chiffre : ";
			int b ;
			cin>>b ;
			switch (b)
			{
				case 1:
					if(v<capacite[0])
					{
						
						tkt.setValues(cate[0]);
						billets.push_back(tkt);
						
						return &tkt ;
					}
					else 
					return nullptr ;
					break;
				case 2:
					if(v<capacite[1])
					{
						
						tkt.setValues(cate[1]);
						billets.push_back(tkt);
						return &tkt ;
					}
					else 
					return nullptr ;
					break;
				case 3:
					if(v<capacite[2])
					{
						
						tkt.setValues(cate[2]);
						billets.push_back(tkt);
						return &tkt ;
					}
					else 
					return nullptr ;
					break;
				case 4:
					if(v<capacite[3])
					{
						
						tkt.setValues(cate[3]);
						billets.push_back(tkt);
						return &tkt ;
					}
					else 
					return nullptr ;
					break;
				
				default:
					cout<<" entre un chiffre valide"<<endl;
					break;
			}

		}
		return nullptr ;
	}
	void afficherbillet(){
		cout<<"les tickets vendu : "<<endl;
		for(int i=0;i<billets.size();i++)
		billets[i].afficheTicket();
	}
	int getCapacite(){
		int s=0;
		for(int i=0;i<capacite.size();i++)
		s=s+capacite[i];

		return s;
	}
	void modifierterrain(){
		Terrain tr;
		tr.saisirdonneterrain();

		*this=tr;
	}
	int getId(){return id;}
};
int Terrain::idterrain= 5000;

class Spectateur {
private:
    int id;
	int ticket;
    string nom ;
    Ticket tkt;
public: 
	static int idspct ;
	Spectateur(){
		this->ticket=0;
		this->id=idspct;
		idspct++;
	}
	void sinscrire(){
		cout<<" votre id: "<<id<<endl;
		cout<<" Entre votre nom: ";
		cin>>this->nom;
	}
    void achatTicket(Terrain t){
		//cout<<"done 3"<<endl;
		tkt=*t.achterBillet();
		this->ticket=1;
		//cout<<"done 4"<<endl;
    }
    void afficherSpactateur(){
	cout<<" ID: "<<id<<endl<<" Nom: "<<nom<<endl;
	    if(this->ticket==1)
		    tkt.afficheTicket();
    }
    int getid(){return id;}
};
int Spectateur::idspct= 3000;
class Resultat{
private:
	int nbA;
	int nbB;
	int duree; // -1 avant match , 0 en cours , 1 termine
public: 
	Resultat():nbA(0),nbB(0),duree(-1){}
	void afficheResmt(){
		if(duree == 0)
		cout<<" "<<nbA<<" en cours "<<nbB<<" ";
		else if(duree == 1)
		cout<<" "<<nbA<<" fini "<<nbB<<" ";
		else
		cout<<" "<<nbA<<" x "<<nbB<<" ";
	}
	void setRes(int a , int b, int d){
		if(duree!=1)
		{
			this->nbA=a;
			this->nbB=b;
			this->duree=d;
		}
	}
	int getNbA(){return nbA;}
	int getNbB(){return nbB;}
	int getDuree(){return duree;}
};
class Match{
private: 
		int id ;
		Arbitre arbitre;
		Terrain terrain;
		Equipe equipe1;
		Equipe equipe2;
		Resultat resultat;
		string type ; // Elimination, Phase_de_group, Quart_de_final, Demi_final, Final
public: 
	static int idm ;
	Match(){
		this->id=idm;
		idm++;
	};
	Match(Arbitre arbitre , Terrain terrain , Equipe equipe1,Equipe equipe2)
	:arbitre(arbitre),terrain(terrain),equipe1(equipe1),equipe2(equipe2){this->id=idm;
		idm++;}
	Match(Arbitre arbitre,Terrain terrain,Equipe equipe1,Equipe equipe2,Resultat resultat)
	:arbitre(arbitre),terrain(terrain),equipe1(equipe1),equipe2(equipe2),resultat(resultat){
		this->id=idm;
		idm++;
	}
	void afficheinfomatch()
	{
		cout<<" Match : "<<type<<" ID    : "<<id<<" ";
		cout<<equipe1.getNom()<<" x ";
		cout<<equipe2.getNom()<<" |  ";
		if(resultat.getDuree()!=-1)
		cout<<resultat.getNbA()<<" "<<resultat.getNbB();
		cout<<endl;
	}
	void afficheMatch(){
		cout<<" Match : "<<type<<endl;
		cout<<equipe1.getNom();
		resultat.afficheResmt();
		cout<<equipe2.getNom()<<endl;
		arbitre.afficherArbitre(resultat.getDuree());
		terrain.affciheTerrain();
		//desp.affciheDescription();
		cout<<"**************************************"<<endl;
	}
	void ModifierMatch	( Arbitre newArbitre, Terrain newTerrain, Equipe newEquipe1, Equipe newEquipe2, Resultat newResultat, string newType) { 
        arbitre = newArbitre;
        terrain = newTerrain;
        equipe1 = newEquipe1;
        equipe2 = newEquipe2;
        resultat = newResultat;
        type = newType;
	};
	string getTypeM(){ 
		return type ;
	}
	void settype(string type){
		this->type=type;
	}
	vector<Equipe> equipesmatch(){
		vector <Equipe> e;
		e.push_back(equipe1);
		e.push_back(equipe2);
		return e;
	}
	Equipe* equipegagnat(){
		if(resultat.getDuree()==1){
			if(resultat.getNbA()>resultat.getNbB())
				return &equipe1;
			if(resultat.getNbA()<resultat.getNbB())
				return &equipe2;
		}
		else
			cout<<" le match est en cours"<<endl;

		return nullptr;
	}
	bool matchtermine(){
		if(resultat.getDuree()==1)
		return true ;

		return false ;
	}
	void majmatch(){
		int be1,be2,d;
		cout<<" but equipe1 : ";
		cin>>be1;
		cout<<" but equipe2 : ";
		cin>>be2;
		cout<<" entre 1 si le match est termine sinon 0 :";
		cin>>d;
		resultat.setRes(be1,be2,d);
	}
	void majmatchalt(){
		int be1,be2,d=1;
		be1=rand()%8 +0;
		do
		{
			be2=rand()%8 +0;
		} while (be1==be2);
		resultat.setRes(be1,be2,d);
	}
	void affichermatchevantdecommence(){
		if(resultat.getDuree()==-1)
		Match::afficheinfomatch();
	}
	void afficherticket(){
		terrain.afficherbillet();
	}
	void affichematchdequipe(int id){
		if(equipe1.getId()==id || equipe2.getId()==id)
		Match::afficheMatch();
		
	}
	int getId(){return id;}
	Resultat getresultat(){ return resultat;}
	Terrain* getterrain(){return &this->terrain;}
};
int Match::idm= 2000;

bool trivect( Equipe_pnts& e1, Equipe_pnts& e2);
template <typename T>
int existeTinvector(vector<T> a, T b) ;
class Group{
private:
	int nbrEqp ;
public:
	vector<Equipe_pnts> equipe;
    Group(){nbrEqp=4;}

    void ajouterEquipe(Equipe_pnts equipe){
        if(this->equipe.size() < nbrEqp & existeTinvector(this->equipe,equipe)==-1)
			this->equipe.push_back(equipe);
		else	
			cout<<" Impossible d'ajouter cette equipe "<<endl ;
    }
    int nombreEquipes(){
        return equipe.size();
	}   
    void afficherEquipesgrp(){
        cout<<"______________________________"<<endl;
		cout<<"Nom|point|win|lose|draw|GO|GI|"<<endl;
		cout<<"______________________________"<<endl;
		for (int i=0;i<equipe.size();i++)
			equipe[i].afficheEquipepnt();
    }
    void modifierclassement(Equipe e1,Equipe e2,Resultat res){
        for (int i =0;i<equipe.size();i++)
		{
			if(e1.getNom()== equipe[i].getNom())
			{
				if(res.getDuree()==1)
				equipe[i].modfierpoint(res.getNbA(),res.getNbB());
				else
				cout<<" impossible de modifier le classement avant la fin du match "<<endl;
			}
			if(e2.getNom()== equipe[i].getNom())
			{
				if(res.getDuree()==1)
				equipe[i].modfierpoint(res.getNbB(),res.getNbA());
				else
				cout<<" impossible de modifier le classement avant la fin du match "<<endl;
			}
		}
    }	
   	vector<Equipe_pnts> equipesQualifiees()  {
		vector<Equipe_pnts> qualifiees;
		
		sort(equipe.begin(),equipe.end(),trivect);
		qualifiees.push_back(equipe[0]);
		qualifiees.push_back(equipe[1]);

		return qualifiees;
	}
	int equipeexistedansgrp(Equipe e){
		for(Equipe eqp:equipe)
		if(eqp.getId() == e.getId())
		return 1 ;

		return -1 ;
	}
};

class Gestion_dequipe {
    public:
		vector<Equipe> equipe;
		Gestion_dequipe(){}
		Gestion_dequipe(vector<Equipe> equipe):equipe(equipe){}
        void ajouterEquipetrn(Equipe e){
			if(existeTinvector(equipe,e)==-1)
			equipe.push_back(e);
		}
        void supprimerEquipetrn(Equipe e){
			int i=existeTinvector(equipe,e);
			if(i!=-1)
				equipe.erase(equipe.begin()+i);
			else
				cout<<"equipe nexiste pas";
		}
		void setquialifiation(){
			for(int i=0;i<equipe.size();i++)
			{
				equipe[i].setqualifie();
			}
		}
		void afficherlesequipes(){
			for (int i = 0; i < equipe.size(); i++)
			{
				equipe[i].affciheEquipe();
			}
			
		}
};

class Gestion_des_matchs {
private: 
	
public:
	vector<Match> VectMatch;
	void ajouterMatchGM(Match m){
		if(existeTinvector(VectMatch,m))
			VectMatch.push_back(m);
	}
	bool equipeexist(Equipe e){
		for(int i=0;i<VectMatch.size();i++)
		{
			vector <Equipe> ep ;
			ep.push_back(VectMatch[i].equipesmatch()[0]);
			ep.push_back(VectMatch[i].equipesmatch()[1]);
			for(int j=0;j<ep.size();j++)
				if(e.getId()==ep[j].getId())
					return 1 ;
		}
		return 0;
	}
	void afficherlesmatch(){
		for (int i = 0; i < VectMatch.size(); i++)
		{
			VectMatch[i].afficheMatch();
		}
	}
	void affichernextmatches(){
		for(Match m:VectMatch)
		m.affichermatchevantdecommence();
	}
};
class Gestion_des_Group {
public:
	vector<Group> VectGrp;
	void ajoutergrp(Group g){
		VectGrp.push_back(g);
	}
	void affichelesgroup(){
		for (int i = 0; i < VectGrp.size(); i++)
		{
			VectGrp[i].afficherEquipesgrp();
		}
		
	}
	void modifierclassementgrp(Match m){
		for(int i=0;i<VectGrp.size();i++)
		if(VectGrp[i].equipeexistedansgrp(m.equipesmatch()[0]))
		{
			VectGrp[i].modifierclassement(m.equipesmatch()[0],m.equipesmatch()[1],m.getresultat());
		}
	}
};
class Gestion_de_terrain{
public: 
	vector<Terrain> VectTerrain;
	Gestion_de_terrain(){}
	Gestion_de_terrain(vector<Terrain> VectTerrain):VectTerrain(VectTerrain){}
	Terrain terrainfinal(){
		int max=0;
		for(int i=1;i<VectTerrain.size();i++)
		{
			if(VectTerrain[i].getCapacite()>VectTerrain[max].getCapacite())
			max=i;
		}
		return VectTerrain[max] ;
	}
	void afficherterrainGT(){
		for(int i=0;i<VectTerrain.size();i++)
		VectTerrain[i].affciheTerrain();
	}
};
class Gestion_de_spectateur{
public:    
	vector<Spectateur> VectSpect ;
	void affichespectateurGS(){
		for(int i=0;i<VectSpect.size();i++)
		VectSpect[i].afficherSpactateur();
	}
	void ajouterunspectateur(Spectateur sp){
		VectSpect.push_back(sp);
		cout<<" *************Bienvenue chez nous************* "<<endl;
	}
	int indicespect(int id){
		for(int i=0;i<VectSpect.size();i++)
		if(VectSpect[i].getid() == id)
		return i;

		return -1;
	}
};
class Gestion_darbitre{
    public:
		vector<Arbitre> Varbtr;
		Gestion_darbitre(){}
        Gestion_darbitre(vector<Arbitre> Varbtr):Varbtr(Varbtr){}
		void ajouterArbtr(Arbitre a){
			if(existeTinvector(Varbtr,a))
				Varbtr.push_back(a);
		}
		void afficherlesarbitres(){
			for(Arbitre ar:Varbtr)
			ar.afficherArbitre(1);
		}
};

class classement_global {
public: 
	int nbEqp ;
	vector<Equipe_pnts> equipes;
	void afficheclassement();
};

class Tournoi {
private:
	int ID;
	string nom;
	Equipe vainqueur;
	Gestion_dequipe GestEqp; 		//32 equipe
	Gestion_darbitre GestArbt; 		//8 arbitre
	Gestion_des_matchs GestMtch; 		//47 match qu total
	Gestion_de_terrain GestTrn; 		//4 terrain
	Gestion_de_spectateur spect ;
	Gestion_des_Group Gestgrp; 		//4 groupe apres l'elimination
public:
	static int idtr;
	Tournoi(){
		this->ID=idtr;
		idtr++;
	}
	void creetournoi(Gestion_dequipe GestEqp,Gestion_darbitre GestArbt,Gestion_de_terrain GestTrn)
	{
		// ajouter les equipes aléatoirement
		do
		{
			int valeur  = rand()%GestEqp.equipe.size() +0;
			if(existeTinvector(this->GestEqp.equipe,GestEqp.equipe[valeur])==-1)
				this->GestEqp.equipe.push_back(GestEqp.equipe[valeur]);
			
		} while (this->GestEqp.equipe.size()<32);
		
		
		// ajouter les arbittres aléatoirement
		do
		{
			int valeur  = rand()%GestArbt.Varbtr.size() +0;
			if(existeTinvector(this->GestArbt.Varbtr,GestArbt.Varbtr[valeur])==-1)
				this->GestArbt.Varbtr.push_back(GestArbt.Varbtr[valeur]);
			
		} while (this->GestArbt.Varbtr.size()<8);
		
		// ajouter les terrain aléatoirement // error
		
		do
		{
			int valeurS  = rand()%GestTrn.VectTerrain.size() +0;
			if(existeTinvector(this->GestTrn.VectTerrain,GestTrn.VectTerrain[valeurS])==-1)
				this->GestTrn.VectTerrain.push_back(GestTrn.VectTerrain[valeurS]);
		} while (this->GestTrn.VectTerrain.size()<4);
		
	}
	void affcicheinfotournoi(){
		cout<<" Tournoi: "<<ID<<endl;
	}
	void affichertournoir(){
		cout<<" Tournoi : "<<ID<<endl;
		cout<<" Equipe  : "<<endl;
		GestEqp.afficherlesequipes();
	}
	void afficherinfoMacthtournoi(){
		for(int i=0;i<GestMtch.VectMatch.size();i++)
		GestMtch.VectMatch[i].afficheinfomatch();
	}
	void afficherMacthtournoi(){
		for(int i=0;i<GestMtch.VectMatch.size();i++)
		GestMtch.VectMatch[i].afficheMatch();
	}
	void gerematch(){
		int b=0 ;
		for(int i=0;i<GestMtch.VectMatch.size();i++)
		{
			if(GestMtch.VectMatch[i].matchtermine())
			b=1;
			else
			{
				b=0;
				break;
			}
		}
		
		if(GestMtch.VectMatch.size()==0)// <=> Elimination
		{
			while (GestMtch.VectMatch.size()<16)
			{
				int equipe1;
				do{
					equipe1  = rand()%GestEqp.equipe.size() +0;
				}while (GestMtch.equipeexist(GestEqp.equipe[equipe1])==1);
				
				int equipe2;
				do{
					equipe2  = rand()%GestEqp.equipe.size() +0;
				}while (GestMtch.equipeexist(GestEqp.equipe[equipe2])==1 || equipe1==equipe2);
				
				int arbitre  = rand()%GestArbt.Varbtr.size() +0;
				int terrain  = rand()%GestTrn.VectTerrain.size() +0;
				
				Match m(GestArbt.Varbtr[arbitre],GestTrn.VectTerrain[terrain],GestEqp.equipe[equipe1],GestEqp.equipe[equipe2]);
				m.settype("Elimination");
				GestMtch.VectMatch.push_back(m);
			}
		}
		else if(GestMtch.VectMatch.size()==16 & b==1 )// <=> Phase de group
		{ 	
			vector<int> eqp;
			for(int i=0;i<GestMtch.VectMatch.size();i++)
			{
				int e=existeTinvector(GestEqp.equipe,*GestMtch.VectMatch[i].equipegagnat());
				if(e!=-1)
				{
					GestEqp.equipe[e].Eqpqualifie();
					eqp.push_back(e);
				}
			}
			
			do{
				Group gp;
				do{
					
					int i=rand()%eqp.size() +0;
					Equipe_pnts ep(GestEqp.equipe[eqp[i]]);
					if(existeTinvector(gp.equipe,ep) == -1)
					{
						gp.ajouterEquipe(ep);
						eqp.erase(eqp.begin()+i);
					}
				}while(gp.nombreEquipes()<4);
				Gestgrp.VectGrp.push_back(gp);
			}while(Gestgrp.VectGrp.size()<4);
			
			for(int i=0;i<Gestgrp.VectGrp.size();i++)
			{
				int arbitre  = rand()%GestArbt.Varbtr.size() +0;
				int terrain  = rand()%GestTrn.VectTerrain.size() +0;
				for(int j =0;j<3;j++)
				{
					for(int k=j+1;k<Gestgrp.VectGrp[i].equipe.size();k++)
					{
						Match m(GestArbt.Varbtr[arbitre],GestTrn.VectTerrain[terrain],
						Gestgrp.VectGrp[i].equipe[j],Gestgrp.VectGrp[i].equipe[k]);
						m.settype("Phase de group");
						GestMtch.VectMatch.push_back(m);
					}	
				}
			}
			
			GestEqp.setquialifiation();
		}
		else if(GestMtch.VectMatch.size()==40 & b==1 )//Quart de final
		{
			// equipe qualifie
			for(int i=0;i<Gestgrp.VectGrp.size();i++)
			{
				int e=existeTinvector(GestEqp.equipe,Gestgrp.VectGrp[i].equipesQualifiees()[0].getEquip());
				GestEqp.equipe[e].Eqpqualifie();
				e=existeTinvector(GestEqp.equipe,Gestgrp.VectGrp[i].equipesQualifiees()[1].getEquip());
				GestEqp.equipe[e].Eqpqualifie();
			}

			int arbitre  = rand()%GestArbt.Varbtr.size() +0;
			int terrain  = rand()%GestTrn.VectTerrain.size() +0;
			Match m(GestArbt.Varbtr[arbitre],GestTrn.VectTerrain[terrain],Gestgrp.VectGrp[0].equipesQualifiees()[0],Gestgrp.VectGrp[1].equipesQualifiees()[1]);
			m.settype("Quart de final");
			GestMtch.VectMatch.push_back(m);

			int arbitre1  = rand()%GestArbt.Varbtr.size() +0;
			int terrain1  = rand()%GestTrn.VectTerrain.size() +0;
			Match m0(GestArbt.Varbtr[arbitre1],GestTrn.VectTerrain[terrain1],Gestgrp.VectGrp[0].equipesQualifiees()[1],Gestgrp.VectGrp[1].equipesQualifiees()[0]);
			m0.settype("Quart de final");
			GestMtch.VectMatch.push_back(m0);

			int arbitre2  = rand()%GestArbt.Varbtr.size() +0;
			int terrain2  = rand()%GestTrn.VectTerrain.size() +0;
			Match m1(GestArbt.Varbtr[arbitre2],GestTrn.VectTerrain[terrain2],Gestgrp.VectGrp[2].equipesQualifiees()[0],Gestgrp.VectGrp[3].equipesQualifiees()[1]);
			m1.settype("Quart de final");
			GestMtch.VectMatch.push_back(m1);

			int arbitre3  = rand()%GestArbt.Varbtr.size() +0;
			int terrain3  = rand()%GestTrn.VectTerrain.size() +0;
			Match m2(GestArbt.Varbtr[arbitre3],GestTrn.VectTerrain[terrain3],Gestgrp.VectGrp[2].equipesQualifiees()[1],Gestgrp.VectGrp[3].equipesQualifiees()[0]);
			m2.settype("Quart de final");
			GestMtch.VectMatch.push_back(m2);

			GestEqp.setquialifiation();
		}
		else if(GestMtch.VectMatch.size()==44 & b==1 )//Demi_final
		{
			vector<int> indicequialifie;
			//equipe qualifi du quart
			for(int i=0;i<GestMtch.VectMatch.size();i++)
			{
				if(GestMtch.VectMatch[i].getTypeM() == "Quart de final")
				{
					int e =existeTinvector(GestEqp.equipe,*GestMtch.VectMatch[i].equipegagnat());
					GestEqp.equipe[e].Eqpqualifie();
					if(e!=-1)
						indicequialifie.push_back(e);
				}
			}
			
			int arbitre  = rand()%GestArbt.Varbtr.size() +0;
			int terrain  = rand()%GestTrn.VectTerrain.size() +0;
			Match m(GestArbt.Varbtr[arbitre],GestTrn.VectTerrain[terrain],GestEqp.equipe[indicequialifie[0]],GestEqp.equipe[indicequialifie[1]]);
			m.settype("Demi final");
			GestMtch.VectMatch.push_back(m);

			int arbitre1  = rand()%GestArbt.Varbtr.size() +0;
			int terrain1  = rand()%GestTrn.VectTerrain.size() +0;
			Match m1(GestArbt.Varbtr[arbitre1],GestTrn.VectTerrain[terrain1],GestEqp.equipe[indicequialifie[2]],GestEqp.equipe[indicequialifie[3]]);
			m1.settype("Demi final");
			GestMtch.VectMatch.push_back(m1);

			GestEqp.setquialifiation();
		}
		else if(GestMtch.VectMatch.size()==46 & b==1)//Final
		{
			vector<int> indicequialifie;
			for(int i=0;i<GestMtch.VectMatch.size();i++)
			{
				if(GestMtch.VectMatch[i].getTypeM() == "Demi final")
				{
					int e =existeTinvector(GestEqp.equipe,*GestMtch.VectMatch[i].equipegagnat());
					GestEqp.equipe[e].Eqpqualifie();
					if(e!=-1)
						indicequialifie.push_back(e);
				}
			}
			
			int arbitre  = rand()%GestArbt.Varbtr.size() +0;
			Match m(GestArbt.Varbtr[arbitre],GestTrn.terrainfinal(),GestEqp.equipe[indicequialifie[0]],GestEqp.equipe[indicequialifie[1]]);
			m.settype("Final");
			GestMtch.VectMatch.push_back(m);

			GestEqp.setquialifiation();
		}
		else if(GestMtch.VectMatch.size()==47 & b==1)//vainqueur
		{
			int e;
			for(int i=0;i<GestMtch.VectMatch.size();i++)
			{
				if(GestMtch.VectMatch[i].getTypeM() == "Final")
				{
					e =existeTinvector(GestEqp.equipe,*GestMtch.VectMatch[i].equipegagnat());
					GestEqp.equipe[e].Eqpqualifie();
					vainqueur=GestEqp.equipe[e];
				}
			}
			cout<<" - Le vainqueur de cette tournoi :"<<endl;
			vainqueur.affciheEquipe();
		}
		
	}
	void majmatchtournoi(int id){
		for(int i=0;i<GestMtch.VectMatch.size();i++)
			if(GestMtch.VectMatch[i].getId() == id)
				GestMtch.VectMatch[i].majmatch();
	}
	void affichematch(int id){
		for(int i=0;i<GestMtch.VectMatch.size();i++)
			if(GestMtch.VectMatch[i].getId() == id)
			GestMtch.VectMatch[i].afficheMatch();
	}
	void afficheavantmatch(){
		GestMtch.affichernextmatches();
	}
	void affichermatchdequipe(int id){
		for(Match m:GestMtch.VectMatch)
		m.affichematchdequipe(id);
	}
	void majmatchtournoialt(){
		for(int i=0;i<GestMtch.VectMatch.size();i++)
		{
			GestMtch.VectMatch[i].majmatchalt();
			if(GestMtch.VectMatch[i].getTypeM()=="Phase de group" and GestMtch.VectMatch.size()<=40)
			Gestgrp.modifierclassementgrp(GestMtch.VectMatch[i]);
		}
	}
	void afficherlesgroup(){
		Gestgrp.affichelesgroup();
	}
	int getId(){return ID;}
	int getnbrmatch(){return GestMtch.VectMatch.size();}
	Terrain* getTerrain(int idmatch){
		for(int i=0;i<GestMtch.VectMatch.size();i++)
		if(GestMtch.VectMatch[i].getId() == idmatch)
		return GestMtch.VectMatch[i].getterrain();
		

		return nullptr;
	}
	void afficherlesbillet(){
		for(Match m:GestMtch.VectMatch)
		m.afficherticket();
	}
};
int Tournoi::idtr = 1000;

class Gestion_des_tournois{
public:
	vector<Tournoi> tournoi;
	Gestion_des_tournois(){}
	void ajoutertrournoi(Tournoi tr){
		tournoi.push_back(tr);
	}
	void afficherlestournoi(){
		for (int i = 0; i < tournoi.size(); i++)
		{
			tournoi[i].affcicheinfotournoi();
		}
		
	}
	int getindicetrnoi(int id){
		for(int i=0;i<tournoi.size();i++)
		if(tournoi[i].getId()==id)
			return i ;
		
		return -1;
	}

};

template <typename T>
int existeTinvector(vector<T> a, T b) {
    for(int i=0;i<a.size();i++)
    if(a[i].getId() == b.getId())
        return i ;
    return -1;
}

bool trivect( Equipe_pnts& e1, Equipe_pnts& e2)
{
	return e1.getPnts()>e2.getPnts();
}
