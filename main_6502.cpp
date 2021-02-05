#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char;		//8Bit  bzw. 1Byte von 0 bis 255
using Word = unsigned short;	//16Bit bzw. 2Bytes von 0 bis 65.535
using u32 = unsigned int;		//32Bit bzw. 4Bytes von 0 bis 4.294.967.295


	// http://www.obelisk.me.uk/6502/index.html, https://www.c64-wiki.com/wiki/Reset_(Process), https://sta.c64.org/cbm64mem.html

struct RAM
{
	//Erstellt ein Array mit 65536Bytes, also 64Kb an Speicher
	static constexpr u32 MAX_MEM = 1024 * 64;
	Byte Data[MAX_MEM];


	//Leert den Speicher Data
	void Init()
	{
		for (u32 i = 0; i < MAX_MEM; i++)
		{
			Data[i] = 0;
		}
	};


	// Gibt das Byte aus Data an der Stelle Adress zurück
	Byte operator[](u32 Adress) const
	{
		return Data[Adress];
	}
};

struct CPU
{
	Word PC;	// Programm counter
	Byte SP;	// Stack Pointer

	Byte A, X, Y;	//Registers

	//Flags: 1Bit jeweils, also insgesammt 1Byte
	Byte C : 1; // Carry Flag
	Byte Z : 1; // Zero Flag
	Byte I : 1; // Interrupt disable flag
	Byte D : 1; // Decimal mode flag
	Byte B : 1; // Break flag
	Byte V : 1; // Overflow Flag
	Byte N : 1; // Negative Flag


	//Initialisiert den Prozessor indem der Programm-Counter, der StackPointer, die Flags und die Register gecleared werden
	void Init()
	{
		PC = 0xFFFC;
		SP = 0x0100;
		C = Z = I = D = B = V = N = 0;
		A = X = Y = 0;
	}

	//Gibt das nächste Byte aus Memory zurück, dekrementiert Cycles um 1 und erhöht den ProcessCounter um 1
	Byte FetchByte(u32& Cycles, RAM& Memory)
	{
		Byte Data = Memory[PC];
		PC++;
		Cycles--;
		return Data;
	}

	//Gibt das nächste Word aus Memory zurück, dekrementiert Cycles um 2 und erhöht den ProcessCounter um 2
	Word FetchWord(u32& Cycles, RAM& Memory)
	{
		//TODO: Fallunterscheidung für Big-Endian Plattformen
		Word Data = Memory[PC];
		PC++;
		Data |= (Memory[PC] << 8);
		PC++;
		Cycles -= 2;
		return Data;
	}


	//Führt die übergebene menge an Cycles aus und ließt dafür aus Memory
	void Execute(u32& Cycles, RAM& Memory)
	{
		while (Cycles != 0)
		{
			Byte Instruction = FetchByte(Cycles, Memory);
			switch (Instruction)
			{
			default:
			{
				printf("Instruction not Implemented %d", Instruction);
			}break;
			}
		}
	}
};




int main()
{
	CPU cpu;
	RAM ram;
	cpu.Init();
	ram.Init();
}
