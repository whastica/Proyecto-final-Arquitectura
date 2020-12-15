/* 
 * File:   ADC_Header_File.h
 * Autores: Juan David Pasquel y Whalen Stiven Caicedo
 * Created on 13 de diciembre de 2020
*/

#ifndef ADC_HEADER_FILE_H
#define	ADC_HEADER_FILE_H

#ifdef	__cplusplus
extern "C" {
#endif

void ADC_Init();
int ADC_Read(int);

#ifdef	__cplusplus
}
#endif

#endif	/* ADC_HEADER_FILE_H */

