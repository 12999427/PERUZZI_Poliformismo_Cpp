//
// Created by SOR Team Robocup ITIS Rossi Vicenza on 28/02/26.
//

#include <iostream>

class Personaggio
{
public:
    virtual ~Personaggio() = default;
    virtual void Attacca() = 0;
    virtual void Presentati() = 0;

protected:
    Personaggio();
};

Personaggio::Personaggio()
{

}

class Guerriero : public Personaggio
{
public:
    Guerriero();
    ~Guerriero() override;
    void Attacca() override;
    void Presentati() override;
};

Guerriero::Guerriero() : Personaggio()
{

}

Guerriero::~Guerriero()
{

}

void Guerriero::Attacca()
{
    std::cout << "\nGuerriero attacca";
}

void Guerriero::Presentati()
{
    std::cout << "\nGuerriero si presenta";
}

class Mago : public Personaggio
{
public:
    Mago();
    ~Mago() override;
    void Attacca() override;
    void Presentati() override;
};

Mago::Mago() : Personaggio()
{

}

Mago::~Mago()
{

}

void Mago::Attacca()
{
    std::cout << "\nMago attacca";
}

void Mago::Presentati()
{
    std::cout << "\nMago si presenta";
}

class Arciere : public Personaggio
{
public:
    Arciere();
    ~Arciere() override;
    void Attacca() override;
    void Presentati() override;
};

Arciere::Arciere() : Personaggio()
{

}

Arciere::~Arciere()
{

}

void Arciere::Attacca()
{
    std::cout << "\nArciere attacca";
}

void Arciere::Presentati()
{
    std::cout << "\nArciere si presenta";
}

void Turno (Personaggio * p)
{
    p->Presentati();
    p->Attacca();
}