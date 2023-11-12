struct operandInfo {
	String mnemonic;
	int bytes; 
};

operandInfo operands[256] = {	{"ADD   ",4}, {"ADD   ",4}, {"ADD   ",4}, {"ADD   ",4}, {"ADD   ",4}, {"ADD   ",4}, {"PUSH  ",4}, {"POP   ",4}, {"OR    ",4}, {"OR    ",4}, {"OR    ",4}, {"OR    ",4}, {"OR    ",4}, {"OR    ",4}, {"PUSH  ",4}, {"PVAM  ",4},
								{"ADC   ",4}, {"ADC   ",4}, {"ADC   ",4}, {"ADC   ",4}, {"ADC   ",4}, {"ADC   ",4}, {"PUSH  ",4}, {"POP   ",4}, {"SBB   ",4}, {"SBB   ",4}, {"SBB   ",4}, {"SBB   ",4}, {"SBB   ",4}, {"SBB   ",4}, {"PUSH  ",4}, {"POP   ",4},
								{"AND   ",4}, {"AND   ",4}, {"AND   ",4}, {"AND   ",4}, {"AND   ",4}, {"AND   ",4}, {"SEG   ",4}, {"DAA   ",4}, {"SUB   ",4}, {"SUB   ",4}, {"SUB   ",4}, {"SUB   ",4}, {"SUB   ",4}, {"SUB   ",4}, {"SEG   ",4}, {"DAS   ",4},
								{"XOR   ",4}, {"XOR   ",4}, {"XOR   ",4}, {"XOR   ",4}, {"XOR   ",4}, {"XOR   ",4}, {"SEG   ",4}, {"AAA   ",4}, {"CMP   ",4}, {"CMP   ",4}, {"CMP   ",4}, {"CMP   ",4}, {"CMP   ",4}, {"CMP   ",4}, {"SEG   ",4}, {"AAS   ",4},
								{"INC   ",4}, {"INC   ",4}, {"INC   ",4}, {"INC   ",4}, {"INC   ",4}, {"INC   ",4}, {"INC   ",4}, {"INC   ",4}, {"DEC   ",4}, {"DEC   ",4}, {"DEC   ",4}, {"DEC   ",4}, {"DEC   ",4}, {"DEC   ",4}, {"DEC   ",4}, {"DEC   ",4},
								{"PUSH  ",4}, {"PUSH  ",4}, {"PUSH  ",4}, {"PUSH  ",4}, {"PUSH  ",4}, {"PUSH  ",4}, {"PUSH  ",4}, {"PUSH  ",4}, {"POP   ",4}, {"POP   ",4}, {"POP   ",4}, {"POP   ",4}, {"POP   ",4}, {"POP   ",4}, {"POP   ",4}, {"POP   ",4},
								{"PUSHA ",4}, {"POPA  ",4}, {"BOUND ",4}, {"ARPL  ",4}, {"RESRVD",4}, {"RESRVD",4}, {"RESRVD",4}, {"RESRVD",4}, {"PUSH  ",4}, {"IMUL  ",4}, {"PUSH  ",4}, {"IMUL  ",4}, {"INSB  ",4}, {"INSW  ",4}, {"OUTSB ",4}, {"OUTSW ",4},
								{"JO    ",4}, {"JNO   ",4}, {"JB    ",4}, {"JNB   ",4}, {"JE    ",4}, {"JNE   ",4}, {"JBE   ",4}, {"JNBE  ",4}, {"JS    ",4}, {"JNS   ",4}, {"JP    ",4}, {"JNP   ",4}, {"JL    ",4}, {"JNL   ",4}, {"JLE   ",4}, {"JNLE  ",4},
								{"Immed ",4}, {"Immed ",4}, {"Immed ",4}, {"Immed ",4}, {"TEST  ",4}, {"TEST  ",4}, {"XCHG  ",4}, {"XCHG  ",4}, {"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4}, {"LEA   ",4}, {"MOV   ",4}, {"POP   ",4},
								{"NOP   ",4}, {"XCHG  ",4}, {"XCHG  ",4}, {"XCHG  ",4}, {"XCHG  ",4}, {"XCHG  ",4}, {"XCHG  ",4}, {"XCHG  ",4}, {"CBW   ",4}, {"CWD   ",4}, {"CALL  ",4}, {"WAIT  ",4}, {"PUSHF ",4}, {"POPF  ",4}, {"SAHF  ",4}, {"LAHF  ",4},
								{"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4}, {"MOVSB ",4}, {"MOVSW ",4}, {"CMPsb ",4}, {"CMPSW ",4}, {"TEST  ",4}, {"TEST  ",4}, {"STOSB ",4}, {"STOSW ",4}, {"LODSB ",4}, {"LODSW ",4}, {"SCASB ",4}, {"SCASW ",4},
								{"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4}, {"MOV   ",6}, {"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4}, {"MOV   ",4},
								{"Shift ",4}, {"Shift ",4}, {"RET   ",4}, {"RET   ",4}, {"LES   ",4}, {"LDS   ",4}, {"MOV   ",4}, {"MOV   ",6}, {"ENTER ",4}, {"LEAVE ",4}, {"RET   ",4}, {"RET   ",4}, {"INT   ",4}, {"INT   ",4}, {"INTO  ",4}, {"IRET  ",4},
								{"Shift ",4}, {"Shift ",4}, {"Shift ",4}, {"AAM   ",4}, {"AAD   ",4}, {"RESRVD",4}, {"CLAT  ",4}, {"ESC   ",4}, {"ESC   ",4}, {"ESC   ",4}, {"ESC   ",4}, {"ESC   ",4}, {"ESC   ",4}, {"ESC   ",4}, {"ESC   ",4}, {"ESC   ",4},
								{"LOOPNZ",4}, {"LOOPZ ",4}, {"LOOP  ",4}, {"JCXZ  ",4}, {"IN    ",4}, {"IN    ",4}, {"OUT   ",4}, {"OUT   ",4}, {"CALL  ",4}, {"JMP   ",4}, {"JMP   ",6}, {"JMP   ",4}, {"IN    ",4}, {"IN    ",4}, {"OUT   ",4}, {"OUT   ",4},
								{"LOCK  ",4}, {"RESRVD",4}, {"REP   ",4}, {"REPZ  ",4}, {"HLT   ",4}, {"CMC   ",4}, {"Grp 1 ",4}, {"Grp 1 ",4}, {"CLC   ",4}, {"STC   ",4}, {"CLI   ",4}, {"STI   ",4}, {"CLD   ",4}, {"STD   ",4}, {"Grp 2 ",4}, {"Grp 2 ",4} };
 
//String Instructions[256] = { "ADD   ", "ADD   ", "ADD   ", "ADD   ", "ADD   ", "ADD   ", "PUSH  ", "POP   ", "OR    ", "OR    ", "OR    ", "OR    ", "OR    ", "OR    ", "PUSH  ", "PVAM  ",
//								"ADC   ", "ADC   ", "ADC   ", "ADC   ", "ADC   ", "ADC   ", "PUSH  ", "POP   ", "SBB   ", "SBB   ", "SBB   ", "SBB   ", "SBB   ", "SBB   ", "PUSH  ", "POP   ",
//								"AND   ", "AND   ", "AND   ", "AND   ", "AND   ", "AND   ", "SEG   ", "DAA   ", "SUB   ", "SUB   ", "SUB   ", "SUB   ", "SUB   ", "SUB   ", "SEG   ", "DAS   ",
//								"XOR   ", "XOR   ", "XOR   ", "XOR   ", "XOR   ", "XOR   ", "SEG   ", "AAA   ", "CMP   ", "CMP   ", "CMP   ", "CMP   ", "CMP   ", "CMP   ", "SEG   ", "AAS   ",
//								"INC   ", "INC   ", "INC   ", "INC   ", "INC   ", "INC   ", "INC   ", "INC   ", "DEC   ", "DEC   ", "DEC   ", "DEC   ", "DEC   ", "DEC   ", "DEC   ", "DEC   ",
//								"PUSH  ", "PUSH  ", "PUSH  ", "PUSH  ", "PUSH  ", "PUSH  ", "PUSH  ", "PUSH  ", "POP   ", "POP   ", "POP   ", "POP   ", "POP   ", "POP   ", "POP   ", "POP   ",
//								"PUSHA ", "POPA  ", "BOUND ", "ARPL  ", "RESRVD", "RESRVD", "RESRVD", "RESRVD", "PUSH  ", "IMUL  ", "PUSH  ", "IMUL  ", "INSB  ", "INSW  ", "OUTSB ", "OUTSW ",
//								"JO    ", "JNO   ", "JB    ", "JNB   ", "JE    ", "JNE   ", "JBE   ", "JNBE  ", "JS    ", "JNS   ", "JP    ", "JNP   ", "JL    ", "JNL   ", "JLE   ", "JNLE  ",
//								"Immed ", "Immed ", "Immed ", "Immed ", "TEST  ", "TEST  ", "XCHG  ", "XCHG  ", "MOV   ", "MOV   ", "MOV   ", "MOV   ", "MOV   ", "LEA   ", "MOV   ", "POP   ",
//								"NOP   ", "XCHG  ", "XCHG  ", "XCHG  ", "XCHG  ", "XCHG  ", "XCHG  ", "XCHG  ", "CBW   ", "CWD   ", "CALL  ", "WAIT  ", "PUSHF ", "POPF  ", "SAHF  ", "LAHF  ",
//								"MOV   ", "MOV   ", "MOV   ", "MOV   ", "MOVSB ", "MOVSW ", "CMPsb ", "CMPSW ", "TEST  ", "TEST  ", "STOSB ", "STOSW ", "LODSB ", "LODSW ", "SCASB ", "SCASW ",
//								"MOV   ", "MOV   ", "MOV   ", "MOV   ", "MOV   ", "MOV   ", "MOV   ", "MOV   ", "MOV   ", "MOV   ", "MOV   ", "MOV   ", "MOV   ", "MOV   ", "MOV   ", "MOV   ",
//								"Shift ", "Shift ", "RET   ", "RET   ", "LES   ", "LDS   ", "MOV   ", "MOV   ", "ENTER ", "LEAVE ", "RET   ", "RET   ", "INT   ", "INT   ", "INTO  ", "IRET  ",
//								"Shift ", "Shift ", "Shift ", "AAM   ", "AAD   ", "RESRVD", "CLAT  ", "ESC   ", "ESC   ", "ESC   ", "ESC   ", "ESC   ", "ESC   ", "ESC   ", "ESC   ", "ESC   ",
//								"LOOPNZ", "LOOPZ ", "LOOP  ", "JCXZ  ", "IN    ", "IN    ", "OUT   ", "OUT   ", "CALL  ", "JMP   ", "JMP   ", "JMP   ", "IN    ", "IN    ", "OUT   ", "OUT   ",
//								"LOCK  ", "RESRVD", "REP   ", "REPZ  ", "HLT   ", "CMC   ", "Grp 1 ", "Grp 1 ", "CLC   ", "STC   ", "CLI   ", "STI   ", "CLD   ", "STD   ", "Grp 2 ", "Grp 2 " };
////TO DO Fill in the following array with propery byte length for each instruction
//int InstructionBytes[256] = { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
//								4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
//								4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
//								4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
//								4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
//								4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
//								4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
//								4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
//								4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
//								4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
//								4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
//								4,4,4,4,4,4,4,4,4,4,4,6,4,4,4,4,
//								4,4,4,4,4,4,4,6,4,4,4,4,4,4,4,4,
//								4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
//								4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
//								4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 };