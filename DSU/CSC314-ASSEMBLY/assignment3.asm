;***************************************************************
;* Student: Stephen Razon
;* Program Name: assignment3.asm
;* Synopsis: This is an assembly program that generates a
;*           random number and is guessed by the user
;* Dependencies: N/A
;***************************************************************

%include "/usr/local/share/csc314/asm_io.inc"


segment .data
    prompt db "Enter a guess: ", 0
    msg1 db "Too high", 0
    msg2 db "Too low", 0
    msg3 db "Correct!", 0

segment .bss
    userInput RESD 1

segment .text
	global  asm_main

asm_main:
	push	ebp
	mov		ebp, esp
	; ********** CODE STARTS HERE **********

    ; generate random number 0-255 (from instructor's hint)
    mov EBX, 0
    mov BL, CL

    call print_nl             ; printf("\n");

    do_while_body:
        mov EAX, prompt       ; EAX = prompt;
        call print_string     ; printf("Enter a guess: ");
        call read_int         ; scanf("%d");
        mov [userInput], AL   ; userInput = scanf("%d");

        cmp [userInput], BL   ;ZF = 1 when equal, else ZF = 0

        ; if userInput > BL
        jg guessedGreater      ;ZF = 0 and SF = OF

        ; if userInput == BL
        je guessedCorrect      ;ZF = 1

        ; if userInput < BL
        jmp guessedLesser      ;SF != OF

    do_while_cond:
        cmp BL, [userInput]
        jne guessedCorrect

    guessedGreater:
        mov EAX, msg1
        call print_string
        call print_nl
        jmp do_while_body

    guessedLesser:
        mov EAX, msg2
        call print_string
        call print_nl
        jmp do_while_body

    guessedCorrect:
        mov EAX, msg3
        call print_string
        call print_nl
        jmp end

    end:

        ; display register & memory values
        dump_regs 1
        call print_nl
        dump_mem 1, msg3, 1
        call print_nl

	; *********** CODE ENDS HERE ***********
	mov		eax, 0
	mov		esp, ebp
	pop		ebp
	ret
