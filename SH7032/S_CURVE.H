;*************************************
;--------S CURVE PROCESS-------------*
;*************************************
	MOV INCREA,R0
	MOV @R0,R1
	ADD #1,R1
	MOV R1,@R0
		
;	MOV ACC_STA,R0
;	MOV @R0,R2
;	MOV ACC_END,R0
;	MOV @R0,R3
;	MOV ACC_ALL,R0
;	MOV @R0,R4
;	CMP/GT R2,R1		;IF COUNTER MORE THAN ACCEL START TIME
;	BT  ACC_LIN		;THEN JMP TO ACC_LIN 

	MOV #0,R3
	MOV K50,R2
	MOV R2,R4

;-----calculate accel time every 1 ms.------------------
	ADD R2,R3		;ELSE SOFT ACCEL START CONTINUE
	SHLL R4
	SUB R3,R4
	MULS R2,R4
	STS MACL,R5
	MOV #100,R0
	MULS R0,R5
	STS MACL,R5
	MOV A,R1
	SHLL R1
	DIVS R1,R5
;	MOV K,R0
;	CMP/GT R0,R5
;	BF CAL_DEL
;	MOV K,R5
;--------------------------------------------------------
;	MOV K,R5
;	MOV A,R2
;	CMP/GT R2,R1
;	BF CAL_DEL
;	MOV #1,R5
;------change delta of acceleration----------------
CAL_DEL:
	MOV #50,R0
	CMP/GT R0,R5
	BT ACC1
	MOV R5,R6
	DIVS R6,R0
	MOV DELACCS,R1
	MOV.B R0,@R1
	BRA STO_ACC
	NOP
ACC1:  
	MOV #1,R1
	MOV DELACCS,R0
	MOV.B R1,@R0
;----------------------------------------------
STO_ACC:
	MOV ACCTIMS,R0
	MOV R5,@R0
	BRA OUT_S_CURVE
	NOP

		.ALIGN 4
INCREA: 	.DATA.L INCREA_
FRUNS:		.DATA.L FRUN
FSETS:		.DATA.L FSET
ACCTIMS:	.DATA.L ACC_TIM
DECTIMS:	.DATA.L DEC_TIM
SYSFLGS:	.DATA.L SYSFLG
CONSTS:		.DATA.L 5000
STEPTIMS:	.DATA.L STEP_TIM
REMENDERS:	.DATA.L REM_DER
DELACCS:	.DATA.L DEL_ACC
DELDECS:	.DATA.L	DEL_DEC
ACCREMENDS:	.DATA.L ACC_REMEND
MMSECS:		.DATA.L MMSEC
RSTATUSS:	.DATA.L _R_STATUS
PSTATUSS:       .DATA.L _P_STATUS
IDCOMS:		.DATA.L 480	;2.5*SQRT(3)=Y*SQRT(3)=V_VECTOR*2^6=V_VEC_SCALE
IDESTS:		.DATA.L _ID_EST
TTTS: 		.DATA.L 4000
K50:		.DATA.L 20
K:		.DATA.L 3000
A:		.DATA.L 1
OUT_S_CURVE:

