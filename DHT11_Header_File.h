/* 
 * File:   DHT11_Header_File.h
 * Autores: Juan David Pasquel y Whalen Stiven Caicedo
 * Created on 13 de diciembre de 2020
*/

#ifndef DHT11_HEADER_FILE_H
#define	DHT11_HEADER_FILE_H

void DHT11_Start();
void DHT11_CheckResponse();
char DHT11_ReadData();

/** asigna el puerto para datos */
#define Data_Out LATA0  
/** Lee datos del puerto */
#define Data_In PORTAbits.RA0  
/** Direccion del puerto */
#define Data_Dir TRISAbits.RA0 
/** define _XTAL_FREQ para usar retardo interno */
#define _XTAL_FREQ 8000000          

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/** DHT11_HEADER_FILE_H */

