/*
Nome: Marvin Contessi
Classe: 4 inf A
Data di assegnazione: 17/12/13
Data di consegna: 07/01/2014
Caricamento su GitHub: 09/04/2014

Testo:
Sviluppare in C++ una classe orologio con data con tutte le funzioni necessarie. 
Prevedere anche una funzione membro TicTac, che ogni volta che viene richiamata incrementa di 1 i secondi.
Sviluppare un main che utilizza un'oggetto di tipo orologio e gestisce le funzioni:
- setTime()
- getTime()

Il tutto correlato con il diagramma UML delle classi

Diagramma UML:

Nome classe:    orologio
Attributi:		int ore
				int minuti
				int secondi
				int giorni
				int mesi
				int anni

Metodi:			setTime();
				getTime();
				resetTime();
				getDate();
				setDate();
				TicTac();


Nome classe:	sveglia
Attributi:		int hs
				int mins
				int secs
				int attiva
				int suono

Metodi:			setSveglia();
				getSveglia();
				setAttiva();
				TicTac();
*/

/* Includo le librerie necessarie */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

/* Definisco la classe */
class Orologio {

	/* Attributi classe */
	protected:

		/* ORA */
		int h; 		/* Ore */
		int min; 	/* Minuti */
		int sec; 	/* Secondi */

		/* DATA */
		int day; 	/* Giorno */
		int month; 	/* Mese */
		int year; 	/* Anno */

	/* Metodi classe */
	public:

		/* Funzioni per il settaggio del Tempo */
		int setTime(int o, int m, int s); /* Input del tempo */
		int getTime(int *o, int *m, int *s); /* Output del tempo */
		int resetTime(); /* Azzeramento del tempo */

		/* Funzione TicTac */
		int TicTac(); /* Incrementa di 1 i secondi quando richiamata */

		/* Funzioni per il settaggio della data */
		int setDate(int g, int m, int a); /* Input della data */
		int getDate(int *g, int *m, int *a); /* Output della data */

};

/* Classe ereditata per la sveglia */
class Sveglia:public Orologio {

	/* Attributi della classe */
	private:

		/* ORA */
		int hs; /* Ore */
		int mins; /* Minuti */
		int secs; /* Secondi */

		/* SVEGLIA */
		int attiva; /* Sveglia attiva */
		int suono; /* Suono della sveglia */

	/* Metodi della classe */
	public:

		int setSveglia(int os, int ms, int ss); /* Input del tempo */
		int getSveglia(int *os, int *ms, int *ss); /* Output del tempo */
		int setAttiva(int att); /* Attivazione della sveglia */
		int TicTac(); /* TicTac della sveglia */

};

/* Prototipi delle funzioni */
void pulizia();

