.global sort
sort:
    push %rbp
    mov %rsp, %rbp
    push %rbx
    push %r12
    push %r13
    push %r14
    push %r15

    # выделение памяти на стеке для массива
    sub $100, %rsp

    # инициализация массива
    mov $100, %r12        # максимальный размер массива
    lea (%rsp), %r13      # указатель на массив
    xor %rax, %rax        # счетчик

init_loop:
    movb $0, (%r13,%rax,1) # обнуление байта
    inc %rax
    cmp %r12, %rax
    jl init_loop

    # сортировка "пузырьком"
    mov %rsi, %r8         # n
    dec %r8               # n-1
    xor %r9, %r9          # i = 0

outer_loop:
    cmp %r8, %r9
    jge end_outer

    xor %r10, %r10        # j = 0
    mov %r8, %r11
    sub %r9, %r11         # n-i-1

inner_loop:
    cmp %r11, %r10
    jge end_inner

    # сравнение arr[j] и arr[j+1]
    mov (%rdi,%r10,4), %eax   # arr[j]
    mov 4(%rdi,%r10,4), %ebx  # arr[j+1]

    cmp %ebx, %eax
    jle no_swap

    # обмен элементов
    mov %ebx, (%rdi,%r10,4)
    mov %eax, 4(%rdi,%r10,4)

    # установка флагов для перемещенных элементов
    lea (%rsp), %rcx
    movb $1, (%rcx,%r10,1)
    movb $1, 1(%rcx,%r10,1)

no_swap:
    inc %r10
    jmp inner_loop

end_inner:
    inc %r9
    jmp outer_loop

end_outer:
    # подсчет количества элементов, изменивших позицию
    xor %rax, %rax        # счетчик
    xor %rcx, %rcx        # индекс

count_loop:
    cmp %rsi, %rcx
    jge end_count
    movb (%rsp,%rcx,1), %dl
    test %dl, %dl
    jz skip
    inc %rax
skip:
    inc %rcx
    jmp count_loop

end_count:
    # эпилог функции
    add $100, %rsp
    pop %r15
    pop %r14
    pop %r13
    pop %r12
    pop %rbx
    pop %rbp
    ret
