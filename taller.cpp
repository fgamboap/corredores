#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


struct Atleta {
    string nombre;
    int numero;
};


struct Tiempo {
    int numero; 
    double tiempo; 
};

    queue<Tiempo> fifo; 
    stack<double> lifo; 
    Atleta atleta;

    int registrar(){

      cout << "Ingrese el nombre del atleta: ";
      getline(cin, atleta.nombre);
      cout << "Ingrese el número del atleta: ";
      cin >> atleta.numero;

       char opcion;
    do {
        Tiempo tiempo;
        tiempo.numero = atleta.numero;
        cout << "Ingrese el tiempo de vuelta: ";
        cin >> tiempo.tiempo;
        fifo.push(tiempo);
        cout << "¿Desea ingresar otro tiempo? (S/N): ";
        cin >> opcion;
    } while (opcion == 'S' || opcion == 's');


    }

    int calcular_ordenar(){

         if (fifo.size() >= 2) {
        double suma = 0;
        int n = 0;
        while (!fifo.empty()) {
            Tiempo tiempo = fifo.front();
            fifo.pop();
            suma += tiempo.tiempo;
            n++;
            if (n == 2) {
                double promedio = suma / n;
                lifo.push(promedio);
                n = 0;
                suma = 0;
            }
        }

        
        vector<double> promedios;
        while (!lifo.empty()) {
            promedios.push_back(lifo.top());
            lifo.pop();
        }
        sort(promedios.begin(), promedios.end());
        for (double promedio : promedios) {
            lifo.push(promedio);
        }
    }
}

int mostrar(){

  cout << "\nResultados:\n";
    cout << "Nombre del atleta: " << atleta.nombre << endl;
    cout << "Número del atleta: " << atleta.numero << endl;

    if (lifo.empty()) {
        cout << "No hay suficientes datos para calcular promedios.\n";
    } else {
        cout << "Promedios:\n";
        while (!lifo.empty()) {
            cout << lifo.top() << endl;
            lifo.pop();
        }
    }

    return 0;

}

int main() {
   
 int opcion=0;  


    do {


        cout<<"1. Registrar atleta"<<endl;
        cout<<"2. Calcular promedio y ordenar "<<endl;
        cout<<"3. mostrar resultados"<<endl;
        cout<<"4. salir"<<endl;

       
        cin>>opcion;
        switch (opcion)
        {
            case 1: registrar();
             break;

            case 2:   calcular_ordenar();
             break;

              case 3:   mostrar();
             break;

          case 4: exit;
       
       
        }
    }while(opcion!=4);
   
 return 0;
    
   

}