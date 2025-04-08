#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "interprete.h"
#include "bison.tab.h"
#include <dlfcn.h>

/*
 * Se utiliza un árbol binario equilibrado (AVL), que mejora la eficiencia en las búsquedas de elementos.
 *
 * Utilizamos un factor de equilibrio (FE), calculado como:
 *              altura(subárbol derecho) - altura(subárbol izquierdo).
 *
 * Para las rotaciones, guardamos, además, un puntero al padre de cada nodo
 */

// Typedefs necesarios
typedef char *tipoclave;
// Los elementos son contenedores (pares de comp_lexico y lexema)
typedef contenedor tipoelem;

// Estructura de un nodo
struct celda {
    tipoelem info;
    int fe; // Factor de equilibio do AVL
    struct celda *padre, *izq, *der;
};

// Typedef del AVL
typedef struct celda *avl;

// Variable global para saber cuándo dejar de propagar el equilibrio
int equilibrar;
int eliminacion_concreta = 0; // Variable usada para saber cando ten lugar unha eliminación concreta durante a eliminación dun nodo
int parar_calculo = 0; // Variable usada para saber cando se ten que parar o cálculo de FE durante a eliminación dun nodo




// FUNCIONES PRIVADAS ///////////////////////////////////////////////

/**
 *
 * @param A
 * @param antiguoFE
 * @return
 */
tipoelem _suprimir_max(avl *A, int *antiguoFE);

/**
 * Extrae la clave de un nodo
 * @param E nodo
 * @return clave
 */
tipoclave _clave_elem(tipoelem *E) {
    return E->lexema;
}

/**
 * Compara dos claves
 * @param cl1 clave 1
 * @param cl2 clave 2
 * @return 0 si son iguales
 * @return negativo si cl1 < cl2
 * @return positivo si cl1 > cl2
 */
int _comparar_claves(tipoclave cl1, tipoclave cl2) {
    return strcmp(cl1, cl2) == 0 ? 0 : strcmp(cl1, cl2) > 0 ? 1 : -1;
}

/**
 * Compara una clave con la de un elemento
 * @param cl clave
 * @param E elemento
 * @return 0 si son iguales
 * @return negativo si cl < clave(E)
 * @return positivo si cl > clave(E)
 */
int _comparar_clave_elem(tipoclave cl, tipoelem E) {
    return _comparar_claves(cl, _clave_elem(&E));
}

/**
 * Rotación de tipo DD a partir de un nodo
 * @param A nodo
 */
void _DD(avl *A) {
    avl nodo_padre = (*A)->padre;
    avl nodo_aux = (*A)->der;
    avl nodo_aux_izq = nodo_aux->izq;

    (*A)->der = nodo_aux_izq; // n->der = nodo_aux->izq
    if (nodo_aux_izq != NULL) {
        nodo_aux_izq->padre = *A; // Si había un nodo en nodo_aux->izq, pasa padre de nodo_aux->izq al nuevo (n)
    }

    nodo_aux->izq = *A; // nodo_aux->izq = n
    (*A)->padre = nodo_aux; // Pasa padre de n al nuevo (nodo_aux)

    nodo_aux->padre = nodo_padre; // Pasa padre de nodo_aux al nuevo (padre de n)
    if (nodo_padre == NULL) {
        *A = nodo_aux; // Se n no tenía padre, se cambia a nodo_aux
    } else {
        if (nodo_padre->izq == *A) { // Se cambia a nodo_aux el hijo izquierdo
            nodo_padre->izq = nodo_aux;
        } else {                // Se cambia a nodo_aux el hijo derecho
            nodo_padre->der = nodo_aux;
        }
    }

    // Nuevos factores de equilibrio
    (*A)->fe = 0;
    (*A)->izq->fe = 0;
}

// El comportamiento de las siguientes funciones de rotación es similar al de la anterior

/**
 * Rotación de tipo DI a partir de un nodo
 * @param A nodo
 */
