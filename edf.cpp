#include <iostream>
#include <string>
using namespace std;

void printar_matriz(int lista[][4]){

    cout << "{";
    for (int indexf = 0; indexf < 3; indexf++){
        for (int indexs = 0; indexs < 4; indexs++){
            cout << lista[indexf][indexs] <<", ";
        }
    }
    cout << "}"<< endl;

}

void printar_array(int lista[], int tam){
    cout << "{";
    for(int i = 0; i < tam; i++){
        cout << lista[i] << ", ";
    }
    cout << "}"<< endl;
}

int hiper_periodo(int lista[][4], int qnt){
    int temp = 0;
    for(int i = 0; i < qnt; i++){
        cout << temp << endl;
        if (lista[i][3] > temp){
            temp = lista[i][3];
        }
    }
    return temp;
}

int escolher_melhor_deadline(int qnt, int deadlines[]){
    int menor_deadline = 10000;
    int escolhido = -1;
    for(int i = 0; i < qnt; i++){
        if (deadlines[i] < menor_deadline){
            menor_deadline = deadlines[i];
            escolhido = i;
        }
    }
    return escolhido;
}

int * arr_dinamico(int qnt){
    int x;
    int *arr = new int(qnt);
    for (int x = 0; x < qnt; x++){
        arr[x] = 0;
        //cout << x << " : " << arr[qnt] << endl;
    }
    return arr;
}


void edf(int processos[][4], int qnt){
    int relogio = 0;

    int * deadlines = arr_dinamico(qnt);
    for(int i = 0; i < qnt; i++){
        deadlines[i] = processos[i][2];
    }

    int * periodos = arr_dinamico(qnt);
    for(int i = 0; i < qnt; i++){
        periodos[i] = processos[i][3];
    }
    cout<< "Processos: ";
    printar_matriz(processos);
    cout << "Deadlines: ";
    printar_array(deadlines,qnt);
    cout << "Periodos: ";
    printar_array(periodos,qnt);

    int * contador = arr_dinamico(qnt);

    while (relogio < 20){
        int escolhido = escolher_melhor_deadline(qnt,deadlines);
        cout << "Processo escolhido: " << escolhido << endl;
        if(periodos[escolhido] >= relogio){
            relogio = relogio + processos[escolhido][1];
            cout << "Processo: P" << escolhido << " executando... \n";
            cout << "Relogio: "<<relogio << endl;
            cout << "Burst Time do Processo P" << escolhido << ": " << processos[escolhido][1] << endl;
            cout << "Deadline ANTERIOR do Processo : " << deadlines[escolhido] << endl;
            deadlines[escolhido] = deadlines[escolhido] + processos[escolhido][3];
            cout << "Deadline do Processo P" << escolhido << " Atualizada: " << deadlines[escolhido] << endl;
            cout << "Periodo ANTERIOR do Processo: " << periodos[escolhido] << endl;
            periodos[escolhido] = periodos[escolhido] + processos[escolhido][3];
            cout << "Periodo do Processo P" << escolhido << " Atualizado: " << periodos[escolhido] << endl;
            contador[escolhido] = contador[escolhido] + 1;
        }

    }

    for(int i = 0; i<qnt; i++){
        cout << "O Processo P" << i << " Executou " << contador[i] << " vezes \n";
    }



}


int main (){

    int processos[3][4] = {
    {0,3,7,20},
    {1,2,4, 5},
    {2,2,8,10}
    };
    int qnt = sizeof(processos)/sizeof(processos[0]);
    edf(processos, qnt);

    //int * ptr = arr_dinamico(qnt);


return 0;
}
