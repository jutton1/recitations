.text

.globl main
main:
    # Make space on the stack for the return address
    addi $sp, $sp, -4

    sw $ra, 0($sp)

    li $s0, 1
    li $s1, 2

    move $a0, $s0
    move $a1, $s1

    jal foo

    add $t5, $v0, $s0
    add $t5, $t5, $s1

    move $a0, $t5
    li $v0, 1
    syscall

    lw $ra, 0($sp)
    addi $sp, $sp, 4

    jr $ra

foo:
    addi $sp, $sp, -8
    sw $s0, 0($sp)
    sw $s1, 4($sp)

    add $v0, $a0, $a1

    lw $s0, 0($sp)
    lw $s1, 4($sp)
    addi $sp, $sp, 8

    jr $ra