/* Main */
int main(void)
{
	Sveglia sv; /* Dichiaro l'oggetto */

	/* flag vari */
	int flag = 0; /* flag menu */
	int flags = 0; /* flag sveglia */
	int orf = 0; /* flag ora */
	int daf = 0; /* flag data */

	/* Variabili per l'input/output dei valori dell'orologio */
	int ora = 13; 
	int minuti = 37;
	int secondi = 0;

	int sveglia = 0;
	int atv = 0;

	int giorno = 27;
	int mese = 11;
	int anno = 2010;

	/* Scelta del menu */
	int scelta = 0;
	char sceltac[32];

	/* menu */
	do
	{
		do
		{
			/* stampo le opzioni del menu */
			pulizia();
			cout << "************** OROLOGIO **************" << endl;
			cout << "*                                    *" << endl;
			cout << "*  1- Imposta ora                    *" << endl;
			cout << "*  2- Leggi ora                      *" << endl;
			cout << "*  3- Azzera ora                     *" << endl;
			cout << "*  4- Incrementa ora                 *" << endl;
			cout << "*                                    *" << endl;
			cout << "*  5- Imposta data                   *" << endl;
			cout << "*  6- Leggi data                     *" << endl;
			cout << "*                                    *" << endl;
			cout << "*  7- Imposta sveglia                *" << endl;
			cout << "*  8- Stampa ora sveglia             *" << endl;
			cout << "*  9- On / Off Sveglia               *" << endl;
			cout << "*                                    *" << endl;
			cout << "*  0- Esci                           *" << endl;
			cout << "*                                    *" << endl;
			cout << "**************************************" << endl;
			cout << endl << "Inserire scelta: ";
            cin >> sceltac;
            cout << endl;
            if( strlen(sceltac) > 0) scelta = atoi(sceltac);
            else scelta = -1;
		} while ( (scelta < 0 ) || (scelta > 9) );

		/* esamino le varie opzioni */
		switch ( scelta )
		{
			case 1:
			{
				/* imposta ora */
				cout << "Inserire ora, minuti e secondi separati da uno spazio." << endl;
				cout << "e.g. 13 37 00" << endl << endl;
				/* prendo in input l'ora */
				cin >> ora >> minuti >> secondi;
				flag = sv.setTime(ora,minuti,secondi);
				/* controllo il valore di ritorno */
				if ( flag )
				{
					cout << "Ora impostata correttamente!" << endl;
					getchar();
					getchar();
					/* setto il flag */
					orf = 1;
				}
				else
				{
					cout << "Errore. Riprovare di nuovo." << endl;
					getchar();
					getchar();
				}
				break;
			}

			case 2:
			{
				/* leggi ora */
				flag = sv.getTime(&ora,&minuti,&secondi);
				/* controllo il valore di ritorno */
				if ( flag && orf )
				{
					/* Stampo l'ora */
					cout << "Ora letta correttamente!" << endl;
					cout << "Sono le " << ora << ":" << minuti << ":" << secondi << endl;
					getchar();
					getchar();
				}
				else
				{
					/* Stampo l'errore */
					cout << "Errore. Riprovare di nuovo oppure inserire prima un orario." << endl;
					getchar();
					getchar();
				}
				break;
			}
			
			case 3:
			{
				/* reset ora */
				flag = sv.resetTime();
				/* controllo il valore di ritorno */
				if ( flag )
				{
					cout << "Ora azzerata correttamente!" << endl;
					getchar();
					getchar();
				}
				else
				{
					cout << "Errore. Riprovare di nuovo." << endl;
					getchar();
					getchar();
				}
				break;
			}
			
			case 4:
			{
				/* incrementa ora */
				atv= sv.TicTac();
				/* controllo il valore di ritorno */
				if ( atv )
				{
					cout << "DRIIIIIN DRIIIIIIN DRIIIIIIN" << endl;
					getchar();
					getchar();
				}
				break;
			}
			
			case 5:
			{
				/* imposta data */
				cout << "Inserire giorno, mese e anno separati da uno spazio." << endl;
				cout << "e.g. 12 11 2010" << endl << endl;
				/* prendo in input la data */
				cin >> giorno >> mese >> anno;
				flag = sv.setDate(giorno,mese,anno);
				/* controllo il valore di ritorno */
				if ( flag )
				{
					cout << "Data impostata correttamente!" << endl;
					getchar();
					getchar();
					daf = 1;
				}
				else
				{
					cout << "Errore. Riprovare di nuovo." << endl;
					getchar();
					getchar();
				}
				break;
			}
			
			case 6:
			{
				/* leggi data */
				flag = sv.getDate(&giorno,&mese,&anno);
				/* controllo il valore di ritorno */
				if ( flag && daf )
				{
					cout << "Data letta correttamente!" << endl;
					cout << "È il " << giorno << "/" << mese << "/" << anno << endl;
					getchar();
					getchar();
				}
				else
				{
					cout << "Errore. Riprovare di nuovo oppure inserire prima una data." << endl;
					getchar();
					getchar();
				}
				break;
			}

			case 7:
			{
				/* imposta ora */
				cout << "Inserire ora, minuti e secondi separati da uno spazio." << endl;
				cout << "e.g. 13 37 00" << endl << endl;
				/* prendo in input l'ora */
				cin >> ora >> minuti >> secondi;
				flag = sv.setSveglia(ora,minuti,secondi);
				/* controllo il valore di ritorno */
				if ( flag )
				{
					cout << "Sveglia impostata correttamente!" << endl;
					getchar();
					getchar();
					/* setto il flag */
					flags = 1;
				}
				else
				{
					cout << "Errore. Riprovare di nuovo." << endl;
					getchar();
					getchar();
				}
				break;
			}

			case 8:
			{
				/* leggi ora sveglia */
				flag = sv.getSveglia(&ora,&minuti,&secondi);
				/* controllo il valore di ritorno */
				if ( flag && flags )
				{
					cout << "Ora letta correttamente!" << endl;
					cout << "Sono le " << ora << ":" << minuti << ":" << secondi << endl;
					getchar();
					getchar();
				}
				else
				{
					cout << "Errore. Riprovare di nuovo oppure inserire prima un orario." << endl;
					getchar();
					getchar();
				}
				break;
			}

			case 9:
			{
				if ( flags )
				{
					cout << "Inserire 1 per attivare la sveglia, 0 per disattivarla. " << endl;
					cin >> sveglia;
					sv.setAttiva(sveglia);
				}
				else 
				{
					cout << "Errore! Sveglia non impostata!" << endl;
					getchar();
					getchar();
				}
				break;
			}
		}

	} while ( scelta != 0 );
	return(0);
}




