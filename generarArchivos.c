/*
 * generarArchivos.c
 * 
 * Copyright 2017 Angel Oswaldo Vázquez Patiño <angel.vazquezp@ucuenca.edu.ec>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
 
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/**
 * @param argumento1 número de registros a generar 
 * @param argumento2 ruta del archivo en donde se va a guardar
 * @example
./generarArchivos 1000000 /home/angelv/Desktop/archivoPrueba.csv
Generando 1000000 registros en el archivo
/home/angelv/Desktop/archivoPrueba.csv...

Generados 100000 (10%) de 1000000 registros.
Generados 200000 (20%) de 1000000 registros.
Generados 300000 (30%) de 1000000 registros.
Generados 400000 (40%) de 1000000 registros.
Generados 500000 (50%) de 1000000 registros.
Generados 600000 (60%) de 1000000 registros.
Generados 700000 (70%) de 1000000 registros.
Generados 800000 (80%) de 1000000 registros.
Generados 900000 (90%) de 1000000 registros.
Generados 1000000 (100%) de 1000000 registros.

Se generaron 1000000 registros en el archivo
/home/angelv/Desktop/archivoPrueba.csv
Wall time: 2.00 segundos
 * @return 0 si la ejecución no tiene errores
 */
int main(int argc, char **argv)
{
	time_t start = time(NULL);          //!< para medir el tiempo de ejecución
	srand(100);                         //!< la misma semilla para generar los mismos números aleatorios en cada nueva ejecución
	//srand(time(NULL));                  //!< diferente semilla para generar diferentes números aleatorios en cada ejecución
	unsigned int campo1;                //!< campo1
	char campo2[6];                     //!< campo2
	char campo3[6];                     //!< campo3 true o false
	signed char nCaract;                //!< número de caracteres que tendrá el campo2
	signed char i;                      //!< 
	time_t curtime;                     //!< para generar una fecha al azar
	struct tm *info;                    //!< 
	char buffer[11];                    //!< 
	
	unsigned long nRegistros = 1000000; //!< un millón por defecto
	char filePath[500] = "/home/angelv/Desktop/archivoPrueba.csv";
	
	if(argc==3)
	{
		nRegistros = atoi(argv[1]);
		strcpy(filePath, argv[2]);		
	}

	FILE *fp = fopen(filePath, "w+");
	printf("Generando %lu registros en el archivo\n%s...\n\n", nRegistros, filePath);
for(unsigned long j=0; j<nRegistros; j++)
{	
	if((j+1)%100000==0)
		printf("Generados %lu (%2.lu%%) de %lu registros.\n", j+1, (j+1)*100/nRegistros, nRegistros);
	campo1 = rand()%100000;
	
	nCaract = 1 + rand()%5;	
	_Bool bandera;
	for(i=0; i<nCaract; i++)
	{
		bandera = rand()%2;	
		if(bandera)
			campo2[i] = 48+rand()%10;
		else
			campo2[i] = 97+rand()%26;
	}
	campo2[i] = '\0';
	
	bandera = rand()%2;
		
	if(bandera)
		strcpy(campo3, "true");
	else
		strcpy(campo3, "false");
		
	time(&curtime);
	curtime = rand()%curtime;
	info = localtime(&curtime);	
	strftime(buffer,11,"%d/%m/%Y", info);
	
	//printf("%i,%s,%s,%s\n", campo1, campo2, campo3, buffer);
	fprintf(fp, "%i,%s,%s,%s\n", campo1, campo2, campo3, buffer);
}
	fclose(fp);	
	printf("\nSe generaron %lu registros en el archivo\n%s\n", nRegistros, filePath);
	printf("Wall time: %.2f segundos\n", difftime(time(NULL), start));
	return 0;
}
