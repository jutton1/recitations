.text

.globl main
main:
    # Make space on the stack for the return address, and the caller saves t registers
    addi $sp, $sp, -12

    sw $ra, 0($sp)

    li $t0, 1
    li $t1, 2

    move $a0, $t0
    move $a1, $t1

    sw $t0, 4($sp)
    sw $t1, 8($sp)

    jal foo

    lw $t0, 4($sp)
    lw $t1, 8($sp)

    add $t5, $v0, $t0
    add $t5, $t5, $t1

    move $a0, $t5
    li $v0, 1
    syscall

    lw $ra, 0($sp)
    addi $sp, $sp, 12

    jr $ra

foo:
    add $v0, $a0, $a1
    jr $ra