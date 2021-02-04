#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char;		//8Bit  bzw. 1Byte von 0 bis 255
using Word = unsigned short;	//16Bit bzw. 2Bytes von 0 bis 65.535
using u32 = unsigned int;		//32Bit bzw. 4Bytes von 0 bis 4.294.967.295


	// http://www.obelisk.me.uk/6502/index.html

struct cpu
{
	Word PC;	// Programm counter
	Byte SP;	// Stack Pointer

	Byte A, B, C;	//Registers

	//Flags: 1Bit jeweils, also insgesammt 1Byte
	Byte C : 1; // Carry Flag
	Byte Z : 1; // Zero Flag
	Byte I : 1; // Interrupt disable flag
	Byte D : 1; // Decimal mode flag
	Byte B : 1; // Break flag
	Byte V : 1; // Overflow Flag
	Byte N : 1; // Negative Flag
};

struct ram
{
	static constexpr u32 MAX_MEM = 1024 * 64;
	Byte Data[MAX_MEM];

	void init()
	{

	};
};




int main()
{
	return 0;
}