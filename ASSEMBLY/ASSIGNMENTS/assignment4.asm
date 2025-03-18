%include "/usr/local/share/csc314/asm_io.inc"

segment .data
    prompt1 db "Enter the first number: ", 0
    prompt2 db "Enter the second number: ", 0
    prompt3 db "Enter the third number: ", 0
    outMsgMax db "The maximum of the three numbers is: ", 0
    outMsgMin db "The minimum of the three numbers is: ", 0

segment .bss
    number1 resd 1
    number2 resd 1
    number3 resd 1
    maxNumber resd 1
    minNumber resd 1

segment .text
    global  asm_main

asm_main:
    push    ebp
    mov     ebp, esp
    ; ********** CODE STARTS HERE **********

    ; read the first input
    mov     eax, prompt1
    call    print_string
    call    read_int
    mov     [number1], eax

    ; read the second input
    mov     eax, prompt2
    call    print_string
    call    read_int
    mov     [number2], eax

    ; read the third input
    mov     eax, prompt3
    call    print_string
    call    read_int
    mov     [number3], eax

    ; push the values in variables onto the stack
    push    dword [number1]
    push    dword [number2]
    push    dword [number3]

    ; call the max subprogram & determine the largest number
    call    max

    ; The maximum value is now in EAX

    ; Call storeMax to store and print the maximum number
    push    eax
    call    storeMax

    ; pop the maximum value from the stack
    pop     eax

    ; Call storeMin to store and print the minimum number
    push    eax  ; pushing the maximum again for comparison
    call    min

    ; *********** CODE ENDS HERE ***********
    mov     eax, 0
    mov     esp, ebp
    pop     ebp
    ret

max:
    push    ebp
    mov     ebp, esp

    mov     eax, [ebp + 8]              ; first parameter
    mov     ebx, [ebp + 12]             ; second parameter
    cmp     eax, ebx
    jg      greaterThanEax
    mov     eax, ebx

greaterThanEax:
    mov     ebx, [ebp + 16] ; third parameter
    cmp     eax, ebx
    jg      greaterThanEaxOrEbx
    mov     eax, ebx

greaterThanEaxOrEbx:
    mov     esp, ebp
    pop     ebp
    ret

storeMax:
    mov     [maxNumber], eax            ; store the maximum number in maxNumber

    ; display the largest number
    mov     eax, outMsgMax
    call    print_string
    mov     eax, [maxNumber]
    call    print_int
    call    print_nl
    ret

min:
    push    ebp
    mov     ebp, esp

    mov     eax, [ebp + 8]              ; first parameter
    mov     ebx, [ebp + 12]             ; second parameter
    cmp     eax, ebx
    jle     checkThirdNumber            ; Jump if the first number is less than or equal to the second number
    mov     eax, ebx                    ; Otherwise, update EAX with the value of the second number

checkThirdNumber:
    mov     ebx, [ebp + 16]             ; third parameter
    cmp     ebx, eax                    ; Compare the current minimum (EAX) with the third number
    mov     eax, ebx
    jle     storeMin                    ; Jump if EAX is less than or equal to the third number
    ;mov     eax, ebx                    ; Update EAX if the third number is smaller

storeMin:
    mov     [minNumber], eax            ; store the minimum number in minNumber

    ; display the smallest number
    mov     eax, outMsgMin
    call    print_string
    mov     eax, [minNumber]
    call    print_int
    call    print_nl

    mov     esp, ebp
    pop     ebp
    ret