/* ================================= METODI DELL'OROLOGIO ================================ */


/* Sviluppo la funzione membro setTime */
int Orologio::setTime(int o, int m, int s)
{
	int f = 0; /* flag per il corretto inserimento */
	if(( o >= 0) || ( o < 24 )) /* Se l'ora èn'ora accettabile */
	{
		h = o; /* La aggiorna */
		f++; /* E incrementa il flag */
	}
	if(( m >= 0 ) || ( m < 59 )) /* Se il numero di minuti èn numero accettabile */
	{
		min = m; /* Aggiorno i minuti */
		f++; /* E incremento il flag */
	}
	if(( s >= 0 ) || ( s < 59 )) /* Se il numero dei secondi èn numero accettabile */
	{
		sec = s; /* Aggiorno i secondi */
		f++; /* E incremento il flag */
	}
	if ( f != 3) /* Se uno dei valori presi precedentemente non èccettabile */
	{
		return(-1); /* Ritorno un numero negativo */
	}
	return(1); /* Altrimenti ritorno 1 per indicare il corretto funzionamento */
}

/* Sviluppo la funzione getTime */
int Orologio::getTime(int *o, int *m, int *s)
{
	*o = h; /* Prendo le ore */
	*m = min; /* I minuti */
	*s = sec; /* E i secondi */
	return(1); /* Ritorno 1 per indicare il corretto funzionamento */
}

/* Sviluppo la funzione resetTime */
int Orologio::resetTime()
{
	h = 0; /* Azzero le ore */
	min = 0; /* I minuti */
	sec = 0; /* E i secondi */
	return(1); /* Ritorno 1 per indicare il corretto funzionamento */
}

/* Sviluppo la funzione TicTac */
int Orologio::TicTac()
{
	if( sec < 59 )
	{
		sec++; /* Incremento i secondi di uno */
	}
	else if ( min < 59 )
	{
		sec = 0; /* Azzero i secondi e incremento i minuti */
		min++;
	}
	else if ( h < 23 )
	{
		sec = 0; /* Azzero i secondi e i minuti e incremento le ore */
		min = 0;
		h++;
	}
	else
	{
		sec = 0; /* Azzero tutto */
		min = 0;
		h = 1;
	}
	return(1); /* Ritorno 1 per indicare il corretto funzionamento */
}

