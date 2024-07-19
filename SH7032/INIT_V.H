;*************************************
;   INITIAL VARIABLE
;*************************************
        MOV #0,R10
        MOV MSEC11,R11
        MOV.W R10,@R11
        MOV SEC11,R11
        MOV.W R10,@R11

        MOV #0,R10
        MOV DATA_BUFF11,R11
        MOV R10,@R11
        ADD #4,R11
        MOV.B R10,@R11

        MOV #0,R11
xx:     MOV #1,R10
        mov TMPB1,r12
        mov.b r11,@r12
;        BSR EE_WR
        NOP
        mov TMPB1,r12
        mov.b @r12,r11
        ADD #1,R11
        MOV R11,R0
        CMP/EQ #50,R0
        BT XX1
;        bra xx
        nop
XX1:

        MOV DBOUNCE0,R1
        MOV #7,R2
        MOV.B R2,@R1
