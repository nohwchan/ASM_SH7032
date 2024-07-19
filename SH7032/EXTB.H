CHK_EXT:
        MOV INPORT1,R1
        MOV.W @R1,R0
        AND #B'00110000,R0        ;MASK TO CHECK FWD OR RWD
        TST #B'00110000,R0
        BF NO_FW_RW               ;NO FWD OR RWD
        CMP/EQ #0,R0              
        BT NO_FW_RW               ;FWD AND RWD SIMULTANOUS JMP

CHK_RWD:
        TST #B'00100000,R0
        BT CHK_FWD
RUN_RWD:
        MOV P_STATUS,R1
        MOV.B @R1,R0
        TST #B'100,R0            ;IF P_STATUS.2=0 IS KEY START STOP
        BT K_RWD     
        BRA EXT_RWD
        NOP

NO_FW_RW:
        MOV SYSFLG1,R1
        MOV.B @R1,R0
        TST #B'100,R0
        BF N_RUN1                 ;RUN MODE AND NO FWD-RWD JMP
        TST #B'10000,R0           ;FIRST RUN JMP
        BF NO_RUN
        BRA OUT_EXT
        NOP
NO_RUN: MOV FSET1,R1
        MOV #0,R0
        MOV.W R0,@R1
        BRA FRIST_RUN
        NOP
N_RUN1: MOV FSET1,R1
        MOV #0,R0
        MOV.W R0,@R1
        MOV P_STATUS,R1
        MOV.B @R1,R0
        TST #B'100000,R0
        BT N_RUN11
        MOV FLAST1,R1
        MOV #0,R2
        MOV.W R2,@R1
        ;CLR MSPD
        ;BRA N_RUN11
        ;NOP
N_RUN11:TST #B'1000,R0
        BT N_RUN2
        BRA OUT_EXT
        NOP

K_RWD:  MOV R_STATUS,R1
        MOV.B @R1,R0
        TST #H'80,R0
        BF KRWD_RUN               ;RUN BEFORE
        BRA KRWD_NRUN
        NOP

KRWD_RUN:
        TST #1,R0
        BF KRWD_BF                ;RUN RWD BEFORE THEN JMP
        BRA K_FWD_BF              

KRWD_BF:
        TST #B'100000,R0
        BT KRWD_BF1               ;NO DECEL TO STOP JMP
        BRA NO_FW_RW
        NOP

KRWD_BF1:
        MOV FRUN1,R1
        MOV.W @R1,R0
        CMP/EQ #0,R0
        BT KRWD_STILL             ;FRUN=0 STAND STILL

        ;FRUN<>0 RUNNING
        TST #B'10,R0
        BF KRWD_FR1
        TST #1,R0
        BF KRWD_DEC
KRWD_FR1:
        BRA NO_FW_RW
        NOP

KRWD_DEC:
        MOV R11_STATUS,R1
        MOV.B @R1,R0
        TST #1,R0
        BF NO_FW_RW
        MOV FLAST1,R1
        MOV.W @R1,R1
        MOV FSET_,R2 
        MOV.W R1,@R2
        BRA NO_FW_RW
        NOP

KRWD_STILL:
        MOV P_STATUS,R1
        MOV.B @R1,R0
        TST #B'10,R0
        BF KRWD_BRK
        MOV R_STATUS,R1
        MOV.B @R1,R0
        TST #B'10000,R0
        BF KRWD_R_B
        MOV R11_STATUS,R1
        TST #1,R0
        BF NO_FW_RW
        MOV R_STATUS,R1
        MOV.B @R1,R0
        OR #B'10000,R0      
KRWD_R_B:
        MOV FLAST1,R1
        MOV.W @R1,R1
        MOV FSET_,R2 
        MOV.W R1,@R2
        BRA FRIST_RUN
        NOP

KRWD_BRK:
        MOV FLAST1,R1
        MOV.W @R1,R1
        MOV STOP_F1,R2
        CMP/GE R2,R1
        BT KRWD_R_A
        MOV R_STATUS,R1
        MOV.B R1,@R0
        TST #B'10000,R0
        BF KRWD_R_A
        BRA NO_FW_RW
        NOP
KRWD_R_A:
        MOV FLAST1,R1
        MOV.W @R1,R1
        MOV START_F1,R2
        CMP/GE KRWD_R_A
        BF NO_FW_RW
        MOV R_STATUS,R1
        MOV.B @R1,R0
        OR #B'10000,R0
        AND #B'11111101,R0
        MOV.B R0,@R1
        MOV FLAST1,R1
        MOV.W @R1,R1
        MOV FSET_,R2 
        MOV.W R1,@R2
        BRA FRIST_RUN
        NOP

K_FWD_BF:

EXT_FBF:
EXT_RWD:

CHK_FWD:

FRIST_RUN:

OUT_EXT:
