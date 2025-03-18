%include "/usr/local/share/csc314/asm_io.inc"


segment .data
    prompt1 db "Enter a value for A: ", 0
    prompt2 db "Enter a value for B: ", 0
    msg db "The value of X = (17 + A) * ((B * 32) / A) + 123 - B is ", 0

segment .bss
    userInputA RESD 1
    userInputB RESD 1

    result RESD 1

    resultPT1 RESD 1
    resultPT2 RESD 1

segment .text
	global  asm_main

asm_main:
	push	ebp
	mov		ebp, esp
	; ********** CODE STARTS HERE **********

    call print_nl

	mov EAX, prompt1        ;EAX = prompt1
    call print_string       ;printf(prompt1)
    call read_int           ;scanf("%d")
    mov [userInputA], EAX   ;

    mov EAX, prompt2        ;EAX = prompt2
    call print_string       ;printf(prompt2)
    call read_int           ;scanf("%d")
    mov [userInputB], EAX   ;

    ; ******** START CALCULATIONS ********
    mov EAX, 17              ;
    add EAX, [userInputA]    ;
    mov [resultPT1], EAX     ;

    mov AL, [userInputB]     ;
    mov DL, 32               ;
    mul DL                   ;
    ;mov [result], AX        ;
    mov CL, [userInputA]     ;
    div CL                   ; 
    mov [resultPT2], AX      ;

    mov EAX, [resultPT1]
    mov EDX, [resultPT2]
    mul EDX
    add EAX, 123
    sub EAX, 20
    mov [result], EAX
    
    ; ******** END CALCULATIONS *****

    mov EAX, msg            ;EAX = msg
    call print_string       ;printf("The value of X...")

    mov EAX, [result]       ;
    call print_int          ;
    call print_nl

    call print_nl           ;printf("\n")

    dump_regs 1
    call print_nl
    dump_mem  1,msg, 1

	; *********** CODE ENDS HERE ***********
	mov		eax, 0
	mov		esp, ebp
	pop		ebp
	ret
