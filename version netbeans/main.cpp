#include <iostream>
//#include <windows.h>
#include <list> 
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cstdlib>

#include <string>  //for std::string


using namespace std;
int horizontal = 0;//Variable publica.
struct nodo
{
	nodo *izquierda;
	nodo *derecha;
	int dato;
        int nivel;
   
};
//void mostrarArbol(nodo *miArbol, int auxY);

void mostrarMenu();
void gotoxy(int x, int y);

void preorden(nodo *&arbolBinario);
void inorden(nodo *&arbolBinario);
void postorden(nodo *&arbolBinario);

nodo* crearNodo(int n,int *&nivel);
void insertarNodosEnArbolBinario(nodo *&arbolBinario,int n);
vector<nodo*> autoLlenado(nodo *& arbolBinario);
 vector<nodo*> llenadoUsuario(nodo *& arbolBinario);
void ponerNiveles(nodo *&arbolBinario,int separador);

void recorrerEnAmplitud(nodo *&arbolBinario);
void mostrarArbolBinario(nodo *&arbolBinario,int separador);



int main()
{
    int seleccion;
    nodo* arbolBinario=NULL;
        
    vector<nodo*> arbol;
	 
    //autoLlenado(arbolBinario);
	
    //preorden(arbolBinario);
       
    //mostrarArbolBinario(arbolBinario,0);
    do {
        mostrarMenu();
        cin>>seleccion;
        
        switch(seleccion)
        {
        case 1:
            llenadoUsuario(arbolBinario);
            break;
        case 2:
            cout<<endl<<"ARBOL BINARIO VERTICAL"<<endl;
            mostrarArbolBinario(arbolBinario,0);
            break;
        case 3:
            cout<<endl<<"preorden"<<endl;
            
            preorden(arbolBinario);
            
            cout<<endl<<"inorden"<<endl;
            
            inorden(arbolBinario);
            
            cout<<endl<<"postorden"<<endl;
            
            postorden(arbolBinario);

            break;
        case 4:
            autoLlenado(arbolBinario);
            break; 
            
        case 5:
            return 0; 
        }
        }while(true);
}


//numero de nodos del arbol
nodo* crearNodo(int n)
{
    nodo *nuevo=new nodo();
    
    nuevo -> dato = n;
    nuevo -> derecha = NULL;
    nuevo -> izquierda = NULL;
    nuevo -> nivel=1;

    return nuevo;
}

void insertarNodosEnArbolBinario(nodo *&arbolBinario,int n)
{   
    
    
	if(arbolBinario==NULL)
	{
		nodo *nuevo=crearNodo(n);
		arbolBinario=nuevo;
        //cout<<"crear nodo: "<<n<<endl;        
	}else
	{   
           int datoRaiz=arbolBinario -> dato;
           
        //recursion n
        if(n<datoRaiz)
            {   
                
                insertarNodosEnArbolBinario
                (arbolBinario -> izquierda ,n);
               // cout<<"hijo de "<<datoRaiz<<": izquierda valor: "<<n<<endl; 
                
            }else //derecha o izquierda
            {
                
                insertarNodosEnArbolBinario
                (arbolBinario -> derecha ,n);
               // cout<<"hijo de "<<datoRaiz<<": derecha valor: "<<n<<endl;
                
            }
           
	}
        nodo *valor=arbolBinario;
       // cout<<endl<<"--"<<arbolBinario->dato<<"--"<<endl;
}

void mostrarMenu()
{
    cout<<endl<<endl<<"Seleccione una opcion"<<endl;
    cout<<"1) Darle valores al arbol"<<endl;
    cout<<"2) Imprimir arbol"<<endl;
    cout<<"3) Mostrar recorridos "<<endl;
    cout<<"4) Autollenado"<<endl;
    cout<<"5) Salir"<<endl;
    
    
    
}

 vector<nodo*> autoLlenado(nodo *& arbolBinario)
{
    vector<nodo* > arbol;
    
    int datos[9]={8,3,10,1,6,14,4,7,13};
    for(int i=0;i<9;i++)
        {
            //cout<<"Insertar los elementos"<<endl;
            //cin>>n;
            //cout<<endl;
            insertarNodosEnArbolBinario(arbolBinario,datos[i]);
           // cout<<endl<<"fin insercion"<<endl<<endl;
        }
    
    ponerNiveles(arbolBinario,0);
    
    return arbol;
}
 vector<nodo*> llenadoUsuario(nodo *& arbolBinario)
{
    vector<nodo* > arbol;
    int n;
    for(int i=0;i<9;i++)
        {   
            cout<<"Insertar los elementos"<<endl;
            cin>>n;
            insertarNodosEnArbolBinario(arbolBinario,n);
            cout<<endl;
        }
    
    ponerNiveles(arbolBinario,0);
    
    return arbol;
}


void ponerNiveles(nodo *&arbolBinario,int separador)
{
    
    if(arbolBinario==NULL)
    {
        
     return;
    }else
    {
        
        arbolBinario->nivel=separador+1;
        
        ponerNiveles(arbolBinario-> derecha, separador +1);   
        for(int i=0;i<separador;i++)
            {
                //cout<<"-";
            }
            //cout<<arbolBinario->dato<<endl;
            
            
        ponerNiveles(arbolBinario -> izquierda,separador+1);
    }
    
}


void preorden(nodo *&arbolBinario)
{
    
    if(arbolBinario==NULL)
        {
        
            return ;
        }
        else   
        {

            cout<<arbolBinario->dato<<" ";    
            
        preorden(arbolBinario->izquierda);
        preorden(arbolBinario->derecha);

        }
}

void inorden(nodo *&arbolBinario)
{
    
    if(arbolBinario==NULL)
        {

            return ;
        }
        else
        {
            inorden(arbolBinario->izquierda);
            cout<<arbolBinario->dato<<" ";
            inorden(arbolBinario->derecha);

        }
}

void postorden(nodo *&arbolBinario)
{
    
    if(arbolBinario==NULL)
        {
            return ;
        }
        postorden(arbolBinario->izquierda);
        postorden(arbolBinario->derecha);
        cout<<arbolBinario->dato<<" ";
}

void recorrerEnAmplitud(nodo *&arbolBinario)
{
    queue<nodo*> cola;
    
    cola.push(arbolBinario);
    
    cout<<"nota"<<endl;
    
    while(true)
    {
        nodo *miNodo=cola.front();
        cola.pop();
        
        cout<<miNodo->dato<<" ";
        
        cola.push(miNodo->derecha);
        cola.push(miNodo->izquierda);
    }
}


void mostrarArbolBinario(nodo *&arbolBinario,int separador)
{
    
    if(arbolBinario==NULL)
    {
        
     return;
    }else
    {        
        
        //cout<<"nivel de: "<<arbolBinario ->dato<<"="<<arbolBinario->nivel<<endl;
        
        mostrarArbolBinario(arbolBinario-> izquierda, separador +1);   
        for(int i=0;i<separador;i++)
            {
                cout<<" ";
            }
            cout<<" "<<arbolBinario->dato;
            
        mostrarArbolBinario(arbolBinario -> derecha,separador+1);
    }
}
/*
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

void mostrarArbol(nodo* arbolBinario, int vertical)
{


if(arbolBinario == NULL)
{

    return;
}

horizontal += 5;

mostrarArbol(arbolBinario -> izquierda,vertical+2);

gotoxy(10+horizontal-vertical , 15+vertical);

cout << arbolBinario -> dato << endl << endl;


mostrarArbol(arbolBinario -> derecha,vertical+2);



}*/
