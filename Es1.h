//
// Created by SOR Team Robocup ITIS Rossi Vicenza on 28/02/26.
//

#include <iostream>

class Veicolo
{
public:
    virtual ~Veicolo() = default;

    //i metodi astratti devono essere public perchè così possono essere chiamati da un riferimento alla classe base
    virtual void Muovi() = 0;
    virtual std::string Descrizione() const = 0; //const opzionale

protected:
    //Veicolo() // se ci fossero stati parametri comuni tra i veicoli
};

class Auto : public Veicolo
{
public:
    Auto();
    ~Auto();
    void Muovi() override;
    std::string Descrizione() const override;
};

Auto::Auto() /* : Veicolo() */ // per assegnare caratteristiche comuni a tutti i veicoli
{
    //eventuale assegnazione di caratteristiche
}

Auto::~Auto()
{
    //eventuale deallocazione
}

std::string Auto::Descrizione() const
{
    return "Veicolo Auto";
    //le stringhe letterali come "..." sono immutabili, quindi per restituirle o uso string o uso const char *. Usare char * è come char array[n] e prevedere che possa fare array[i] = sostituto - se ciò viene fatto con le stringhe letterali da errore
}

void Auto::Muovi()
{
    std::cout<<"\nAuto Si Muove";
}

class Bicicletta : public Veicolo
{
public:
    Bicicletta();
    ~Bicicletta();
    void Muovi() override;
    std::string Descrizione() const override;
};

Bicicletta::Bicicletta()
{

}

Bicicletta::~Bicicletta()
{

}

std::string Bicicletta::Descrizione() const
{
    return "Veicolo Bicicletta";
}

void Bicicletta::Muovi()
{
    std::cout<<"\nBicicletta Si Muove";
}


class Treno : public Veicolo
{
public:
    Treno();
    ~Treno();
    void Muovi() override;
    std::string Descrizione() const override;
};


Treno::Treno()
{

}

Treno::~Treno()
{

}

std::string Treno::Descrizione() const
{
    return "Veicolo Treno";
}

void Treno::Muovi()
{
    std::cout<<"\nTreno Si Muove";
}
