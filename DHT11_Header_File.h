/* 
 * File:   DHT11_Header_File.h
 * Author: Henry Muñoz
 *
 * Created on 13 de diciembre de 2020, 03:13 PM
 */

#ifndef DHT11_HEADER_FILE_H
#define	DHT11_HEADER_FILE_H

void DHT11_Start();
void DHT11_CheckResponse();
char DHT11_ReadData();

#define Data_Out LATA0              /* assign Port pin for data*/
#define Data_In PORTAbits.RA0       /* read data from Port pin*/
#define Data_Dir TRISAbits.RA0      /* Port direction */
#define _XTAL_FREQ 8000000          /* define _XTAL_FREQ for using internal delay */

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* DHT11_HEADER_FILE_H */

