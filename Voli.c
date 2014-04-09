/*
Nome: Marvin
Cognome: Contessi
Classe: 4° Inf A
Data: 9/10/13
Richiesta:
ANSI C SUL SERVER
Si scriva un programma che crei un file volixx il cui record è così strutturato:
Struct{
    char[5] cod; Codice di volo
    char[20] des; Descrizione del volo
    int nump; Numero totale dei posti
    int po; Numero dei posti occupati
    int flag; flag validità
}


Gestione voli AIRMONTANI
1) Inserimento nuovo volo
2) Stampa VOLO (richiesta codice [e descrizione], stampa volo)
3) Stampa tutti i voli
*/
#ifdef WIN32                                /* Se viene usato un sistema windows */
#define CLEAR() (system("cls"))             /* Allora CLEAR() richiama system("cls") */
#else                                       /* Altrimenti */
#define CLEAR() (printf("\e[2J\e[H"))       /*CLEAR() richiama printf( "\e[2J\e[H" )*/
#endif
/* printf( "\e[2J\e[H" ) è un'alternativa al system("cls") da utilizzare in ambienti A.N.S.I.*/
                                 /* Includo le librerie necessarie */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

/* Definisco la struct per il volo */

typedef struct _Volo
{
    char cod[5]; /* Codice del volo */
    char des[20]; /* Descrizione del volo */
    int nump; /* Numero totale dei posti */
    int po; /* Numero dei posti occupati */
} volo;

/* Definisco i prototipi delle funzioni */

int Inserimento(void);
int Ricerca(char cod[5]);
int StampaV(void);
int Prenotazione(void);
int Stampa();
void pulizia();


/* Main */

int main(void)
{
    int scelta = 0; /* Scelta del menu */
    char sceltac[32];
    int flag = 0; /* flag inserimento */
    int fp = 0;

    /* Controllo sull'esistenza del file */
    fp = open("voli05.bin", O_RDWR);
    if( fp < 0 )
    {
        /* Se non dovesse esistere chiedo se crearlo */
        printf("Il file non esiste. Crearlo? [1/0]\n");
        scanf("%s",sceltac);
        scelta = atoi(sceltac);
        close(fp);
        if( scelta == 0 )
        {
            return(-1);
        }
        else
        {
            fp = creat("voli05.bin", 0666);
            close(fp);
        }
    }
    /*
         _________________________          _____
        |                         \          \ U \__      _____
        |   AIR      MONTANI       \__________\   \/_______\___\_____________
        |                          /          < /_/   .....................  `-.
        |_________________________/            `-----------,----,--------------'
                                                         _/____/
    */

    do
    {
        do
        {
            /* Stampo le opzioni del menu */
            pulizia();
            printf("################ GESTIONE VOLI ################\n");
            printf("#                                             #\n");
            printf("#        (1) Inserimento volo                 #\n");
            printf("#        (2) Stampa Volo                      #\n");
            printf("#        (3) Stampa tutti i voli              #\n");
            printf("#        (4) Prenotazione posti               #\n");
            printf("#                                             #\n");
            printf("#        (0) Esci                             #\n");
            printf("#                                             #\n");
            printf("###############################################\n");
            printf("\nInserire scelta: ");
            scanf("%s",&sceltac); /* Prendo in input la scelta */
            printf("\n");
            if( strlen(sceltac) > 0) scelta = atoi(sceltac);
            else scelta=-1;
        }while((scelta < 0) || (scelta > 4));

        switch( scelta )
        {
            case 1:
            {
                /* Inserimento */
                Inserimento();
                flag = 1;
                break;
            }
            case 2:
            {
                /* Stampa volo */
                if( flag == 1 )
                {
                    StampaV();
                }
                else
                {
                    printf("Errore!\n");
                }
                getchar();
                break;
            }
            case 3:
            {
                /* Stampa voli */
                if( flag == 1 )
                {
                    Stampa();
                }
                else
                {
                    printf("Errore!\n");
                }
                getchar();
                break;
            }
            case 4:
            {
                /* Prenotazione voli */
                    Prenotazione();
                getchar();
                break;
            }
        }
    }while( scelta != 0);
}

int Inserimento(void)
{
    /* Funzione per l'inserimento */
    int fp = 0;
    volo buff;
    char numpc[32];
    char poc[32];
    int rip = 1;
    char ripc[32];
    fp = open("voli05.bin", O_WRONLY);
    if ( fp == -1 ) { printf ("Errore!\n"); return(-1); }
    while( rip == 1 )
    {
        printf("Inserire codice volo: ");
        scanf("%s",&buff.cod); /* Prendo il codice */
        printf("\nInserire descrizione: ");
        scanf("%s",&buff.des); /* Prendo la descrizione */
        printf("\nInserire posti totali: ");
        scanf("%s",&numpc);
        buff.nump = atoi(numpc);
        printf("\nInserire posti occupati: ");
        scanf("%s",&poc);
        buff.po = atoi(poc);

        write(fp, &buff, sizeof(volo)); /* Stampo la struct sul file */
        pulizia();
        printf("Inserire un altro volo? [1 = si] \n");
        scanf("%s",&ripc);
        rip = atoi(ripc);
    }
    close(fp);
    return(1);
}

