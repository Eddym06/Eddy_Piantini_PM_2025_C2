#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(int argc, char *argv[]) {
if (argc < 2) {
printf("Uso: %s <imagen_de_entrada.jpg>\n", argv[0]);
return 1;
}

char *archivo_entrada = argv[1];
char *archivo_salida = "salida_en_gris.jpg";

int ancho, alto, canales;
unsigned char *img = stbi_load(archivo_entrada, &ancho, &alto, &canales, 0);
if (img == NULL) {
printf("Error: No se pudo cargar la imagen '%s'.\n", archivo_entrada);
return 1;
}
printf("Imagen cargada: %dpx de ancho, %dpx de alto, %d canales.\n", ancho, alto, canales);

size_t tamano_img = ancho * alto;
unsigned char *img_gris = malloc(tamano_img);
if (img_gris == NULL) {
printf("Error: No se pudo reservar memoria para la imagen en gris.\n");
stbi_image_free(img);
return 1;
}

for (unsigned char *p = img, *pg = img_gris; p != img + (tamano_img * canales); p += canales, pg++) {
uint8_t valor_gris = (uint8_t)(0.299 * p[0] + 0.587 * p[1] + 0.114 * p[2]);
*pg = valor_gris;
}

if (stbi_write_jpg(archivo_salida, ancho, alto, 1, img_gris, 100)) {
printf("Imagen convertida a escala de grises y guardada como '%s'.\n", archivo_salida);
} else {
printf("Error: No se pudo guardar la imagen en gris.\n");
}

stbi_image_free(img);
free(img_gris);

return 0;
}
