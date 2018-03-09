#ifndef _BIT_MATH_H
	#define _BIT_MATH_H
	
	#define SET_BIT(VAR,BitNo) (VAR)|=(1<<(BitNo))

	#define CLR_BIT(VAR,BitNo) (VAR)&=~(1<<(BitNo))

	#define GET_BIT(VAR,BitNo) (VAR)=(((VAR)>>(BitNo))&1)

	#define TOGGLE_BIT(VAR,BitNo) (VAR)^=(1<<(BitNo))


	#define CONC_BIT(A7, A6, A5, A4, A3, A2, A1,A0) CONC_Help(A7, A6, A5, A4, A3, A2, A1,A0)
	#define CONC_Help(A7, A6, A5, A4, A3, A2, A1,A0) 0b##A7##A6##A5##A4##A3##A2##A1##A0

	#define SET_HIGH_NIBB(VAR) (VAR)|=(0x0f<<4)

	#define SET_LOW_NIBB(VAR) (VAR)|=(0x0f)

	#define CLR_HIGH_NIBB(VAR) (VAR)&=(0x0f)

	#define CLR_LOW_NIBB(VAR) (VAR)&=(0x0f<<4)

	#define Get_High_Nibb(VAR) (VAR=(VAR&=0xf0)>>4)

	#define Get_Low_Nibb(VAR) (VAR&=0x0f)

#endif