void _DI(avl *A) {
    avl nodo_padre = (*A)->padre;
    avl n = *A;
    avl n2 = (*A)->der->izq;
    avl n2_der = n2->der;
    avl n2_izq = n2->izq;

    (*A)->der->izq = n2_der;
    if (n2_der != NULL) {
        n2_der->padre = (*A)->der;
    }

    n2->der = (*A)->der;
    (*A)->der->padre = n2;

    n->der = n2_izq;
    if (n2_izq != NULL) {
        n2_izq->padre = *A;
    }

    n2->izq = n;
    (*A)->padre = n2;

    n2->padre = nodo_padre;
    // n = n2
    if (nodo_padre == NULL) {
        *A = n2;
    } else {
        if (nodo_padre->izq == *A) {
            nodo_padre->izq = n2;
        } else {
            nodo_padre->der = n2;
        }
    }

    if ((*A)->fe == 1) {
        (*A)->izq->fe = -1;
        (*A)->der->fe = 0;
    } else if ((*A)->fe == -1){
        (*A)->izq->fe = 0;
        (*A)->der->fe = 1;
    } else {
        (*A)->izq->fe = 0;
        (*A)->der->fe = 0;
    }
    (*A)->fe = 0;
}

/**
 * Rotación de tipo II a partir de un nodo
 * @param A nodo
 */
void _II(avl *A) {
    avl nodo_padre = (*A)->padre;
    avl nodo_aux = (*A)->izq;
    avl nodo_aux_der = nodo_aux->der;

    (*A)->izq = nodo_aux_der;
    if (nodo_aux_der != NULL) {
        nodo_aux_der->padre = *A;
    }

    nodo_aux->der = *A;
    (*A)->padre = nodo_aux;

    nodo_aux->padre = nodo_padre;
    // n = nodo_aux
    if (nodo_padre == NULL) {
        *A = nodo_aux;
    } else {
        if (nodo_padre->izq == *A) {
            nodo_padre->izq = nodo_aux;
        } else {
            nodo_padre->der = nodo_aux;
        }
    }

    (*A)->fe = 0;
    (*A)->der->fe = 0;
}

/**
 * Rotación de tipo ID a partir de un nodo
 * @param A nodo
 */
void _ID(avl *A) {
    avl nodo_padre = (*A)->padre;
    avl n = *A;
    avl n2 = (*A)->izq->der;
    avl n2_der = n2->der;
    avl n2_izq = n2->izq;

    (*A)->izq->der = n2_izq;
    if (n2_izq != NULL) {
        n2_izq->padre = (*A)->izq;
    }

    n2->izq = (*A)->izq;
    (*A)->izq->padre = n2;

    n->izq = n2_der;
    if (n2_der != NULL) {
        n2_der->padre = *A;
    }

    n2->der = n;
    (*A)->padre = n2;

    n2->padre = nodo_padre;
    if (nodo_padre == NULL) {
        *A = n2;
    } else {
        if (nodo_padre->izq == *A) {
            nodo_padre->izq = n2;
        } else {
            nodo_padre->der = n2;
        }
    }

    if ((*A)->fe == 1) {
        (*A)->izq->fe = -1;
        (*A)->der->fe = 0;
    } else if ((*A)->fe == -1){
        (*A)->izq->fe = 0;
        (*A)->der->fe = 1;
    } else {
        (*A)->izq->fe = 0;
        (*A)->der->fe = 0;
    }
    (*A)->fe = 0;
}

/**
 * Restructura el AVL si es necesario, es decir, si:
 *      * FE(n) = 2 y FE(hijo_der) >= 0 => DD
 *      * FE(n) = 2 y FE(hijo_der) < 0 => DI
 *      * FE(n) = -2 y FE(hijo_izq) <= 0 => II
 *      * FE(n) = -2 y FE(hijo_izq) >0 => ID
 * @param A nodo
 */
