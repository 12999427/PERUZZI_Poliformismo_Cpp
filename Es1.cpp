//
// Created by SOR Team Robocup ITIS Rossi Vicenza on 28/02/26.
//

class Veicolo
{
private:
    Veicolo();

public:
    ~Veicolo();
    virtual void Muovi() = 0;
    virtual char * Descrizione() = 0;
};

class Auto : public Veicolo
{
public:
    Auto()
    {

    }
    ~Auto()
    {

    }
    void Muovi() override
    {

    }
    char * Descrizione() override
    {

    }
};

class Bicicletta : public Veicolo
{

};

class Treno : public Veicolo
{

};