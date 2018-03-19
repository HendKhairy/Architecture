/*
 * SPI_prog.c
 *
 *  Created on: Mar 18, 2018
 *      Author: Hend
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SPI_int.h"
#include "SPI_priv.h"

void SPI_voidMasterInit(void)
{
	/* Description:	SPI Enable 				*/
	SET_BIT(SPCR,SPE);
	/* Description:	Master Enable			*/
	SET_BIT(SPCR,MSTR);
	/* Description:	LSB Enable				*/
	CLR_BIT(SPCR,DORD);
	/* Description:	IDLE LOW Enable			*/
	CLR_BIT(SPCR,CPOL);
	/* Description:	Setup on falling Enable	*/
	CLR_BIT(SPCR,CPHA);
	/* Description:	Setup Clock Freq. F/4   */
	CLR_BIT(SPCR,SPR0);
	/* Description:	Setup Clock Freq. F/4	*/
	CLR_BIT(SPCR,SPR1);
	/* Description:	Setup Clock Freq. F/4	*/
	CLR_BIT(SPSR,SPI2X);


}

void SPI_voidSlaveInit(void)
{
	/* Description:	SPI Enable 				*/
	SET_BIT(SPCR,SPE);
	/* Description:	Slave Enable			*/
	CLR_BIT(SPCR,MSTR);
	/* Description:	LSB Enable				*/
	CLR_BIT(SPCR,DORD);
	/* Description:	IDLE LOW Enable			*/
	CLR_BIT(SPCR,CPOL);
	/* Description:	Setup on falling Enable */
	CLR_BIT(SPCR,CPHA);
	/* Description:	Setup Clock Freq. F/4   */
	CLR_BIT(SPCR,SPR0);
	/* Description:	Setup Clock Freq. F/4	*/
	CLR_BIT(SPCR,SPR1);
	/* Description:	Setup Clock Freq. F/4	*/
	CLR_BIT(SPSR,SPI2X);
}

u8 SPI_u8Transfer(u8 Copy_Data)
{
	SPDR=Copy_Data;
	while(GET_BIT(SPSR,SPIF)==0);

	return SPDR;
}
