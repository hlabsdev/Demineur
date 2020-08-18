#pragma once
#include <memory>
#include <stack>
#include "Etat.hpp"

namespace TepeGolo
{
    typedef std::unique_ptr<Etat> EtatRef;

    class EtatMachine
    {
    public:
        EtatMachine(){};
        ~EtatMachine(){};

        void AjoutEtat(EtatRef newEtat, bool estRemplacer = true);
        void RetireEtat();

        void ProcessEtatChange();

        EtatRef &GetActiveEtat();

    private:
        std::stack<EtatRef> _etats;
        EtatRef _newEtat;

        bool _estEnlever;
        bool _estRemplacer;
        bool _estAjouter;
    };
} // namespace TepeGolo
