//
// Created by SOR Team Robocup ITIS Rossi Vicenza on 28/02/26.
//

#include <iostream>
#include <string>

class Notifica
{
public:
    virtual bool invia(std::string messaggio) = 0;
    virtual ~Notifica() = default;

    /*
    Una classe polimorfica deve avere un distruttore
    virtuale perché potresti distruggere un oggetto
    derivato tramite un puntatore alla classe base.

    Se il distruttore non è virtuale → comportamento indefinito.

    Una classe “normale” (non usata polimorficamente) non ne ha bisogno
    */

//eventualmente costruttore base protected
};

class NotificaEmail : public Notifica
{
public:
    bool invia(std::string messaggio) override;
    ~NotificaEmail() override;
};


NotificaEmail::~NotificaEmail()
{

}

bool NotificaEmail::invia(std::string messaggio)
{
    std::cout<<"Notifica Email Inviata";
    return true;
}

class NotificaSMS : public Notifica
{
public:
    bool invia(std::string messaggio) override;
    ~NotificaSMS() override;
};


NotificaSMS::~NotificaSMS()
{

}

bool NotificaSMS::invia(std::string messaggio)
{
    std::cout<<"Notifica SMS Inviata";
    return true;
}

class NotificaPush : public Notifica
{
public:
    bool invia(std::string messaggio) override;
    ~NotificaPush() override;
};


NotificaPush::~NotificaPush()
{

}

bool NotificaPush::invia(std::string messaggio)
{
    std::cout<<"Notifica Push Inviata";
    return true;
}


class GestoreNotifiche
{
private:
    std::vector<Notifica*> notifiche;

public:
    GestoreNotifiche();
    ~GestoreNotifiche();
    void Aggiungi(Notifica* n);
    void InviaATutti(std::string messaggio);
};

GestoreNotifiche::GestoreNotifiche()
{

}

GestoreNotifiche::~GestoreNotifiche()
{
    for (auto notificaP : notifiche)
    {
        delete notificaP;
    }

    //il std::vector si cancellarà automaticamente dalla memoria
    //fuori dal suo scope, ma non cancelleraà gli oggetti. Lo devo fare io
}

void GestoreNotifiche::Aggiungi(Notifica* n)
{
    notifiche.push_back(n);
}

void GestoreNotifiche::InviaATutti(std::string messaggio)
{
    for (auto notificaP : notifiche)
    {
        notificaP->invia(messaggio);
    }
}
