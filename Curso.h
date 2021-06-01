//curso.h
#ifndef __CURSO_H__
#define __CURSO_H__
using namespace std;
//#include <string>

class Curso {
        string nombre;
        double notaFinal;
        int totalEstudiantes;
        string codigo;
    public:

        Curso(string _nombre = "", double _notaFinal = 0, int _totalEstudiantes = 0, string _codigo = ""): nombre(_nombre), notaFinal(_notaFinal), totalEstudiantes(_totalEstudiantes), codigo(_codigo){}
        //Setter
        void setNombre(string nombre){
            this->nombre=nombre;
        }
        void setNotaFinal(double notaFinal){
            this->notaFinal=notaFinal;
        }
        void setTotalEstudiantes(int totalEstudiantes){
            this->totalEstudiantes = totalEstudiantes;
        }
        void setCodigo(string codigo){
            this->codigo=codigo;
        }

        //Getter
        string getNombre();
        double getNotaFinal();
        int getTotalEstudiantes();
        std::string getCodigo();
        //implementacion de sobrecarga del metodo ostream para la clase Curso
        friend ostream& operator<<(ostream&o,const Curso &p){
            o<<"( "<<p.nombre<<" , "<<p.notaFinal<<" , "<<p.totalEstudiantes<<" , "<<p.codigo<<" )";
            return o;
        }
        
};

double Curso::getNotaFinal(){
    return notaFinal;
}

int Curso::getTotalEstudiantes(){
    return totalEstudiantes;   
}

std::string Curso::getNombre(){
    return nombre;
}

std::string Curso::getCodigo(){
    return codigo;
}

#endif