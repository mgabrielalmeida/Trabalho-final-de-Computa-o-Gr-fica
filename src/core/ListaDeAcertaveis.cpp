#include "Objetos/ListaDeAcertaveis.h"

#include "Core/Vetor3.h"
#include "Core/Material.h"
#include "Core/HitRecords.h"

#include "Objetos/Acertavel.h"

#include <vector>


ListaDeAcertaveis::ListaDeAcertaveis() {}
ListaDeAcertaveis::ListaDeAcertaveis(const std::vector<Acertavel*>& l) : lista(l) {}

void ListaDeAcertaveis::inserir(Acertavel* obj){
    lista.push_back(obj);
}

HitRecords ListaDeAcertaveis::intersect(Raio ray){
    float t_min = -1;
    HitRecords retorno;

    for(auto obj : lista){

        float t_atual = obj->intersect(ray).t;

        if(t_atual){
            if(t_atual < t_min || t_min == -1){
                t_min = t_atual;
                retorno = obj->intersect(ray);
            }
        }
    }

    return retorno;
}