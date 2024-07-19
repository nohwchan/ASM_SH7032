;;********************************************
;; DIVIDE UNSIGN  REG1/REG0 (32 / 16 ===> 16)
;;********************************************
                .MACRO  DIVU  REG0,REG1
                SHLL16  \REG0
                DIV0U
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                ROTCL   \REG1
                EXTU.W  \REG1,\REG1
                .ENDM

;;******************************************
;; DIVIDE SIGN  REG1/REG0 (32 / 16 ===> 16)
;;******************************************
                .MACRO  DIVS  REG0,REG1
                SHLL16  \REG0
                DIV0S   \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                DIV1    \REG0,\REG1
                ROTCL   \REG1
                EXTS.W  \REG1,\REG1
                .ENDM

;;************************************
;; DIV SIGN BY 16
;;************************************
		.MACRO	DIVS16	REG0
		SHAR	\REG0
		SHAR	\REG0
		SHAR	\REG0
		SHAR	\REG0
		.ENDM
;;************************************
;; DIV SIGN BY 32
;;************************************
		.MACRO	DIVS32	REG0
		SHAR	\REG0
		SHAR	\REG0
		SHAR	\REG0
		SHAR	\REG0
		SHAR	\REG0
		.ENDM
;;************************************
;; DIV SIGN BY 64
;;************************************
		.MACRO	DIVS64	REG0
		SHAR	\REG0
		SHAR	\REG0
		SHAR	\REG0
		SHAR	\REG0
		SHAR	\REG0
		SHAR	\REG0
		.ENDM
;;************************************
;; DIV SIGN BY 128
;;************************************
		.MACRO	DIVS128	REG0
		SHAR	\REG0
		SHAR	\REG0
		SHAR	\REG0
		SHAR	\REG0
		SHAR	\REG0
		SHAR	\REG0
		SHAR	\REG0
		.ENDM
;;******************************************
;; DIVIDE SIGN  REG1/REG0 (32 / 32 ===> 32)
;;******************************************
                .MACRO  DIVSN  REG0,REG1
		MOV	R1,@-SP
		MOV	R3,@-SP
		MOV	\REG1,R3
		ROTCL	R3
		SUBC	R1,R1
		XOR	R3,R3
		SUBC	R3,\REG1
		DIV0S	\REG0,R1
;		.arepeat 32
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1
		ROTCL	\REG1
		DIV1	\REG0,R1

;		.aendr	
		ROTCL	\REG1
		ADDC	R3,\REG1
		MOV	@SP+,R3
		MOV	@SP+,R1

                .ENDM
