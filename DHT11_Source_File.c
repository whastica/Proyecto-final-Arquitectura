/* 
 * File:   DHT11_source_File.c
 * Autores: Juan David Pasquel y Whalen Stiven Caicedo
 * Created on 13 de diciembre de 2020
*/

#include<pic18f4550.h>
#include<xc.h>
#include "DHT11_Header_File.h"

/**\brief lee datos del DHT11*/
char DHT11_ReadData()
{
    /**
      \details 
       * Espera el pulso 0 para iniciar el pulso de datos  
    */
    char i,data = 0;  
    for(i=0;i<8;i++)
    {
        while(!(Data_In & 1));   
        __delay_us(30);         
        if(Data_In & 1)             /** comprobar si el dato es 1 o 0 */    
          data = ((data<<1) | 1); 
        else
          data = (data<<1);  
        while(Data_In & 1);
    }
    return data;
}
/**\brief lee datos del DHT11*/
void DHT11_Start()
{   
    /**
      \details 
       * Establece el puerto de salida 
       * envia un bajo pulso
       * por ultimo establecer como puero de entrada 
    */
    Data_Dir = 0;       
    Data_Out = 0;      
    __delay_ms(18);
    Data_Out = 1;       
    __delay_us(20);
    Data_Dir = 1;        
}

void DHT11_CheckResponse()
{
    while(Data_In & 1);     /** espera hasta que el autobús esté alto */     
    while(!(Data_In & 1));  /** espera hasta que el autobús esté bajo*/
    while(Data_In & 1);     /** espera hasta que el autobús esté alto */
}
