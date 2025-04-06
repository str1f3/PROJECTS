%include "/usr/local/share/csc314/asm_io.inc"


segment .data
    prompt db "Enter the value of A: ", 0
    msg    db "The value of E is: ", 0

segment .bss
    aVar RESD 1

    bVar RESD 1
    cVar RESD 1
    dVar RESD 1
    eVar RESD 1

    result RESD 1
segment .text
	global  asm_main

asm_main:
	push	ebp
	mov		ebp, esp
	; ********** CODE STARTS HERE **********

	mov EAX, prompt          ;EAX = prompt
    call print_string        ;printf("Enter the value of A: ");
    call read_int
    mov [aVar], EAX          ;EAX = xVar
    
    sub EAX, 10
    mov [result], EAX        ;gtg 20
    add EAX, [aVar]
    mov [result], EAX        ;gtg 50
    sub EAX, 1
    mov [result], EAX        ;this should be 49
    add EAX, 20
    mov [result], EAX        ;this should be 49+20
    add EAX, 30
    mov [result], EAX

    ;mov [cVar], EAX
    ;sub EAX, 1
    ;add EAX, [bVar]
    ;mov [bVar], EAX
   

    mov EAX, msg             ;EAX = msg
    call print_string        ;printf("The value of E is: ");

    mov EAX, [result]
    call print_int           ;printf("...%d", xVar);

    call print_nl

	; *********** CODE ENDS HERE ***********
	mov		eax, 0
	mov		esp, ebp
	pop		ebp
	ret
