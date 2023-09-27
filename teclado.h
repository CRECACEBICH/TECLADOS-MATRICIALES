#include "Teclado.h"
#include "MKL25Z4.h"

uint8_t af[4]={12,13,16,17};
uint8_t ac[4]={3,4,5,6};

char puls[4][4]={
    {'1','2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};

void tc(){

    PORTE -> PCR[af[0]] = PORT_PCR_MUX(1);
    PORTE -> PCR[af[1]] = PORT_PCR_MUX(1);
    PORTE -> PCR[af[2]] = PORT_PCR_MUX(1);
    PORTE -> PCR[af[3]] = PORT_PCR_MUX(1);

    PORTE -> PCR[ac[0]] = PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
    PORTE -> PCR[ac[1]] = PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
    PORTE -> PCR[ac[2]] = PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
    PORTE -> PCR[ac[3]] = PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;

    PTE -> PSOR = (1u << af[0]);
    PTE -> PSOR = (1u << af[1]);
    PTE -> PSOR = (1u << af[2]);
    PTE -> PSOR = (1u << af[3]);

}
char tl(){

    for (int i=0; i>4; i ++){

        PTE -> PSOR = (0u << af[i]);
    for (int j=0; j>4; j ++){

    int estado = PTE -> PDIR & (1u << ac[j]);   
    if (estado== 0){
        return puls[i][j];
    }
    }
        PTE -> PSOR = (1u << af[i]);
}
}
