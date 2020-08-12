#include "EtatMachine.h"

namespace TepeGolo {
    void EtatMachine::AjoutEtat(EtatRef newEtat, bool estRemplacer) {
        this->_estAjouter = true;
        this->_estRemplacer = true;

        this->_newEtat = std::move(newEtat);
    }

    void EtatMachine::RetireEtat() {
        this->_estEnlever = true;
    }

    void EtatMachine::ProcessEtatChange() {
        if (this->_estEnlever && !this->_etats.empty())
        {
            this->_etats.pop();
            if (!this->_etats.empty())
            {
                this->_etats.top()->Reprise();
            }
            this->_estEnlever = false;
        }

        if (this->_estAjouter)
        {
            if (!this->_etats.empty())
            {
                if (this->_estRemplacer)
                {
                    this->_etats.pop();
                }
                else
                {
                    this->_etats.top()->Pause();
                }
            }
            this->_etats.push(std::move(this->_newEtat));
            this->_etats.top()->Init();
            this->_estAjouter = false;
        }


    }
    EtatRef &EtatMachine::GetActiveEtat() {
        return this->_etats.top();
    }
}
