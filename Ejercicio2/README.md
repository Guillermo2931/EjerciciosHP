Para el segundo ejercicio se usa la libreria windows.h que proporciona diferentes herramientas para la navegación de archivos, en este caso usaremos FIND_DATA
Primero se toma la dirección que proporciona el usuario y se le agrega un "/" para el funcionamiento adecuado de las funciones.
Se decalara e inicia todo lo necesario respecto al archivo json que se va a crear, dando un nombre y creando una variable ofstream para el archivo, así como iniciar el FIND_DATA.
Se escribe el inicio del json y empezamos la búsqueda de archivos.
Primero con  if (auto handle = FindFirstFile((a_carpeta + "/*.*").c_str(), &ffd)) se verifica que exista la carpeta y se apunta en su dirección para recorrerla posteriormente.
Dentro de la carpeta con el FIND_DATA creado se empezará a buscar los archivos pero un problema presente es que los primeros archivos que entrega son "." y ".." por lo que esto afecta al funcionamiento y debemos evitarlos, para eso se añade un contador que las primeras dos veces no realiza la escritura en el json, hsta la tercera que ya sabemos que es un archivo real.
Al tener nuestros archivos vamos a ir complementando el json escribiendo en el archivo los datos correspondintes, usando ffd.cFileName para obtener el nombre del archivo y escirnirlo y std::filesystem::file_size(a_carpeta+ffd.cFileName) para obtener el tamaño de nuestro archivo en bytes. Esto se realiza hasta no encontrar archivos en el directorio que se proporcionó. Al finalizar solo se completa el json y se cierra el archivo.
Nota: La ruta no debe contener subcarpetas, debido a que solo lista los archivos con su tamaño como lo pide la especificación
El ejecutable se encuentra en la carpeyta bin/debug de este proyecto
