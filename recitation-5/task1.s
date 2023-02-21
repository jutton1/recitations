.text

.globl main
main:
    addi $sp, $sp, -4
    sw $ra, 0($sp)

    li $a0, 1
    li $a1, 2
    jal foo

    move $a0, $v0
    li $v0, 1
    syscall

    lw $ra, 0($sp)
    addi $sp, $sp, 4
    jr $ra

foo:
    add $v0, $a0, $a1
    jr $ra