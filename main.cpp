#include <iostream>

#include <vector>
#include <memory>

#include "Es1.h"
#include "Es2.h"
#include "Es3.h"
#include "Es4.h"

int main()
{
    int numeroEsercizio;

    std::cout << "Inserisci numero esercizio (1-4): ";
    std::cin >> numeroEsercizio;

    switch (numeroEsercizio)
    {

    // ==========================
    // ESERCIZIO 1
    // ==========================
    case 1:
    {
        std::vector<Veicolo*> veicoli;

        veicoli.push_back(new Auto());
        veicoli.push_back(new Bicicletta());
        veicoli.push_back(new Treno());

        for (Veicolo* v : veicoli)
        {
            std::cout << v->Descrizione() << std::endl;
            v->Muovi();
            std::cout << std::endl;
        }

        for (Veicolo* v : veicoli)
            delete v;

        break;
    }

    // ==========================
    // ESERCIZIO 2
    // ==========================
    case 2:
    {
        std::vector<Personaggio*> personaggi;

        personaggi.push_back(new Guerriero());
        personaggi.push_back(new Mago());
        personaggi.push_back(new Arciere());

        for (Personaggio* p : personaggi)
        {
            Turno(p);
            std::cout << std::endl;
        }

        for (Personaggio* p : personaggi)
            delete p;

        break;
    }

    // ==========================
    // ESERCIZIO 3
    // ==========================
    case 3:
    {
        std::vector<MetodoPagamento*> metodi;

        metodi.push_back(new CartaCredito());
        metodi.push_back(new PayPal());
        metodi.push_back(new Contanti());

        double importo = 100.0;

        std::cout << "\n--- Pagamento senza commissione ---\n";
        for (MetodoPagamento* m : metodi)
        {
            m->Paga(importo);
            std::cout << std::endl;
        }

        std::cout << "\n--- Pagamento con commissione 10% ---\n";
        for (MetodoPagamento* m : metodi)
        {
            m->PagaConCommissione(importo, 10.0);
            std::cout << std::endl;
        }

        for (MetodoPagamento* m : metodi)
            delete m;

        break;
    }

    // ==========================
    // ESERCIZIO 4
    // ==========================
    case 4:
    {
        GestoreNotifiche gestore;

        gestore.Aggiungi(new NotificaEmail());
        gestore.Aggiungi(new NotificaSMS());
        gestore.Aggiungi(new NotificaPush());

        gestore.InviaATutti("Messaggio di prova!");

        break;
    }

    default:
        std::cout << "Numero esercizio non valido." << std::endl;
    }

    return 0;
}