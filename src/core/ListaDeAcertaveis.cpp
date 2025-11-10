#include "Vetor3.h"
#include "Acertavel.h"
#include "Material.h"
#include "HitRecords.h"
#include <vector>

#include "ListaDeAcertaveis.h"

std::vector<Acertavel*> lista;
float t; // O "t" a ser retornado

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