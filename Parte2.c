#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Función para convertir un carácter en un número entero (dígito)
int charToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0'; // Conversión de dígito ASCII a valor entero
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10; // Conversión de carácter hexadecimal a valor entero
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10; // Conversión de carácter hexadecimal a valor entero (minúsculas)
    } else {
        return -1; // Carácter no válido
    }
}

// Función para convertir un número entero en un carácter
char intToChar(int n) {
    if (n >= 0 && n <= 9) {
        return n + '0'; // Conversión de valor entero a dígito ASCII
    } else {
        return n - 10 + 'A'; // Conversión de valor entero a carácter hexadecimal
    }
}

// Función para convertir un número en una base dada a decimal
int convertToDecimal(char *num, int base) {
    int decimal = 0;
    int len = strlen(num);
    for (int i = 0; i < len; i++) {
        int digit = charToInt(num[i]); // Convertir cada dígito/caracter en un valor entero
        if (digit == -1 || digit >= base) { // Verificar si el dígito es válido para la base dada
            printf("Número no válido para la base proporcionada.\n");
            exit(1);
        }
        decimal += digit * (int)pow(base, len - i - 1); // Calcular el valor decimal del número
    }
    return decimal;
}

// Función para convertir un número decimal a una base dada
void convertFromDecimal(int decimal, int base) {
    char result[100];
    int i = 0;
    while (decimal > 0) {
        result[i++] = intToChar(decimal % base); // Convertir cada residuo en un dígito/caracter
        decimal /= base; // Dividir el número decimal por la base para la próxima iteración
    }
    printf("El número en base %d es: ", base);
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", result[j]); // Imprimir los dígitos/caracteres en orden inverso
    }
    printf("\n");
}

int main() {
    char num[100];
    int baseFrom, baseTo;

    // Solicitar al usuario el número y las bases de conversión
    printf("Ingrese el número: ");
    scanf("%s", num);

    printf("Ingrese la base del número: ");
    scanf("%d", &baseFrom);

    // Validar la base de entrada
    if (baseFrom < 2 || baseFrom > 16) {
        printf("La base debe estar entre 2 y 16.\n");
        return 1;
    }

    printf("Ingrese la base a la que desea convertir: ");
    scanf("%d", &baseTo);

    // Validar la base de salida
    if (baseTo < 2 || baseTo > 16) {
        printf("La base debe estar entre 2 y 16.\n");
        return 1;
    }

    // Convertir el número de la base de entrada a decimal y luego a la base de salida
    int decimal = convertToDecimal(num, baseFrom);
    convertFromDecimal(decimal, baseTo);

    return 0;
}