void _reestructurar(avl *A) {
    if ((*A)->fe == 2) {
        if ((*A)->der->fe >= 0) { // Rotación DD
            _DD(A);
        } else {                  // Rotación DI
            _DI(A);
        }
    } else if ((*A)->fe == -2) {
        if ((*A)->izq->fe <= 0) { // Rotación II
            _II(A);
        } else {                  // Rotación ID
            _ID(A);
        }
    }
}

// Función que destrúe o contido dun elemento
void _destruir_elem(tipoelem *E) {
    free(E->lexema);
    /*if (E->comp_lexico == LIB) {
        dlclose(E->valor.libhandle);
    }*/
}

// FUNCIONES PÚBLICAS ///////////////////////////////////////////

void crear(avl *A) {
    *A = NULL;
}

void destruir(avl *A) {
    // Se libera la memoria
    if (*A != NULL) {
        destruir(&(*A)->izq);
        destruir(&(*A)->der);
        if ((*A)->info.comp_lexico == LIB) {
            dlclose((*A)->info.valor.libhandle);
        }
        free((*A)->info.lexema);
        free(*A);
        *A = NULL;
    }
}

unsigned vacia(avl A) {
    return A == NULL;
}

void leer(avl A, tipoelem *E) {
    *E = A->info;
}

avl izq(avl A) {
    return A->izq;
}

avl der(avl A) {
    return A->der;
}

void buscar_nodo(avl A, tipoclave cl, tipoelem *nodo) {
    if (vacia(A)) {
        // Si no hay nodo
        return;
    }
    int comp = _comparar_clave_elem(cl, A->info);

    // Varios casos
    if (comp == 0) {        // cl == A->info
        *nodo = A->info;
    } else if (comp < 0) {  // cl < A->info
        buscar_nodo(A->izq, cl, nodo);
    } else {                // cl > A->info
        buscar_nodo(A->der, cl, nodo);
    }
}

void insertar(avl *A, tipoelem E) {
    if (vacia(*A)) {
        // Si el árbol no tiene ningún nodo

        // Reservas de memoria
        *A = malloc(sizeof(struct celda));
        (*A)->info.comp_lexico = E.comp_lexico;
        (*A)->info.lexema = malloc((strlen(E.lexema) + 1) * sizeof(char));

        // Copiar con strcpy
        strcpy((*A)->info.lexema, E.lexema);

        switch (E.comp_lexico) {
            case VARIABLE:
                (*A)->info.valor.var = E.valor.var;
                break;
            case CONSTANTE:
                (*A)->info.valor.var = E.valor.var;
                break;
            case FUNC0:
            case FUNC1:
            case FUNC2:
            case COMANDO0:
            case COMANDO1:
                // revisar si esto va bien
                (*A)->info.valor.funcptr = E.valor.funcptr;
                break;
            case LIB:
                // revisar si esto va bien
                (*A)->info.valor.libhandle = E.valor.libhandle;
                break;
            default:
                break;
        }

        // Inicializaciones
        (*A)->padre = NULL;
        (*A)->izq = NULL;
        (*A)->der = NULL;
        (*A)->fe = 0;

        // Se activa la propagación al insertar
        equilibrar = 1;

        return;
    }

    // Comportamiento recursivo
    tipoclave cl = _clave_elem(&E);
    int comp = _comparar_clave_elem(cl, (*A)->info);

    // Varios casos
    if (comp > 0) {
        insertar(&(*A)->der, E);
        if ((*A)->der->padre == NULL) {
            (*A)->der->padre = *A;
        }
        if (equilibrar) {
            (*A)->fe++;
        }
        _reestructurar(A);
        if ((*A)->fe == 0) {
            equilibrar = 0;
        }
    } else {
        insertar(&(*A)->izq, E);
        if ((*A)->izq->padre == NULL) {
            (*A)->izq->padre = *A;
        }
        if (equilibrar) {
            (*A)->fe--;
        }
        _reestructurar(A);
        if ((*A)->fe == 0) {
            equilibrar = 0;
        }
    }
}

