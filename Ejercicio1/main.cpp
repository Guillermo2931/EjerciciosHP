#include <iostream>
#include <string>
using namespace std;

int main(int argc, char * argv[])
{
    int a,b,c,d;
    int r1,r2,r3,inc,i,aux,b2,c2,b3;
    int ra1,ra2,ra3;
    ra1=0;
    ra2=0;
    ra3=0;
    aux=0;
    //Asignamos los valores del polinomio que se recibió como argumento
    a=atoi(argv[1]);
    b=atoi(argv[2]);
    c=atoi(argv[3]);
    d=atoi(argv[4]);
    //Verificamos si d es negativo o positivo para asignar el incremento
    if(d>0){
        inc=1;
    }
    else{
        inc=-1;
    }
    cout<<"{";
    //Iniciamos el recorrido por todos los numeros que están entre -d y d buscando los divisores
    for(i=(-1*d);i!=d+inc;i=i+inc){
        if (i!=0){
                //Verifica si i es divisor de d
            if (d%i==0){
                //Realiza el metodo de Ruffini
                r1=b+a*i;
                r2=c+i*r1;
                r3=d+i*r2;
                if (r3==0){
                    cout<<i;
                    ra1=i;
                    break;
                }
            }
        }
    }
    //Guarda los valores de los resultados anteriores en nuevas variables para poder trabajar
    aux=r2;
    b2=r1;
    c2=r2;
    //Repetimos el proceso anterior
    if(aux>0){
        inc=1;
    }
    else{
        inc=-1;
    }
    for(i=(-1*aux);i!=aux+inc;i=i+inc){
        if (i!=0){
            if (d%i==0){
                    //Realizamos el método de Riffini pero con una operación menos
                r1=b2+a*i;
                r2=c2+i*r1;
                if (r2==0){
                    //Verificamos que no se repuita
                    if(i!=ra1){
                        cout<<","<<i;
                    }
                    break;
                }
            }
        }
    }
    //Repetimos lo anterior para terminar de buscar las raices
    aux=r1;
    b3=r1;
    if(aux>0){
        inc=1;
    }
    else{
        inc=-1;
    }
    for(i=(-1*aux);i!=aux+inc;i=i+inc){
        if (i!=0){
            if (d%i==0){
                r1=b3+a*i;
                if (r1==0){
                    if(i!=ra1&& i!=ra2){
                        cout<<","<<i;
                    }
                    break;
                }
            }
        }
    }
    cout<<"}";
}
