.text
.align 2

.globl main
main:
    li $t0, 0
    li $t1, 10

    li $v0, 4
    la $a0, msg
    syscall                 # prints $t0

_loop:
    bgt $t0, $t1, _end_loop

    li $v0, 1
    move $a0, $t0
    syscall

    li $v0, 4
    la $a0, nln
    syscall                 # prints the new line character

    addi $t0, $t0, 1

    j _loop                 # jumps to _loop label, j = jump, b = branch basically do the same thing

_end_loop:
    li $v0, 0

    jr $ra

.data
    msg: .asciiz "printing numbers now...\n"
    nln: .asciiz "\n"