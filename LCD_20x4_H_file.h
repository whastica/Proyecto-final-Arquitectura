/* 
 * File:   LCD_20x4_H_file.h
 * Autores: Juan David Pasquel y Whalen Stiven Caicedo
 * Created on 13 de diciembre de 2020
*/

/** Define la libreria en caso de no estarlo */
#ifndef LCD_20x4_H_H_					
#define LCD_20x4_H_H_

#include<pic18f4550.h>

/** Define el puerto de direccion de datos del LCD  */
#define LCD_Data_Dir TRISD				
/** Define LCD puerto de direccion de datos */
#define LCD_Command_Dir TRISC
/** Define LCD puerto de datos */
#define LCD_Data_Port LATD				
#define LCD_Command_Port LATC
#define EN LATC2                                                            
/** Define Lectura/Escritura pin de señal */
#define RW LATC1							
#define RS LATC0							

void LCD_Command (char);				
/** LCD escribe datos en la funcion */
void LCD_Char (char);					
/** LCD Inicializa la funcion */
void LCD_Init (void);					
/** Enviar cadena a la función LCD */
void LCD_String (const char*);				
/** Enviar fila, posición y cadena a la función LCD */
void LCD_String_xy (char,char,const char*);	
/** LCD funcion limpiar */
void LCD_Clear (void);					
/** funcion de retardo */
void MSdelay(unsigned int);          

#endif									/* LCD_20x4_H_FILE_H_ */