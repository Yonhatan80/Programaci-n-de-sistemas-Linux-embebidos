#include <stdio.h>
#include <ctype.h>

int main() {
  //abrir el archivo de texto
    FILE *archivo;   
  //FILE, que se utiliza para manejar archivos.
    char prueba[] = "prueba.txt"; //Se añade a la cadena de caracteres el contenido del archivo de texto
    archivo = fopen(prueba, "r"); // Abrir el archivo en modo lectura
    if (archivo == NULL) { // Si el archivo no se pudo abrir
        printf("Error al abrir el archivo.\n");//Si el archivo no se abre, se muestra un mensaje de error
        return 1;
    }
    // Inicializar contadores para tipos de caracteres
    int letras = 0, numeros = 0, espacios = 0, otros_caracteres = 0;
    int contadores[256] = {0}; //  contabilizar la cantidad de cada carácter en función de su valor ASCII.


    // Leer y procesar el contenido del archivo carácter por carácter
    int caracter;
    while ((caracter = fgetc(archivo)) != EOF) {
      // fgetc es para leer un carácter del archivo,EOF comprueba si no hemos llegado al final del archivo 
        if (isalpha(caracter)) {
          // Verifica si el carácter es una letra.
            letras++;
        } else if (isdigit(caracter)) {
          // Verifica si el carácter es un dígito.
            numeros++;
        } else if (isspace(caracter)) {
          // Verifica si el carácter es un espacio en blanco.
            espacios++;
        } else {
            otros_caracteres++;
        }

      
        // Incrementar el contador para este valor de ASCII
        contadores[caracter]++;
    }

    printf("Tipos de caracteres en el archivo:\n");
    printf("Letras: %d\n", letras);
    printf("Números: %d\n", numeros);
    printf("Espacios: %d\n", espacios);
    printf("Otros Caracteres: %d\n", otros_caracteres);

    printf("\nCaracteres y sus repeticiones:\n");
    for (int i = 0; i < 256; i++) {
        if (contadores[i] > 0) {
            printf("'%c': %d\n", (char)i, contadores[i]);
        }
    }

    fclose(archivo); // Cerrar el archivo
    return 0;
}
