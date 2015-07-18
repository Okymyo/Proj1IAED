/* =====================
 * Grupo 5, IAED, LEIC-T
 * 81900 - Nuno Anselmo
 * 81943 - Gonçalo Matos
 * 82047 - André Mendes
   ===================== */

#pragma once

#include "includes.h"
#include "network.h"

/*
* Requests input to the user and modifies a network depending of it.
* @param network Network that is going to suffer changes depending on the user input.
* @returns       An int so it knows whenever the user quits or not.
*/
int requestInput(Network *network);
