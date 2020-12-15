/* 
 * File:   ADC_source_File.c
 * Autores: Juan David Pasquel y Whalen Stiven Caicedo
 * Created on 13 de diciembre de 2020
*/

#include<pic18f4550.h>
#include<xc.h>
#include "ADC_Header_File.h"
/**\brief inicializa el ADC*/
void ADC_Init()
{    
    /**
      \details 
        * puerto a como entrada
        * ADCON1 fija los pines como analogos y fija la referencia de voltaje a 5 voltios 
        * ADCON2 Justificacion a la derecha y tiempo de adquisicion y conversion 
        * Adres Registros del ADC
    */
    TRISA = 0xFF;	
    ADCON1 = 0xFF;	
    ADCON2 = 0x92;	
    ADRESH=0;		
    ADRESL=0;   
}

/**\brief lee el ADC*/
int ADC_Read(int channel)
{
    
    /**
      \details 
        *Lectura ADC
        \param channel canal 
        \return variable digital 
    */
    int digital;

    /* Channel 0 is selected i.e.(CHS3CHS2CHS1CHS0=0000) & ADC is disabled */
    ADCON0 =(ADCON0 & 0b11000011)|((channel<<2) & 0b00111100);  
    
    ADCON0 |= ((1<<ADON)|(1<<GO));	/*Enable ADC and start conversion*/

    /* Wait for End of conversion i.e. Go/done'=0 conversion completed */
    while(ADCON0bits.GO_nDONE==1);

    digital = (ADRESH*256) | (ADRESL);	/*Combine 8-bit LSB and 2-bit MSB*/
    return(digital);
}
