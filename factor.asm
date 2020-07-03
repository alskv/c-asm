global factorization

section .text
factorization:
    push ebp ;prolog
    mov ebp, esp

    push ebx
    push esi
    push edi

    mov eax, [esp+20] ;number
    mov edi, [esp+24] ;callback 
    mov ebx, 2 ;factor

_factor:
    cmp eax, 1 ;check the end of factorization
    je .exit

    mov esi, eax
    xor edx, edx
    div ebx ;factorization

    cmp edx, 0
    jne .update_factor

    mov esi, eax
    push eax  
    push ebx
    call edi ;callback if the factor is correct
    add esp, 8
    mov ebx, 2
    mov eax, esi
    jmp _factor

    .update_factor:
        mov eax, esi
        add ebx, 1
        jmp _factor

    .exit:
    pop edi ;epilog and exit from function
    pop esi
    pop ebx

    mov esp, ebp
    pop ebp
    ret




