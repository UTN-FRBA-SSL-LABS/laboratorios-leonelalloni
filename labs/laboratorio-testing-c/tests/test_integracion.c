#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */
void test_compra_con_descuento (){
    Carrito c;
    Producto p1 = {"Pan",200,3};
    Producto p2 = {"Leche",350,2};
    carrito_init(&c);
    carrito_agregar(&c,p1);
    ASSERT_IGUAL(600, carrito_total(&c));
    carrito_agregar(&c,p2);
    ASSERT_IGUAL(1300, carrito_total(&c));
    carrito_descuento(1300,10);
    ASSERT_IGUAL(1170, carrito_descuento(1300,10));

    
}
/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */
void test_agregar_hasta_llenar(){

    Carrito c;

    Producto p1 = {"Pan", 200, 1};
    Producto p2 = {"Leche", 350, 1};
    Producto p3 = {"Huevos", 500, 1};
    Producto p4 = {"Queso", 800, 1};
    Producto p5 = {"Cafe", 1000, 1};

    carrito_init(&c);

    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);
    carrito_agregar(&c, p3);
    carrito_agregar(&c, p4);

    ASSERT_IGUAL(MAX_ITEMS, c.cantidad);

    ASSERT_IGUAL(0, carrito_agregar(&c, p5));

    ASSERT_IGUAL(MAX_ITEMS, c.cantidad);
}





int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();  
    RESUMEN();
    return EXIT_CODE();
}