/* Sviluppo la funzione setDate */
int Orologio::setDate( int g, int m, int a )
{
	int f = 0; /* flag per il corretto inserimento */
	int mesi[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	 /* Array per il controllo dei mesi dell'anno */
	if (( m > 0) || (m < 13 )) /* Se il mese èccettabile */
	{
		month = m; /* Allora lo aggiorno */
		f++; /* E incremento il flag */
	}
	if ( g <= mesi[month + 1] ) /* Se il numero dei giorni è accettabile */
	{
		day = g; /* Allora li aggiorno */
		f++; /* E incremento il flag */
	}
	if ((a > 1900) || (a < 2030)) /* Se il numero degli anni è accettabile */
	{
		year = a; /* Allora lo aggiorno */
		f++; /* E incremento il flag */
	}
	if ( f != 3) /* Se uno dei valori presi precedentemente non è accettabile */
	{
		return(-1); /* Ritorno un numero negativo */
	}
	return(1); /* Altrimenti ritorno 1 per indicare il corretto funzionamento */
}

/* Sviluppo la funzione getDate */
int Orologio::getDate(int *g, int *m, int *a)
{
	*g = day; /* Prendo i giorni */
	*m = month; /* I mesi */
	*a = year; /* E gli anni */
	return(1); /* Ritorno 1 per indicare il corretto funzionamento */
}




/* ================================= METODI DELLA SVEGLIA ================================ */

/* Sviluppo la funzione setSveglia */
int Sveglia::setSveglia(int os, int ms, int ss)
{
	int fs = 0; /* flag per il corretto inserimento */
	if(( os >= 0) || ( os < 24 )) /* Se l'ora è un'ora accettabile */
	{
		hs = os; /* La aggiorna */
		fs++; /* E incrementa il flag */
	}
	if(( ms >= 0 ) || ( ms < 59 )) /* Se il numero di minuti è un numero accettabile */
	{
		mins = ms; /* Aggiorno i minuti */
		fs++; /* E incremento il flag */
	}
	if(( ss >= 0 ) || ( ss < 59 )) /* Se il numero dei secondi è un numero accettabile */
	{
		secs = ss; /* Aggiorno i secondi */
		fs++; /* E incremento il flag */
	}
	if ( fs != 3) /* Se uno dei valori presi precedentemente non è accettabile */
	{
		return(-1); /* Ritorno un numero negativo */
	}
	return(1); /* Altrimenti ritorno 1 per indicare il corretto funzionamento */

}

/* Sviluppo la funzione getSveglia */
int Sveglia::getSveglia(int *os, int *ms, int *ss)
{
	*os = hs; /* Prendo le ore */
	*ms = mins; /* I minuti */
	*ss = secs; /* E i secondi */
	return(1); /* Ritorno 1 per indicare il corretto funzionamento */
}

/* Sviluppo la funzione setAttiva */
int Sveglia::setAttiva(int att)
{
	if ( att == 1 ) /* Verifico se il valore inserito è valido */
	{
		attiva = 1; /* Setto il flag a 1 */
	}
	else /* Altrimenti */
	{
		attiva = 0; /* Setto il flag a 0 */
	}
	return(1); /* Ritorno 1 per indicare il corretto funzionamento */
}

/* Sviluppo la funzione per il TicTac e quindi il suono della sveglia */
int Sveglia::TicTac()
{
	Orologio::TicTac(); /* Eseguo la funzione TicTac della classe orologio */
	if ((sec == secs) && (min == mins) && (h == hs) && (attiva == 1))
	/* Controllo che i minuti, i secondi, le ore, e il flag corrispondano tra le due classi */
	{
		suono = 1; /* Pongo il flag del suono uguale a 1 */
	}
	else
	{
		suono = 0; /* Altrimenti lo pongo uguale a 0 */
	}
	return(suono); /* Ritorno il flag del suono */
}


/* =========================== Sviluppo le funzioni ============================ */

void pulizia()
{
	cout << "\e[2J\e[H" << endl;
}
