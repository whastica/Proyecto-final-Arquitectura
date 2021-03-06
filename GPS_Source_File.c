/* 
 / File:   GPS_source_File.c
 / Autores: Juan David Pasquel y Whalen Stiven Caicedo
 / Created on 13 de diciembre de 2020
*/
#include<pic18f4550.h>
#include<xc.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "ADC_Header_File.h"
#include "LCD_20x4_H_file.h"
#include "DHT11_Header_File.h"
#include "USART_Header_File.h"

void Light_Management(unsigned long int UTC_Time);
void Irrigation_Management(char RH, char T);

char stringBT [50];
char val_aux [50];

/**\brief principal del proyecto*/
void main(void) {
    
    /**
      \details 
       * Establece el ascilador interno con una Fq de 4 MHZ
       * envia un bajo pulso
       * por ultimo establecer como puero de entrada 
    */
    char value[10];
    char RH_Decimal, RH_Integral, T_Decimal, T_Integral, Checksum;
    
    OSCCON = 0xD2;   
    TRISBbits.RB2 = 0;
    TRISBbits.RB3 = 0;
    
    LCD_Init();
    INTCONbits.GIE=1;   /** Habilita la interrupcion global */
    INTCONbits.PEIE=1;  /** habilita la interrupcion periferica */
    PIE1bits.RCIE=1;    /* habilita la recepcion de interrupcion */
    USART_Init(9600);
    ADC_Init();
    __delay_ms(10);
    
    while(1)
    { 
        DHT11_Start();                  /* send start pulse to DHT11 module */
        DHT11_CheckResponse();          /* wait for response from DHT11 module */

        /* read 40-bit data from DHT11 module */
        RH_Integral = DHT11_ReadData(); /* read Relative Humidity's integral value */
        RH_Decimal  = DHT11_ReadData(); /* read Relative Humidity's decimal value */
        T_Integral  = DHT11_ReadData(); /* read Temperature's integral value */
        T_Decimal   = DHT11_ReadData(); /* read Relative Temperature's decimal value */
        Checksum    = DHT11_ReadData(); /* read 8-bit checksum value */

        LCD_String_xy(1,0,"DATE: ");
        
        LCD_String_xy(2,0,"TIME: ");
        
        /** convertir el valor de temperatura a ascii y enviarlo para mostrar*/
        memset(value,0,10);             
        sprintf(value,"%d",T_Integral); 
        LCD_String_xy(3,0,"TEMP: ");
        LCD_String(value);
        sprintf(value,".%d",T_Decimal); 
        LCD_String(value);
        LCD_Char(0xdf);
        LCD_Char('C');
        
        /** convertir el valor de humedad a ascii y enviarlo para mostrar*/    
        memset(value,0,10);
        sprintf(value,"%d",RH_Integral);
        LCD_String_xy(4,0,"HUMEDITY: ");
        LCD_String(value);
        sprintf(value,".%d ",RH_Decimal);
        LCD_String(value);
        LCD_Char('%');
        
        Irrigation_Management(RH_Integral, T_Integral);
        
        sprintf(value,"%d",RH_Integral);
        strcpy(val_aux, value);
        sprintf(value,".%d",RH_Decimal);
        strcat(val_aux, value);
        __delay_ms(500);
        
        strcat(val_aux, ",");
        sprintf(value,"%d",T_Integral);
        strcat(val_aux, value);
        sprintf(value,".%d",T_Decimal);
        strcat(val_aux, value);
        
        strcat(val_aux, "\r\n");
        USART_SendString(val_aux);  /* send LED ON status to terminal */
        
        __delay_ms(500);
    }
} 

void Light_Management(unsigned long int UTC_Time)
{
    unsigned int hour;
    hour = (UTC_Time / 10000);
    while(hour>=18 & hour<=6)
    {
        LATB2=0xFF;
    }
        LATB2=0x00;
}

void Irrigation_Management(char RH, char T)
{
    if(RH<25 || (T<=20 & T>0))
    {
        LATB3=0xFF;
        __delay_ms(500);
        LATB3=0;
    }
}