int Ricerca(char cod[5])
{
    /* Funzione per la ricerca */
    volo buff;
    int pos = 0;
    int fp = 0;
    int n = 0;
    fp = open("voli05.bin", O_RDONLY);
    if ( fp == -1 ) { printf ("Errore!\n"); return(-1); }
    n = read(fp, &buff, sizeof(volo));
    while(n != 0)
    {
        pos = pos + 1;
        if( strcmp(cod, buff.cod) == 0 )
        {
            close(fp);
            return(pos);
        }
        n = read(fp, &buff, sizeof(volo));
    }
    close(fp);
    return(-1);
}

int StampaV()
{
    /* Funzione per la stampa di un volo */
    volo buff;
    char codc[5];
    int pos = 0;
    int fp = 0;
    fp = open("voli05.bin", O_RDONLY);
    if ( fp == -1 ) { printf ("Errore!\n"); return(-1); }
    printf("Inserire il codice del volo da stampare: ");
    scanf("%s", codc);
    pos = Ricerca(codc);
    if( pos > -1 )
    {
        pos = pos - 1;
    }
    else
    {
        printf("Errore: Volo non trovato!\n");
        close(fp);
        return(-1);
    }
    lseek(fp, sizeof(volo)*pos, SEEK_SET);
    read(fp, &buff, sizeof(volo));
    printf("\nCodice Volo: %s", buff.cod);
    printf("\nDescrizione: %s", buff.des);
    printf("\nPosti totali: %d", buff.nump);
    printf("\nPosti occupati: %d", buff.po);
    getchar();
    close(fp);
}

int Stampa(void)
{
    /* Funzione per la stampa di tutti i voli */
    volo buff;
    int fp = 0;
    int spazi = 0;
    int spazicod = 16;
    int spazides = 20;
    int spazipos = 16;
    int i = 0;
    int num = 1;
    int n = 0;
    fp = open("voli05.bin", O_RDONLY);
    if ( fp == -1 ) { printf ("Errore!\n"); return(-1); }
    fflush(stdin);
    fflush(stdout);
    printf("Codice\t\tDescrizione\tPosti Tot.\tPosti Occ.");
    fflush(stdin);
    fflush(stdout);
    printf("\n");
    while( (n = read(fp, &buff, sizeof(volo))) > 0)
    {
        printf("%s", buff.cod);
        spazi = spazicod - strlen(buff.cod);
        for( i = 0; i < spazi; i++ )
        {
            printf(" ");
        }
        printf("%s", buff.des);
        spazi = spazides - strlen(buff.des);
        for( i = 0; i < spazi; i++ )
        {
            printf(" ");
        }
        printf("%d", buff.nump);
        num = buff.nump;
        i = snprintf(NULL, 0, "%d", num);
        /*while(num > 0)
        {
            i++;
            num = num / 10;
        }*/
        spazi = spazipos - i;
        for( i = 0; i < spazi; i++ )
        {
            printf(" ");
        }
        printf("%d\n", buff.po);
    }
    getchar();
    close(fp);
    return(1);
}

void pulizia()
{
     CLEAR();
     fflush(stdin);
     fflush(stdin);
     fflush(stdout);
}

int Prenotazione(void)
{
    /* Funzione per la prenotazione dei posti */
    /* Blocco il file mentre modifico le struct */
    int block = 0;
    char codr[5];
    int pos = 0;
    int fp = 0;
    int posti = 0;
    volo buff;

    fp = open("voli05.bin", O_RDWR);
    if ( fp == -1 ) { printf ("Errore!\n"); return(-1); }

    printf("Inserire il codice del volo: ");
    scanf("%s",&codr);
    pos = Ricerca(codr);
    if( pos > -1 )
    {
        pos = pos - 1;
    }
    else
    {
        printf("Errore: Volo non trovato!\n");
        getchar();
        close(fp);
        return(-1);
    }
    block = lockf(fp, F_TEST, sizeof(volo));
    if ( block == -1 )
    {
        printf("\nFile bloccato. Riprovare più tardi.");
        getchar();
        close(fp);
        return(-1);
    }
    else if( block == 0 )
    {
        /* Blocca */
        lockf(fp, F_LOCK, sizeof(volo));

        /* Modifica posti */
        lseek(fp, sizeof(volo)*pos, SEEK_SET);
        read(fp, &buff, sizeof(volo));
        printf("\nInserire i posti da occupare: ");
        scanf("%d",&posti);

        /* Controllo posti */
        if ( ( posti + buff.po ) > buff.nump )
        {
            printf("\nErrore: Troppi posti occupati.");
            getchar();
            close(fp);
            return(-1);
        }
        else
        {
            /* Write */
            buff.po += posti;
            lseek(fp, sizeof(volo)*pos, SEEK_SET);
            write(fp, &buff, sizeof(volo));
            printf("\nPrenotazione avvenuta con successo.");
            getchar();
        }

        /* Sblocca */
        lockf(fp,F_ULOCK, sizeof(volo));
        close(fp);
        return(1);
    }
    else
    {
        printf(" ERROR \n");
    }
    

}

