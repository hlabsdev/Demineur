#pragma once

namespace TepeGolo
{
    class Etat {
    public:
        virtual void Init()=0;
        virtual void GererEntrer()=0;
        virtual void Update(float dt)=0;
        virtual void Dessiner(float dt)=0;

        virtual void Pause() {};
        virtual void Reprise() {};
    };
}
