MODULE MainModule
	CONST jointtarget PtoSingularidade:=[[2,2,2,2,31,1],[9E+09,9E+09,9E+09,9E+09,9E+09,9E+09]];
	CONST robtarget PtoSeg:=[[464.87,17.53,317.99],[0.189626,0.0129772,0.9816,0.0182986],[0,0,0,0],[9E+09,9E+09,9E+09,9E+09,9E+09,9E+09]];
	CONST robtarget PtoRef:=[[377.31,2.18,112.09],[0.0601448,-0.0096712,-0.998065,-0.0124363],[0,0,-1,0],[9E+09,9E+09,9E+09,9E+09,9E+09,9E+09]];
	VAR robtarget pto;
    PROC main()
		MoveAbsJ PtoSingularidade\NoEOffs, v1000, z50, tool0;
		MoveJ PtoSeg, v1000, z50, tool0;
        pto:= offs(PtoRef,30,-30,0);
        LetraI pto;
        pto:= offs(PtoRef,30,-80,0);
        LetraT pto;
        pto:= offs(PtoRef,30,-130,0);
        LetraA pto;
        pto:= offs(PtoRef,30,-180,0);
        LetraL pto;
        pto:= offs(PtoRef,30,-230,0);
        LetraO pto;        
	ENDPROC
    
    PROC LetraI(var robtarget PtoRefL)
        MoveJ Offs(PtoRefL,0,-15,30), v1000, fine, tool0;
		MoveL Offs(PtoRefL,0,-15,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,60,-15,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,60,-15,30), v1000, fine, tool0;
        MoveJ Offs(PtoRefL,65,-15,30), v1000, fine, tool0;
        MoveL Offs(PtoRefL,65,-15,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,75,-20,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,75,-20,30), v1000, fine, tool0;
	ENDPROC
	PROC LetraT(var robtarget PtoRefL)
        MoveJ Offs(PtoRefL,60,0,30), v1000, fine, tool0;
		MoveL Offs(PtoRefL,60,0,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,60,-30,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,60,-30,30), v1000, fine, tool0;
        MoveJ Offs(PtoRefL,60,-15,30), v1000, fine, tool0;
        MoveL Offs(PtoRefL,60,-15,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,0,-15,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,0,-15,30), v1000, fine, tool0;
    ENDPROC
    PROC LetraA(var robtarget PtoRefL)
        MoveJ Offs(PtoRefL,0,0,30), v1000, fine, tool0;
		MoveL Offs(PtoRefL,0,0,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,60,-15,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,0,-30,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,0,-30,20), v1000, fine, tool0;
        MoveJ Offs(PtoRefL,24,-6,20), v1000, fine, tool0;
        MoveL Offs(PtoRefL,24,-6,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,24,-24,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,24,-24,20), v1000, fine, tool0;
    ENDPROC
    PROC LetraL(var robtarget PtoRefL)
        MoveJ Offs(PtoRefL,60,0,30), v1000, fine, tool0;
		MoveL Offs(PtoRefL,60,0,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,0,0,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,0,-30,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,0,-30,20), v1000, fine, tool0;
    ENDPROC
    
    PROC LetraO(var robtarget PtoRefL)
        MoveJ Offs(PtoRefL,45,0,30), v1000, fine, tool0;
		MoveL Offs(PtoRefL,45,0,0), v1000, fine, tool0;
        MoveL Offs(PtoRefL,15,0,0), v1000, fine, tool0;
        MoveC Offs(PtoRefL,0,-15,0), Offs(PtoRefL,15,-30,0), v1000, fine, tool0;
		MoveL Offs(PtoRefL,45,-30,0), v1000, fine, tool0;
        MoveC Offs(PtoRefL,60,-15,0), Offs(PtoRefL,45,0,0), v1000, fine, tool0;
		MoveL Offs(PtoRefL,45,0,30), v1000, fine, tool0;
    ENDPROC
    
    PROC LetraD(var robtarget PtoRefL)
        MoveJ Offs(PtoRefL,0,0,30), v1000, fine, tool0;
		MoveL Offs(PtoRefL,0,0,0), v1000, fine, tool0;
		MoveL Offs(PtoRefL,60,0,0), v1000, fine, tool0;
		MoveC Offs(PtoRefL,30,-30,0), Offs(PtoRefL,0,0,0), v1000, fine, tool0;
		MoveL Offs(PtoRefL,0,0,30), v1000, fine, tool0;
	ENDPROC
ENDMODULE