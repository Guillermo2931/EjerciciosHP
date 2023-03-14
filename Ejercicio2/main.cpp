#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
//Declaramos todo lo que se va a usar
using std::cout; using std::cin;
using std::endl; using std::ifstream;
using std::endl; using std::ofstream;
using std::endl; using std::fstream;
using std::endl; using std::string;

int main(int argc, char * argv[]) {
    //Tomamos la direccion que proporciona el usuario al llamar el .exe
    string a_carpeta=argv[1];
    //Agregamos un "/" al final para un buen funcionamiento
    a_carpeta.append("/");
    //Creamos el nombre del archivo json
    string nombreArchivo = "dir.json";
    //Creamos nuestra variable para el archivo
    ofstream archivo;
    //Para este caso vamos a apoyarnos de las herramientas nativas de windows para buscar archivos, por lo que creamos nuestro FIND_DATA
    WIN32_FIND_DATA ffd{};
    //Este contador se crea debido a que primero se toman dos archivos que no nos sirven, los cuales son "." y "..", por lo que este contador nos ayuda a evitarlos
    int conta=0;
    //Empezamos a escribir el json
    string cadena="{ \"files\": [";
    //Abrimos nuestro archivo para escritura
    archivo.open(nombreArchivo.c_str(), fstream::out);
    //Escribimos el inicio del json en el archivo
    archivo << cadena;
    //Empezamos la busqueda de archivos en el directorio verificando que exista la carpeta
    if (auto handle = FindFirstFile((a_carpeta + "/*.*").c_str(), &ffd))
    {
        //Vamos a recorrer la lista de archivos hasta el final
        do
        {
            //Verificamos que haya pasado el archivo "." y ".."
            if(conta>1){
                //Verificamos que no sea el primer archivo que se va a agregar al json para poder poner una ","
                if (conta!=2){
                archivo<<",";
                }
                //damos un salto de linea en el json y posteriormente escribirmos la estructura deseado
                archivo << endl;
                archivo << "{\"name\":\"";
                //Escribimos el nombre del archivo en el json
                archivo << ffd.cFileName;
                archivo << "\",\"size\":";
                //Con esto obtenemos el tamaño del archivo en la ruta que se proporcionó y se escribe en el json
                archivo << std::filesystem::file_size(a_carpeta+ffd.cFileName);
                archivo <<"}";
            }
            conta=conta+1;
        }
        //Busca si aun hay un archivo siguiente
        while (FindNextFile(handle, &ffd) != 0);
    }//Finalizamos la escritura y cerramos
    archivo << "]}";
    archivo.close();
}
