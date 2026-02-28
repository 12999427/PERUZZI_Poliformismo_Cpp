//
// Created by SOR Team Robocup ITIS Rossi Vicenza on 28/02/26.
//

#include <iostream>

class MetodoPagamento
{
public:
    virtual bool Paga(double importo) = 0;
    virtual ~MetodoPagamento() = default;
    bool PagaConCommissione(double importo, double percCommissione);

protected:
    MetodoPagamento();
};

MetodoPagamento::MetodoPagamento()
{

}

bool MetodoPagamento::PagaConCommissione(double importo, double percCommissione)
{
    double ImportoTot = importo * (1+percCommissione/100.0);
    return Paga(ImportoTot);
}


class CartaCredito : public MetodoPagamento
{
public:
    bool Paga(double importo) override;
    ~CartaCredito() override;
    CartaCredito();
};

CartaCredito::CartaCredito() : MetodoPagamento()
{

}

CartaCredito::~CartaCredito()
{

}

bool CartaCredito::Paga(double importo)
{
    std::cout<<"Pagato "<< importo << "€ con carta";
    return true;
}

class PayPal : public MetodoPagamento
{
public:
    bool Paga(double importo) override;
    ~PayPal() override;
    PayPal();
};

PayPal::PayPal() : MetodoPagamento()
{

}

PayPal::~PayPal()
{

}

bool PayPal::Paga(double importo)
{
    std::cout<<"Pagato "<< importo << "€ con pagapall";
    return true;
}

class Contanti : public MetodoPagamento
{
public:
    bool Paga(double importo) override;
    ~Contanti() override;
    Contanti();
};

Contanti::Contanti() : MetodoPagamento()
{

}

Contanti::~Contanti()
{

}

bool Contanti::Paga(double importo)
{
    std::cout<<"Pagato "<< importo << "€ con contanti";
    return true;
}