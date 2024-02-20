#include <iostream>
using namespace std;

void metodoPorInsercion(int arreglo[], int elementos){
    for (int i = 0; i < elementos; i++) {

        int posicion = i;
        int auxiliar = arreglo[i];

        while((posicion>0) && (arreglo[posicion-1]>auxiliar)){
            arreglo[posicion] = arreglo[posicion-1];
            posicion--;
        }

        arreglo[posicion] = auxiliar;
    }
}

//METODOOS PARA EL ORDENAMIENTO POR MEZCLA

void mezclar(int arreglo [], int izquierda, int medio, int derecha) {
    int elementos1 = medio - izquierda + 1;
    int elementos2 = derecha - medio;

    int izquierda_temp [elementos1];
    int derecha_temp [elementos2];

    for (int i = 0; i < elementos1; i++) {
        izquierda_temp[i] = arreglo[izquierda + i];
    }
    for (int j = 0; j < elementos2; j++) {
        derecha_temp[j] = arreglo[medio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = izquierda;

    while (i < elementos1 && j < elementos2) {
        if (izquierda_temp[i] <= derecha_temp[j]) {
            arreglo[k] = izquierda_temp[i];
            i++;
        } else {
            arreglo[k] = derecha_temp[j];
            j++;
        }
        k++;
    }

    while (i < elementos1) {
        arreglo[k] = izquierda_temp[i];
        i++;
        k++;
    }

    while (j < elementos2) {
        arreglo[k] = derecha_temp[j];
        j++;
        k++;
    }
}

void ordenamientoPorMezcla(int arreglo[],int izquierda, int derecha){
    if (izquierda < derecha) {

        int medio = izquierda + (derecha - izquierda) / 2;

        ordenamientoPorMezcla(arreglo, izquierda, medio);
        ordenamientoPorMezcla(arreglo, medio + 1, derecha);

        mezclar(arreglo, izquierda, medio, derecha);
    }

}

void imprimirArreglo(int arreglo[], int elementos){
    for (int i = 0; i < elementos; i++) {
        cout << arreglo[i] << " ";
    }
}

int main() {
    //EJEMPLO
    int arreglo [] = {10,20,30,40,5,8,9,21,31,99,100};
    int elementos = sizeof(arreglo) / sizeof(arreglo[0]);

    cout<<"Ordenamiento por INSERCION"<<endl;
    cout<<"Sin ordenar"<<endl;
    imprimirArreglo(arreglo,elementos);
    cout << endl;
    cout << endl;

    cout<<"Ordenado por INSERCION"<<endl;
    metodoPorInsercion(arreglo,elementos);
    imprimirArreglo(arreglo, elementos);
    cout << endl;
    cout << endl;
    cout << endl;

    //ORDENAMIENTO POR MEZCLA
    int arreglo2 [] = {10,20,30,40,5,8,9,21,31,99,100,200,150,1,7};
    int elementos2 = sizeof(arreglo2) / sizeof(arreglo2[0]);

    cout<<"Ordenamiento por MEZCLA"<<endl;
    cout<<"Sin ordenar"<<endl;
    imprimirArreglo(arreglo2,elementos2);
    cout << endl;
    cout << endl;

    cout<<"Ordenado por MEZCLA"<<endl;
    ordenamientoPorMezcla(arreglo2,0,elementos2-1);
    imprimirArreglo(arreglo2, elementos2);
    cout << endl;


    return 0;

}