unsigned es_miembro_clave(avl A, tipoclave cl) {
    if (vacia(A)) {
        // Si no hay nodos
        return 0;
    }
    int comp = _comparar_clave_elem(cl, A->info);

    // Varios casos
    if (comp == 0) { //cl == A->info
        return 1;
    } else if (comp > 0) { //cl > A->info
        return es_miembro_clave(A->der, cl);
    }
    //cl < A->info
    return es_miembro_clave(A->izq, cl);
}

void asignar_valor_nodo(avl* A, tipoclave cl, double valor) {
    if (vacia(*A)) {
        return;
    }

    int comp = _comparar_clave_elem(cl, (*A)->info);
    if (comp == 0) {
        (*A)->info.valor.var = valor;
    } else if (comp < 0) {
        asignar_valor_nodo(&(*A)->izq, cl, valor);
    } else {
        asignar_valor_nodo(&(*A)->der, cl, valor);
    }
}

void eliminar_nodo(avl *A, tipoelem e) {
    avl aux;
    if (vacia(*A)) {
        return;
    }

    tipoclave cl = _clave_elem(&e);
    int comp = _comparar_clave_elem(cl, (*A)->info);
    if (comp < 0) { // Se (E < (*A)->info)
        eliminar_nodo(&(*A)->izq, e);
        if (!eliminacion_concreta && !parar_calculo) {
            if ((*A)->fe == 0) {
                parar_calculo = 1;
            }
            (*A)->fe++;
        }
        _reestructurar(A);
    } else if (comp > 0) { // Se (E > (*A)->info)
        eliminar_nodo(&(*A)->der, e);
        if (!eliminacion_concreta && !parar_calculo) {
            if ((*A)->fe == 0) {
                parar_calculo = 1;
            }
            (*A)->fe--;
        }
        _reestructurar(A);
    } else if (vacia((*A)->izq) && vacia((*A)->der)) { // Se está vacío a ambos lados:
        eliminacion_concreta = 0;
        parar_calculo = 0;
        _destruir_elem(&((*A)->info));
        free(*A);
        *A = NULL;
    } else if (vacia((*A)->izq)) { // Se está vacío á dereita e non á esquerda:
        eliminacion_concreta = 0;
        parar_calculo = 0;
        aux = *A;
        *A = (*A)->der;
        _destruir_elem(&aux->info);
        free(aux);
    } else if (vacia((*A)->der)) { // Se está vacío á esquerda e non á dereita:
        eliminacion_concreta = 0;
        parar_calculo = 0;
        aux = *A;
        *A = (*A)->izq;
        _destruir_elem(&aux->info);
        free(aux);
    } else { // Se non está vacío nin á dereita nin á esquerda:
        eliminacion_concreta = 1;
        parar_calculo = 0;

        int antiguoFE;
        _destruir_elem(&(*A)->info); // Elimino a información sen liberar o nodo
        (*A)->info = _suprimir_max(&(*A)->izq, &antiguoFE); // No seu lugar ponse o máximo da subárbore esquerda

        (*A)->fe = antiguoFE;
        if (vacia((*A)->izq) && !vacia((*A)->der)) {
            (*A)->fe++;
        }
        if (vacia((*A)->der)) {
            (*A)->padre->fe++;
        }
    }
}


///////// FUNCIONES PRIVADAS ////////////////

// Funcion auxiliar que devolve máximo de árbore indicada
tipoelem _suprimir_max(avl *A, int *antiguoFE) {
    avl aux;
    tipoelem E;
    if (vacia((*A)->der)) { // Se á dereita está vacío, devólvese o nodo actual
        E = (*A)->info;
        *antiguoFE = (*A)->fe;
        aux = *A;
        *A = (*A)->izq;
        free(aux);
        return E;
    } else {
        return _suprimir_max(&(*A)->der, antiguoFE); // Vólvese a buscar o máximo da rama dereita
    }
}




