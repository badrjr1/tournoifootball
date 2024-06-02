#include"codeDfinal.cpp"
int main(){
    int a ,c, s;
    Equipe e1("FC Barcelona"), e2("Real Madrid"), e3("Bayern Munich"), e4("Manchester City"),
        e5("Liverpool"), e6("Paris Saint-Germain"), e7("Chelsea"), e8("Manchester United"),
        e9("Juventus"), e10("Atletico Madrid"), e11("Borussia Dortmund"), e12("Arsenal"),
        e13("Inter Milan"), e14("Tottenham Hotspur"), e15("AC Milan"), e16("Napoli"),
        e17("AS Roma"), e18("Leicester City"), e19("Ajax"), e20("Valencia"),
        e21("Sevilla"), e22("Everton"), e23("Benfica"), e24("Porto"),
        e25("Olympique Lyonnais"), e26("Villarreal"), e27("Wolverhampton Wanderers"),
        e28("Bayer Leverkusen"), e29("Lazio"), e30("RB Leipzig"),
        e31("Olympique de Marseille"), e32("Zenit Saint Petersburg");
    Arbitre a1("John Smith"), a2("Emily Johnson"), a3("Michael Brown"), a4("Sarah Davis"),
        a5("David Wilson"), a6("Jennifer Martinez"), a7("Robert Anderson"), a8("Jessica Taylor");
    Terrain t1("Camp Nou", 99354, "Carrer d'Aristides Maillol, 08028 Barcelona, Espagne"),
        t2("Old Trafford", 74879, "Sir Matt Busby Way, Stretford, Manchester M16 0RA, Royaume-Uni"),
        t3("Santiago Bernabéu", 81044, "Av. de Concha Espina, 1, 28036 Madrid, Espagne"),
        t4("Allianz Arena", 75000, "Werner-Heisenberg-Allee 25, 80939 München, Allemagne");
    vector <Equipe> equip ;
    vector <Arbitre> abrbt;
    vector <Terrain> trn ;
    // ajouter les arbitres
    abrbt.push_back(a1);
    abrbt.push_back(a2);
    abrbt.push_back(a3);
    abrbt.push_back(a4);
    abrbt.push_back(a5);
    abrbt.push_back(a6);
    abrbt.push_back(a7);
    abrbt.push_back(a8);
    // ajouter les equipes
    equip.push_back(e1);
    equip.push_back(e2);
    equip.push_back(e3);
    equip.push_back(e4);
    equip.push_back(e5);
    equip.push_back(e6);
    equip.push_back(e7);
    equip.push_back(e8);
    equip.push_back(e9);
    equip.push_back(e10);
    equip.push_back(e11);
    equip.push_back(e12);
    equip.push_back(e13);
    equip.push_back(e14);
    equip.push_back(e15);
    equip.push_back(e16);
    equip.push_back(e17);
    equip.push_back(e18);
    equip.push_back(e19);
    equip.push_back(e20);
    equip.push_back(e21);
    equip.push_back(e22);
    equip.push_back(e23);
    equip.push_back(e24);
    equip.push_back(e25);
    equip.push_back(e26);
    equip.push_back(e27);
    equip.push_back(e28);
    equip.push_back(e29);
    equip.push_back(e30);
    equip.push_back(e31);
    equip.push_back(e32);
    // ajouter les terrains
    trn.push_back(t1);
    trn.push_back(t2);
    trn.push_back(t3);
    trn.push_back(t4);
    
    Gestion_darbitre GSarbtr(abrbt);
    Gestion_de_terrain GStrn(trn);
    Gestion_dequipe GSeqp(equip);
    Gestion_des_tournois GStournoi ;
    Gestion_de_spectateur GSspct;
    
    

    do{
        //menu principlae
		cout << " Tapez 1 pour la partie service "<< endl ;
		cout << " Tapez 2 pour la partie client "<< endl ;
		cout << " Tapez 0 pour quitter "<< endl ;
		cout<<endl<<"  Entre un chiffre : ";
		cin >> a ;
		system("cls");
        switch (a)
        {
        case 1: // partie service
            do
            {
                // ajouter equipe , ajouter terrain , ajouter arbitre
                cout<<"1- Cree tournoi"<<endl;
                cout<<"2- Selectionner une tournoi"<<endl;
                cout<<"3- Modifier une equipe"<<endl;
                cout<<"4- Modifier un terrain"<<endl;
                cout<<"5- Modifier un arbitre"<<endl;
                cout<<"6- Afficher les spectateur"<<endl;
                cout<<"0- Pour retourner au menu principale "<< endl ;
                Tournoi tr ;
                cout<<endl<<"  Entre un chiffre : ";
                cin>> s ;
                system("cls");
                switch(s)
                {
                case 1: //cree tournoi
                    tr.creetournoi(GSeqp,GSarbtr,GStrn);
                    tr.gerematch();
                    GStournoi.ajoutertrournoi(tr);
                    cout<<" tournoi cree avec succes"<<endl;
                    break;
                case 2: //select tournoi
                    {
                        int gst ;
                        int id ;
                            GStournoi.afficherlestournoi();
                            cout<<"entre l'ID du tournoi: ";
                            cin>>id;
                        do{
                            int idmatch;
                            int i=GStournoi.getindicetrnoi(id);
                            cout<<"1- Afficher les informations du tournoi; "<<endl;
                            cout<<"2- Afficher les matches du tournoi; "<<endl;
                            cout<<"3- Afficher les matches du tournoi avec resulatat; "<<endl;
                            cout<<"4- Mettre a jour les matches en cours;"<<endl;
                            cout<<"5- Mettre a jour les matches en cours aleatoirement ;"<<endl;
                            cout<<"6- Afficher les groupes ;"<<endl;
                            cout<<"7- Chercher un match"<<endl;
                            cout<<"8- Le vainqueur"<<endl;
                            cout<<"0-  Pour retourner au menu d'avant "<< endl ;
                            
                            cout<<" Entre un chiffre: ";
                            cin>>gst;
                            switch(gst)
                            {
                                case 1 : //Afficher les informations du tournoi
                                    GStournoi.tournoi[i].affichertournoir();
                                    break;
                                case 2 : //Afficher les matches du tournoi
                                    GStournoi.tournoi[i].afficherinfoMacthtournoi();
                                    break;
                                case 3 : //Afficher les matches du tournoi avec resulatat
                                    GStournoi.tournoi[i].afficherMacthtournoi();
                                break;
                                case 4: //Mettre a jour les matches en cours
                                    GStournoi.tournoi[i].afficherinfoMacthtournoi();
                                    cout<<"entre l'ID du match: ";
                                    cin>>idmatch;
                                    GStournoi.tournoi[i].majmatchtournoi(idmatch);
                                    GStournoi.tournoi[i].gerematch();
                                    break;
                                case 5 ://Mettre a jour les matches en cours aleatoirement // ERROR
                                    GStournoi.tournoi[i].majmatchtournoialt();
                                    GStournoi.tournoi[i].gerematch(); // 2 eme if
                                    cout<<" 4 done ";
                                break;
                                case 6: // Afficher les groupes
                                    GStournoi.tournoi[i].afficherlesgroup();
                                break;
                                case 7 : // Chercher un match
                                    GStournoi.tournoi[i].afficherinfoMacthtournoi();
                                    cout<<"entre l'ID du match: ";
                                    cin>>idmatch;
                                    GStournoi.tournoi[i].affichematch(idmatch);
                                break;
                                /*case 8: // vainqueur
                                    GStournoi.tournoi[i].afficherlesbillet();
                                break;*/
                                case 0: 
                                break;
                                default: 
                                    cout<<" ****** entre un chiffre valide ******"<<endl;
                                    break;
                            }
                        }while(gst!=0);
                    break;
                    }
                case 3 : // MODOFIER UNE EQUIPE
                {    
                    GSeqp.afficherlesequipes();
                    cout<<" Entre l'ID d'equipe: ";
                    int ideqp ;
                    cin>>ideqp;
                    Equipe e(ideqp);
                    int i=existeTinvector(GSeqp.equipe,e);
                    GSeqp.equipe[i].modifiereqp();
                }
                break;
                case 4://Modifier un terrain
                {
                    GStrn.afficherterrainGT();
                    int idt ;
                    cout<<" Entre l'ID du terrain: ";
                    cin>>idt;
                    Terrain t(idt) ;
                    int e=existeTinvector(GStrn.VectTerrain,t);
                    if(e!=-1)
                    GStrn.VectTerrain[e].modifierterrain();
                    else
                    cout<<"********** id entre introuvable************"<<endl;
                }
                break;
                case 5://Modifier un arbitre
                {
                    GSarbtr.afficherlesarbitres();
                    int ida ;
                    cout<<" Entre l'ID arbitre: ";
                    cin>>ida;
                    Arbitre ab(ida);
                    int i=existeTinvector(GSarbtr.Varbtr,ab);
                    if(i!=-1)
                    GSarbtr.Varbtr[i].modifierarbitre();
                }
                break;
                case 6: // afficher les spectateur
                GSspct.affichespectateurGS();
                cout << " \t cliquer sur entrer " << endl ;
				getch();
                break;

                default:
                    cout<<" ****** entre un chiffre valide ******"<<endl;
                }
            } while (s!=0);
            
            break;
        case 2 : // partie client
            do
            {
                cout<<"1- Afficher une tournoi"<<endl;
                cout<<"2- S'inscrire"<<endl;
                cout<<"3- Acheter une ticket de match"<<endl;
                cout<<"4- Cherhcer un match"<<endl;
                cout<<"5- Chercher un equipe"<<endl;
                cout<<"0-  Pour retourner au menu principale "<< endl ;
                cout<<endl<<"  Entre un chiffre : ";
                cin>>c;
                switch (c)
                {
                case 1://Afficher une tournoi
                    {
                        int id ;
                        GStournoi.afficherlestournoi();
                        cout<<"entre l'ID du tournoi: ";
                        cin>>id;
                        int i =GStournoi.getindicetrnoi(id);
                        GStournoi.tournoi[i].afficherinfoMacthtournoi();
                        GStournoi.tournoi[i].afficherMacthtournoi();
                    }
                    break;
                case 2://s'inscrire
                {
                    Spectateur sp;
                    sp.sinscrire();
                    GSspct.ajouterunspectateur(sp);
                }
                break;
                case 3://Acheter une ticket de match
                {
                    for(Tournoi tr:GStournoi.tournoi)
                    if(tr.getnbrmatch()!=0)
                    {
                        cout<<" Entre votre id: ";
                        int ids;
                        cin>>ids;
                        int indice=GSspct.indicespect(ids);
                        for(Tournoi gst:GStournoi.tournoi)
                        gst.afficheavantmatch();
                        Terrain trn;
                        int id ;
                        cout<<" Entre l'ID du match: ";
                        cin>>id;
                        cout<<"done 1"<<endl;
                        for(int i=0;i<GStournoi.tournoi.size();i++)
                        {
                            if(GStournoi.tournoi[i].getTerrain(id) != nullptr)
                            {
                                
                                trn=*GStournoi.tournoi[i].getTerrain(id);
                                
                            }
                        }
                        cout<<"done 33"<<endl;
                        if(&trn!=nullptr)
                        GSspct.VectSpect[indice].achatTicket(trn);
                        else
                        cout<<"match introuvalbe"<<endl;
                    }
                    else 
                    cout<<"******** aucine match disponible ********"<<endl;
                }
                break;
                case 4://Cherhcer un match
                {
                    for(Tournoi tr:GStournoi.tournoi)
                    tr.afficherinfoMacthtournoi();

                    int id ;
                    cout<<" Entre l'ID du match: ";
                    cin>>id;

                    for(Tournoi tr:GStournoi.tournoi)
                    tr.affichematch(id);

                }
                break;
                case 5://Cherhcer une equipe
                {
                    GSeqp.afficherlesequipes();
                    int ide ;
                    cout<<" Entre l'ID de l'equipe: ";
                    cin>>ide;

                    for(Tournoi tr:GStournoi.tournoi)
                    tr.affichermatchdequipe(ide);
                }
                break;
                case 0:
                break;
                default:
                    cout<<" ****** entre un chiffre valide ******"<<endl;
                }
            } while (c!=0);
            
            break;

        default:
            cout<<" ****** entre un chiffre valide ******"<<endl;
            break;
        }
    }while(a!=0);
    
    return 0;
}
