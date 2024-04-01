section .text
global dot_product_asm

dot_product_asm:
    ; RCX = float* A, RDX = float* B, R8 = int n
    xorps   xmm0, xmm0                ; This will be returned later
    xor     rax, rax                  ; Clear out rax for loop counter
    
dot_product_loop:
    movss   xmm1, [rcx + 4*rax] 
    mulss   xmm1, [rdx + 4*rax]       ; Multiply A[i] * B[i]              
    addss   xmm0, xmm1                ; Add to the running sum

    add     rax, 1                    ; Increment loop counter
    cmp     rax, r8                   ; Compare with length 
    jl      dot_product_loop          ; Loop until all elements are processed
    
    ret

